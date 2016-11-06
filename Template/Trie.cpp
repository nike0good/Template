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
#define F (20071027)
long long mul(long long a,long long b){return (a*b)%F;}
long long add(long long a,long long b){return (a+b)%F;}
long long sub(long long a,long long b){return (a-b+(a-b)/F*F+F)%F;}
typedef long long ll;
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
#define MAXNode (100000*5+10)
#define Sigma_size (26)
class Trie
{
public:
	int ch[MAXNode][Sigma_size];
	int v[MAXNode],siz;
	Trie(int _siz=0):siz(_siz){MEM(ch) MEM(v)}
	void mem(int _siz=0){siz=_siz; MEM(ch) MEM(v)	}
	int idx(char c){return c-'a';}
	void insert(char *s,int val=0)
	{
		int u=0,n=strlen(s);
		Rep(i,n)
		{
			int c=idx(s[i]);
			if (!ch[u][c])
			{
				++siz;
				MEM(ch[siz]);
				ch[u][c]=siz;
			}
			u=ch[u][c];
		}
		v[u]=val;
	}
	void find(char *s)
	{
		int u=0,n=strlen(s);
		Rep(i,n)
		{
			int c=idx(s[i]);
			if (!ch[u][c])
			{
				return;
			}
			u=ch[u][c];
		}
	}
	
}T;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	
	return 0;
}

