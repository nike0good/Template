#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
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
#define F (1000003)
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
const int N=524300,P=1000003,M=1000;
int n,a,b,c,i,j,k,pos[N],ans;
int pa[N],pb[N],fac[N],inv[N],A[N],B[N],C[N];
namespace FFT{
	struct comp{
		ld r,i;comp(ld _r=0,ld _i=0){r=_r;i=_i;}
		comp operator+(const comp x){return comp(r+x.r,i+x.i);}
		comp operator-(const comp x){return comp(r-x.r,i-x.i);}
		comp operator*(const comp x){return comp(r*x.r-i*x.i,r*x.i+i*x.r);}
		comp conj(){return comp(r,-i);}
	}A[N],B[N];
	int a0[N],b0[N],a1[N],b1[N];
	const ld pi=acos(-1.0);
	void FFT(comp a[],int n,int t){
		For(i,n-1) if(i<pos[i]) swap(a[i],a[pos[i]]);
		for(int d=0;(1<<d)<n;d++) {
	    	int m=1<<d,m2=m<<1;
	    	ld o=pi*2/m2*t;comp _w(cos(o),sin(o));
	    	for(int i=0;i<n;i+=m2){
				comp w(1,0);
				for(int j=0;j<m;j++){
					comp&A=a[i+j+m],&B=a[i+j],t=w*A;
					A=B-t;B=B+t;w=w*_w;
				}
			}
		}
		if(t==-1)for(int i=0;i<n;i++)a[i].r/=n;
	}
	//c=a*b 
	void mul(int*a,int*b,int*c){
		int i,j;
		for(i=0;i<k;i++)A[i]=comp(a[i],b[i]);
		FFT(A,k,1);
		for(i=0;i<k;i++){
			j=(k-i)&(k-1);
			B[i]=(A[i]*A[i]-(A[j]*A[j]).conj())*comp(0,-0.25);
	  }
		FFT(B,k,-1);
		for(i=0;i<k;i++)c[i]=((long long)(B[i].r+0.5))%P;
	}
	//c = a*b mod P 
	void mulmod(int*a,int*b,int*c){
		int i;
		for(i=0;i<k;i++)a0[i]=a[i]/M,b0[i]=b[i]/M;
		for(mul(a0,b0,a0),i=0;i<k;i++){
			c[i]=1LL*a0[i]*M*M%P;
			a1[i]=a[i]%M,b1[i]=b[i]%M;
		}
		for(mul(a1,b1,a1),i=0;i<k;i++){
			c[i]=(a1[i]+c[i])%P,a0[i]=(a0[i]+a1[i])%P;
			a1[i]=a[i]/M+a[i]%M,b1[i]=b[i]/M+b[i]%M;
		}
		for(mul(a1,b1,a1),i=0;i<k;i++)c[i]=(1LL*M*(a1[i]-a0[i]+P)+c[i])%P;
	}
}
int main(){
//	freopen("F.in","r",stdin);
	while(cin>>n>>a>>b>>c) {
		ans=0;
		for(pa[0]=i=1;i<=n;i++)pa[i]=1LL*pa[i-1]*a%P;
		for(pb[0]=i=1;i<=n;i++)pb[i]=1LL*pb[i-1]*b%P;
		for(fac[0]=i=1;i<=n+n;i++)fac[i]=1LL*fac[i-1]*i%P;
		for(inv[0]=inv[1]=1,i=2;i<=n;i++)inv[i]=1LL*(P-inv[P%i])*(P/i)%P;
		for(i=1;i<=n;i++)inv[i]=1LL*inv[i]*inv[i-1]%P;
		for(i=1;i<=n;i++){
			cin>>j;
			if(i>1)ans=(1LL*fac[n+n-i-2]*inv[n-i]%P*pa[n-1]%P*pb[n-i]%P*j+ans)%P;
 		}
		for(i=1;i<=n;i++){
			cin>>j;
			if(i>1)ans=(1LL*fac[n+n-i-2]*inv[n-i]%P*pa[n-i]%P*pb[n-1]%P*j+ans)%P;
		}
		ans=1LL*ans*inv[n-2]%P;
		for(k=1;k<=n;k<<=1);k<<=1;
		j=__builtin_ctz(k)-1;
		for(i=0;i<k;i++)pos[i]=pos[i>>1]>>1|((i&1)<<j);
		for(i=2;i<=n;i++)A[i]=1LL*pa[n-i]*inv[n-i]%P;
		for(i=2;i<=n;i++)B[i]=1LL*pb[n-i]*inv[n-i]%P;
		FFT::mulmod(A,B,C);
		for(i=4;i<=n+n;i++)ans=(1LL*C[i]*fac[n+n-i]%P*c+ans)%P;
		printf("%d\n",ans);
	}
	return 0;
}
