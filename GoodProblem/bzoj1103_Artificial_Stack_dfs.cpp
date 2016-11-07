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
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (1000000007)
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case #%d: %I64d\n",kcase,ans);
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
int n,m;
struct BIT{
	#define MAXN ( 2*250000+10)
	ll f[MAXN]; 
	void add(int x,ll v) {
		for(int i=x;i<=2*n;i+=i&(-i)) 
		 		f[i]+=v;
	}
	ll qur(int x) {
		ll v=0;
		for(int i=x;i;i-=i&(-i)) 
		 		v+=f[i];
		return v;
	}
}T;
int tim=0;
ll a[MAXN];
vi edges[MAXN];
int st[MAXN]={0},top=0;
int l[MAXN]={0},r[MAXN],fa[MAXN]={0};
void dfs() {
	st[++top]=1;
	while(top) {
		int now=st[top];
		top--;
		if (!l[now]) {
			l[now]=++tim;
			st[++top]=now;
			Rep(i,SI(edges[now])) {
				int v=edges[now][i];
				if (v^fa[now]) {
					st[++top]=v;
					fa[v]=now;
				}
			}
		} else r[now]=++tim;
	}
}

int main()
{
//	freopen("bzoj1103.in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	For(i,n-1) {
		int u=read(),v=read();
		edges[u].pb(v);
		edges[v].pb(u);
	}	
	dfs();
	MEM(T.f) 
	For(i,n) {
		T.add(l[i],1);T.add(r[i],-1);
	}
	m=read();
	For(i,n+m-1) {
		char op[2];
		scanf("%s",op);
		if(op[0]=='W') {
			printf("%lld\n",T.qur(l[read()])-1);
		} else {
			int u=read(),v=read();
			if (l[u]>l[v]) swap(u,v);
			T.add(l[v],-1);T.add(r[v],1);
		}
	}
	return 0;
}
