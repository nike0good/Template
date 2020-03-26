#include<bits/stdc++.h> 
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
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
#define gmax(a,b) a=max(a,b);
#define gmin(a,b) a=min(a,b);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return ((a-b)%F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
ll costA[410]; 
namespace KM{
    const int N=405;
	bool b[410][410];
    const ll inf=1e15;
    ll n,nl,nr,m,z,py,x,y,i,j,p,lk[N],pre[N];
    bool vy[N];
    ll lx[N],ly[N],d,w[N][N],slk[N];ll ans;
    ll work(int nl,int nr){ // nl nr w 求最大权值匹配，边权均在1e9且正数，答案可以超出int 
      n=max(nl,nr);
//      For(i,nl) For(j,nr) w[i][j]=max(0,f[i][j]);
    For(i,nl) For(j,nr) w[i][j]=0;
    MEM(b)
    For(x,nl) {
    	int m=read(),y;
		while(m--)
			scanf("%d",&y),w[y][x]=max(w[y][x],costA[x]),b[x][y]=1;
	}
//    For(i,nl) {
//    	For(j,nr) cout<<w[i][j]<<' ';cout<<endl;
//	}
      for(i=1;i<=n;i++)for(j=1;j<=n;j++)lx[i]=max(lx[i],w[i][j]);
      for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)slk[j]=inf,vy[j]=0;
        for(lk[py=0]=i;lk[py];py=p){
          vy[py]=1;d=inf;x=lk[py];
          for(y=1;y<=n;y++)if(!vy[y]){
            if(lx[x]+ly[y]-w[x][y]<slk[y])slk[y]=lx[x]+ly[y]-w[x][y],pre[y]=py;
            if(slk[y]<d)d=slk[y],p=y;
          }
          for(y=0;y<=n;y++)if(vy[y])lx[lk[y]]-=d,ly[y]+=d;else slk[y]-=d;
        }
        for(;py;py=pre[py])lk[py]=lk[pre[py]];
      }
      for(i=1;i<=n;i++)ans+=lx[i]+ly[i];
//    printf("%lld\n",ans);
    for(i=1;i<=nl;i++){
    	
		printf("%I64d ",w[lk[i]][i]?((b[i][lk[i]])?lk[i]:0):0);
    }
	}
}
int n,m;
int main()
{
//	freopen("b.in","r",stdin);
	freopen("beloved.in","r",stdin);
	freopen("beloved.out","w",stdout);
	int n=read();
	For(i,n) costA[i]=read();
	For(i,n) costA[i]=costA[i]*costA[i];
	
    KM::work(n,n);
	
	return 0;
}

