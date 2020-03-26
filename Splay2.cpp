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
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
int modF(int a,int b){return (a+a/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}

int n,m;
int a[MAXN];
class Splay
{
public:
	int father[MAXN],siz[MAXN],n;
	int ch[MAXN][2],val[MAXN];
	bool root[MAXN],rev[MAXN];	
	int addv[MAXN],minv[MAXN];
	int roo; //root
	void mem(int _n)
	{
		MEM(father) MEM(siz) MEM(root) MEM(rev)	MEM(ch) MEM(val) flag=0; MEM(addv) MEM(minv)
		n=0; 
		roo=1; 
		build(roo,1,_n,0);root[1]=1;
	}
	void newnode(int &x,int f,int v)
	{
		x=++n;
		father[x]=f;
		val[x]=minv[x]=v;siz[x]=1;
	}
	
	void build(int &x,int L,int R,int f)
	{
		if (L>R) return ;
		int m=(L+R)>>1;
		newnode(x,f,a[m]); 
		build(ch[x][0],L,m-1,x);
		build(ch[x][1],m+1,R,x);
		maintain(x);
	}
	int getkth(int x,int k)
	{
		pushdown(x); 
		int t;
		if (ch[x][0]) t=siz[ch[x][0]]; else t=0;
		
		if (t==k-1) return x;
		else if (t>=k) return getkth(ch[x][0],k);
		else return getkth(ch[x][1],k-t-1);
		
	}
	
	
	void pushdown(int x)
	{
		if (x) if (rev[x])
		{
			swap(ch[x][0],ch[x][1]);
			if (ch[x][0]) rev[ ch[x][0] ]^=1;
			if (ch[x][1]) rev[ ch[x][1] ]^=1;
			rev[x]^=1;
		}
		if (addv[x])
		{
			if (ch[x][0]) addv[ ch[x][0] ]+=addv[x],minv[ ch[x][0] ]+=addv[x],val[ ch[x][0] ]+=addv[x];
			if (ch[x][1]) addv[ ch[x][1] ]+=addv[x],minv[ ch[x][1] ]+=addv[x],val[ ch[x][1] ]+=addv[x];
			addv[x]=0;
		}
	}
	void maintain(int x)
	{
		siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
		minv[x]=val[x];
		if (ch[x][0]) minv[ x ]=min(minv[x],minv[ ch[x][0] ] + addv[x] );
		if (ch[x][1]) minv[ x ]=min(minv[x],minv[ ch[x][1] ] + addv[x] );
	}
	void rotate(int x)
	{
		int y=father[x],kind=ch[y][1]==x;
		
		pushdown(y); pushdown(x);
			
		ch[y][kind]=ch[x][!kind];
		if (ch[y][kind]) {
			father[ch[y][kind]]=y;
		}
		father[x]=father[y];
		father[y]=x;
		ch[x][!kind]=y;
		if (root[y])
		{
			root[x]=1;root[y]=0;roo=x;
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
		roo=x;
	}
	void splay(int x,int r)
	{
		while(!(father[x]==r))
		{
			int y=father[x];
			int z=father[y];
			if (father[y]==r) rotate(x);
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
	
	void Cut(int a,int b,int c)
	{
		int x=getkth(roo,a),y=getkth(roo,b);
		splay(x);
		splay(y,roo);
		pushdown(x);pushdown(y);
		int z=ch[y][0];
		ch[y][0]=0; maintain(y); maintain(x);
		
		int u=getkth(roo,c),v=getkth(roo,c+1);
		splay(u);
		splay(v,roo);
		pushdown(u);pushdown(v);
		ch[v][0]=z;father[z]=v;
		maintain(v);maintain(u);
		
	}
	
	void Flip(int a,int b)
	{
		int x=getkth(roo,a),y=getkth(roo,b);
		splay(x);
		splay(y,roo);
		pushdown(x);pushdown(y);
		int z=ch[y][0];
		rev[z]^=1;
		maintain(y); maintain(x);
	} 
	
	void Add(int a,int b,int c)
	{
		int x=getkth(roo,a),y=getkth(roo,b);
		splay(x);
		splay(y,roo);
		pushdown(x);pushdown(y);
		int z=ch[y][0];
		addv[z]+=c; val[z]+=c; minv[z]+=c;
		maintain(y); maintain(x);
	} 
	
	int queryMin(int a,int b)
	{
		int x=getkth(roo,a),y=getkth(roo,b);
		splay(x);
		splay(y,roo);
		pushdown(x);pushdown(y);
		int z=ch[y][0];		
		maintain(y); maintain(x);
		return minv[z];
	} 
	
	void insert(int a,int P)
	{
		int x=getkth(roo,a),y=getkth(roo,a+1);
		splay(x);
		splay(y,roo);
		pushdown(x);pushdown(y);
		newnode(ch[y][0],y,P);
		maintain(y); maintain(x);
	}
	void Delete(int a,int b)
	{
		int x=getkth(roo,a),y=getkth(roo,b);
		splay(x);
		splay(y,roo);
		pushdown(x);pushdown(y);
		int z=ch[y][0];
		ch[y][0]=0; father[z]=0; maintain(y); maintain(x);
		
	}
	
	bool flag;
	void print(int x)
	{
		if (x==0) return ;
		pushdown(x);
		print(ch[x][0]);
		printf("%d ",val[x]);
		print(ch[x][1]);	
	} 
}S;

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	while(cin>>n)
	{
	
		S.print(S.roo);cout<<endl;		
	}
	
	
	return 0;
}

