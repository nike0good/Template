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
#define MAXN (10010)
int n;
double x[MAXN],y[MAXN],g[MAXN];
double sqr(double x){return x*x;}
double dis(double a,double b,int i) {
	return sqrt(sqr(a-x[i])+sqr(b-y[i]));
}
void hillclimbing() {
	double t=1000,X,Y,ansx=0,ansy=0;
	For(i,n) {
		ansx+=x[i]*g[i]; ansy+=y[i]*g[i];
	}
	ansx/=n,ansy/=n;
	while(t>1e-8) {
		X=Y=0;
		For(i,n) {
			X+=(x[i]-ansx)*g[i]/dis(ansx,ansy,i);
			Y+=(y[i]-ansy)*g[i]/dis(ansx,ansy,i);
		}
		ansx+=X*t;
		ansy+=Y*t;
		if (t>0.5) t*=0.5;
		else t*=0.97;
	}
	printf("%.3lf %.3lf\n",ansx,ansy);
}
int main()
{
//	freopen("bzoj3680.in","r",stdin);
//	freopen(".out","w",stdout);
	
	n=read();
	For(i,n) {
		scanf("%lf%lf%lf",&x[i],&y[i],&g[i]);
	}
	hillclimbing();
	
	return 0;
}

