#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
#include<vector>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (10000+10)
#define MAXM (50000+10)
long long mul(long long a,long long b){return (a*b)%F;}
long long add(long long a,long long b){return (a+b)%F;}
long long sub(long long a,long long b){return (a-b+(a-b)/F*F+F)%F;}
typedef long long ll;
class SSC
{
public:
	int n,b[MAXN],num[MAXN];
	vector<int> G[MAXN],rG[MAXN]; //图，反向后的图 
	vector<int> vs; //后续遍历顶点列表 
	void mem(int _n)
	{
		n=_n; MEM(num)
		For(i,n) G[i].clear(),rG[i].clear();
		vs.clear();
	}
	void addedge(int u,int v)
	{
		G[u].push_back(v);
		rG[v].push_back(u);
	}
	void dfs(int x)
	{
		b[x]=1;
		Rep(i,G[x].size())
		{
			if (!b[G[x][i]]) dfs(G[x][i]);
		}
		vs.push_back(x);
	}
	void rdfs(int x,int k)
	{
		b[x]=1;num[x]=k;
		Rep(i,rG[x].size())
		{
			if (!b[rG[x][i]]) rdfs(rG[x][i],k);
		}
	}
	int ssc()
	{
		MEM(b) 
		For(i,n) if (!b[i]) dfs(i);
		MEM(b) int k=0;
		RepD(i,vs.size()-1) if (!b[vs[i]]) rdfs(vs[i],++k);
		return k;
	}
	
}S;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
		
	return 0;
}

