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
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
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
typedef long long ll;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
int n,m;
struct Edge{
	int from,to;
	double dist;
};
#define MAXN (1000)
struct BellmanFord {
	int n,m;
	vector<Edge> edges;
	vi G[MAXN];
	bool inq[MAXN];
	double d[MAXN];
	int cnt[MAXN],p[MAXN];
	void addedge(int u,int v,int w){
		edges.pb((Edge){u,v,w});
		G[u].pb(m++);
	}
	void addedge2(int u,int v,int w) {
		addedge(u,v,w);addedge(v,u,w);
	}
	void init(int _n){
		n=_n; m = 0;
		Rep(i,n) G[i].clear();
		edges.clear(); 
	} 
	bool negativeCycle() {
		queue<int> Q;
		MEM(inq) MEM(cnt)
		Rep(i,n) d[i]=0,inq[i]=1,Q.push(i);
		while(!Q.empty()) {
			int u = Q.front(); Q.pop();
			inq[u] = 0;
			int mm=G[u].size();
			Rep(i,mm) {
				Edge e = edges[G[u][i]];
				if (d[e.to]>d[u]+e.dist ) {
					d[e.to]=d[u]+e.dist;
					p[e.to]=G[u][i];
					
					if (!inq[e.to]) {
						Q.push(e.to);
						inq[e.to]=1;
						if (++cnt[e.to]>n) return 1;
					}
				}
			} 
		} 
		return 0;
 	}
	
}S1;

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	return 0;
}

