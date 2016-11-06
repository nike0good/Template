#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
#include<vector>
#include<iomanip> 
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=Pre[x];p;p=Next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=Next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (100000+10)
#define MAXM (200000+10)
#define MAXV (1000+10)
#define pb push_back
#define mp make_pair
#pragma comment(linker, "/STACK:1024000000,1024000000") 
typedef int ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
struct Chain{
	int u,v,w;
	Chain(){}
	Chain(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
};
vector<Chain> a[MAXN];
int n,m;
int edge[MAXM],Next[MAXM],Pre[MAXN],siz=1;
void addedge(int u,int v)
{
	edge[++siz]=v;
	Next[siz]=Pre[u];
	Pre[u]=siz;
}
void addedge2(int u,int v){addedge(u,v);addedge(v,u);}

bool vis[MAXN]; 
int cnt,id[MAXN];
int son[MAXN],dep[MAXN],sz[MAXN],top[MAXN],pre[MAXN],q[MAXN];
void build()
{
	MEM(vis) cnt=0; MEM(id)
	MEM(son) MEM(dep) MEM(sz) MEM(top) MEM(pre) MEM(q) 
	int r=1;
	vis[dep[1]=q[1]=1]=1;
	For(i,r)
	{
		int u=q[i];
		Forp(u)
		{
			int v=edge[p];
			if (vis[v]) continue; else vis[v]=1;
			dep[ q[++r]=v ]=dep[u]+1;
			pre[v]=u;
		}
	}
	ForD(i,r) {
		sz[pre[q[i]]] += ++sz[q[i]];
		if (sz[son[pre[q[i]]]]<sz[q[i]] ) son[pre[q[i]]] = q[i];
	}
	For(i,r) {
		if (!top[q[i]])
			for(int x=q[i];x;x=son[x]) {
				top[x]=q[i];
				id[x]=++cnt; 
			}
	}
	
}
int lca(int a,int b)
{
	while(1) {
		if (top[a]==top[b]) return dep[a]<=dep[b] ? a:b;
		if (dep[top[a]]<dep[top[b]]) swap(a,b);
		a=pre[top[a]];
	}
}


#define MEM2(a,i) memset(a,i,sizeof(a));
class SegmentTree  
{  
    ll a[MAXN*4],minv[MAXN*4],sumv[MAXN*4],maxv[MAXN*4],addv[MAXN*4],setv[MAXN*4];  
    int n;  
public:  
    SegmentTree(){MEM(a) MEM(minv) MEM(sumv) MEM(maxv) MEM(addv) MEM2(setv,-1) }  
    SegmentTree(int _n):n(_n){MEM(a) MEM(minv) MEM(sumv) MEM(maxv) MEM(addv) MEM2(setv,-1) }  
    void mem(int _n)  
    {  
        n=_n;  
        MEM(a) MEM(minv)  MEM(sumv) MEM(maxv) MEM(addv) MEM2(setv,-1)
    }  

    void maintain(int o,int L,int R)  
    {
    	
		sumv[o]=maxv[o]=minv[o]=0;
    	if (L<R) //只考虑左右子树 
		{
			sumv[o]=sumv[Lson]+sumv[Rson];
			minv[o]=min(minv[Lson],minv[Rson]);
			maxv[o]=max(maxv[Lson],maxv[Rson]);
		} //只考虑add操作 
		if (setv[o]>=0) sumv[o]=setv[o]*(R-L+1),minv[o]=maxv[o]=setv[o];
		
		minv[o]+=addv[o];maxv[o]+=addv[o];sumv[o]+=addv[o]*(R-L+1);
    }

	int y1,y2,v;
	void update(int o,int L,int R) //y1,y2,v
	{
		if (y1<=L&&R<=y2) {
			addv[o]+=v;
		}
		else{
			pushdown(o);
			int M=(R+L)>>1;
			if (y1<=M) update(Lson,L,M); else maintain(Lson,L,M); 
			if (M< y2) update(Rson,M+1,R); else maintain(Rson,M+1,R);
		}
		
		maintain(o,L,R); 
		
	}
	void update2(int o,int L,int R) 
	{
		if (y1<=L&&R<=y2) {
			setv[o]=v;addv[o]=0;
		}
		else{
			pushdown(o);
			int M=(R+L)>>1;
			if (y1<=M) update2(Lson,L,M); else maintain(Lson,L,M); //维护pushodown，再次maintain 
			if (M< y2) update2(Rson,M+1,R); else maintain(Rson,M+1,R);
		}
		
		maintain(o,L,R); 
	}
	
	void pushdown(int o) 
	{
		if (setv[o]>=0)
		{
			setv[Lson]=setv[Rson]=setv[o]; 
			addv[Lson]=addv[Rson]=0;
			setv[o]=-1;
		}
		if (addv[o])
		{
			addv[Lson]+=addv[o];
			addv[Rson]+=addv[o];
			addv[o]=0;
		} 
	}
	ll _min,_max,_sum; 
	
	void query2(int o,int L,int R,ll add)
	{
		if (setv[o]>=0)
		{
			_sum+=(setv[o]+addv[o]+add)*(min(R,y2)-max(L,y1)+1);
			_min=min(_min,setv[o]+addv[o]+add);
			_max=max(_max,setv[o]+addv[o]+add); 
		} else if (y1<=L&&R<=y2)
		{
			_sum+=sumv[o]+add*(R-L+1);
			_min=min(_min,minv[o]+add);
			_max=max(_max,maxv[o]+add); 
		} else {
		//	pushdown(o);
			int M=(L+R)>>1;
			if (y1<=M) query2(Lson,L,M,add+addv[o]);// else maintain(Lson,L,M); 
			if (M< y2) query2(Rson,M+1,R,add+addv[o]);// else maintain(Rson,M+1,R);
		}
		//maintain(o,L,R);
	}
	
	void query(int o,int L,int R,ll add) //y1,y2
	{
		if (y1<=L&&R<=y2)
		{
			_sum+=sumv[o]+add*(R-L+1);
			_min=min(_min,minv[o]+add);
			_max=max(_max,maxv[o]+add); 
		} 
		else{
			int M=(R+L)>>1;
			if (y1<=M) query(Lson,L,M,add+addv[o]);
			if (M< y2) query(Rson,M+1,R,add+addv[o]);
		}		
	}

	void add(int l,int r,ll v)
	{
		if (l>r) swap(l,r);
		y1=l,y2=r;this->v=v;
		update(1,1,n);
	}
	void set(int l,int r,ll v)
	{
		y1=l,y2=r;this->v=v;
		update2(1,1,n);
	}
	ll ask(int l,int r,int b=1)
	{
		if (l>r) swap(l,r);
		_sum=0,_min=INF,_max=-1;
		y1=l,y2=r;
		query2(1,1,n,0);
		switch(b)
		{
			case 1:return _sum;
			case 2:return _min;
			case 3:return _max;
			default:break;
		}		
	}
	void print()
	{
		For(i,n)
			cout<<ask(i,i,1)<<' ';
		cout<<endl;
	
	}

    //先set后add 
}S[2];   //sum & dp

ll Ask(int a,int b,int f)
{
	ll ans=0;
	while (top[a]^top[b]) {
		if (dep[top[a]]<dep[top[b]]) swap(a,b);
		ans+=S[f].ask(id[top[a]],id[a],1);
		a=pre[top[a]];
	}
	if (dep[a]>dep[b]) swap(a,b);
	ans+=S[f].ask(id[a],id[b],1);
	return ans;
}



int main()
{
//	freopen("hdu5293.in","r",stdin);
	

	return 0;
}

