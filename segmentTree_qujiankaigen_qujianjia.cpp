#include<bits/stdc++.h>
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

#define MAXN (100000+10)
ll mark[MAXN<<2],sum[MAXN<<2],mx[MAXN<<2],mn[MAXN<<2];
void pushUp(int o) {
	sum[o]=sum[Lson] + sum[Rson];
	mx[o]=max(mx[Lson],mx[Rson]);
	mn[o]=min(mn[Lson],mn[Rson]);
}
void pushDown(int o,ll m) {
	if (mark[o]) {
		sum[Lson]+=(m-(m>>1))*mark[o];
		sum[Rson]+=(m>>1)* mark[o];
		mx[Lson]+=mark[o],mx[Rson]+=mark[o];
		mn[Lson]+=mark[o],mn[Rson]+=mark[o];
		mark[Lson]+=mark[o],mark[Rson]+=mark[o];
		mark[o]=0;
	}
} 
void build(int l,int r,int o) {
	mark[o]=0;
	if (l==r) {
		sum[o]=mx[o]=mn[o]=read();
		return;
	}
	int m=(l+r)>>1;
	build(l,m,Lson);
	build(m+1,r,Rson);
	pushUp(o);
}
void update(int l,int r,int o,int L,int R,ll c) {
	if (L<=l&&r<=R) {
		sum[o]+=c*(r-l+1);
		mx[o]+=c,mn[o]+=c;
		mark[o]+=c;
		return;
	}
	pushDown(o,r-l+1);
	int m=(l+r)>>1;
	if (L<=m) update(l,m,Lson,L,R,c);
	if (m<R) update(m+1,r,Rson,L,R,c);
	pushUp(o);
}
ll query(int l,int r,int o,int L,int R) {
	if (L<=l && r<=R) {
		return sum[o];
	}
	pushDown(o,r-l+1);
	int m=(l+r)>>1;
	ll ret=0;
	if (L<=m) ret+=query(l,m,Lson,L,R);
	if (m<R) ret+=query(m+1,r,Rson,L,R);
	return ret;	
}
void gen(int l,int r,int o,int L,int R) {
	if (L<=l && r<=R) {
		if ((mx[o]-mn[o]==1&&(int)sqrt(mx[o])!=(int)sqrt(mn[o]))||mx[o]==mn[o]) {
			ll c=(ll)sqrt(mx[o])-mx[o];
			sum[o]+=c*(r-l+1);
			mx[o]+=c,mn[o]+=c;
			mark[o]+=c;
			return;
		}
	}
	pushDown(o,r-l+1);
	int m=(l+r)>>1;
	if (L<=m) gen(l,m,Lson,L,R);
	if (m<R) gen(m+1,r,Rson,L,R);
	pushUp(o);
}

int main()
{
//	freopen("uoj228.in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),m=read();
	build(1,n,1);
	For(i,m) {
		int op=read(),x=read(),y=read();
		switch(op) {
			case 1:update(1,n,1,x,y,read());break;
			case 2:gen(1,n,1,x,y);break;
			case 3:printf("%lld\n",query(1,n,1,x,y));
		}
	}
	return 0;
}
