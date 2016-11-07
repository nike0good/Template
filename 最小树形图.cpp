#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cctype>
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
#define MAXN (500+50)
#define MAXM (2000+10) 
#define MAXS (500+60)
#define MAXE (10000+10)
typedef __int64 ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}



struct edge{
	int u,v,w;
	edge(){}
	edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
}e[MAXE];
int tot=0;

int id[MAXN],in[MAXN],pre[MAXN],vis[MAXN];
int MST_Directed(int root,int numv,int nume) {
	int ans=0;
 
	while (1) {
		For(i,numv) in[i]=INF,pre[i]=INF;
		For(i,nume) {
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if (w<in[v]&&u!=v) {
				pre[v]=u;
				in[v]=w;
			}
		}
		
		For(i,numv) {
			if (i==root) continue;
			if (in[i]==INF) return -1;
		} 
		in[root]=0;
		For(i,numv) ans+=in[i];
		
		memset(id,-1,sizeof(id));
		memset(vis,-1,sizeof(vis));
		int cntnode=0; 
	
		For(i,numv) {
			int v=i;
			while( vis[ v ] !=i && id[v] == -1 && (v!=root) ) {
				vis[v]=i;
				v=pre[v];
			}	
			if (v!=root && id[v] == -1 ) {
				++cntnode;
				for(int u=pre[v];u!=v;u=pre[u]) id[u]=cntnode;
				id[v]= cntnode; 
			}		
		}
		
		if (!cntnode) break;
		For(i,numv) {
			if (id[i]==-1) {
				id[i]= ++ cntnode; 
			}
		}
		
		For(i,nume) {
			int v=e[i].v;
			e[i].u=id[e[i].u];
			e[i].v=id[e[i].v];
			if (e[i].u != e[i].v )  {
				e[i].w-=in[v];
			}
		}
				
		numv=cntnode;
		root=id[root];
		
	}
	return ans;
}


int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);

	return 0;
}

