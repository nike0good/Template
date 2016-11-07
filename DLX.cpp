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
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 

struct DLX {
	#define maxn (10000000+10)
	#define MAXNode (10000000+10)
	#define maxr (10000000)
	int n, sz;
	int S[maxn];
	int row[MAXNode],col[MAXNode];
	int L[MAXNode],R[MAXNode],U[MAXNode],D[MAXNode];
	int ansd, ans[maxr];
	
	void init(int n) {
		this->n = n;
		Rep(i,n+1) {
			U[i] = D[i] = i ; L[i]=i-1; R[i]=i+1;
		}
		R[n]=0; L[0]=n;
		sz=n+1;
		MEM(S)
	}
	
	void addRow(int r, vi columns) {
		int fir = sz;
		int cSz=columns.size();
		Rep(i,cSz) {
			int c=columns[i];
			L[sz] = sz-1; R[sz] = sz+1; D[sz] = c; U[sz] = U[c];
			D[ U[c] ] =sz; U[c]=sz;
			row[sz] = r; col[sz] = c;
			S[c]++; sz++;
		}
		R[sz-1]=fir; L[fir] = sz-1;
	}
	#define FOR(i,A,s) for(int i=A[s];i!=s;i=A[i])
	void remove(int c) {
		L[R[c]] = L[c];
		R[L[c]] = R[c];
		FOR(i,D,c) 
			FOR(j,R,i) {
				U[D[j]] = U[j]; D[U[j]] = D[j]; --S[col[j]];
			}
	} 
	void restore(int c) {
		FOR(i,U,c) 
			FOR(j,L,i) {
				++S[col[j]];
				U[D[j]] = j;
				D[U[j]] = j;
			} 
		L[R[c]]=c;
		R[L[c]]=c;
	} 
	bool dfs(int d) {
		if ( R[0] == 0) {
			ansd = d;
			return 1;
		} 
		int c = R[0];
		FOR(i,R,0) if (S[i] < S[c]) c = i;
		remove(c);
		FOR(i,D,c) {
			ans[d] = row[i];
			FOR(j,R,i) remove(col[j]);
			if (dfs(d+1)) return 1;
			FOR(j,L,i) restore(col[j]);
		} 
		restore(c);
		return 0;
	} 	
	bool solve(vi &v) {
		v.clear();
		if (!dfs(0)) return 0;
		Rep(i,ansd) v.pb(ans[i]);
		return 1;
	}	
};
DLX solver;
char puzzle[16][20];
bool init() {
	Rep(i,16) {
		if (scanf("%s",puzzle[i])!=1) return 0;
	}
	return 1;
}
const int SLOT = 0;
const int ROW = 1;
const int COL = 2;
const int SUB = 3;

int encode(int a,int b,int c) {
	return a*16*16+b*16+c+1;
}
void decode(int code,int &a,int &b,int &c) {
	code--;
	c=code%16; code/=16;
	b=code%16; code/=16;
	a=code;
}
int main()
{
//	freopen("uva1309.in","r",stdin);
//	freopen(".out","w",stdout);
	bool fl=0;
	while(init()) {
		if (fl) puts("");	fl=1;
		solver.init(1024); //列数要初始化  
		Rep(r,16) Rep(c,16) Rep(v,16) { // put v in (r,c)
			if (puzzle[r][c]=='-'||puzzle[r][c]=='A'+v) {
				vi columns;
				columns.pb(encode(SLOT,r,c));
				columns.pb(encode(ROW,r,v));
				columns.pb(encode(COL,c,v));
				columns.pb(encode(SUB,r/4*4+c/4,v));
				solver.addRow(encode(r,c,v),columns);
			} 
		}
		vi ans;
		solver.solve(ans);
		int sz=SI(ans);
		Rep(i,sz) {
			int a,b,c;
			decode(ans[i],a,b,c);
			puzzle[a][b]=c+'A';
		}
		Rep(r,16) puts(puzzle[r]);
	}
	
	
	return 0;
}

