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
#define F (10086)
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
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
#define MAXN (100000+10)
int n;
ll a[MAXN];
void gauss(int n) {
	For(i,n) {
		Fork(j,i+1,n) if (a[j]>a[i]) swap(a[i],a[j]);
		if (!a[i]) return ;
		For(k,n) if (i^k) a[k]=min(a[k],a[k]^a[i]);			
	}				
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	For(i,n) a[i]=read();
	gauss(n);
	return 0;
}

