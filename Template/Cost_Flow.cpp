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
#define MAXN (1000+10)
#define MAXM (10000*4+10)
#define MAXAi (35000)
#define eps (1e-3)
long long mul(long long a,long long b){return (a*b)%F;}
long long add(long long a,long long b){return (a+b)%F;}
long long sub(long long a,long long b){return (a-b+(a-b)/F*F+F)%F;}
typedef long long ll;

// PS double 替换成int 不然会超时
//ps2: 注意q的大小 
class Cost_Flow  
{  
public:  
    int n,s,t;  
    int q[10000000];  
    int edge[MAXM],next[MAXM],pre[MAXN],weight[MAXM],size;  
    double cost[MAXM];  
    void addedge(int u,int v,int w,double c)    
    {    
        edge[++size]=v;    
        weight[size]=w;    
        cost[size]=c;    
        next[size]=pre[u];    
        pre[u]=size;    
    }    
    void addedge2(int u,int v,int w,double c){addedge(u,v,w,c),addedge(v,u,0,-c);}   
    bool b[MAXN];  
    double d[MAXN];  
    int pr[MAXN],ed[MAXN];  
    bool SPFA(int s,int t)    
    {    
        For(i,n) d[i]=INF;  
        MEM(b)  
        d[q[1]=s]=0;b[s]=1;    
        int head=1,tail=1;    
        while (head<=tail)    
        {    
            int now=q[head++];    
            Forp(now)    
            {    
                int &v=edge[p];    
                if (weight[p]&&d[now]+cost[p]<d[v])    
                {    
                    d[v]=d[now]+cost[p];    
                    if (!b[v]) b[v]=1,q[++tail]=v;    
                    pr[v]=now,ed[v]=p;    
                }    
            }    
            b[now]=0;    
        }    
        return fabs(d[t]-INF)>eps;    
    }   
    double totcost;    
          
    double CostFlow(int s,int t)    
    {    
        while (SPFA(s,t))    
        {    
            int flow=INF;    
            for(int x=t;x^s;x=pr[x]) flow=min(flow,weight[ed[x]]);      
            totcost+=(double)flow*d[t];    
            for(int x=t;x^s;x=pr[x]) weight[ed[x]]-=flow,weight[ed[x]^1]+=flow;         
        }    
        return totcost;    
    }    
    void mem(int n,int t)  
    {  
        (*this).n=n;  
        size=1;  
        totcost=0;  
        MEM(pre) MEM(next)   
    }  
}S;  

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);

	
	return 0;
}

