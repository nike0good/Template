#include<bits/stdc++.h> 
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
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
ll DP[100][2][2];
ll DIG[100];
ll dfs(int pos,int pre,int status,int limit) // pos from high to low  
{
	if(pos < 1) {
		return !status;
	}
    if(!limit && DP[pos][pre][status] != -1) {
		return DP[pos][pre][status];
    }

	int end = limit ? DIG[pos] : 1;
	ll ret = 0;

	for(int i = 0;i <= end;i ++)
		ret += dfs(pos - 1,i,status || (pre == 1 && i == 1),limit && (i == end));

	if(!limit)
		DP[pos][pre][status] = ret;
	return	ret;
}
#define MAXN (3)
struct M  
{  
    int n,m;  
    ll a[MAXN][MAXN];  
    M(int _n=0){n=m=_n;MEM(a);}	
    M(int _n,int _m){n=_n,m=_m;MEM(a);}
	void make_I(int _n)  
    {  
    	n=m=_n; MEM(a)
        For(i,n) a[i][i]=1;  
    }  
}A;
M operator*(M a,M b)  
{  
    M c(a.n,b.m);  
    For(k,a.m)
	    For(i,a.n)  
            For(j,b.m)  
                c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%F;  
	return c;     
}  
M pow2(M a,ll b)  
{  
    M c;c.make_I(a.n);    
    static bool a2[1000000];    
    int n=0;while (b) a2[++n]=b&1,b>>=1;    
    For(i,n)    
    {    
        if (a2[i]) c=c*a;    
        a=a*a;    
    }    
    return c;    
}
ll work2(ll n) {
	M fib(2,2),ans(1,2);
	fib.a[1][1]=fib.a[1][2]=fib.a[2][1]=1;
	ans.a[1][1]=ans.a[1][2]=1;
	return (ans*pow2(fib,n)).a[1][1];
	
}
int main()
{
//	freopen("bzoj3329.in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while(T--) {
		MEMx(DP,-1)
		ll x;cin>>x;
		ll ans2=work2(x);
		int len=0;
		while(x) {
			DIG[++len]=x%2;
			x/=2;
		}
		ll ans1=dfs(len,-1,0,1)-1;
		cout<<ans1<<endl<<ans2<<endl;
	}
	
	
	return 0;
}

