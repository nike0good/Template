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
#define F (100000007)
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case %d: %lld\n",kcase,ans);
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
#define MAXN (200010+10) 
vi G[MAXN];
int pre[MAXN],lowlink[MAXN],sccno[MAXN],dfs_clock,scc_cnt;
stack<int> S; 
void dfs(int u) {
	pre[u] = lowlink[u] = ++dfs_clock;
	S.push(u);
	int sz=SI(G[u]);
	Rep(i,sz) {
		int v=G[u][i];
		if (!pre[v]) {
			dfs(v);
			lowlink[u]=min(lowlink[u],lowlink[v]);
		} else if (!sccno[v]) {
			lowlink[u]=min(lowlink[u],pre[v]);
		} 
	} 
	if (lowlink[u]==pre[u]) {
		scc_cnt++;	
		while(1) {
			int x=S.top();S.pop();
			sccno[x]=scc_cnt;
			if (x==u) break;  
		} 
	}		
} 
void find_scc(int n) {
	dfs_clock = scc_cnt = 0;
	MEM(sccno) 
	MEM(pre)
	Rep(i,n) if (!pre[i]) dfs(i);
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	For(kcase,T) {
		int n=read(),m=read();
		Rep(i,m) {
			int u=read()-1,v=read()-1;
			G[u].pb(v);
		}
		find_scc(n);
		Rep(i,n) G[i].clear();
	}
	return 0;
}

