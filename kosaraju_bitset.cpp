#include<bits/stdc++.h> 
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
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
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
int n,tot=0;
#define MAXN (200+10)
#define MAXM (80000+10)
const int BLOCK = 4;
int LIM;
struct Bitset {
    ull c[BLOCK] ;
    bool none () {
        for ( int i = 0 ; i < LIM ; ++ i ) {
            if ( c[i] ) return 0 ;
        }
        return 1 ;
    }
    void set () {
        for ( int i = 0 ; i < LIM ; ++ i ) {
            c[i] = ~0ull ;
        }
    }
    void reset () {
        for ( int i = 0 ; i < LIM ; ++ i ) {
            c[i] = 0 ;
        }
    }
    void flip ( int x ) {
        c[x >> 6] ^= 1ull << ( x & 63 ) ;
    }
    ull& operator [] ( const int index ) {
        return c[index] ;
    }
}G[MAXN<<1],V[MAXN<<1],vis[2] ;
ull pos[MAXN],val[MAXN];
int scc[MAXN<<1],scc_cnt=0;	
vi S;
void add1 ( int x , int y ) { //·­×ªx->y 
    G[x << 1].flip ( y ) ;
    G[y << 1].flip ( x ) ;
    V[x << 1 | 1].flip ( y ) ;
    V[y << 1 | 1].flip ( x ) ;
}

void add2 ( int x , int y ) { //·­×ª!x->y 
    G[x << 1 | 1].flip ( y ) ;
    G[y << 1 | 1].flip ( x ) ;
    V[x << 1].flip ( y ) ;
    V[y << 1].flip ( x ) ;
}

void dfs1 ( int u , int o ) {
    vis[o].flip ( u ) ;
    for ( int i = 0 ; i < LIM ; ++ i ) while ( 1 ) {
        ull v = vis[o ^ 1][i] & G[u << 1 | o][i] ;
        if ( !v ) break ;
        dfs1 ( i << 6 | __builtin_ctzll ( v ) , o ^ 1 ) ;
    }
    S.push_back ( u << 1 | o ) ;
}

void dfs2 ( int u , int o ) {
    vis[o].flip ( u ) ;
    scc[u << 1 | o] = scc_cnt ;
    for ( int i = 0 ; i < LIM ; ++ i ) while ( 1 ) {
        ull v = vis[o ^ 1][i] & V[u << 1 | o][i] ;
        if ( !v ) break ;
        dfs2 ( i << 6 | __builtin_ctzll ( v ) , o ^ 1 ) ;
    }
}

pair<int ,pi > edges[MAXM];
void init() {
	Rep(i,n) {
		G[i<<1].reset();
		V[i<<1].reset();
		G[i<<1 | 1].reset();
		V[i<<1 | 1].reset();
		pos[i]=i>>6;
		val[i]=1ull<<(i&63);
	}

}
int check() {
	S.clear();
	Rep(i,2) vis[i].reset();
	Rep(i,n) {
		vis[0][pos[i]] |= val[i];
		vis[1][pos[i]] |= val[i];
	}
	Rep(i,LIM) while(vis[0][i]) {
		dfs1(i<<6|__builtin_ctzll ( vis[0][i] ) , 0 ) ;
	}
	
	Rep(i,2) vis[i].reset();
	Rep(i,n) {
		vis[0][pos[i]] |= val[i];
		vis[1][pos[i]] |= val[i];
	}
	
	scc_cnt=0;
	RepD(i,S.size()-1) {
		int o=S[i]&1,x=S[i]>>1;
		if (vis[o][pos[x]] & val[x]) {
			++scc_cnt;
			dfs2(x,o);
		}
	} 

	Rep(i,n) if (scc[i<<1]==scc[i << 1 | 1]) {
		return 0;
	}
	return 1;
}
int main()
{
//	freopen("F.in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),tot=0;
	ll ans=2e9;
	init();
	LIM=(n-1)/64+1;
	For(i,n) {
		Fork(j,i+1,n) {
			edges[++tot]=mp(read(),mp(i-1,j-1));
		}
	}
	sort(edges+1,edges+1+tot);
	
	For(i,tot) 
		add1(edges[i].se.fi,edges[i].se.se);
			
	for(int i=0,j=tot;i<=j;i++) {
		while(i&&i<=j) {
			add1(edges[i].se.fi,edges[i].se.se);
			if (edges[i].fi!=edges[i+1].fi) break;
			++i;
		}
		while(i<j) {
			add2(edges[j].se.fi,edges[j].se.se);
			if (check()) --j;
			else {
				add2(edges[j].se.fi,edges[j].se.se);
				break;
			}
		} 
		ans=min(ans,(ll)edges[i].fi+edges[j].fi);
	}
	cout<<ans<<endl;
	return 0;
}
