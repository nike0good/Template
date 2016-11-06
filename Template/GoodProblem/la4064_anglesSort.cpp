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
#define eps (1e-9)
#define vi vector<int> 
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Scenario %d:\nThere are %lld sites for making valid tracks\n",kcase,ans);
#define PRi(a,n) For(i,n-1) cout<<a[i]<<' '; cout<<a[i]<<endl;
#define PRi2D(a,n,m) For(i,n) { \
                        For(j,m-1) cout<<a[i][j]<<' ';\
                        cout<<a[i][m]<<endl; \
                        } 
#define pi (acos(-1.0))
typedef long long ll;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
ll gcd(ll a,ll b){if (!b) return a ; return gcd(b,a%b);}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
    return x*f;
} 
#define MAXN (4000+10)
pair<ll,ll> p[MAXN];
double ang(pair<ll,ll> p,pair<ll,ll> p2) { return atan2((double)p2.se-p.se,(double)p2.fi-p.fi); }

int kcase=0,n;
double r[MAXN];
int main()
{
//  freopen("la4064.in","r",stdin);
    while(cin>>n && n)
    {
        For(i,n) cin>>p[i].fi>>p[i].se;
        ll ans=0;
        For(i,n) {
            int m=0;
            For(j,n)
                if (j^i)
                    Rep(k,2) r[++m]=pi*k*2+ang(p[i],p[j]);
            sort(r+1,r+m+1);
            int mv=1,mv2=1;
            For(j,n-1) {
                while (r[mv]<=r[j]+pi/2-eps) ++mv;
                while (r[mv2]<r[j]+pi) ++mv2;
                int cnt=mv2-mv;
                ans += cnt;
            }
        }
        Pr(++kcase,((ll)(n-1)*(n-2)*n/6-ans));
    }
//  {
//      freopen("la4064_makedata.in","w",stdout);
//      cout<<"100"<<endl;
//      For(i,100) {
//          int a=rand()%10000,b=rand()%10000;
//          if (gcd(a,b)==1) cout<<a<<' '<<b<<endl; else i--;
//      }
//      cout<<"0\n";
//              
//  }
    return 0;
}
