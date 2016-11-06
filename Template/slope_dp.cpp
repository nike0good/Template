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
ll sub(ll a,ll b){return ((a-b)%F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
int n;
pair<ll,ll> p2[100000];
ll f[100000];
int que[100000]={0};
int H = 0 , T = 0;
ll getdp(int i,int j) {
	return f[que[H]] + p2[que[H]+1].fi * p2[i].se;
}  
ll getUp(int j,int k) { //yj-yk
	return f[j]-f[k];
}
ll getDown(int j,int k) { // xj-xk
	return p2[j+1].fi - p2[k+1].fi;
}
// fi = min( fj + cost(j+1,i) )
void slope_dp(int n) {
	MEM(que) H=T=0;
	f[0]=0;
	For(i,n) {
		while( H<T && getUp(que[H+1],que[H] ) <= getDown(que[H+1], que[H]) * (-p2[i].se ) )		// 条件 que[H+1]比que[H]优 
			++H;
		f[i]=getdp(i,que[H]);
		while( H<T && getUp(i,que[T] ) * getDown(que[T],que[T-1]) >= getUp(que[T], que[T-1] ) * getDown(i, que[T] ) ) // 大等于和下等于取决于  min,max 
			--T;
		que[++T] =i;  
	}
}
int main()
{
//	freopen("bzoj1597.in","r",stdin);
//	freopen(".out","w",stdout);
	
	
	return 0;
}

