#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (998244353)
#define eps (1e-3)
#define MAXN (16+10)
#define MAXM (16*16+10)
typedef __int64 ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}

typedef double Matrix[MAXN][MAXN];

void gauss_elimination(Matrix A, int n) { //假设系数矩阵A可逆 A[0..n-1,0..n]
//运行结束后A[i][i]极为第i个变量的值 
	Rep(i,n) {
		int r=i;
		Fork(j,i+1,n-1) {
			if (fabs(A[j][i])>fabs(A[r][i])) r=j;
		}	
		if (r>i) {
			Rep(j,n+1) swap(A[r][j],A[i][j]);
		}
		/* 不精确 
		Fork(k,i+1,n-1) {
			double f = A[k][i] / A[i][i];
			Fork(j,i,n) A[k][j] -= f * A[i][j];
		}*/
		
		Fork(k,i+1,n-1) {
			ForkD(j,i,n) A[k][j] -= A[k][i] / A[i][i] * A[i][j];
		}

	}
	RepD(i,n-1) {
		Fork(j,i+1,n-1) A[i][n] -= A[j][n] * A[i][j];
		A[i][n] /= A[i][i];
	}
}

void gauss_jordan(Matrix A, int n) { //矛盾方程和多余方程都可以 A[0..n-1,0..n]
//运行结束后A[i][i]极为第i个变量的值 
	Rep(i,n) {
		int r=i;
		Fork(j,i+1,n-1) {
			if (fabs(A[j][i])>fabs(A[r][i])) r=j;
		}
		if (fabs(A[r][i]) < eps ) continue;	
		if (r>i) {
			Rep(j,n+1) swap(A[r][j],A[i][j]);
		} 
		
		Rep(k,n) if (k^i) {
			double f = A[k][i] / A[i][i];
			ForkD(j,i,n) A[k][j] -= f * A[i][j];
		}
	}
}

struct M  
{  
    int n,m;  
    ll a[MAXN][MAXN];  
    M(int _n=0){n=m=_n;MEM(a);}	
    M(int _n,int _m){n=_n,m=_m;MEM(a);}
    void mem (int _n=0){n=m=_n;MEM(a);}
    void mem (int _n,int _m){n=_n,m=_m;MEM(a);}
    
	friend M operator*(M a,M b)  
    {  
        M c(a.n,b.m);  
	    For(k,a.m)
		    For(i,a.n)  
	            For(j,b.m)  
	                c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%F;  
		return c;     
    }  
    friend M operator+(M a,M b)  
    {  
	    For(i,a.n)  
            For(j,a.m)  
                a.a[i][j]=(a.a[i][j]+b.a[i][j])%F;  
		return a;
    }  
	void make_I(int _n)  
    {  
    	n=m=_n; MEM(a)
        For(i,n) a[i][i]=1;  
    }  
	// 求行列式    
    long double mat[MAXN][MAXN],tmp[MAXN];
    long double det()
    {
    	For(i,n) For(j,m) mat[i][j]=a[i][j]; 
    	For(i,n)
    	{
    		int pos=i;
    		while (fabs(mat[pos][i])<eps&&pos<n) ++pos;
    		if (fabs(mat[pos][i])<eps) continue;
    		if (pos^i)
    		{
    			copy(mat[pos]+1,mat[pos]+1+m+1,tmp+1);
    			copy(mat[i]+1,mat[i]+1+m+1,mat[pos]+1);
    			copy(tmp+1,tmp+1+m+1,mat[i]+1);
    		}
			For(j,n)
				if (i^j)
				{
					long double p = mat[j][i]/mat[i][i];
					For(k,m) mat[j][k]-=mat[i][k]*p;
				} 
    	}
    	long double ans=1;
    	For(i,n) ans*=mat[i][i];
    	return ans;
    }
}A,C,D;
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
bool a3[1000000];  
M pow222(M a,ll b)  
{  
    M c;c.make_I(a.n);    
    int n=0;while (b) a3[++n]=b&1,b>>=1;
    c=a; b=1;
    M d=c;
	ForD(i,n-1)    
    {    
		b=b*2+a3[i];
	    c=c*d+c;
	    d=d*d;
	    if (a3[i]) c=c*a+a,d=d*a;
    }    
    return c;    
}




const ll p2[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536}; 
M a;
int n,m,t[MAXN];
void work()
{
	ll ans=0,cnt;
	
	//t[i] 表示t缩点的标号 
	//将C[G]的第a行,第b列同时去掉后得到的新矩阵 a,b为任意(1≤a,b≤n) 
	// 处理t 最大值为n-cnt+1 
	a.mem(n-cnt);
	For(j,n)
		For(l,n)
			if (t[j]!=t[l]&&A.a[j][l])
			{
				a.a[t[j]][t[j]]++;
				a.a[t[j]][t[l]]--;
			}
	ll t2=(ll)(fabs(a.det())+eps)%F;
	
	cout<<ans<<endl; 
}

int u[MAXN],v[MAXN];
void Kirchhoff()
{
	while (cin>>n>>m) {
		A.mem(n),D.mem(n),C.mem(n);
		For(i,m)
		{
			scanf("%d%d",&u[i],&v[i]);
			D.a[u[i]][u[i]]++;
			D.a[v[i]][v[i]]++;
			A.a[u[i]][v[i]]++;
			A.a[v[i]][u[i]]++;
		}
		work();		
	}	
	
}


int main()
{
//	freopen(".in","r",stdin);
	
	
	
	
	
	return 0;
}

