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
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<sstream>
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
#define F (1000000007 )
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case #%d: %I64d\n",kcase,ans);
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
void upd(ll &a,ll b){a=(a%F+b%F+2*F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
#define MAXN (100000+10) 
ll tar[MAXN];
void prework() {
	MEM(tar) 
	tar[0] = 1;
	For(i,1e5) {
		tar[i]=0;
		for(int k=1;;k++) {
			int b=(k&1)?1:-1 ;
			int j1=i - k*(3*k-1)/2;
			int j2=i - k*(3*k+1)/2;
			if (j1<0) break;
			if (j1>=0) upd(tar[i],b*tar[j1]);
			if (j2>=0) upd(tar[i],b*tar[j2]);
		} 
	} 
}
int main()
{
//	freopen("C.in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	prework();
	while(T--) {
		int n=read(),K=read();
		ll ans=tar[n];
		for(int k=1;;k++) {
			int b=-((k&1)?1:-1) ;
			int j1=n - (3*k*k+k)/2*K;
			int j2=n - (3*k*k-k)/2*K;
			if (j1<0&&j2<0) break;
			if (j1>=0) upd(ans,b*tar[j1]);
			if (j2>=0) upd(ans,b*tar[j2]);
		} 
		printf("%I64d\n",ans);
	}
	
	
	return 0;
}

