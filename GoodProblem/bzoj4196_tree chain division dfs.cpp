#include<cstdio>
#include<cstring> 
#include<algorithm>
#include<functional>
#include<cctype>
#include<cstdlib>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=Pre[x];p;p=Next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=Next[p])  
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,0x3f,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define MEMx(a,b) memset(a,b,sizeof(a));
#define INF (0x3f3f3f3f)
#define F (1000000007)
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case #%d: %lld\n",kcase,ans);
#define PRi(a,n) For(i,n-1) cout<<a[i]<<' '; cout<<a[n]<<endl;
#define PRi2D(a,n,m) For(i,n) { \
                        For(j,m-1) cout<<a[i][j]<<' ';\
                        cout<<a[i][m]<<endl; \
                        } 
#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return ((a-b)%F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
    return x*f;
} 
#define MAXN (400000+10)
#define Lson (o<<1)
#define Rson ((o<<1)+1)
ll cover[MAXN<<2],sum[MAXN<<2];
void pushUp(int o,int m) {
    sum[o]=sum[Lson]+sum[Rson];
}
void pushDown(int o,ll m) {
    if (cover[o]!=-1) {
        cover[Lson]=cover[Rson]=cover[o];
        sum[Lson]=(m-(m>>1))*cover[o];
        sum[Rson]=(m>>1)*cover[o];
        cover[o]=-1;
    }
} 
void build(int l,int r,int o) {
    cover[o]=-1;
    sum[o]=0;
    if (l==r) {
        return;
    }
    int m=(l+r)>>1;
    build(l,m,Lson);
    build(m+1,r,Rson);
    pushUp(o,r-l+1);
}
void update(int l,int r,int o,int L,int R,int c) {
    if (L<=l&&r<=R) {
        cover[o]=c;
        sum[o]=(r-l+1)*c;
        return;
    }
    pushDown(o,r-l+1);
    int m=(l+r)>>1;
    if (L<=m) update(l,m,Lson,L,R,c);
    if (m<R) update(m+1,r,Rson,L,R,c);
    pushUp(o,r-l+1);
}
ll query(int l,int r,int o,int L,int R) {
    if (L<=l && r<=R) {
        return sum[o];
    }
    pushDown(o,r-l+1);
    int m=(l+r)>>1;
    ll ret=0;
    if (L<=m) ret+=query(l,m,Lson,L,R);
    if (m<R) ret+=query(m+1,r,Rson,L,R);
    return ret; 
}
int n,m,a[MAXN];
struct Tree{
    #define MAXM (200000+10)
    void mem(){MEM(Pre) siz=1;}
    int edge[MAXM],Next[MAXM],Pre[MAXN],siz;
    void addedge(int u,int v)
    {
        edge[++siz]=v;
        Next[siz]=Pre[u];
        Pre[u]=siz;
    }
    void addedge2(int u,int v){addedge(u,v);addedge(v,u);}
    bool vis[MAXN]; 
    int cnt,id[MAXN],mx[MAXN];
    int son[MAXN],dep[MAXN],sz[MAXN],top[MAXN],pre[MAXN],q[MAXN];
    void build()
    {
        MEM(vis) cnt=0; MEM(id)
        MEM(son) MEM(dep) MEM(sz) MEM(top) MEM(pre) MEM(q) 
        int r=1;
        vis[dep[1]=q[1]=1]=1;
        For(i,r)
        {
            int u=q[i];
            Forp(u)
            {
                int v=edge[p];
                if (vis[v]) continue; else vis[v]=1;
                dep[ q[++r]=v ]=dep[u]+1;
                pre[v]=u;
            }
        }
        ForD(i,r) {
            sz[pre[q[i]]] += ++sz[q[i]];
            if (sz[son[pre[q[i]]]]<sz[q[i]] ) son[pre[q[i]]] = q[i];
        }       
        dfs(1,0,1);
    }
    void dfs(int x,int fa,int tp){
        top[x]=tp; id[x]=++cnt;
        if (son[x]) dfs(son[x],x,tp);
        Forp(x)
        {
            int v=edge[p];
            if (v==fa||v==son[x]) continue;
            dfs(v,x,v);
        }   
        mx[x]=cnt;
    }
    int lca(int a,int b)
    {   
        while(1) {
            if (top[a]==top[b]) return dep[a]<=dep[b] ? a:b;
            if (dep[top[a]]<dep[top[b]]) swap(a,b);
            a=pre[top[a]];
        }
    }

    ll AskSum(int a,int b)
    {
        ll ans=0;
        while (top[a]^top[b]) {
            ans+=query(1,n,1,id[top[a]],id[a]);
            a=pre[top[a]];
        }   
        ans+=query(1,n,1,id[b],id[a]);
        return ans;
    }

    void MakeOne(int a,int b)
    {
        while (top[a]^top[b]) {
            update(1,n,1,id[top[a]],id[a],1);
            a=pre[top[a]];
        }   
        update(1,n,1,id[b],id[a],1);
    }
}S;
int main()
{
//  freopen("bzoj4196.in","r",stdin);
    scanf("%d",&n);
    Fork(i,2,n) {
        a[i]=read()+1;
    }
    S.mem();
    Fork(i,2,n) S.addedge2(a[i],i);
    S.build();
    m=read();
    For(i,m) {
        char s[100];int x;
        scanf("%s %d",s,&x);x++;
        if (s[0]=='i') {
            printf("%lld\n",S.dep[x]-S.AskSum(x,1));
            S.MakeOne(x,1);

        } else {
            printf("%lld\n",query(1,n,1,S.id[x],S.mx[x]));
            update(1,n,1,S.id[x],S.mx[x],0);
        }
    }
    return 0;
}
