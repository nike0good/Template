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
#define MAXN (1000+10)
#define MAXM (1000000+10)
struct Edge{
	int u,v;
	Edge(int _u=0,int _v=0):u(_u),v(_v){}
};
int pre[MAXN],post[MAXN],iscut[MAXN],bccno[MAXN],dfs_clock,bcc_cnt;
vi G[MAXN],bcc[MAXN]; 
int low[MAXN];
stack<Edge> S;
void PREVISIT(int u){ pre[u]=++dfs_clock;}
void POSTVISIT(int u){ post[u]=++dfs_clock;}
int dfs(int u,int fa) {
	int lowu=pre[u] = ++dfs_clock;
	int child = 0;
	int sz = G[u].size();
	Rep(i,sz) {
		int v=G[u][i];
		Edge e = Edge(u,v);
		if (!pre[v]) {
			S.push(e);
			child++;
			int lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if (lowv>=pre[u]) {
				iscut[u]=1;
				bcc_cnt++; bcc[bcc_cnt].clear();
				while(1) {
					Edge x = S.top(); S.pop();
					if (bccno[x.u]!=bcc_cnt) {bcc[bcc_cnt].pb(x.u); bccno[x.u]=bcc_cnt; }
					if (bccno[x.v]!=bcc_cnt) {bcc[bcc_cnt].pb(x.v); bccno[x.v]=bcc_cnt; }
					if (x.u==u && x.v==v) break;
				}
			}
		}
		else if (pre[v]<pre[u]&&v!=fa) {
			S.push(e);
			lowu = min(lowu , pre[v]);
		}
	}
	if (fa<0 && child == 1 ) iscut[u] = 0;
	low[u] = lowu;
	return lowu;
}
void find_bcc(int n) {
	MEM(pre) MEM(iscut) MEM(bccno)
	dfs_clock = bcc_cnt = 0;
	Rep(i,n) if (!pre[i]) dfs(i,-1); 
}
int color[MAXN];
bool bipartite(int u,int b) {
	int sz=G[u].size();
	Rep(i,sz) {
		int v=G[u][i];
		if (bccno[v]!=b) continue;
		if (color[v]==color[u]) return 0;
		if (!color[v]) {
			color[v]=3-color[u];
			if (!bipartite(v,b)) return 0;
		}
	}
	return 1;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m;
	while(cin>>n>>m&&n) {
		Rep(i,m) {
			int u=read(),v=read();
			u--,v--;
			G[u].pb(v);
			G[v].pb(u);
		}
		find_bcc(n);
		
		Rep(i,n) G[i].clear();
	}
	
	return 0;
}

