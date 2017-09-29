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
#define MAXN (100000+10)
#define MAXM (60000*2+10)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}

class SPFA
{
public:
	void mem()
	{
		MEM(pre) MEM(edge) MEM(pre) MEM(weight) size=1;
	}
	int q[MAXN*100];
	int edge[MAXM],next[MAXM],pre[MAXN],weight[MAXM],size;
	void addedge(int u,int v,int w)
	{
		edge[++size]=v;
		weight[size]=w;
		next[size]=pre[u];	
		pre[u]=size;
	}
	void addedge2(int u,int v,int w){addedge(u,v,w);addedge(v,u,w);}
	int d[MAXN];
	bool b[MAXN];
	int spfa(int s,int t)
	{
		MEM(b) MEMI(d) 
		b[s]=1; d[s]=0;
		
		int head=1,tail=1;q[1]=1;
		while(head<=tail)
		{
			int now=q[head++];
			b[now]=0;
			Forp(now)
			{
				int v=edge[p];
				if (d[now]+weight[p]<d[v]) {
					d[v]=d[now]+weight[p];
					if (!b[v]) { b[v]=1,q[++tail]=v;
					} 
				}
			}
		}
		return d[t];
	}
}S1,S2;
class link_table
{
public:
	void mem()
	{
		MEM(pre) MEM(edge) MEM(next) MEM(weight) size=1;
	}
	int edge[MAXM],next[MAXM],pre[MAXN],weight[MAXM],size;
	
	void addedge(int u,int v,int w)
	{
		edge[++size]=v;
		weight[size]=w;
		next[size]=pre[u];	
		pre[u]=size;
	}
	void addedge2(int u,int v,int w){addedge(u,v,w);addedge(v,u,w);}
}St;
int n,m;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);

	return 0;
}

