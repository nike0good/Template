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
ll Abs(ll x){return (x<0)?-x:x;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
#define MAXN (100000+10)
struct TwoSat{
	int n;
	vi G[MAXN*2]; 
	bool mark[MAXN*2];
	int S[MAXN*2],c;
	bool dfs(int x) {
		if (mark[x^1]) return 0;
		if (mark[x]) return 1;
		mark[x]=1;
		S[c++]=x;
		int sz=SI(G[x]);
		Rep(i,sz) if (!dfs(G[x][i])) return 0;
		return 1;
	}
	void init(int n) {
		this -> n = n;
		Rep(i,n*2) G[i].clear();
		MEM(mark)
	}
	//x = xval or y = yval
	void add_clause(int x,int xval,int y,int yval) {
		x=x*2+xval;
		y=y*2+yval;
		G[x^1].pb(y);
		G[y^1].pb(x);
	}
	bool solve() {
		for(int i=0;i<n*2;i+=2) {
			if (!mark[i] && !mark[i+1]) {
				c=0;
				if (!dfs(i)) {
					while (c) mark[S[--c]] = 0;
					if (!dfs(i+1)) return 0;
				}
			}
		}
		return 1;
	}
}solver;
int n,m;
int main()
{
	freopen("uva1391.in","r",stdin);
//	freopen(".out","w",stdout);
	while(cin>>n>>m&&n&&m) {
	}	
	return 0;
}

