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
#define INF (1000000000)
#define F (100000007)
#define MAXN (500000+10)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int n;

int cmp_d=0;
class node
{
public:
	int x[2];
	int l,r,minv[2],maxv[2];

	node(){}
	node(int a,int b){MEM(x) l=r=0; x[0]=a,x[1]=b; Rep(i,2) minv[i]=maxv[i]=x[i];}



	int& operator[](int i){return x[i];	} 
};

int dis(node a,node b){
	int ans=0;
	Rep(i,2) ans+=abs(a.x[i]-b.x[i]);
	return ans;	
}

int dis2(node p,node a) // 点p和方形区域a的欧几里德距离 
{
	int ans=0;
	Rep(i,2)
	{
		if (p.x[i]<a.minv[i]) ans+=a.minv[i]-p.x[i];
		else
		if (p.x[i]>a.maxv[i]) ans+=p.x[i]-a.maxv[i];
	}
	return ans;
}


int cmp(node a,node b){return a[cmp_d]<b[cmp_d];	}

class KD_Tree
{
public:	
	node a[MAXN*3];
	KD_Tree()
	{ 	
	}
	
	void mem()
	{
	}
	
	void update(node& o)
	{
		if (o.l)
		{
			node p=a[o.l];
			Rep(i,2) o.minv[i]=min(o.minv[i],p.minv[i]);
			Rep(i,2) o.maxv[i]=max(o.maxv[i],p.maxv[i]);	
		}
		if (o.r)
		{
			node p=a[o.r];
			Rep(i,2) o.minv[i]=min(o.minv[i],p.minv[i]);
			Rep(i,2) o.maxv[i]=max(o.maxv[i],p.maxv[i]);	
		}
		
	}

	int build(int L,int R,int nowd)
	{
		int m=(L+R)>>1;
	
		cmp_d=nowd;
		nth_element(a+L+1,a+m+1,a+R+1,cmp);
		
		if (L^m) a[m].l=build(L,m-1,nowd^1);
		if (R^m) a[m].r=build(m+1,R,nowd^1);
		
		update(a[m]);
		
		return m;
		
	} 
	
	int root;
	void _build(int L,int R,int nowd) //1-n的节点 至少为1 
	{
		root=build(L,R,nowd);
	}
	
	void insert(int o,int k,int nowd)
	{
		int p=a[o].x[nowd];
		int p2=a[k].x[nowd];
		
		if (p2<=p) 
		{
			if (a[o].l) 
				insert(a[o].l,k,nowd^1);
			else a[o].l=k;
		}
		else
		{
			if (a[o].r)
				insert(a[o].r,k,nowd^1);		
			else a[o].r=k;
				
		}
		
			
		update(a[o]);	
			
	}
	void _insert(int k,int nowd)
	{
		int p=root;
		insert(root,k,nowd);		
	}
	
	
	node _p;
	int _ans;
	
	void ask_min_dis(int o)
	{
		if (o==0) return;
		_ans=min(_ans,dis(a[o],_p));
		
		int ans1=a[o].l ? dis2(_p,a[a[o].l]) : INF;	// 点p到区域内任意一点的距离的最小值
		int ans2=a[o].r ? dis2(_p,a[a[o].r]) : INF;
		
		
		
		if (ans1<ans2) 
		{
			if(ans1<_ans) ask_min_dis(a[o].l);
			if(ans2<_ans) ask_min_dis(a[o].r);
		}
		else {
			if(ans2<_ans) ask_min_dis(a[o].r);
			if(ans1<_ans) ask_min_dis(a[o].l);
		}
		
		
	}
	
	int _ask(node p)
	{
		_p=p;_ans=INF;
		ask_min_dis(root);
		return _ans; 
	}
	
}S;
int main()
{
	For(i,n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		S.a[i]=node(x,y);
	} 
	S.a[++n]=node(INF,INF);
	S._build(1,n,0);
	return 0;
}

