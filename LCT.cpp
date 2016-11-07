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
#define MAXN (200000+10)
#define MAXM (100000+10) 
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}

int n,m;

class Splay
{
public:
	int father[MAXN],siz[MAXN];
	int ch[MAXN][2];
	bool root[MAXN];
	void mem(int n)
	{
		MEM(father) MEM(siz) MEM(root)
		For(i,n+1) siz[i]=1,root[i]=1;root[0]=1;
		MEM(ch) 
		 
	}
	void maintain(int x)
	{
		siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
	}
	void rotate(int x)
	{
		int y=father[x],kind=ch[y][1]==x;
		ch[y][kind]=ch[x][!kind];
		if (ch[y][kind]) {
			father[ch[y][kind]]=y;
		}
		father[x]=father[y];
		father[y]=x;
		ch[x][!kind]=y;
		if (root[y])
		{
			root[x]=1;root[y]=0;
		}
		else
		{
			ch[father[x]][ ch[father[x]][1]==y ] = x;
		}
		maintain(y);maintain(x);
	}
	void splay(int x)
	{
		while(!root[x])
		{
			int y=father[x];
			int z=father[y];
			if (root[y]) rotate(x);
			else if ( (ch[y][1]==x)^(ch[z][1]==y) )
			{
				rotate(x); rotate(x);
			} 
			else 
			{
				rotate(y); rotate(x);
			}
		}
	}
	
	int access(int x)
	{
		int y=0;
		do
		{
			splay(x);
			if (ch[x][1]) root[ch[x][1]]=1;
			ch[x][1]=y;
			if (y) root[y]=0;		
			maintain(x);
			y = x;
			x=father [x]; 
		} while (x) ;
		return y;
	}
	void cut(int x)
	{
		access(x);
		splay(x);
		
		father[ch[x][0]]=0;
		root[ch[x][0]]=1;
		ch[x][0]=0;
		maintain(x);
	}
	
	void join(int x,int w)
	{
		father[x]=w;
	}
	int find_root(int x) {
		access(x);
		splay(x);
		int t=x;
		while(ch[t][0]) t=ch[t][0];
		return t;
	}

}S;


int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	 
	
	
	return 0;
}

