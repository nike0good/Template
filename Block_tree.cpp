#include<bits/stdc++.h> 
using namespace std;
#define ALL(x) (x).begin(),(x).end()
const int N=200011;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
int Pre[N],Edge[N<<1],Next[N<<1];
int PRE[N],EDGE[N<<1],NEXT[N<<1];
int a[N],fa[N],belong[N];
int n,m,cnt,ans,CNT,tot,B;
struct node
{
    int size;
    vector<int> a;
    inline void insert(int x)
    {
    	++size;
        a.insert(lower_bound(ALL(a),x+1),x);
    }
    inline void change(int x,int y)
    {
    	del(x); insert(y);
	}
    inline void del(int x)
    {
    	--size;
    	a.erase(lower_bound(ALL(a),x));
    }
    inline int query(int x)
    {
        int t=upper_bound(ALL(a),x)-a.begin()+1;
        return size-t+1;
    }
}block[200200];
inline void addedge(int x,int y)
{
    Next[++cnt]=Pre[x];
    Pre[x]=cnt;
    Edge[cnt]=y;
}
inline void deledge(int x,int y) 
{
	if (Edge[Pre[x]]==y) Pre[x]=Next[Pre[x]];
	else
	for(int p=Pre[x];p;p=Next[p]) {
		if (Edge[Next[p]]==y) {
			Next[p]=Next[Next[p]];
			return;
		}
	}
}
inline void DELEDGE(int x,int y) 
{
	if (EDGE[PRE[x]]==y) PRE[x]=NEXT[PRE[x]];
	else
	for(int p=PRE[x];p;p=NEXT[p]) {
		if (EDGE[NEXT[p]]==y) {
			NEXT[p]=NEXT[NEXT[p]];
			return;
		}
	}
}

inline void INSERT(int x,int y) 
{
    NEXT[++CNT]=PRE[x];
    PRE[x]=CNT;
    EDGE[CNT]=y;
}
void dfs(int x)
{
    if (block[belong[fa[x]]].size==B)
        belong[x]=++tot,block[tot].insert(a[x]),INSERT(belong[fa[x]],tot);
    else belong[x]=belong[fa[x]],block[belong[x]].insert(a[x]);
    for (int i=Pre[x];i;i=Next[i])
        if (Edge[i]!=fa[x])
            fa[Edge[i]]=x,dfs(Edge[i]);
}
void dfs1(int x,int y)
{
    ans+=block[x].query(y);
    for (int i=PRE[x];i;i=NEXT[i])
        dfs1(EDGE[i],y);
}
void query(int x,int y)
{
    if (a[x]>y) ans++;
    for (int i=Pre[x];i;i=Next[i])
        if (Edge[i]!=fa[x])
        {
            if (belong[Edge[i]]==belong[x]) query(Edge[i],y);
            else dfs1(belong[Edge[i]],y);
        }
}


void dfs2(int x,int col,int tocol)
{
	belong[x]=tocol;
	block[tocol].insert(a[x]);
	block[col].del(a[x]);
	
    for (int i=Pre[x];i;i=Next[i])
        if (Edge[i]!=fa[x]){
    	    if (belong[Edge[i]]==col) {
        	    dfs2(Edge[i],col,tocol);
        	} else {
        		DELEDGE(col,belong[Edge[i]]);
        		INSERT(tocol,belong[Edge[i]]);
        	}			 
    }
}

int main()
{
//	freopen("bzoj3731.data","r",stdin);
//	freopen("bzoj3731.out","w",stdout);
    n=read(); B=static_cast<int>(sqrt(n*7*log2(n))+1e-7); 
    for (int i=1;i<n;i++)
    {
        int u=read(),v=read();
        addedge(u,v); addedge(v,u);
    }
    for (int i=1;i<=n;i++) a[i]=read();
    dfs(1);
    m=read();
    for (int i=1;i<=m;i++)
    {
//    	ans=0;
        int opt=read(),u=read()^ans,x;
		if (opt<3) x=read()^ans;
        if (opt==0)
        {
            ans=0;
            if (fa[u]) query(u,x);
            else dfs1(belong[u],x);
            printf("%d\n",ans);
        }
        else if (opt==1)
        {
            block[belong[u]].change(a[u],x);
            a[u]=x;
        }
        else if (opt==2)
        {
            a[++n]=x; 
            addedge(u,n);
            fa[n]=u;
            if (block[belong[u]].size==B)
                belong[n]=++tot,block[tot].insert(x),INSERT(belong[u],tot);
            else
            {
                belong[n]=belong[u],block[belong[n]].insert(a[n]);
            }
        }
        else {
        	if (!fa[u]) continue;
        	int f=fa[u];
        	if (belong[f]!=belong[u]) {
        		deledge(f,u); deledge(u,f);
        		DELEDGE(belong[f],belong[u]);
        		fa[u]=0;
        	}
        	else {
        		deledge(f,u); deledge(u,f);
				++tot;
        		int col=belong[u];
				dfs2(u,col,tot);
				fa[u]=0;
        	}
        }
    }
    return 0;
}
