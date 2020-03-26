#include<bits/stdc++.h>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define pb push_back
#define mp make_pair 
#define eps (1e-1)
#define MAXN (800000+10)
#define pi ((double)3.1415926535897932384626)
typedef long long ll;
typedef complex<double> cd;

class fft { 
public:
	cd A[MAXN];
	int n,l;
	void brc(cd *A,int l) {
		int i,j,k;
		for(i=1,j=l>>1;i<l-1;i++) {
			if (i<j) swap(A[i],A[j]);
			k=l>>1;
			while(j>=k) {
				j-=k;
				k>>=1;
			} 
			j+=k;
		} 	
	}	
	void DFT(int l,int on) //on 	
	{
		brc(A,l);
		
		for(int h=2;h<=l;h<<=1) {
			cd wn=cd(cos(on*2*pi/h),sin(on*2*pi/h));
			for(int j=0;j<l;j+=h) {
				cd w=cd(1,0);
				
				for(int k=j;k<j+h/2;k++) {
					cd u=A[k],t=w*A[k+h/2];
					A[k]=u+t;
					A[k+h/2]=u-t;
					w*=wn;
				}
			}
			
		}
		if (on==-1) Rep(i,l) A[i]/=l;
		
		//DFT = Äæ¾ØÕó=-A/l  
		
	}
	void mem(int _n) {
		MEM(A)  n=_n;
		l=1; 
		while(l<n) l<<=1; 
		l<<=1;
	}
	
	void scan(int *a,int n) {
		MEM(A)
		Rep(i,n) {
			A[i]=cd(a[i],0);
		}		
	}
	
}S1,S2;

int n,a[MAXN]={0},b[MAXN]={0}; 
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    scanf("%d",&n);
    S1.mem(n);S2.mem(n);
	
    Rep(i,n)
        scanf("%d%d",&a[i],&b[n-i-1]); 

    S1.scan(a,n);
    S2.scan(b,n);
    S1.DFT(S1.l,1);
    S2.DFT(S2.l,1);

    Rep(i,S1.l) S1.A[i] *= S2.A[i];

    S1.DFT(S1.l,-1);

    Fork(i,n-1,2*n-2) printf("%d\n",(int)(S1.A[i].real()+eps));


	return 0;
}

