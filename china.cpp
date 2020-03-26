#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define PRi(a,n) Rep(i,n-1) cout<<a[i]<<' '; cout<<a[n-1]<<endl;
#define PRi2D(a,n,m) For(i,n) { \
						For(j,m-1) cout<<a[i][j]<<' ';\
						cout<<a[i][m]<<endl; \
						} 
typedef long long ll;
ll F;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
void gcd(ll a,ll b,ll &d,ll &x,ll &y) {
	if (!b) {d=a,x=1,y=0;	}
	else {gcd(b,a%b,d,y,x); y-=x*(a/b);	}
}
// x mod m0=a0,x mod m =a,noSolution return 0 
//³õÊ¼¿ÉÁî m0 = 1 ,a0 = 0 
bool china(ll &m0,ll &a0,ll m,ll a)  
{
	ll g,x,y;
	ll c=abs(a-a0);
	gcd(m0,m,g,x,y);
	if ( c % g ) return 0;
	x*=(a-a0)/g; 
	x%=m/g;
	a0=x*m0+a0;
	m0*=m/g;
	a0%=m0;
	if(a0<0) a0+=m0;
	return 1;
}
int q1[MAXN],m1[MAXN];

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);

	ll m0=1,a0=0;
	bool flag=1;
	Rep(i,n) {
		flag=china(m0,a0,m1[i],q1[i]);
		if (!flag) break;
	}
	if (flag) printf("%I64d\n",(!a0)?m0:a0);
	else puts("Creation August is a SB!");
	
	
	
	return 0;
}

