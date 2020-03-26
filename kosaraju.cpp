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
#define MAXN (20000+10)
vi G[MAXN],G2[MAXN];
vi S;
int vis[MAXN],sccno[MAXN],scc_cnt;
void dfs1(int u) {
	if (vis[u]) return ;
	vis[u] = 1;
	int sz=SI(G[u]);
	Rep(i,sz) dfs1(G[u][i]);
	S.pb(u);
}
void dfs2(int u) {
	if (sccno[u]) return;
	sccno[u] = scc_cnt;
	int sz=SI(G2[u]);
	Rep(i,sz) dfs2(G2[u][i]);
}
void find_scc(int n) {
	scc_cnt=0;
	S.clear();
	MEM(sccno) MEM(vis) 
	Rep(i,n) dfs1(i);
	RepD(i,n-1)
		if (!sccno[S[i]]) {
			scc_cnt++; dfs2(S[i]);
		}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	int T=read();
	while(T--) {
		int n=read(),m=read();
		Rep(i,m) {
			int u=read()-1,v=read()-1;
			G[u].pb(v);G2[v].pb(u);
		}
		find_scc(n);
	}
	
	return 0;
}

