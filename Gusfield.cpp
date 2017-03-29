#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
#include<cmath>
#include<set>
#include<cctype>
#include<ctime>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=Pre[x];p;p=Next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=Next[p])
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define SI(x) ((x).size())
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define vi vector<int>
#define pb push_back
#define MAXN (200+100)
#define MAXM (40000*2+100)
typedef long long ll;
long long mul(long long a,long long b){return (a*b)%F;}
long long add(long long a,long long b){return (a+b)%F;}
long long sub(long long a,long long b){return (a-b+(a-b)/F*F+F)%F;}
int gmin(int &a,int b) {return a=min(a,b);}
int read()
{
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
    return x*f;
} 
class Max_flow  //dinic+???????????   
{    
public:    
    int n,t;    
    int q[MAXN];    
    int edge[MAXM],Next[MAXM],Pre[MAXN],weight[MAXM],size;    
    void addedge(int u,int v,int w)      
    {      
        edge[++size]=v;      
        weight[size]=w;      
        Next[size]=Pre[u];      
        Pre[u]=size;      
    }      
    void addedge2(int u,int v,int w){addedge(u,v,w),addedge(v,u,0);}     
    bool b[MAXN];    
    int d[MAXN];    
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
                if (weight[p]&&!b[v])      
                {      
                    d[v]=d[now]+1;      
                    b[v]=1,q[++tail]=v;      
                }      
            }          
        }      
        return b[t];      
    }     
    int iter[MAXN];  
    int dfs(int x,int f)  
    {  
        if (x==t) return f;  
        Forpiter(x)  
        {  
            int v=edge[p];  
            if (weight[p]&&d[x]<d[v])  
            {  
                  int nowflow=dfs(v,min(weight[p],f));  
                  if (nowflow)  
                  {  
                    weight[p]-=nowflow;  
                    weight[p^1]+=nowflow;  
                    return nowflow;  
                  }  
            }  
        }  
        return 0;  
    }  
    int max_flow(int s,int t)  
    {  
        (*this).t=t;
        int flow=0;  
        while(SPFA(s,t))  
        {  
            For(i,n) iter[i]=Pre[i];  
            int f;  
            while (f=dfs(s,INF))  
                flow+=f;   
        }  
        return flow;  
    }   
    void mem(int n)    
    {    
        (*this).n=n;  
        size=1;    
        For(i,n) Pre[i]=0;   
    }    
}S;   
int n,m,f[MAXN];
int g[MAXN][MAXN];
int ans[MAXN][MAXN];
int cut(int u,int v){
    S.mem(n);
    For(i,n) For(j,n) if (i!=j){
        S.addedge2(i,j,g[i][j]);
    }
    return S.max_flow(u,v);
}
int main()
{
//  freopen("uva11594.in","r",stdin);
//  freopen(".out","w",stdout);
    int T=read();
    For(tcase,T) {
        printf("Case #%d:\n",tcase);
        n=read(); 
        MEMI(ans) For(i,n) ans[i][i]=0;
        For(i,n) For(j,n) g[i][j]=read();

        For(i,n) f[i]=1;
        Fork(i,2,n) {
            int v=f[i];
            int p=cut(i,v);
            vi v1,v2;
            For(j,n) if (1) {
                if (S.b[j]) v1.pb(j);
                else v2.pb(j);
            }
            // Rep(i,SI(v1)) cout<<v1[i]<<' ';cout<<endl;
            // Rep(j,SI(v2)) cout<<v2[j]<<' ';cout<<endl;

            Rep(i,SI(v1)) Rep(j,SI(v2)) {
                gmin(ans[v1[i]][v2[j]],p);
                gmin(ans[v2[j]][v1[i]],p);

            }
            // For(j,i) gmin(ans[i][j],min(p,ans[f[i]][j])),gmin(ans[j][i],min(p,ans[f[i]][j]));
            Fork(j,i,n) {
                if (f[j]==v&&S.b[j]) f[j]=i;
            }
        }
        For(i,n) {
            For(j,n-1) printf("%d ",ans[i][j]);
            printf("%d\n",ans[i][n]);
        }

    }
    return 0;
}
