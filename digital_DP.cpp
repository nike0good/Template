#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<complex>
#include<stack>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
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
#define gmax(a,b) a=max(a,b);
#define gmin(a,b) a=min(a,b);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
int T;
#define MAXN (111)
char a[MAXN];
ll f[MAXN][10][2][2][2];
//first i,jth num,k is_0qiandao,x 0down 1 up ,y is==n 
int main()
{
//	freopen("E.in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while(T--) {
		scanf("%s",a+1);
		ll ans=0;
		int n=strlen(a+1);
		For(i,n) a[i]-='0';
		MEM(f)
		f[0][0][0][0][1]=1;
		Rep(i,n) {
			Rep(j,10) Rep(k,2) Rep(x,2) Rep(y,2) {
				if (f[i][j][k][x][y]) {
					Rep(t,10) {
						int nk=k|(t>0);
						int nx=x,ny=(y&&t==a[i+1]);
						if (y&&t>a[i+1]) continue;
						if (k) {
							if (!x&& t>j) nx=1;
							else if(x && t<j) continue;
						}
						
						if (k && x && t<j ) continue;
						if (!k) nx=0;
						if (k && t>j && nx==0) nx=1;
						upd(f[i+1][t][nk][nx][ny],f[i][j][k][x][y]);
					}
				}
			}
		}
		int k=1;
		Rep(j,10) Rep(x,2) Rep(y,2) {
			upd(ans,f[n][j][k][x][y]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}

