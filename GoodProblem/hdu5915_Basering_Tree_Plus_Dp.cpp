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
#include<bitset>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<sstream>
#include<complex>
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
#define vpi vector<pi >
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
#define MAXN (101000)
int n,p[MAXN];
vi edges[MAXN];
bitset<MAXN> used,inCircle;
int circleLen,circleHead,circletail;
void init_dfs(int x,int fa) {
	p[x]=fa;
	used[x]=1;
	for(auto v:edges[x]) if (v!=fa) {
		if (used[v]) {
			circleHead=x;
			circletail=v;
			continue;
		}
		init_dfs(v,x);
	}
}
int d[MAXN],maxDepth[MAXN],maxDepthP[MAXN];
pi d_p[MAXN];
void dfs(int x,int fa) {
	d[x] = maxDepth[x] = 0;
	d_p[x]=mp(x,x); maxDepthP[x]=x;
	pi tmp_p;
	for(auto v:edges[x]) {
		if (v==fa||inCircle[v]) continue;
		dfs(v,x);
		if (d[x] < d[v]) {
			d[x]=d[v];
			d_p[x]=d_p[v];
		} else if (d[x] == d[v] && d_p[x] > d_p[v] ) {
			d_p[x]=d_p[v];
		}
		tmp_p.fi=min(maxDepthP[x],maxDepthP[v]);
		tmp_p.se=max(maxDepthP[x],maxDepthP[v]);
		if (d[x]<maxDepth[x]+maxDepth[v]+1) {
			d[x]=maxDepth[x]+maxDepth[v]+1;
			d_p[x]=tmp_p;
		} else if (d[x]==maxDepth[x]+maxDepth[v]+1 && d_p[x] > tmp_p) {
			d_p[x]=tmp_p;
		}
		if (maxDepth[x]<maxDepth[v]+1 || (maxDepth[x] == maxDepth[v]+1 && maxDepthP[x]>maxDepthP[v] )) {
			maxDepth[x]=maxDepth[v]+1;
			maxDepthP[x] = maxDepthP[v];
		}
	}
}
void MAIN() {
	n=read();
	Rep(i,n) edges[i].clear();
	Rep(i,n) {
		int u=read(),v=read();
		u--,v--;
		edges[u].pb(v);
		edges[v].pb(u);
	}
	used.reset(); inCircle.reset();
	init_dfs(0,0);
	vi circle;
	for(int i=circletail ;;i=p[i]) {
		inCircle[i]=1;
		circle.pb(i);
		if (i==circleHead) break;
	}
	int ans=n*2;
	pi ans_p=mp(0,0);
	circleLen=SI(circle);
	for(auto x:circle) {
		dfs(x,x);
		if (ans>2*n-circleLen-d[x] || ans==2*n-circleLen-d[x] && ans_p>d_p[x]) {
			ans=2*n-circleLen-d[x];
			ans_p=d_p[x];
		}
	}
	int nowMax=maxDepth[circle[0]], nowChosen = maxDepthP[circle[0]];
	For(i,circleLen-1) {
		int now=circle[i],len=2*n-2-nowMax-maxDepth[now]-i;
		pi tmp_p=mp(min(nowChosen,maxDepthP[now]),max(nowChosen,maxDepthP[now]));
		if (ans>len || ( ans==len && ans_p>tmp_p )) {
			ans=len;
			ans_p=tmp_p;
		}
		if (nowMax<maxDepth[now]-i || (nowMax==maxDepth[now]-i && nowChosen > maxDepthP[now])) {
			nowMax=maxDepth[now]-i;
			nowChosen = maxDepthP[now];
		}
	}
	
	nowMax=maxDepth[circle[0]], nowChosen = maxDepthP[circle[0]];
	For(i,circleLen-1) {
		int now=circle[i],len=2*n-2-nowMax-maxDepth[now]-circleLen+i;
		pi tmp_p=mp(min(nowChosen,maxDepthP[now]),max(nowChosen,maxDepthP[now]));
		if (ans>len || ( ans==len && ans_p>tmp_p )) {
			ans=len;
			ans_p=tmp_p;
		}
		if (nowMax<maxDepth[now]+i || (nowMax==maxDepth[now]-i && nowChosen > maxDepthP[now])) {
			nowMax=maxDepth[now]+i;
			nowChosen = maxDepthP[now];
		}
	}
	
	printf("%d %d %d",ans,ans_p.fi+1,ans_p.se+1);
}
int main()
{
//	freopen("hdu5915.in","r",stdin);
//	freopen(".out","w",stdout);
	
	int T=read();
	For(kcase,T) {
		printf("Case #%d: ",kcase);
		MAIN();
		puts("");
	}
	
	return 0;
}

