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
#define Pr(kcase) printf("Case %d:\n",kcase);
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
const int maxn =60000;
int sum[maxn<<2],a[maxn];
void pushup(int o) {
	sum[o]=sum[Lson]+sum[Rson];
}
void build(int l,int r,int o) {
	if (l==r) {
		sum[o]=a[l];	return ;
	}
	int m=(l+r)>>1;
	build(l,m,Lson),build(m+1,r,Rson);
	pushup(o);
}
void update(int l,int r,int o,int p,int v) {
	if (l==r) {
		sum[o]+=v;  return;
	}
	int m=(l+r)>>1;
	if (p<=m) update(l,m,Lson,p,v); 
	else update(m+1,r,Rson,p,v);
	pushup(o);
}
int query(int l,int r,int o,int L,int R) {
	if(L<=l && r<=R ) return sum[o];
	int m=(l+r)>>1;
	int ret=0;
	if(L<=m) ret+=query(l,m,Lson,L,R);
	if(m<R) ret+=query(m+1,r,Rson,L,R); 
	return ret;
}
int main()
{
//	freopen("hdu1166.in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	For(kcase,T) {	Pr(kcase)
		int n=read();
		For(i,n) a[i]=read();
		build(1,n,1);
		char s[10];
		while(scanf("%s",s)&&s[0]!='E') {
			int p1=read(),p2=read();
			switch(s[0]){
				case'Q':{
					cout<<query(1,n,1,p1,p2)<<endl;
					break;
				}
				default:{
					if (s[0]=='S') p2=-p2;
					update(1,n,1,p1,p2);
				}
			}
		}
	}	
	
	
	return 0;
}

