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
#define F (1000000007)
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
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 

struct Int_128{
    ull a,b;
    Int_128(ll x){a=0,b=x;}
    friend bool operator < (Int_128 x,Int_128 y)
    {
        return x.a<y.a||x.a==y.a&&x.b<y.b;
    }
    friend Int_128 operator + (Int_128 x,Int_128 y)
    {
        Int_128 re(0);
        re.a=x.a+y.a+(x.b+y.b<x.b);
        re.b=x.b+y.b;
        return re;
    }
    friend Int_128 operator - (Int_128 x,Int_128 y)
    {
        y.a=~y.a;y.b=~y.b;
        return x+y+1;
    }
    void Div2()
    {
        b>>=1;b|=(a&1ll)<<63;a>>=1;
    }
    friend Int_128 operator * (Int_128 x,Int_128 y)
    {
        Int_128 re=0;
        while(y.a||y.b)
        {
            if(y.b&1)re=re+x;
            x=x+x;y.Div2();
        }
        return re;
    }
    friend Int_128 operator % (Int_128 x,Int_128 y)
    {
        Int_128 temp=y;
        int cnt=0;
        while(temp<x)temp=temp+temp,++cnt;
        for(;cnt>=0;cnt--)
        {
            if(temp<x)x=x-temp;
            temp.Div2();
        }
        return x;
    }
};

int main()
{
	freopen("A.in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while(T--) {
		
	}
	
	
	return 0;
}

