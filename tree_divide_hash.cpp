#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
#include<iomanip> 
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<sstream>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=Next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=Next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case #%d: %I64d\n",kcase,ans);
#define PRi(a,n) For(i,n-1) cout<<a[i]<<' '; cout<<a[n]<<endl;
#define PRi2D(a,n,m) For(i,n) { \
						For(j,m-1) cout<<a[i][j]<<' ';\
						cout<<a[i][m]<<endl; \
						} 
#pragma comment(linker, "/STACK:102400000,102400000")
#define F (1000003)
#define MAXN (100000+10)
#define MAXM (200000+10)
long long mul(long long a,long long b){return (a*b)%F;}
long long add(long long a,long long b){return (a+b)%F;}
long long sub(long long a,long long b){return (a-b+(a-b)/F*F+F)%F;}
typedef long long ll;
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
int n;
int edge[MAXM],Next[MAXM]={0},pre[MAXN]={0},size=0;
void addedge(int u,int v)
{
	edge[++size]=v;
	Next[size]=pre[u];
	pre[u]=size;
}
void addedge2(int u,int v){addedge(u,v),addedge(v,u);}
int v[MAXN],K;
int opt[MAXN],siz[MAXN],val[MAXN]={0},all[MAXN],tot=0;
void dfs(int x,int fa)
{
	siz[x]=1;opt[x]=0;all[++tot]=x;
	Forp(x)
	{
		int &v=edge[p];
		if (v^fa&&!val[v])
		{
			dfs(v,x);siz[x]+=siz[v];
			opt[x]=max(opt[x],siz[v]);
		}
	}
}
int h[F]={0},b[F]={0};
int cas=0;
ll pow2(ll a,int b,ll p)  //a^b mod p 
{  
    if (b==0) return 1%p;  
    if (b==1) return a%p;  
    ll c=pow2(a,b/2,p)%p;  
    c=c*c%p;  
    if (b&1) c=c*a%p;  
    return c%p;  
}  
ll Inv(ll a,ll p) { //gcd(a,p)=1
	return pow2(a,p-2,p);
}
ll inv[F]; 
void prework() {
	Rep(i,F) inv[i]=Inv(i,F);
}
void dfs_calc(int x,int fa,ll t,int cas)
{
	t=mul(t,v[x]);
	if (b[t]!=cas||h[t]>x) h[t]=x,b[t]=cas;
	Forp(x)
	{
		int &v=edge[p];
		if (v^fa&&!val[v])
		{
			dfs_calc(v,x,t,cas);
			
		}
	}
}
pi ans;
void upd(pi &v,pi t) {
	if (t.se==t.fi) return;
	if (t.se<t.fi) swap(t.se,t.fi);
	v=min(v,t);
}
void dfs_calc2(int x,int fa,ll t,int cas)
{
	t=mul(t,inv[v[x]]);
	if (b[t]==cas) {
		upd(ans,mp(x,h[t]));
	}
	Forp(x)
	{
		int &v=edge[p];
		if (v^fa&&!val[v])
		{
			dfs_calc2(v,x,t,cas);
			
		}
	}
}
void solve(int root,int l)
{
	tot=0,dfs(root,0);
	int minopt=INF,minoptx=0;
	For(i,tot)
	{
		int u=all[i];
		opt[u]=max(opt[u],tot-siz[u]);
		if (minopt>opt[u]) minopt=opt[u],minoptx=u;
	}
	val[root=minoptx]=l;
	
	++cas;
//	b[v[root]]=cas; h[v[root]]=root;
	Forp(root) {
		int &V=edge[p];
		if (!val[V]) {
			dfs_calc2(V,root,K,cas); 
			dfs_calc(V,root,v[root],cas);
		}
	}	
	if (b[K]==cas) upd(ans,mp(root,h[K]));
	
	Forp(root)
	{
		int &v=edge[p];
		if (!val[v]) solve(v,l+1);
	}
}
int main()
{
//	freopen("D.in","r",stdin);
	prework();
	while(cin>>n>>K) {
		MEM(edge) MEM(Next) MEM(pre) size=0;
		MEM(opt) MEM(siz) MEM(val) 
		For(i,n) v[i]=read();
		For(i,n-1)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			addedge2(u,v);
		}
		ans=mp(INF,INF); 
		solve(1,1);
		if (ans==mp(INF,INF)) puts("No solution");
		else {
			printf("%d %d\n",ans.fi,ans.se);
		}

	}
	return 0;
}
