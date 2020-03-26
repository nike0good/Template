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
#define MAXN (2000+10)
struct IntervalTree2D{
	int Max[MAXN][MAXN],Min[MAXN][MAXN],n,m;
	int xo,xleaf,x1,y1,x2,y2,x,y,v,vmax,vmin;
	void query1D(int o,int L,int R) {
		if (y1<=L&&R<=y2) {
			vmax=max(Max[xo][o],vmax); 
			vmin=min(Min[xo][o],vmin);
		} else {
			int M=(L+R)>>1;
			if (y1<=M) query1D(Lson,L,M);
			if (M<y2) query1D(Rson,M+1,R);
		}
	}
	void query2D(int o,int L,int R) {
		if (x1<=L&&R<=x2) {
			xo=o; query1D(1,1,m);
		} else {
			int M=(L+R)>>1;
			if (x1<=M) query2D(Lson,L,M);
			if (M<x2) query2D(Rson,M+1,R);
		}
	}
	void modify1D(int o,int L,int R) {
		if (L==R) {
			if (xleaf) { Max[xo][o] = Min[xo][o] = v; return ;}
			Max[xo][o]=max(Max[xo<<1][o],Max[(xo<<1)|1][o]);
			Min[xo][o]=min(Min[xo<<1][o],Min[(xo<<1)|1][o]);
		} else {
			int M=(L+R)>>1;
			if (y<=M) modify1D(Lson,L,M);
			else modify1D(Rson,M+1,R);	
			Max[xo][o]=max(Max[xo][Lson],Max[xo][Rson]);
			Min[xo][o]=min(Min[xo][Lson],Min[xo][Rson]);
		}
	}
	void modify2D(int o,int L,int R) {
		if (L==R) {
			xo=o; xleaf=1;modify1D(1,1,m); return;
		}
		int M=(L+R)>>1;
		if (x<=M) modify2D(Lson,L,M);
		else modify2D(Rson,M+1,R);
		xo=o; xleaf=0; modify1D(1,1,m);
	}
	void query(){vmax=-INF,vmin=INF; query2D(1,1,n);}
}S;
int main()
{
//	freopen("uva11297.in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),m=n;
	S.n=n,S.m=m;
	For(i,n) For(j,m) {
		S.v=read();S.x=i,S.y=j;
		S.modify2D(1,1,n);
	}
	int q=read();
	while(q--) {
		char s[10];
		cin>>s;
		if (s[0]=='q') {
			S.x1=read(),S.y1=read(),S.x2=read(),S.y2=read();
			S.query();
			cout<<S.vmax<<' '<<S.vmin<<endl;
		} else {
			S.x=read(),S.y=read(),S.v=read();
			S.modify2D(1,1,n);
		}
	}
	return 0;
}

