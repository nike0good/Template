#include<bits/stdc++.h> 
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,0x3f,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define MEMx(a,b) memset(a,b,sizeof(a));
#define INF (0x3f3f3f3f)
#define F (1000000007)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case #%d: %lld\n",kcase,ans);
#define PRi(a,n) For(i,n-1) cout<<a[i]<<' '; cout<<a[n]<<endl;
#define PRi2D(a,n,m) For(i,n) { \
						For(j,m-1) cout<<a[i][j]<<' ';\
						cout<<a[i][m]<<endl; \
						} 
#pragma comment(linker, "/STACK:102400000,102400000")
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return ((a-b)%F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
#define MAXN (5000000)
struct node{
    int sum,lmax,rmax;
    node(){};
    node(int s,int l,int r):sum(s),lmax(l),rmax(r){}; 
    friend node operator+(node a,node b) {
    	return node(a.sum+b.sum,max(a.lmax,a.sum+b.lmax),max(b.rmax,b.sum+a.rmax));
    }
}seg[MAXN],z;
int lc[MAXN],rc[MAXN],tot=0,T[MAXN]; 
void build(int l,int r,int &rt){
    rt=++tot;
    if(l==r){	seg[rt]=node(1,1,1);	return;}
    int m=l+r>>1;
    build(l,m,lc[rt]);  build(m+1,r,rc[rt]);
    seg[rt]=seg[lc[rt]]+seg[rc[rt]];
}
void modify(int p,int k,int v,int l,int r,int &rt){
    rt=++tot;
    lc[rt]=lc[p];   rc[rt]=rc[p];
    if(l==r){   seg[rt]=node(v,v,v);    return;}
    int m=l+r>>1;
    if(k<=m) modify(lc[p],k,v,l,m,lc[rt]);
    else        modify(rc[p],k,v,m+1,r,rc[rt]);
    seg[rt]=seg[lc[rt]]+seg[rc[rt]];
}
node ask(int L,int R,int l,int r,int rt){
    if(L>R)  return node(0,0,0); 
    if(L==l&&r==R)  return seg[rt];
    int m=l+r>>1;
    if (R<=m) return ask(L,R,l,m,lc[rt]);
    else if(L>m) return ask(L,R,m+1,r,rc[rt]);
    else return ask(L,m,l,m,lc[rt])+ask(m+1,R,m+1,r,rc[rt]);
}
int a[MAXN],q[4],n;
pair<int,int> p[MAXN];
inline int check(int k){
    return ask(q[0],q[1],0,n-1,T[k]).rmax+ask(q[1]+1,q[2]-1,0,n-1,T[k]).sum+ask(q[2],q[3],0,n-1,T[k]).lmax	;
}
int main()
{
//	freopen("bzoj3744.in","r",stdin);
//	freopen(".out","w",stdout);
	
	n=read();
	Rep(i,n) a[i]=read();
	Rep(i,n) p[i]=mp(a[i],i);
	sort(p,p+n);
	build(0,n-1,T[0]);
	For(i,n-1) modify(T[i-1],p[i-1].se,-1,0,n-1,T[i]);
	
	int x=0,Q=read();
	while(Q--) {
		Rep(i,4) q[i]=(read()+x)%n;
		sort(q,q+4);
		int l=0,r=n-1,ans=0;
		while(l<=r) {
			int m=(l+r)/2;
			if (check(m)>=0) l=m+1,ans=m;else r=m-1;
		}	
		x=p[ans].fi;
		printf("%d\n",x);
	}
	return 0;
}

