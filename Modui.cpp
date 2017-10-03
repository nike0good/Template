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
#define MAXN (100010)
#define N (100000)
bitset<100000> f,g;
int b[MAXN],res[MAXN],belong[MAXN],cnt[MAXN]={};
struct node{
	int op,l,r,x,id;
	friend bool operator<(node a,node b) {
		if (belong[a.l] ^ belong[b.l] )
			return belong[a.l] < belong[b.l];
		return a.r<b.r; 
	}
}a[MAXN];
int main()
{
//	freopen("bzoj4810.in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),m=read();
	int BS=sqrt(n);
    For(i,n)
		b[i]=read();
	For(i,m){
        a[i]=node{read(),read(),read(),read(),i};
    }
	For(i,n)
		belong[i]=(i-1)/BS+1;
	sort(a+1,a+m+1);
	int l=0,r=0;
    For(i,m){
        while(l>a[i].l){
            l--,cnt[b[l]]++;f[b[l]]=1;g[100000-b[l]]=1;
        }while(r<a[i].r){
            r++,cnt[b[r]]++;f[b[r]]=1;g[100000-b[r]]=1;
        }while(l<a[i].l){
            cnt[b[l]]--;if(!cnt[b[l]])f[b[l]]=0,g[100000-b[l]]=0;l++;
        }while(r>a[i].r){
            cnt[b[r]]--;if(!cnt[b[r]])f[b[r]]=0,g[100000-b[r]]=0;r--;
        }
		if(a[i].op==1){
            res[a[i].id] = ((f>>a[i].x)&f).any();
        }else if(a[i].op==2){
            res[a[i].id] = ((g>>(100000-a[i].x))&f).any();
        }else{
            for(int j=1;j*j<=a[i].x;j++) if(a[i].x%j==0){
                if (f[j]==1&&f[a[i].x/j]==1) {res[a[i].id]=1;break;}
            }
			if(a[i].x==0&&f[0]) res[a[i].id]=1;
        }
    }
	For(i,m)
		puts(res[i]?"yuno":"yumi");
	return 0;
}

