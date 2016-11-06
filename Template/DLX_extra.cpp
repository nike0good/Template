#pragma comment(linker, "/STACK:102400000,102400000")  
#include <stdio.h>  
#include <iostream>  
#include <algorithm>  
#include <sstream>  
#include <stdlib.h>  
#include <string.h>  
#include <limits.h>  
#include <string>  
#include <time.h>  
#include <math.h>  
#include <queue>  
#include <stack>  
#include <set>  
#include <map>  
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
#define INF (0x3f3f3f3f)
#define F (100000007)
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
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
int ans=0;
struct DLX {
	#define MAXNode (1000000+10)
	#define maxn (1000000+10)
	#define maxm (1000) 
	int L[MAXNode],R[MAXNode],U[MAXNode],D[MAXNode];
	int sz,col[MAXNode],S[maxm],H[maxn];
	bool vis[maxm];
	void init(int m) {
		Rep(i,m+1) {
			L[i] = i-1;
			R[i] = i+1;
			U[i] = D[i] =i;
			S[i] = 0;
		} 
		memset(H,-1,sizeof(H));
		L[0]=m; R[m] = 0;
		sz=m+1;
	} 
	#define FOR(i,A,s) for(int i=A[s];i!=s;i=A[i])   
	void remove(int c) {
		FOR(i,D,c) {
			L[R[i]] = L[i];
			R[L[i]] = R[i];
		}
	} 
	void resume(int c) {
		int i; 
		for(int i=U[c];i!=c;i=U[i]) {
			L[R[i]] = R[L[i]] = i;
		}
	} 
	void link(int r,int c) {
		U[sz] = c;
		D[sz] = D[c];
		U[D[c]] = sz;
		D[c] = sz;
		if (H[r]==-1) { H[r]=L[sz]=R[sz]=sz;	}
		else {
			L[sz] =H[r];
			R[sz] = R[H[r]];
			L[R[H[r]]] = sz;
			R[H[r]] = sz;
		} 
		S[c]++ ; col[sz++]=c;
	} 
	int A() {
		MEM(vis)
		int res=0;
		FOR(i,R,0) {
			if (!vis[i]) {
				res++;
				vis[i] = 1;
				FOR(j,D,i) FOR(k,R,j) {
					vis[col[k]]=1;
				} 
			} 
		} 
		return res;
	}
	void dfs(int d) {
		if (!R[0])  {
			ans=min(ans,d);
		} else if (d+A()<ans) {
			int c=R[0];
			FOR(i,R,0) {
				if (S[i]<S[c]) c=i;
			} 
			FOR(i,D,c) {
				remove(i);
				FOR(j,R,i) remove(j);
				dfs(d+1);
				FOR(j,L,i) resume(j);
				resume(i);
			} 
		} 
 	} 
}solver; 
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	
	return 0;
}

