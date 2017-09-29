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
#define pb push_back
#define mp make_pair
#pragma comment(linker, "/STACK:1024000000,1024000000") 
typedef long long ll;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
inline ull read()
{
	ull x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
struct node{
	ull x0,x1;
	node(){}
	node(ull _a,ull _b):x0(_a),x1(_b){}
	friend node operator+(node a,node b) {
		node c;
		c.x0=(a.x0&b.x1)|((~a.x0)&b.x0);  
		c.x1=(a.x1&b.x1)|((~a.x1)&b.x0);  
		return c;
	}
	node(int op,ull x) {
		switch(op) {
			case 1:{
				x0=0&x;
				x1=(~0)&x;
				break;
			}
			case 2:{
				x0=0|x;
				x1=(~0)|x;
				break;
			}
			case 3:{
				x0=0^x;
				x1=(~0)^x;
				break;
			}
		}
	}
};

int op[MAXN]; 
ull a[MAXN];

node vl[MAXN<<2],vr[MAXN<<2];
void pushup(int o) {
	vl[o]=vl[Lson]+vl[Rson];
	vr[o]=vr[Rson]+vr[Lson];
}
void build(int l,int r,int o) {
	if (l==r) {
		vl[o]=vr[o]=node(op[l],a[l]);	return ;
	}
	int m=(l+r)>>1;
	build(l,m,Lson),build(m+1,r,Rson);
	pushup(o);
}
void update(int l,int r,int o,int p) {
	if (l==r) {
		vl[o]=vr[o]=node(op[l],a[l]);	return ;
	}
	int m=(l+r)>>1;
	if (p<=m) update(l,m,Lson,p); 
	else update(m+1,r,Rson,p);
	pushup(o);
}
node queryL(int l,int r,int o,int L,int R) {
	if(L<=l && r<=R ) return vl[o];
	int m=(l+r)>>1;
	if(R<=m) return queryL(l,m,Lson,L,R);
	else if(L>m) return queryL(m+1,r,Rson,L,R); 
	else return queryL(l,m,Lson,L,R)+queryL(m+1,r,Rson,L,R);
}
node queryR(int l,int r,int o,int L,int R) {
	if(L<=l && r<=R ) return vr[o];
	int m=(l+r)>>1;
	if(R<=m) return queryR(l,m,Lson,L,R);
	else if(L>m) return queryR(m+1,r,Rson,L,R); 
	else return queryR(m+1,r,Rson,L,R)+queryR(l,m,Lson,L,R);
}


int n,m;
struct Tree{
	void mem(){MEM(Pre) siz=1;}
	int edge[MAXM],Next[MAXM],Pre[MAXN],siz;
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
	
	node Ask(int a,int b)
	{
		node vl(3,0),vr(3,0);
		while (top[a]^top[b]) {
			if (dep[top[a]]>dep[top[b]]) {
				vl=vl+queryR(1,n,1,id[top[a]],id[a]);
				a=pre[top[a]];
			} else {
				vr=queryL(1,n,1,id[top[b]],id[b])+vr;
				b=pre[top[b]];
			}
		}	
		if (dep[a]>dep[b]) {
			return vl+queryR(1,n,1,id[b],id[a]) + vr;
		} else {
			return vl+queryL(1,n,1,id[a],id[b])+vr;
		}
	}

}S;
int op2[MAXN];
ull a2[MAXN];
int main()
{
//	freopen("bzoj4811.data","r",stdin);
//	freopen("bzoj4811.out","w",stdout);
	
	n=read(),m=read();int k=read();
	S.mem();
	For(i,n) op2[i]=read(),a2[i]=read();
	For(i,n-1)  {
		S.addedge2(read(),read());
	}
	S.build();
	For(i,n) {
		op[S.id[i]]=op2[i];
		a[S.id[i]]=a2[i];
	}
	build(1,n,1);
	
	For(i,m) {
		ull op=read(),x=read(),y=read(),z=read();
		if (op==1) {
			node t=S.Ask(x,y);
			ull ans=0,now=0;
			RepD(i,k-1) {
				if(t.x0&(1ull<<i)){ 
					ans+=(1ull<<i);
				}else if ((t.x1&(1ull<<i))&&now+(1ull<<i)<=z) {
					ans+=(1ull<<i);
					now+=(1ull<<i);
				}
			}
			printf("%llu\n",ans);
		} else {
			::op[S.id[x]]=y;
			::a[S.id[x]]=z;
			update(1,n,1,S.id[x]);
		}
	}
	return 0;
}

