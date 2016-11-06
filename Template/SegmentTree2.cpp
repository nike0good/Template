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
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define MEM2(a,i) memset(a,i,sizeof(a));
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
    ll a[MAXN*4],minv[MAXN*4],sumv[MAXN*4],maxv[MAXN*4],addv[MAXN*4],setv[MAXN*4];  
    int n;  
public:  
    SegmentTree(){MEM(a) MEM(minv) MEM(sumv) MEM(addv) MEM2(setv,-1) }  
    SegmentTree(int _n):n(_n){MEM(a) MEM(minv) MEM(sumv) MEM(addv) MEM2(setv,-1) }  
    void mem(int _n)  
    {  
        n=_n;  
        MEMI(a) MEMI(minv)  
    }  

    void maintain(int o,int L,int R)  
    {
		sumv[o]=maxv[o]=minv[o]=0;
    	if (L<R) //Ö»¿¼ÂÇ×óÓÒ×ÓÊ÷ 
		{
			sumv[o]=sumv[Lson]+sumv[Rson];
			minv[o]=min(minv[Lson],minv[Rson]);
			maxv[o]=max(maxv[Lson],maxv[Rson]);
		} //Ö»¿¼ÂÇadd²Ù×÷ 
		minv[o]+=addv[o];maxv[o]+=addv[o];sumv[o]+=addv[o]*(R-L+1);
    }

	int y1,y2,v;
	void update(int o,int L,int R)
	{
		if (y1<=L&&R<=y2) {
			addv[o]+=v;
		}
		else{
			int M=(R+L)>>1;
			if (y1<=M) update(Lson,L,M);
			if (M< y2) update(Rson,M+1,R);
		}
		
		maintain(o,L,R); 
	}

	ll _min,_max,_sum; 
	void query(int o,int L,int R,ll add)
	{
		if (y1<=L&&R<=y2)
		{
			_sum+=sumv[o]+add*(R-L+1);
			_min=min(_min,minv[o]+add);
			_max=max(_max,maxv[o]+add); 
		} 
		else{
			int M=(R+L)>>1;
			if (y1<=M) query(Lson,L,M,add+addv[o]);
			if (M< y2) query(Rson,M+1,R,add+addv[o]);
		}		
	}
}S;  
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=1;
	S.mem(1);
	S.y1=1,S.y2=1,S.v=1;
	S.update(1,1,n);
	S.y1=1,S.y2=1,S.v=1;
	S.update(1,1,n);
	S._sum=0;
	S.query(1,1,n,0);
	cout<<S._sum;
	
	
	
	return 0;
}

