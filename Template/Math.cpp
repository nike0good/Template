#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<vector>
#include<ctime>
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
#define MAXN (1000000)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
char s[]="no solution\n";

class Math
{
public: 
	ll gcd(ll a,ll b){if (!b) return a;return gcd(b,a%b);}  
	void gcd(ll a,ll b,ll &d,ll &x,ll &y) {
		if (!b) {d=a,x=1,y=0;	}
		else {gcd(b,a%b,d,y,x); y-=x*(a/b);	}
	}
	// n个方程 x=a[i](mod m[i]) (0<=i<n) 
	ll china(int n,int *a,int *m) {
		ll M=1,d,y,x=0;
		Rep(i,n) M*=a[i];
		Rep(i,n) {
			ll w=M/m[i];
			gcd(m[i],w,d,d,y);
			x=(x+y*w*a[i])%M; 
		}
		return (x+M)%M;
	}
	ll abs(ll x){if (x>=0) return x;return -x;} 
	ll exgcd(ll a,ll b,ll &x, ll &y)  
	{  
	    if (!b) {x=1,y=0;return a;}  
	    ll g=exgcd(b,a%b,x,y);  
	    ll t=x;x=y;y=t-a/b*y;  
	    return g;     
	}  
	ll pow2(ll a,int b,ll p)  //a^b mod p 
	{  
	    if (b==0) return 1%p;  
	    if (b==1) return a%p;  
	    ll c=pow2(a,b/2,p)%p;  
	    c=c*c%p;  
	    if (b&1) c=c*a%p;  
	    return c%p;  
	}  
	ll inv(ll a,ll p) { //gcd(a,p)=1
		return pow2(a,p-2,p);
	}
	ll factnmodp(ll n,ll p) {
		ll t=n;
		while(n) {
			t=(t-n%p+F)%F;
			n/=p;
		}
		return t*inv(p-1,p);
	}
	ll get_factor(vector<ll> &v,ll p) {
		for(ll i=2;i*i<=p;i++) if (p%i==0) {
			v.pb(i);
			if (i*i<p) v.pb(p/i);
		}
		sort(v.begin(),v.end());
	}
	template <class T>
	ll find(vector<T> v,T x) {
		return lower_bound(v.begin(),v.end(),x)-v.begin();
	}
	// p is prime
	// certainly their are phi(p) root
	ll get_primitiveRoot(ll p) { 
		p;
		vector<ll> v;
		get_factor(v,p-1);
		for(ll i=2;;i++) {
			bool fl=0;
			Rep(j,SI(v)) {
				if (pow2(i,v[j],p)==1) {
					fl=1; break;
				}
			}
			if (!fl) return i;
		}
	}
	
	ll Modp(ll a,ll b,ll p)  //a*x=b (mod p)
	{  
	    ll x,y;  
	    ll g=exgcd(a,p,x,y),d;  
	    if (b%g) {return -1;}  
	    d=b/g;x*=d,y*=d;  
	    x=(x+abs(x)/p*p+p)%p;  
	    return x;  
	}  
	int h[MAXN];  
	ll hnum[MAXN];  
	int hash(ll x)  
	{  
	    int i=x%MAXN;  
	    while (h[i]&&hnum[i]!=x) i=(i+1)%MAXN;  
	    hnum[i]=x;
	    return i;
	}
	ll babystep(ll a,ll b,int p)  // a^x = b (mod p)
	{  
		MEM(h) MEM(hnum)
		int m=sqrt(p);while (m*m<p) m++;  
	    ll res=b,ans=-1;  
	      
	    ll uni=pow2(a,m,p);  
	    if (!uni) if (!b) ans=1;else ans=-1; //特判  
	    else  
	    {  
	          
	        Rep(i,m+1)  
	        {  
	            int t=hash(res);  
	            h[t]=i+1;  
	            res=(res*a)%p;  
	        }  
	        res=uni;  
	        
			For(i,m+1)  
			{  
	            int t=hash(res);  
	            if (h[t]) {ans=i*m-(h[t]-1);break;}else hnum[t]=0;  
	            res=res*uni%p;  
	        }  
	        
		}  
		return ans; 
	}  
	
	
}S;

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	

	
	return 0;
}

