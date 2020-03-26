#include<iostream>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cstring> 
#include<functional>
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
typedef long double ll;
typedef long double ld;
typedef unsigned long long ull;
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
ld sqr(ld a){return a*a;}
#define MAXN (200000+10)
class P{
public:
	ld x,y;
	int id; 
	P(){}
	P(ld x,ld y):x(x),y(y){}
	friend long double dis2(P A,P B){return sqr(A.x-B.x)+sqr(A.y-B.y);	}
	friend long double dis(P A,P B){return sqrt(dis2(A,B));	}
	friend bool operator<(P A,P B) {
		return A.x<B.x;
	}
}a[MAXN];
int t[MAXN]; 
int cmp(const void *x,const void *y) {
	return a[*(int*)x].y-a[*(int*)y].y;
}
ld bsearch(int l,int r) {
	int m=(l+r)/2;
	if (l==r) return 1e30;
	
	ld d=min(bsearch(l,m),bsearch(m+1,r)); 
	
	int k=0;
	Fork(i,l,r) {
		if (fabs(a[m].x-a[i].x)<=d) {
			t[++k]=i;
		}
	}
	qsort(t+1,k,sizeof(int),cmp);
	
	For(i,k) {
		Fork(j,i+1,min(k,i+7)) {
			if (a[t[j]].y-a[t[i]].y>d) break;
			if (a[t[i]].id!=a[t[j]].id) d=min(d,dis(a[t[i]],a[t[j]]));
		}
	}
	return d;
} 
int main()
{
//	freopen("Closest_Pair.in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while(T--) {
		int n=read();
		For(i,2*n) a[i].x=read(),a[i].y=read();
		For(i,2*n) a[i].id=i<=n;
		
		sort(a+1,a+1+2*n);
		cout<<setiosflags(ios::fixed)<<setprecision(3);
		cout<<bsearch(1,2*n)<<endl;
	}	

	return 0;
}
