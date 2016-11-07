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
#define MAXN (200000+10)
#define fac 0.65
typedef long long ll;
int n;

int cmp_d=0;
class node
{
public:
	int x[2];
	int l,r,minv[2],maxv[2];
	int w,sumv,siz;
	node(){}
	node(int a,int b,int _w){l=r=0; siz=1; w=sumv=_w; x[0]=a,x[1]=b; Rep(i,2) minv[i]=maxv[i]=x[i];}
	int& operator[](int i){return x[i];	} 
};

int cmp(node a,node b){return a[cmp_d]<b[cmp_d];	}


int cmp2(int i,int j); 

int p;
char c;
int read()
{
	while (c=getchar(),!isdigit(c));
	p=c-'0';
	while (isdigit(c=getchar())) p=p*10+c-'0'; return p;
}
class KD_Tree
{
public:	
	node a[MAXN];
	
	void update(node& o)
	{
		o.sumv=o.w;
		o.minv[0]=o.maxv[0]=o.x[0];o.minv[1]=o.maxv[1]=o.x[1]; 
		o.siz=1;
		if (o.l)
		{
			node p=a[o.l];
			Rep(i,2) o.minv[i]=min(o.minv[i],p.minv[i]);
			Rep(i,2) o.maxv[i]=max(o.maxv[i],p.maxv[i]);	
			o.sumv+=p.sumv;
			o.siz+=p.siz;
		}
		if (o.r)
		{
			node p=a[o.r];
			Rep(i,2) o.minv[i]=min(o.minv[i],p.minv[i]);
			Rep(i,2) o.maxv[i]=max(o.maxv[i],p.maxv[i]);	
			o.sumv+=p.sumv;
			o.siz+=p.siz;
		}
		
	}

	int build(int L,int R,int nowd,node *a)
	{
		int m=(L+R)>>1;
	
		cmp_d=nowd;
		nth_element(a+L+1,a+m+1,a+R+1,cmp);
		
		if (L^m) a[m].l=build(L,m-1,nowd^1,a);
		if (R^m) a[m].r=build(m+1,R,nowd^1,a);
		
		update(a[m]);
		
		return m;
		
	} 
	
	int po[MAXN],pt;
	void dfs(int x)
	{
		po[++pt]=x;
		if (a[x].l) dfs(a[x].l);
		if (a[x].r) dfs(a[x].r);
	}
	
	int rebuild(int L,int R,int nowd)
	{
		int m=(L+R)>>1;
	
		cmp_d=nowd;
		nth_element(po+L+1,po+m+1,po+R+1,cmp2);
		int now=po[m];
		a[now].l=a[now].r=0;
		if (L^m) a[now].l=rebuild(L,m-1,nowd^1);
		if (R^m) a[now].r=rebuild(m+1,R,nowd^1);
		
		update(a[now]);
		
		return now;
		
	} 
	
	int root;
	void _build(int L,int R,int nowd) //1-n的节点 至少为1 
	{
		root=build(L,R,nowd,a);
	}
	
	int insert(int o,int k,int nowd)
	{
		if (!o) return k;
		int p=a[o].x[nowd];
		int p2=a[k].x[nowd];
		int nx=0;
		if (p2<=p) 
		{
			a[o].l=insert(a[o].l,k,nowd^1);
			nx=a[o].l;
		}
		else
		{
			a[o].r=insert(a[o].r,k,nowd^1);
			nx=a[o].r;
		}	
		update(a[o]);	
		
		if (a[nx].siz>(double)a[o].siz*fac)
		{
			pt=0,dfs(o);
			o=rebuild(1,pt,nowd);	
			
		}
		return o;
	}
	void _insert(int k,int nowd)
	{
		int p=root;
		root = insert(root,k,nowd);		
	}
	
	
	int _x1,_y1,_x2,_y2;
	int _ans;
	
	void ask(int o)
	{
		if (o==0) return;
		
		if (_x1<=a[o].minv[0] && a[o].maxv[0]<=_x2 && _y1<=a[o].minv[1] && a[o].maxv[1]<=_y2 ) {
			_ans+=a[o].sumv;return;
		}		
		if (_x1<=a[o].x[0] && a[o].x[0]<=_x2 && _y1<=a[o].x[1] && a[o].x[1]<=_y2 ) {
			_ans+=a[o].w;
		}		
		
		if (a[o].l) {
			int p=a[o].l;
			if (a[p].minv[0]<=_x2 && _x1<=a[p].maxv[0] && a[p].minv[1]<=_y2 && _y1<=a[p].maxv[1] ) 
				ask(p);
		}
		if (a[o].r) {
			int p=a[o].r;
			if (a[p].minv[0]<=_x2 && _x1<=a[p].maxv[0] && a[p].minv[1]<=_y2 && _y1<=a[p].maxv[1] ) 
				ask(p);
		}
		
		
	}
	
	int _ask(int x1,int y1,int x2,int y2)
	{
		_x1=x1;_y1=y1;_x2=x2;_y2=y2;
		;_ans=0;
		ask(root);
		return _ans; 
	}
	
}S;

int cmp2(int i,int j){return S.a[i].x[cmp_d]<S.a[j].x[cmp_d];	}
	
int main()
{
	int N=read();
	
	n=0;
	S.a[++n]=node(N/2,N/2,0);
	S._build(1,n,0);
	
	int p;
	int ans=0;
	int x,y,A;
	int x1,y1,x2,y2;
		
	while (scanf("%d",&p)==1 && p^3)
	{
//		cout<<"t"<<endl;
		if (p==1) {
			x=read(),y=read(),A=read();
			x^=ans;y^=ans;A^=ans;
			S.a[++n]=node(x,y,A);
			S._insert(n,0);
		} else {
			x1=read(),y1=read(),x2=read(),y2=read();
			x1^=ans,y1^=ans,x2^=ans,y2^=ans;
			ans=S._ask(x1,y1,x2,y2);
			printf("%d\n",ans);	
		}
		
	} 
	return 0;
}

