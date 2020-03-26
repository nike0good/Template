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
#define Lson (ls[o])
#define Rson (rs[o])
int ls[10000000],rs[10000000],sum[10000000],mx[10000000],size;
void pushUp(int o) {
	sum[o]=sum[Lson]+sum[Rson];
	mx[o]=max(mx[Lson],mx[Rson]);
}
void mem(){size=0;}
void update(int l,int r,int &o,int x,int c) {
	if (!o) {
		o=++size;
		ls[o]=rs[o]=sum[o]=mx[o]=0;
	}
	if (l==r) {
		sum[o]=mx[o]=c; return;
	}
	int m=(l+r)>>1;
	if (x<=m) update(l,m,Lson,x,c);
	else update(m+1,r,Rson,x,c);
	pushUp(o);
}
int querySum(int l,int r,int o,int L,int R) {
	if (!o) return 0;
	if (L<=l&&r<=R) return sum[o];
	int m=(l+r)>>1;
	int ret=0;
	if (L<=m) ret+=querySum(l,m,Lson,L,R);
	if (m<R) ret+=querySum(m+1,r,Rson,L,R);
	return ret;
}
int queryMx(int l,int r,int o,int L,int R) {
	if (!o) return 0;
	if (L<=l&&r<=R) return mx[o];
	int m=(l+r)>>1;
	int ret=0;
	if (L<=m) ret = max(ret, queryMx(l,m,Lson,L,R));
	if (m<R) ret = max(ret, queryMx(m+1,r,Rson,L,R));
	return ret;
}

#define MAXN (200000+10)
int n,m;
int w[MAXN],c[MAXN],root[MAXN];
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
	int cnt,id[MAXN];
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
		For(i,r) {
			if (!top[q[i]])
				for(int x=q[i];x;x=son[x]) {
					top[x]=q[i];
					id[x]=++cnt; 
				}
		}
		
	}
	int lca(int a,int b)
	{	
		while(1) {
			if (top[a]==top[b]) return dep[a]<=dep[b] ? a:b;
			if (dep[top[a]]<dep[top[b]]) swap(a,b);
			a=pre[top[a]];
		}
	}
	
	ll AskSum(int p,int a,int b)
	{
		ll ans=0;
		while (top[a]^top[b]) {
			ans+=querySum(1,n,root[p],id[top[a]],id[a]);
			a=pre[top[a]];
		}	
		ans+=querySum(1,n,root[p],id[b],id[a]);
		return ans;
	}
	ll AskMx(int p,int a,int b)
	{
		int ans=0;
		while (top[a]^top[b]) {
			ans=max(ans,queryMx(1,n,root[p],id[top[a]],id[a]));
			a=pre[top[a]];
		}	
		ans=max(ans,queryMx(1,n,root[p],id[b],id[a]));
		return ans;
	}
	void set(int &o,int a,int c)
	{
		update(1,n,o,id[a],c);;
	}
}S;
int main()
{
//	freopen("bzoj3531.in","r",stdin);
//	freopen("bzoj3531.out","w",stdout);
	scanf("%d%d",&n,&m);
	MEM(root)
	For(i,n) {
		scanf("%d%d",&w[i],&c[i]);
	}
	mem();
	S.mem();
	For(i,n-1) S.addedge2(read(),read());
	S.build();
	For(i,n)
		S.set(root[c[i]],i,w[i]);
	
	
	while(m--) {
		char op[10]; int a,b;
		scanf("%s%d%d",op,&a,&b);
		int t=S.lca(a,b);
		if (strcmp(op,"QS")==0) {
			 printf("%lld\n",S.AskSum(c[b],a,t)+S.AskSum(c[b],b,t)-S.AskSum(c[b],t,t));
		} else if (strcmp(op,"QM")==0){
			 printf("%lld\n",max(S.AskMx(c[b],a,t),S.AskMx(c[b],b,t)));
		} else if (strcmp(op,"CC")==0) {
			S.set(root[c[a]],a,0);
			c[a]=b;
			S.set(root[c[a]],a,w[a]);
		} else {
			w[a]=b;
			S.set(root[c[a]],a,w[a]);
		}
	}	
	return 0;
}

