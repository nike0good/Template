#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
using std::sort;
using std::unique; 
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
const int MAXN = 1000000+10;
int n,k;
struct P{
public:
    int x,y,z;
    int v,t;
    P(){v=0;t=0;}
    friend bool operator== (P a,P b) { return a.x==b.x && a.y==b.y && a.z==b.z; }
}a[MAXN];
int b[MAXN],c[MAXN];
inline bool cmp1(P a,P b){return a.x==b.x?(a.y==b.y?a.z<b.z:a.y<b.y):a.x<b.x;}
inline bool cmp2(int i,int j){return (a[i].y==a[j].y?a[i].z<a[j].z:a[i].y<a[j].y);}

int pos[MAXN]={0},T=0,bit[MAXN]={0};
void add(int x,int V){
    for(;x<=k;x+=x&-x)
    {
        if (pos[x]==T) bit[x]+=V; else bit[x]=V;
        pos[x]=T;
    }
} 
int sum(int x){
    int t=0;
    for(;x;x-=x&-x)
        if (pos[x]==T) t+=bit[x];
    return t;
} 

void solve(int l,int r) {
    if (l == r) return ;
    int m=(l+r)>>1,t1=0,t2=0;

    Fork(i,l,m) b[++t1]=i;
    Fork(i,m+1,r) c[++t2]=i;
    sort(b+1,b+1+t1,cmp2);
    sort(c+1,c+1+t2,cmp2);

    ++T;
    for(int i=1,j=1;j<=t2;a[c[j]].t+=sum(a[c[j]].z),j++) {
        while(i<=t1&&a[ b[ i ] ].y<=a [ c [ j ] ].y) add(a[b[i]].z,a[ b[ i ] ].v),i++;
    }
    solve(l,m); solve(m+1,r);
}
int ans[MAXN];
int main()
{
//  freopen("bzoj3262.in","r",stdin);
//  freopen(".out","w",stdout);

    n=read(),k=read();
    For(i,n) a[i].x=read(),a[i].y=read(),a[i].z=read();
    sort(a+1,a+1+n,cmp1);

    int m = 1;
    for(int i=1;i<=n;i++)
        if (a[i]==a[m]) a[m].v++;
        else a[++m]=a[i],a[m].v++; 
    solve(1,m);
    For(i,m) ans[a[i].v+a[i].t-1]+=a[i].v;
    Rep(i,n) printf("%d\n",ans[i]);
    return 0;
}
