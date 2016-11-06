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
#define F (51061)
#define MAXN (100000+10)
#define MAXQ (100000+10)
#define MAXC (10000) 
typedef unsigned int ll;
void mul(ll &a,ll b){a=(a*b)%F;}
void add(ll &a,ll b){a=(a%F+b%F)%F;}


class LCT
{
public:
	int father[MAXN],siz[MAXN];
	int ch[MAXN][2];
	bool root[MAXN];
	bool rev[MAXN];
	ll addv[MAXN],mulv[MAXN],sumv[MAXN],val[MAXN];
	void mem(int n)
	{
		MEM(father) MEM(siz) MEM(root)
		For(i,n+1) siz[i]=root[i]=mulv[i]=val[i]=sumv[i]=1;    root[0]=1;
		MEM(ch)  MEM(rev)
		MEM(addv)
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
		if (mulv[x]!=1) {
			if (ch[x][0]) mul(mulv[ch[x][0]],mulv[x]),mul(addv[ch[x][0]],mulv[x]),mul(val[ch[x][0]],mulv[x]),mul(sumv[ch[x][0]],mulv[x]);
			if (ch[x][1]) mul(mulv[ch[x][1]],mulv[x]),mul(addv[ch[x][1]],mulv[x]),mul(val[ch[x][1]],mulv[x]),mul(sumv[ch[x][1]],mulv[x]);
			mulv[x]=1;
		}
		if (addv[x]) {
			if (ch[x][0]) add(addv[ch[x][0]],addv[x]),add(val[ch[x][0]],addv[x]),add(sumv[ch[x][0]],addv[x]*siz[ch[x][0]]);
			if (ch[x][1]) add(addv[ch[x][1]],addv[x]),add(val[ch[x][1]],addv[x]),add(sumv[ch[x][1]],addv[x]*siz[ch[x][1]]);
			addv[x]=0;
		}
	}
	void maintain(int x)
	{
		siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
		sumv[x]=(sumv[ch[x][0]]+sumv[ch[x][1]]+val[x])%F; 
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
	
	void join(int x,int y)
	{
		make_root(x);
		access(y);
		splay(y);
		ch[y][1]=x;
		father[x]=y;
		maintain(y);
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
	
	void Mul(int x,ll cost){
		pushdown(x);mulv[x]=cost; 
		mulv[x]=cost;mul(val[x],cost);mul(addv[x],cost);//mul(sumv[x],cost); 
	}
	void Add(int x,ll cost){
		pushdown(x);
		addv[x]=cost;add(val[x],cost);//add(sumv[x],cost*siz[x]); 
	}
	
}S;

int n,q;

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
		 
	scanf("%d%d",&n,&q);
	S.mem(n);
	For(i,n-1) {
		int u,v;
		scanf("%d%d",&u,&v);
		S.join(u,v);
	}
	
	For(i,q) {
		char c[2];
		int u,v;
		scanf("%s%d%d",c,&u,&v);
		if (c[0]=='+'||c[0]=='*') {
			int cost;
			scanf("%d",&cost);
			S.make_root(u);
			S.access(v);
			S.splay(v);
			if ('+'==c[0]) S.Add(v,cost);
			else S.Mul(v,cost); 
			
		} else if (c[0]=='-') {
			int u2,v2;
			scanf("%d%d",&u2,&v2);
			S.make_root(u);
			S.cut(v);
			S.join(u2,v2);
			
		} else if (c[0]=='/') {
			S.make_root(u);
			S.access(v);
			S.splay(v);
			printf("%u\n",S.sumv[v]%F);	
		}
	}
	
	
	
	return 0;
}

