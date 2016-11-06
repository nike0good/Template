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
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case %d: %lld\n",kcase,ans);
#define PRi(a,n) For(i,n-1) cout<<a[i]<<' '; cout<<a[i]<<endl;
#define PRi2D(a,n,m) For(i,n) { \
						For(j,m-1) cout<<a[i][j]<<' ';\
						cout<<a[i][m]<<endl; \
						} 
typedef long long ll;
typedef unsigned long long ull;
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 

namespace Simpson{
	double a;
	double f(double x) {
		return sqrt(1+4*a*a*x*x);
	}
	double simpson(double a,double b) {
		double c=(a+b)/2;
		return (f(a)+f(b)+4*f(c)) * (b-a) / 6;
	}
	double asr(double a,double b,double eps,double A) {
		double c=(a+b)/2;
		double l=simpson(a,c),r=simpson(c,b);
		
		if (fabs(l+r-A)<=15*eps) return l+r+(l+r-A)/15.;
		return asr(a,c,eps/2,l)+asr(c,b,eps/2,r);
	}
	double asr(double a,double b,double eps) {
		return asr(a,b,eps,simpson(a,b));
	}
}

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	return 0;
}

