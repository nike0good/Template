#include<bits/stdc++.h>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=Pre[x];p;p=Next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=Next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
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
#define MAXN (100001+10)
ll cover[MAXN<<2],ls[MAXN<<2],rs[MAXN<<2],sum[MAXN<<2];
void pushUp(int o,int m) {
	ls[o]=ls[Lson];
	rs[o]=rs[Rson];
	sum[o]=sum[Lson]+sum[Rson]-(rs[Lson]==ls[Rson]);
}
void pushDown(int o,ll m) {
	if(m<=1) return;
	if (cover[o]!=-1) {
		cover[Lson]=cover[Rson]=cover[o];
		ls[Lson]=rs[Lson]=ls[Rson]=rs[Rson]=cover[o];
		sum[Lson]=sum[Rson]=1;
		cover[o]=-1;
	}
} 
void build(int l,int r,int o) {
	cover[o]=-1;
	sum[o]=ls[o]=rs[o]=1;
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
		if (l<r) cover[o]=c;
		ls[o]=rs[o]=c;
		sum[o]=1;
		return;
	}
	pushDown(o,r-l+1);
	int m=(l+r)>>1;
	if (L<=m) update(l,m,Lson,L,R,c);
	if (m<R) update(m+1,r,Rson,L,R,c);
	pushUp(o,r-l+1);
}
int query(int l,int r,int o,int L,int R) {
	if (L<=l&&r<=R) return sum[o];
	pushDown(o,r-l+1);
	int m=(l+r)>>1;
	int ret=0;
	if (L<=m) ret+=query(l,m,Lson,L,R);
	if (m<R) ret+=query(m+1,r,Rson,L,R);
	if (L<=m&&m<R) ret-=rs[Lson]==ls[Rson]; 
	return ret;
}
int queryc(int l,int r,int o,int x) {
	if (l==r) return ls[o];
	if (cover[o]!=-1) return cover[o];
	int m=(l+r)>>1;
	if (x<=m) return queryc(l,m,Lson,x);
	return queryc(m+1,r,Rson,x);
}
int n,m;
struct Tree{
	#define MAXM (100001*2)
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
	
	ll Ask(int a,int b)
	{
		ll ans=0;
		while (top[a]^top[b]) {
			ans+=query(1,n,1,id[top[a]],id[a]);
			ans-=queryc(1,n,1,id[top[a]])==queryc(1,n,1,id[pre[top[a]]]);
			a=pre[top[a]];
		}	
		ans+=query(1,n,1,id[b],id[a]);
		return ans;
	}
	void set(int a,int b,int c)
	{
		while (top[a]^top[b]) {
			update(1,n,1,id[top[a]],id[a],c);
			a=pre[top[a]];
		}
		update(1,n,1,id[b],id[a],c);;
	}

}S;
int a[MAXN];
int main()
{
//	freopen("bzoj2243.in","r",stdin);
//	freopen("bzoj2243.out","w",stdout);
	n=read(),m=read();
	build(1,n,1);
	S.mem();
	For(i,n) a[i]=read();
	For(i,n-1) S.addedge2(read(),read());
	S.build();
	For(i,n) S.set(i,i,a[i]);
	
	while(m--) {
		char op[2]; int a,b;
		scanf("%s%d%d",op,&a,&b);
		int t=S.lca(a,b);
		if (op[0]=='Q') {
			 printf("%lld\n",S.Ask(a,t)+S.Ask(b,t)-1);
		} else {
			int c;
			scanf("%d",&c);
			S.set(a,t,c);
			S.set(b,t,c);
		}
	}	
	return 0;
}

