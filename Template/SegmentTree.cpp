#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
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
#define MAXN (100000)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
class SegmentTree  
{  
    ll a[MAXN*4],minv[MAXN*4];  
    int n;  
public:  
    SegmentTree(){MEM(a) MEM(minv) }  
    SegmentTree(int _n):n(_n){MEM(a) MEM(minv) }  
    void mem(int _n)  
    {  
        n=_n;  
        MEMI(a) MEMI(minv)  
    }  
    int p,v; //set a[p]=v  
    void set(int p,int v)  
    {  
        this->p=p,this->v=v;  
        _set(1,1,n);  
    }  
    void _set(int x,int L,int R)  
    {  
        int M=(L+R)>>1;  
        if (L==R) {a[x]=minv[x]=v;return;}  
        else  
        {  
            if (p<=M) _set(Lson,L,M);  
            else _set(Rson,M+1,R);  
        }   
        minv[x]=min(minv[Lson],minv[Rson]);  
    }  
      
      
    int ql,qr;  
    ll query_min(int ql,int qr)  
    {  
        this->ql=ql,this->qr=qr;  
        if (ql>qr) return INF;  
        return _query_min(1,1,n);   
    }  
      
    ll _query_min(int x,int L,int R)  
    {  
        if (ql<=L&&R<=qr) return minv[x];  
        ll ans=INF,M=(L+R)>>1;  
        if (ql<=M) ans=min(ans,_query_min(Lson,L,M));  
        if (M< qr) ans=min(ans,_query_min(Rson,M+1,R));  
        return ans;  
    }  
      
}S;  
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	
	
	return 0;
}

