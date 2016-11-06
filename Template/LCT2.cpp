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
#define MAXN (10000+10)
#define MAXM (200000+10) 
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
	bool rev[MAXN];
	void mem(int n)
	{
		MEM(father) MEM(siz) MEM(root)
		For(i,n+1) siz[i]=1,root[i]=1;root[0]=1;
		MEM(ch)  MEM(rev)
	}
	void pushdown(int x)
	{
		if (!x) return ; 
		if (rev[x]) {
			if (ch[x][0]) rev[ch[x][0]]^=1;
			if (ch[x][1]) rev[ch[x][1]]^=1;
			swap(ch[x][0],ch[x][1]);
			rev[x]^=1;
		} 
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
	
	void P(int x)
	{
		if (!root[x]) P(father[x]);
		pushdown(x);
	}
	
	void splay(int x)
	{
		P(x);
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
	int find_root(int x) {
		access(x);
		splay(x);
		int t=x;
		while(ch[t][0]) t=ch[t][0];
		return t;
	}

	void join(int x,int y)
	{
		make_root(x);
		access(y);
		splay(y);
		ch[y][1]=x;
		father[x]=y;
		root[x]=0;
	}
	void reverse(int x){
		rev[x]^=1;	 // 标记记完后迅速处理 
	}
	void make_root(int x){
		access(x);splay(x);
		reverse(x);pushdown(x);
	}
	int get_root(int x){
		access(x);
		splay(x);
		do {
			pushdown(x);
			if (ch[x][0]) x=ch[x][0];
			else break;
		}while(1);
		return x;
	}
	
	bool check(int x,int y) {
		while (father[x]) x=father[x];
		while (father[y]) y=father[y];
		return x==y;
	}
	
}S;

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	 

	
	return 0;
}

