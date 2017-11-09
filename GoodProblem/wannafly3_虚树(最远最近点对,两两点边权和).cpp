#include<iostream>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define inf 2000000000
#define pa pair<int,int>
#define ll long long 
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll tot;
int bin[20];
int n,K,top,cnt,q,ind,ans1,ans2;
int last[1000005],last2[1000005],v[1000005];
int mx[1000005],mn[1000005];
int fa[1000005][20],deep[1000005],mark[1000005],st[1000005],h[1000005];
ll size[1000005],f[1000005];
struct edge{
    int to,next,v;
}e[2000005],ed[2000005];
void insert(int u,int v)
{
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
    e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}
void insert2(int u,int v)
{
    if(u==v)return;
    ed[++cnt].to=v;ed[cnt].next=last2[u];last2[u]=cnt;ed[cnt].v=deep[v]-deep[u];
}
void pre(int x)
{
    mark[x]=++ind;
    for(int i=1;bin[i]<=deep[x];i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=last[x];i;i=e[i].next)
        if(e[i].to!=fa[x][0])
        {
            deep[e[i].to]=deep[x]+1;
            fa[e[i].to][0]=x;
            pre(e[i].to);
        }
}
int lca(int x,int y)
{
    if(deep[x]<deep[y])swap(x,y);
    int t=deep[x]-deep[y];
    for(int i=0;bin[i]<=t;i++)
        if(bin[i]&t)x=fa[x][i];
    for(int i=19;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    if(x==y)return x;
    return fa[x][0];
}
bool cmp(int a,int b)
{
    return mark[a]<mark[b];
}
void dp(int x)
{
    int tmp=0;
    size[x]=v[x];f[x]=0;
    mn[x]=v[x]?0:inf;
    mx[x]=v[x]?0:-inf;
    for(int i=last2[x];i;i=ed[i].next)
    {
        int y=ed[i].to;     
        dp(y);
        tot+=(f[x]+size[x]*ed[i].v)*size[y]+f[y]*size[x];
        size[x]+=size[y];
        f[x]+=f[y]+ed[i].v*size[y];
        ans1=min(ans1,mn[x]+mn[y]+ed[i].v);
        ans2=max(ans2,mx[x]+mx[y]+ed[i].v);
        mn[x]=min(mn[x],mn[y]+ed[i].v);
        mx[x]=max(mx[x],mx[y]+ed[i].v);
    }
    last2[x]=0;
}
void solve()
{
    K=read();
    for(int i=1;i<=K;i++)h[i]=read();
    for(int i=1;i<=K;i++)v[h[i]]=1;
    sort(h+1,h+K+1,cmp);
    top=cnt=0;
    int x,f;
    st[++top]=1;
    for(int i=1;i<=K;i++)
    {
        x=h[i];f=lca(x,st[top]);
        if(f==st[top]){st[++top]=x;continue;}
        while(f==lca(x,st[top-1]))
        {
            insert2(st[top-1],st[top]);
            top--;f=lca(x,st[top]);
        }
        insert2(f,st[top]);
        st[top]=f;st[++top]=x;
    }
    while(--top)insert2(st[top],st[top+1]);
    ans1=inf;ans2=-inf;tot=0;
    dp(1);
    if (K==1) puts("0");
    else printf("%d\n",ans2-ans2/2);
    for(int i=1;i<=K;i++)v[h[i]]=0;
}
int main()
{
//  freopen("c.in","r",stdin);
//  freopen(".out","w",stdout);
    bin[0]=1;for(int i=1;i<20;i++)bin[i]=bin[i-1]<<1;
    n=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        insert(u,v);
    }
    pre(1);
    q=read();
    while(q--)solve();
    return 0;
}
