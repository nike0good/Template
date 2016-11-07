#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
#include<iomanip> 
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<sstream>
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
#define MAXN (600)
#define MAXM (25100)
#define MAXL (10)
struct edge{
	int u,v,w;
	edge(int _u=0,int _v=0,int _w=0):u(_u),v(_v),w(_w){}
};
int n,m;
int a[MAXN][MAXN],dis[MAXN],v[MAXN],vis[MAXN];
int stoer_wagner(int n) {
	int ans=INF;
	For(i,n) v[i]=i;
	while(n>1) {
		int p=0,last=0;
		Fork(i,2,n) {
			dis[v[i]] = a[v[1]][v[i]];
			if (dis[v[i]]>dis[v[p]]) p=i;
		}
		MEM(vis)
		vis[v[1]]=1;
		Fork(i,2,n) {
			if (i==n) {
				ans=min(ans,dis[v[p]]);
				For(j,n) a[v[j]][v[last]] = a[v[last]][v[j]] += a[v[j]][v[p]];
				v[p]=v[n--];
			}
			vis[v[last=p]]=1; p=-1;
			Fork(j,2,n) if (!vis[v[j]]) {
				dis[v[j]] +=a[v[last]][v[j]];
				if (p==-1 || dis[v[p]]<dis[v[j]]) p=j;
			}
		}	
	}
	return ans;
}
int main()
{
//	freopen("E.in","r",stdin);
//	freopen(".out","w",stdout);
	while(cin>>n>>m) {
		MEM(a)
		Rep(i,m) {
			int u=read(),v=read(),w=read();
			++u,++v;
			if (u!=v) a[u][v]+=w,a[v][u]+=w;
		}
		cout<<stoer_wagner(n)<<endl;
	}
	return 0;
}
