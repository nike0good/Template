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
#define F (100000007)
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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
ll gcd(ll a,ll b){if (!b) return a; return gcd(b,a%b);}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
ll sqr(ll a){return a*a;}
ld sqr(ld a){return a*a;}
double sqr(double a){return a*a;}

struct Rat{
	ll s,m;
	int t;
	Rat(ll _s=0,ll _m=1,int _t=1) {
		s=_s,m=_m; t=_t;
		ll d=gcd(s,m);
		s/=d,m/=d;
	} 
	Rat operator+ (const Rat &u) {
		ll d = gcd(m,u.m);
		if (t*u.t==1)
			return Rat(u.m/d*s+ m/d*u.s, m/d*u.m,t);
		else {
			if (t==-1) {
				if (u.m/d*s - m/d*u.s>0) {
					return Rat(u.m/d*s - m/d*u.s,m/d*u.m,1);
				} else {
					return Rat(m/d*u.s - u.m/d*s,m/d*u.m,-1);
				}
				if ( m/d*u.s- u.m/d*s>0) {
					return Rat(m/d*u.s - u.m/d*s,m/d*u.m,1);
				} else {
					return Rat(u.m/d*s - m/d*u.s,m/d*u.m,-1);
				}
			}else {
				return Rat(u)+Rat(s,m,d);
			}
		}
	}
	Rat operator- (const Rat &u) {
		return Rat(s,m,t)+Rat(u.s,u.m,-u.t);
	}
	Rat operator* (const Rat &u) {return Rat(s*u.s, m*u.m,t*u.t);	}
	Rat operator/ (const Rat &u) {return Rat(s*u.m, m*u.s,t*u.t);	}

    bool operator < (const Rat& u) const { return s*u.m < u.s*m; }  
	friend inline int dcmp(Rat u) {return (u.s==0)?0:(u.s>0?1:-1);}
	void print() {
		cout<<t*s<<'/'<<m<<endl;
	}
};
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	(Rat(2,3)-Rat(1,2,1)).print();
	
	return 0;
}

