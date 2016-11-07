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
int n,k;

#define MAXN (10000)
struct BigInteger {
	int n;
	int a[MAXN];
	enum {MOD=10000};
	BigInteger() {
		MEM(a) a[0]=1;
	}
    int& operator [] (int p) {return a[p];} 
    const int& operator [] (int p) const {return a[p];}  
	BigInteger(int x) {
		a[0]=1;
		a[1]=x%MOD; 
		x/=MOD;
		while(x) a[++a[0]]=x%MOD,x/=MOD;
	}
	friend BigInteger operator*(BigInteger a,BigInteger b) {
		BigInteger c;
		c[0]=a[0]+b[0];
		For(i,a[0])
            For(j,b[0]){  
                c[i+j-1]+=a[i]*b[j], c[i+j]+=c[i+j-1]/MOD, c[i+j-1]%=MOD;  
            }  
        if (c[c[0]] == 0) c[0]--;  
        return c;
	}
	void print() {
	    ForD(i,a[0]) {
	    	if(i==a[0]) printf("%d",a[i]);
	    	else printf("%04d",a[i]);
	    }
	}
};
int gcd(int a,int b){if (!b) return a;return gcd(b,a%b);}
void calc() {
	if(n>k) {
		puts("0 1");
		return ;
	}
	BigInteger a,b;
	a=1; b=1;
	For(i,n-1) a=a*(k+1);
	int p=k-n+1,w=1;
	For(i,n) {
		int g=gcd(p,k);
		p/=g;
		b=b*(k/g);
	}
	a=a*p;
	a.print();
	putchar(' ');
	b.print();
	puts("");
}
int main()
{
//	freopen("bzoj3680.in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while(T--) {
		n=read(),k=read();
		calc();
	} 
	return 0;
}

