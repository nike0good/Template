#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
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
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}

#define MAXNode (1000000)
#define Sigma_size (26)
class Aho_Corasick_Automata
{
public:
	int ch[MAXNode][Sigma_size];
	int v[MAXNode],siz;
	// AC自动机 
	int f[MAXNode],last[MAXNode];
	Aho_Corasick_Automata(int _siz=0):siz(_siz){MEM(ch) MEM(v) MEM(f) MEM(last)}
	void mem(int _siz=0){siz=_siz; MEM(ch) MEM(v) MEM(f) MEM(last)	}
	int idx(char c){return c-'a';}
	void insert(char *s,int val=1) //val不为0 表示str末尾 
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
	void getFail()
	{
		queue<int> q;
		Rep(c,Sigma_size)
		{
			int u=ch[0][c];
			if (u) q.push(u),last[u]=0;
		}
		while (!q.empty())
		{
			int r=q.front();q.pop();  //r--c-->u
			Rep(c,Sigma_size)
			{
				int u=ch[r][c];
				if (!u) {ch[r][c]=ch[f[r]][c]; continue;} 
				q.push(u);
				f[u]=ch[f[r]][c];
				last[u]=v[f[u]]?f[u]:last[f[u]];
			}
		}
	} 
	void print(int j) //打印全串中所有以j为末尾的str 
	{
		if (j)
		{
			printf("%d %d\n",j,v[j]);
			print(last[j]);
		}
	} 
	void find(char *s)
	{
		int u=0,n=strlen(s);
		Rep(i,n)
		{
			int c=idx(s[i]);
			u=ch[u][c];
			if (v[u]) print(u);
			else if (last[u]) print(u);
		}
	}
	
}T;

int main()
{
	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	
	
	return 0;
}

