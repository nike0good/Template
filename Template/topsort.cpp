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
#define F (1000000007)
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
#define MAXN (1500+100) 
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}



int n,indegree[MAXN];
int f[MAXN][MAXN];
bool b[MAXN];
int q[MAXN*4];
void topsort()    
{
    MEM(q) MEM(b)
    int head_=1,tail=0;
	int fl=0,flm=0;    
    Fork(i,1,n)  
        if (indegree[i]==0)     
        {    
            q[++tail]=i;b[i]=1; ++fl;    
        }    
    if (fl>1) flm=1;
    
    while (head_<=tail)    
    {    
    	fl=0;
        int now=q[head_];    
        Fork(v,1,n)  
            while (f[now][v])  
            {    
                indegree[v]--;f[now][v]--;    
                if (indegree[v]==0)    
                {    
                    q[++tail]=v;b[v]=1; ++fl;    
                }                                       
            }       
        head_++;    
        
		if (fl>1) flm=1;
            
    }         
    if (tail==n)   
    {
    	if (flm) 	//方案>1 
		{
		} 
    	
	    else  //唯一解 
		{
		
			
			printf("%d",q[1]);
			Fork(i,2,n) printf(" %d",q[i]);
			printf("\n");  
    
		}
	} //无解 
	else {
	};  
      
}  

struct Topsort{
	int n,indegree[MAXN];
	vi e[MAXN];
	bool b[MAXN];
	int q[MAXN*4];
	void init(int _n) {
		n=_n;
		Rep(i,n) e[i].clear();
		MEM(indegree)
	}
	void addedge(int u,int v) {
		e[u].pb(v); indegree[v]++;
	}
	void topsort()    
	{
		MEM(q) MEM(b)
		int head_=1,tail=0;
		int fl=0,flm=0;    
		Fork(i,1,n)  
		    if (indegree[i]==0)     
		    {    
		        q[++tail]=i;b[i]=1; ++fl;    
		    }    
		if (fl>1) flm=1;
		
		while (head_<=tail)    
		{    
			fl=0;
		    int now=q[head_];    
		    For(i,SI(e[now]))  
		    {    
		    	int v=e[now][i];
	            indegree[v]--;    
	            if (indegree[v]==0)    
	            {    
	                q[++tail]=v;b[v]=1; ++fl;    
	            }                                       
		    }       
		    head_++;    
			if (fl>1) flm=1;
		}         
		if (tail==n)   
		{
			if (flm) 	//方案>1 
			{
			} 
			
		    else  //唯一解 
			{
			
				
				printf("%d",q[1]);
				Fork(i,2,n) printf(" %d",q[i]);
				printf("\n");  
		
			}
		} //无解 
		else {
		};  
		  
	}    
}S1;

  
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	MEM(f) MEM(indegree) 
	topsort();
	
			
	return 0;
}

