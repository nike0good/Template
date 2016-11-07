#include<bits/stdc++.h> 
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
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
#define ALL(x) (x).begin(),(x).end()
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
#define MAXN (1100)
int n,m,K;
vi edges[MAXN],weight[MAXN];
int bo[MAXN]={},dp[MAXN][1<<10],w[MAXN]={},f[MAXN];
queue<int> q;
int pd[MAXN]={};
void spfa(int now) {
	For(i,n) q.push(i),pd[i]=1;
	while(!q.empty()) {
		int x=q.front(); q.pop();
		Rep(i,SI(edges[x])) {
			int v=edges[x][i];
			if (dp[x][now]+weight[x][i]<dp[v][now]) {
				dp[v][now]=dp[x][now]+weight[x][i];
				if (!pd[v]) pd[v]=1,q.push(v);
			}
		}
		pd[x]=0;
	}
}
int main()
{
//	freopen("bzoj4006.in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>m>>K;
	For(i,m) {
		int u=read(),v=read(),w=read();
		edges[u].pb(v);	edges[v].pb(u);
		weight[u].pb(w); weight[v].pb(w);
	}
	For(i,K) {
		int c=read(),id=read();
		bo[id]=i; w[c]+=(1<<i-1);
	}
	int S=1<<K;
	MEMI(dp)
	For(now,S-1) {
		For(i,n) {
			if (bo[i] && (1<<bo[i]-1) == now ) dp[i][now]=0;
			for(int j=(now-1)&now;j;j=(j-1)&now) dp[i][now]=min(dp[i][now],dp[i][j]+dp[i][now-j]);
		}
		spfa(now);
	}
	MEMI(f)
	For(i,S-1) {
		int k=0;
		For(j,K) if ((i>>j-1)&1) k|=w[j];
		For(j,n) f[i]=min(f[i],dp[j][k]);
		for(int j=(i-1)&i;j;j=(j-1)&i) f[i]=min(f[i],f[j]+f[i-j]);
	}
	cout<<f[S-1];
	return 0;
}

