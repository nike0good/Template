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
#define MAXN (22000) 
class bingchaji
{
public:
	int father[MAXN],n,cnt;
	void mem(int _n)
	{
		n=cnt=_n;
		For(i,n) father[i]=i;
	}
	int getfather(int x) 
	{
		if (father[x]==x) return x;
		
		return father[x]=getfather(father[x]);
	}
	int unite(int x,int y)
	{
		x=getfather(x);
		y=getfather(y);
		if (x^y) {
			--cnt;
			father[x]=y;
			return 1;
		}
		return 0;
	}
	bool same(int x,int y)
	{
		return getfather(x)==getfather(y);
	}
}S;
struct edge{
	int u,v,w;
	edge(){}
	edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
};
bool operator<(edge a,edge b) {
	return a.w<b.w;
}
edge road1[MAXN],road2[MAXN];
int n,m,k;
bool check(int mid) {
	S.mem(n);
	For(i,m) {
		if (road1[i].w>mid) break;
		S.unite(road1[i].u,road1[i].v);
	}
	int tot=n-1-k; 
	For(i,m) {
		if (road2[i].w>mid||!tot) break;
		tot-=S.unite(road2[i].u,road2[i].v);
	}
	return S.cnt==1;
}
int main()
{
//	freopen("bzoj1196.in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>k>>m; --m;
	For(i,m) {
		int a=read(),b=read(),c1=read(),c2=read();
		road1[i]=edge(a,b,c1);
		road2[i]=edge(a,b,c2);
	}
	sort(road1+1,road1+1+m);
	sort(road2+1,road2+1+m);
	int l=0,r=30000,ans=r;
	check(1);
	while(l<=r) {
		int m=l+r>>1;
		if (check(m)) r=m-1,ans=m;else l=m+1;
	}
	cout<<ans;
	 
	return 0;
}

