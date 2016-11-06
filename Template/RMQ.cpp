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
#define F (100000007)
#define eps (1e-5)
#define MAXN (10000+10)
#define MAXLog (30)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
class RMQ
{
public:
	int n,a[MAXN];
	RMQ(int _n=0):n(_n){}
	RMQ(int* _a,int _n=0):n(_n){memcpy(a,_a,sizeof(int)*_n);	}
	void mem(int* _a,int _n=0){n=_n;memcpy(a,_a,sizeof(int)*_n);	}
	int d[MAXN][MAXLog];
	void RMQ_init()
	{
		Rep(i,n) d[i][0]=a[i];
		for(int j=1;(1<<j)<=n;j++)
			for(int i=0;i + (1<<j) -1 < n; i++)
			{
				d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
			}
 	} 
 	int query(int L,int R)
 	{
 		if (L>R) swap(L,R);
 		int k=floor(log(R-L+1)/log(2));
		return min(d[L][k],d[R-(1<<k)+1][k]);
 	}
};
int main()
{
//	freopen(".in","r",stdin);
		
	return 0;
}

