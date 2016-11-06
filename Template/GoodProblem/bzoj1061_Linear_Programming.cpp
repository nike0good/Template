#include<bits/stdc++.h> 
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
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
int m,n;
#define EPS (1E-7)
#define MAXM (10000+10)
#define MAXN (1000+10)
namespace Linear_Programming{  
    double A[MAXM][MAXN],b[MAXM],c[MAXM],v;  
    void Pivot(int l,int e)  
    {  
        int i,j;  
        b[l]/=A[l][e];  
        for(i=1;i<=n;i++)  
            if(i!=e)  
                A[l][i]/=A[l][e];  
        A[l][e]=1/A[l][e];  
  
        for(i=1;i<=m;i++)  
            if(i!=l&&fabs(A[i][e])>EPS)  
            {  
                b[i]-=A[i][e]*b[l];  
                for(j=1;j<=n;j++)  
                    if(j!=e)  
                        A[i][j]-=A[i][e]*A[l][j];  
                A[i][e]=-A[i][e]*A[l][e];  
            }  
  
        v+=c[e]*b[l];  
        for(i=1;i<=n;i++)  
            if(i!=e)  
                c[i]-=c[e]*A[l][i];  
        c[e]=-c[e]*A[l][e];  
    }  
    double Simplex()  
    {  
        int i,l,e;  
        while(1)  
        {  
            for(i=1;i<=n;i++)  
                if(c[i]>EPS)  
                    break;  
            if((e=i)==n+1)  
                return v;  
            double temp=INF;  
            for(i=1;i<=m;i++)  
                if( A[i][e]>EPS && b[i]/A[i][e]<temp )  
                    temp=b[i]/A[i][e],l=i;  
            if(temp==INF) return INF;  
            Pivot(l,e);  
        }  
	}  
}  
int main()
{
//	freopen("bzoj1061.in","r",stdin);
//	freopen(".out","w",stdout);
	
	using namespace Linear_Programming;
	n=read(),m=read();
	For(i,n) { //n=方程数 m=变元数 
		scanf("%lf",&c[i]);
	}	
	For(i,m) {
		int x=read(),y=read(),z=read();
		for(int j=x;j<=y;j++) A[i][j]=1;
		b[i]=z;
	} 
	double ans=Simplex();  
    printf("%d\n",int(ans+0.5));  
	return 0;
}

