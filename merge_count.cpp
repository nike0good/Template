#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
#include<vector>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (10000001)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}

int A[MAXN],t[MAXN];
int fl=0;	
ll merge_count(int l,int r)
{
	int n=r-l+1,m=(l+r)>>1;
	if (n<=1) return 0;
	
	ll cnt=0;
	cnt+=merge_count(l,m);
	cnt+=merge_count(m+1,r);

	int p=l,q=m+1,ai=l;
	while (ai<=r)
	{
		if ( q>r || (p<=m && A[p]<=A[q] ) )
		{
			t[ai++]=A[p++];
		}
		else {
			cnt+=m-p+1;
			t[ai++]=A[q++];
		}
	} 	
	Fork(i,l,r) A[i]=t[i];
	return cnt;
}
int n=10000000;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	For(i,n) A[i]=n-i;
	cout<<merge_count(1,n);
	
	return 0;
}

