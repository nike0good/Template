#include<cstdio>
#include<cctype>
#include<iostream>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=Pre[x];p;p=Next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=Next[p])  
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
#define MAXN (500000+10)
ll cover[MAXN<<2],lsum[MAXN<<2],rsum[MAXN<<2],msum[MAXN<<2];
void pushUp(int o,int m) {
	lsum[o]=lsum[Lson];
	rsum[o]=rsum[Rson];
	if (lsum[o]==m-(m>>1)) lsum[o]+=lsum[Rson];
	if (rsum[o]==(m>>1)) rsum[o]+=rsum[Lson];
	msum[o]=max(msum[Lson], max(msum[Rson], rsum[Lson]+lsum[Rson]));
}
void pushDown(int o,ll m) {
	if (cover[o]!=-1) {
		cover[Lson]=cover[Rson]=cover[o];
		msum[Lson]=lsum[Lson]=rsum[Lson]=(m-(m>>1))*cover[o];
		msum[Rson]=lsum[Rson]=rsum[Rson]=(m>>1)*cover[o];
		cover[o]=-1;
	}
} 
void build(int l,int r,int o) {
	cover[o]=-1;
	msum[o]=lsum[o]=rsum[o]=r-l+1;
	if (l==r) {
		return;
	}
	int m=(l+r)>>1;
	build(l,m,Lson);
	build(m+1,r,Rson);
	pushUp(o,r-l+1);
}
void update(int l,int r,int o,int L,int R,int c) {
	if (L<=l&&r<=R) {
		cover[o]=c;
		msum[o]=lsum[o]=rsum[o]=(r-l+1)*c;
		return;
	}
	pushDown(o,r-l+1);
	int m=(l+r)>>1;
	if (L<=m) update(l,m,Lson,L,R,c);
	if (m<R) update(m+1,r,Rson,L,R,c);
	pushUp(o,r-l+1);
}
int query(int l,int r,int o,int w) {
	if (l==r) return l;
	pushDown(o,r-l+1);
	int m=(l+r)>>1;
	if (msum[Lson]>=w) return query(l,m,Lson,w);
	else if (rsum[Lson]+lsum[Rson]>=w) return m-rsum[Lson]+1;
	return query(m+1,r,Rson,w);	
}
int main()
{
//	freopen("poj3667.in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),m=read();
	build(1,n,1);
	while(m--) {
		int op; int a,b;
		scanf("%d%d",&op,&a);
		if (op==1) {
			if (msum[1]<a) puts("0");
			else {
				int p=query(1,n,1,a);
				cout<<p<<endl;
				update(1,n,1,p,p+a-1,0);
			} 
		} else {
			int b=read();
			update(1,n,1,a,a+b-1,1);
		}
	}	
	return 0;
}

