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
#define MAXN (1000000+10)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
// kmp
class KMP
{
public:
	int f2[MAXN]; //字符串从0开始，但是f[i]表示匹配第i个字符，前面留一个 f[0]--a-->f[1]--...这样的 
	char T2[MAXN],P2[MAXN]; //T is long,P is model str
	void mem(){MEM(f2) MEM(T2) MEM(P2)	}
	int getFail(char *P=0,int* f=0)
	{
		if (P==0) P=P2;if (f==0) f=f2;
		int m=strlen(P);
		f[0]=f[1]=0; 
		For(i,m-1)
		{
			int j=f[i];
			while(j&&P[i]!=P[j]) j=f[j];
			f[i+1]= P[i] == P[j] ? j+1 : 0;
		}
	}
	int find(char* T=0,char* P=0,int* f=0)
	{
		if (T==0) T=T2;if (P==0) P=P2;if (f==0) f=f2;
		int n=strlen(T),m=strlen(P);
		getFail(P,f);
		int j=0;
		Rep(i,n)
		{
			while(j&&T[i]!=P[j]) j=f[j];
			if (T[i]==P[j]) j++;
			if (j==m) return i-m+1;
		}
	}
}S;
int main()
{
	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);

	
	return 0;
}

