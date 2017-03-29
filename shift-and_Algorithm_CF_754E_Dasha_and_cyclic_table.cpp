#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdlib>
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
#define ALL(x) (x).begin(),(x).end()

#define MAXN (803)
class shift_and{
public:
	int n,r;
	bitset<MAXN> v,f[26],c;
	int s[MAXN],s2[MAXN];
	void prework() {
		//s s2 n r
	}
	bool b[MAXN];
	void work() {
		Rep(i,26) f[i].reset();	v.reset(); c.reset();
		Rep(i,r) if (0<=s2[i]&&s2[i]<26) f[s2[i]][i+1]=1;
		else c[i+1]=1;
		Rep(i,26) f[i]|=c;
		v[0]=1;
		Rep(i,n) {
			v=v<<1&f[s[i]];
			v[0]=1;
			b[i]=v[r];
		}
	}	
}S;

char A[MAXN][MAXN],B[MAXN][MAXN];
int n,m,r,c;

bool b[1000][1000];

int main()
{
//	freopen("E.in","r",stdin);
	cin>>n>>m;
	Rep(i,n) cin>>A[i];
	
	cin>>r>>c;
	Rep(i,r) cin>>B[i];
	
	Rep(i,n+r) Rep(j,c+m)
		A[i][j]=A[i%n][j%m];	
	
	
	memset(b,-1,sizeof(b));	

	S.n=c+m,S.r=c;
	Rep(k,r) Rep(i,n)  {
		Rep(j,c+m) S.s[j]=A[i][j]-'a';
		Rep(j,c) S.s2[j]=B[k][j]-'a';
		S.work();
		Fork(l,c-1,c+m-2) if (!S.b[l]) {
			b[((i-k)%n+n)%n][((l-c+1)%m+m)%m]=0;
		}
	}
	Rep(i,n) {
		Rep(j,m) {
			putchar(b[i][j]?'1':'0');
		}puts("");
	}
	
	return 0;
}

