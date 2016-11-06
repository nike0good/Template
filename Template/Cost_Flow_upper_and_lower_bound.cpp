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
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (500+10)
#define MAXM ((100*3+10000)*12+10)
#define MAXAi (35000)
#define eps (1e-3)
long long mul(long long a,long long b){return (a*b)%F;}
long long add(long long a,long long b){return (a+b)%F;}
long long sub(long long a,long long b){return (a-b+(a-b)/F*F+F)%F;}
typedef long long ll;
class Cost_Flow  
{  
public:  
    int n,s,t;  
    int q[MAXM];  
    int edge[MAXM],next[MAXM],pre[MAXN],weight[MAXM],size;  
    int cost[MAXM];  
    void addedge(int u,int v,int w,int c)    
    {    
        edge[++size]=v;    
        weight[size]=w;    
        cost[size]=c;    
        next[size]=pre[u];    
        pre[u]=size;    
    }    
    void addedge2(int u,int v,int w,int c){addedge(u,v,w,c),addedge(v,u,0,-c);}   
    bool b[MAXN];  
    int d[MAXN];  
    int pr[MAXN],ed[MAXN];  
    bool SPFA(int s,int t)    
    {    
        For(i,n) d[i]=INF,b[i]=0; 
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
        return d[t]!=INF;    
    }   
    int totcost;    
          
    int CostFlow(int s,int t)    
    {    
    	int maxflow=0;
        while (SPFA(s,t))    
        {    
            int flow=INF;    
            for(int x=t;x^s;x=pr[x]) flow=min(flow,weight[ed[x]]); 
			totcost+=flow*d[t]; 
			maxflow+=flow;   
            for(int x=t;x^s;x=pr[x]) weight[ed[x]]-=flow,weight[ed[x]^1]+=flow;         
        }    
//        cout<<maxflow<<endl;
        return totcost;    
    }    
    void mem(int n,int t)  
    {  
        (*this).n=n;  
        size=1;  
        totcost=0;  
        MEM(pre) MEM(next)   
    }  
}S1;  
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
int n,m;
int main()
{
//	freopen("bzoj2055.in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();m=read();
	int s=2*n+1,t=s+1,S=t+1,T=S+1;
	S1.mem(T,T);
	const int inf = INF;
	For(i,n) {
		int v=read();		
		S1.addedge2(s,i,inf,0);
		S1.addedge2(n+i,t,inf,0);
	
		S1.addedge2(S,i+n,v,0);
		S1.addedge2(i,T,v,0);
	}
	For(i,n) {
		Fork(j,i+1,n) {
			int c=read();
			if (c==-1) continue;
			S1.addedge2(i+n,j,inf,c);
		}
	} 
	S1.addedge2(t,s,m,0); //无源无汇，保证流量守恒
	
	cout<<S1.CostFlow(S,T)<<endl; 
		
	return 0;
}

