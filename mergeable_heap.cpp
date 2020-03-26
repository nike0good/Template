#pragma comment(linker, "/STACK:102400000000,102400000000") 
#include<bits/stdc++.h> 
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define MAXN (300000+10)
#define MAXM (300000+10)
typedef long long ll;

class mergeable_heap
{
public:
    ll val[MAXN];  
    int dis[MAXN],ch[MAXN][2];  
	ll addv[MAXN],mulv[MAXN];
	bool is_mul[MAXN];
	void mem()
	{
		MEM(val) MEM(dis) MEM(ch) 
		dis[0]=-1;
		MEM(addv) MEM(mulv) MEM(is_mul)
	}
	void pushdown(int x)
	{
		if (x==0) return;
		if (is_mul[x])
		{
			if (ch[x][0]) 
			{
				mulv[ch[x][0]]=is_mul[ch[x][0]] ? mulv[ch[x][0]]*mulv[x] : mulv[x];
				is_mul[ch[x][0]]=1;
				addv[ch[x][0]]*=mulv[x],val[ch[x][0]]*=mulv[x];
			}
			if (ch[x][1]) 
			{
				mulv[ch[x][1]]=is_mul[ch[x][1]] ? mulv[ch[x][1]]*mulv[x] : mulv[x];
				is_mul[ch[x][1]]=1;
				addv[ch[x][1]]*=mulv[x],val[ch[x][1]]*=mulv[x];
			}
			is_mul[x]=mulv[x]=0;
		}
		if (addv[x])
		{
			if (ch[x][0]) addv[ch[x][0]]+=addv[x],val[ch[x][0]]+=addv[x];
			if (ch[x][1]) addv[ch[x][1]]+=addv[x],val[ch[x][1]]+=addv[x];
			addv[x]=0;
		}
	}
	int merge(int k1,int k2)
	{ 
		if (k1==0) return k2;
		if (k2==0) return k1;
		if (val[k1]>val[k2]) swap(k1,k2);
		pushdown(k1);
		ch[k1][1]=merge(ch[k1][1],k2);
		if (dis[ch[k1][0]]<dis[ch[k1][1]]) swap(ch[k1][0],ch[k1][1]);
		dis[k1]=dis[ch[k1][1]]+1;
		return k1;
	}
	int DeleteMin(int x)
	{
		if (x==0) return 0;
		pushdown(x); 
		return merge(ch[x][0],ch[x][1]);
		
	}
	void add(int x,ll v)
	{
		if (x==0) return;
		pushdown(x);
		addv[x]+=v;val[x]+=v;
	}
	void mul(int x,ll v)
	{
		if (x==0) return;
		pushdown(x); 
		is_mul[x]=1;mulv[x]=v;addv[x]*=v;val[x]*=v; 
	}
}S;
int root[MAXN];

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);


	return 0;
}

