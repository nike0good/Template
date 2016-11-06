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
#include<complex>
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
typedef complex<double> atom;
#define pi ((double)3.1415926535897932384626)
#define MAXN (50000+10)
/* n bigger is ok 
*/   
void fft(atom *x,int n,int fl=1){
    for (int i=(n>>1),j=1;j<n;j++){
        if (i<j) swap(x[i],x[j]);
        int k;
        for (k=(n>>1);i&k;i^=k,k>>=1); i^=k;
    }
    for (int m=2;m<=n;m=(m<<1)){
        atom w=(atom){cos(pi*2*fl/m),sin(pi*2*fl/m)};
        for (int i=0;i<n;i+=m){
            atom cur=(atom){1,0};
            for (int j=i;j<i+(m>>1);j++){
                atom u=x[j],v=x[j+(m>>1)]*cur;
                x[j]=u+v; x[j+(m>>1)]=u-v; cur=cur*w;
            }
        }
    }
    if (fl==-1) {
    	Rep(i,n) x[i]/=n;
    }
}

ll pow2(ll a,ll b,ll p)  //a^b mod p 
{  
    if (b==0) return 1%p;  
    if (b==1) return a%p;  
    ll c=pow2(a,b/2,p)%p;  
    c=c*c%p;  
    if (b&1) c=c*a%p;  
    return c%p;  
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
ll P[3]={998244353ll,1005060097ll,950009857ll},
G[3]={3,5,7},
Inv[3]={644348675ll,675933219ll,647895261ll};
//
//void ntt(ll *x,int n,int fl,ll mo,ll G){
//    for (int i=(n>>1),j=1;j<n;j++){
//        if (i<j) swap(x[i],x[j]);
//        int k;
//        for (k=(n>>1);k&i;i^=k,k>>=1); i^=k;
//    }
//    for (int m=2;m<=n;m<<=1){
//        ll w=pow2(G,(mo-1)/m,mo); 
//        for (int i=0;i<n;i+=m){
//            ll cur=1;
//            for (int j=i;j<i+(m>>1);j++){
//                int u=x[j],v=1ll*x[j+(m>>1)]*cur%mo;
//                x[j]=(u+v)%mo; x[j+(m>>1)]=(u-v+mo)%mo;
//                cur=1ll*cur*w%mo;
//            }
//        }
//    }
//    if (fl==-1) {
//        for(int i=1;i<(n>>1);++i)swap(x[i],x[n-i]);
//        ll _inv=pow2(n,mo-2,mo);
//    	Rep(i,n) x[i]=x[i]*_inv%mo;
//    }
//}


void ntt(ll*a,int n,int f,ll P,ll G)
{
    for(int i=1,j=0;i<n-1;++i)
    {
        for(int d=n;j^=d>>=1,~j&d;);
        if(i<j)swap(a[i],a[j]);
    }
    for(int i=1;i<n;i<<=1)
    {
        ll wn=pow2(G,(P-1)/(i<<1),P);
        for(int j=0;j<n;j+=i<<1)
        {
            ll w=1;
            for(int k=0;k<i;++k,w=w*wn%P)
            {
                ll x=a[j+k],y=w*a[j+k+i]%P;
                a[j+k]=(x+y)%P;
                a[j+k+i]=(x-y+P)%P;
            }
        }
    }
    if(f==-1)
    {
        for(int i=1;i<(n>>1);++i)swap(a[i],a[n-i]);
        ll inv=pow2(n,P-2,P);
        for(int i=0;i<n;++i)a[i]=a[i]*inv%P;
    }
}
#define M (50000+10)
void Polynomial_Multiplication(ll a[],ll b[],ll c[],int n,ll MOD)
{
    static ll A[3][M],B[3][M];
    for(int j=0;j<3;++j)
    {
        for(int i=0;i<n;++i)
        {
            A[j][i]=a[i]%P[j];
            B[j][i]=b[i]%P[j];
        }
        ntt(A[j],n,1,P[j],G[j]);
        ntt(B[j],n,1,P[j],G[j]);
        for(int i=0;i<n;i++) A[j][i]=A[j][i]*B[j][i]%P[j];
        ntt(A[j],n,-1,P[j],G[j]);
    }
    Int_128 _MOD=Int_128(P[0]*P[1])*P[2];
    for(int i=0;i<n;++i)
    {
        Int_128 temp=
        Int_128(P[1]*P[2])*Int_128(Inv[0]*A[0][i])+
        Int_128(P[0]*P[2])*Int_128(Inv[1]*A[1][i])+
        Int_128(P[0]*P[1])*Int_128(Inv[2]*A[2][i]);
        c[i]=(temp%_MOD%MOD).b;
    }
}
ll inv(ll a,ll p) { //gcd(a,p)=1
	return pow2(a,p-2,p);
}

int n,a[10];
ll jie[20000];
ll inv2[20000];
ll A[30000],B[30000],C[30000],D[30000];
int main()
{
//	freopen("k.in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	jie[0]=inv2[0]=1;
	For(i,15001)
		jie[i]=mul(jie[i-1],i);
	For(i,15001) 
		inv2[i]=inv(jie[i],F);
	For(kcase,T) {
		int n=read();
		MEM(A)	A[0]=1;
		int m=1;
		for(m=1;m<n+1;m<<=1);m<<=1;
		Rep(i,5) {
			a[i]=min(read(),n);
			if (!i) continue;
			MEM(B)
			Rep(j,a[i]+1) B[j]=inv2[j];
			Polynomial_Multiplication(A,B,C,m,F);
			Rep(j,m) if (j<=n) A[j]=C[j]; else A[j]=0;
		}
		
		MEM(B)
		Rep(j,a[0]+1) B[j]=inv2[j];
		Polynomial_Multiplication(A,B,C,m,F);
		ll ans=mul(C[n],jie[n]);
		
		B[a[0]]=0;
		Polynomial_Multiplication(A,B,C,m,F);
		ll ans2=mul(jie[n-1],C[n-1]);
		cout<<"Case #"<<kcase<<": "<<sub(ans,ans2)<<endl;		
		
	}
	
	
	return 0;
}

