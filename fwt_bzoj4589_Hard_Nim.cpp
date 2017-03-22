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
ll F=1000000007LL;
ll iv2=F+1>>1; //这个计算思路好评 
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return ((a-b)%F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
void fwt(int*a,int n){
	int i,j,k,x;
	for(k=2;k<=n;k<<=1){
		for(i=0;i<n;i+=k){
			for(j=i;j<i+(k>>1);j++){
				x=a[j]+a[j+(k>>1)];if(x>=F) x-=F;
				a[j]=a[j]-a[j+(k>>1)];if(a[j]<0) a[j]+=F;
				a[j+(k>>1)]=x;
			}
		}
	}
}
void twf(int*a,int n){
	int i,j,k,x;
	for(k=n;k>=2;k>>=1){
		for(i=0;i<n;i+=k){
			for(j=i;j<i+(k>>1);j++){
				x=a[j]+a[j+(k>>1)];
				a[j+(k>>1)]=(int)(1LL*(a[j+(k>>1)]-a[j]+F)*iv2%F);
				a[j]=(int)(1LL*x*iv2%F);
			}
		}
	}
}
ll pow2(ll a,ll b){
	if (!b) return 1%F;
	ll p=pow2(a,b/2);
	p=mul(p,p);
	if (b&1) p=mul(p,a);
	return p;
}
#define MAXN (50000<<3)
int b[MAXN],a[MAXN];
ll n,m;
int main()
{
//	freopen("bzoj4589.in","r",stdin);
//	freopen(".out","w",stdout);
	n=50000;
	MEM(b) b[1]=b[0]=1;
	Fork(i,2,n) if (!b[i]) {
		for(int j=2;i*j<=n;j++)
			b[i*j]=1;
	}	
	while(cin>>n>>m) {
		int len=1;
		while(len<=m) len<<=1;
		Rep(i,len) a[i]=(!b[i])&&(i<=m);
		fwt(a,len);
		Rep(i,len) a[i]=pow2(a[i],n);
		twf(a,len);
		printf("%d\n",a[0]);
	}
	return 0;
}

