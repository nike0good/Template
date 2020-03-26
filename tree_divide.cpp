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
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (100000+10)
#define MAXM (200000+10)
long long mul(long long a,long long b){return (a*b)%F;}
long long add(long long a,long long b){return (a+b)%F;}
long long sub(long long a,long long b){return (a-b+(a-b)/F*F+F)%F;}
int n;
int edge[MAXM],next[MAXM]={0},pre[MAXN]={0},size=0;
void addedge(int u,int v)
{
	edge[++size]=v;
	next[size]=pre[u];
	pre[u]=size;
}
void addedge2(int u,int v){addedge(u,v),addedge(v,u);}
int opt[MAXN],siz[MAXN],val[MAXN]={0},all[MAXN],tot=0;
void dfs(int x,int fa)
{
	siz[x]=1;opt[x]=0;all[++tot]=x;
	Forp(x)
	{
		int &v=edge[p];
		if (v^fa&&!val[v])
		{
			dfs(v,x);siz[x]+=siz[v];
			opt[x]=max(opt[x],siz[v]);
		}
	}
}
void solve(int root,int l)
{
	tot=0,dfs(root,0);
	int minopt=INF,minoptx=0;
	For(i,tot)
	{
		int u=all[i];
		opt[u]=max(opt[u],tot-siz[u]);
		if (minopt>opt[u]) minopt=opt[u],minoptx=u;
	}
	val[root=minoptx]=l;
	Forp(root)
	{
		int &v=edge[p];
		if (!val[v]) solve(v,l+1);
	}

}
int main()
{
//  freopen("Commander.in","r",stdin);
	cin>>n;
	For(i,n-1)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge2(u,v);
	}
	solve(1,1);
	For(i,n) if (val[i]>26) {cout<<"Impossible!"<<endl;return 0;}
	For(i,n-1) cout<<(char)(val[i]+'A'-1)<<' ';
	cout<<(char)(val[n]+'A'-1)<<endl;
	return 0;
}
