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
#define MAXN (500000+10)
struct link  
{  
    int pre,next;  
}l[MAXN];  
void del(int x)  
{  
    l[l[x].pre].next=l[x].next;  
    l[l[x].next].pre=l[x].pre;    
}  
void del(int x,int y)  //要求x,y同时在链表中 
{  
	if (x>y) swap(x,y);
    l[l[x].pre].next=l[y].next;  
    l[l[y].next].pre=l[x].pre;    
}  
int n=100;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	for (int i=1;i<=n;i++) {l[i-1].next=i;l[i].pre=i-1;} l[n].next=0;  
	
	for(int i=l[0].next;i;i=l[i].next) cout<<i<<' ';
	
	
	return 0;
}

