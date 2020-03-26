#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
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
#define F (20161119)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pri(a,n) for(int i=1;i<n;i++) cout<<a[i]<<' ';cout<<a[n]<<endl;
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
#define MAXN (3023456)
int n,m;
struct treap{
    ll rnd[MAXN],v[MAXN],w[MAXN];
    int size[MAXN],l[MAXN],r[MAXN],cnt;
    void mem() {
        MEM(size) MEM(rnd) MEM(l) MEM(r) MEM(v) MEM(w)
        cnt=0;
    }
    void update(int x)
    {
        size[x]=size[l[x]]+size[r[x]]+w[x];
    }
    void rturn(int &k)
    {
        int t=l[k];l[k]=r[t];r[t]=k;update(k);update(t);k=t;
    }
    void lturn(int &k)
    {
        int t=r[k];r[k]=l[t];l[t]=k;update(k);update(t);k=t;
    }
    void insert(int &x,ll rank) 
    {
        if(!x)
        {
            x=++cnt;
            v[x]=rank; l[x]=r[x]=0;
            rnd[x]=rand();size[x]=w[x]=1;
            return ;
        }
        size[x]++;
        if(v[x]<rank)
        {
            insert(r[x],rank);
            if(rnd[r[x]]<rnd[x])lturn(x);
        }
        else if (v[x]>rank)
        {
            insert(l[x],rank);
            if(rnd[l[x]]<rnd[x]) rturn(x);
        }else w[x]++ ;
    }
    void del(int &x,ll val) {
        if (!x) return ;
        if (v[x]==val) {
            if (w[x]>1) {--w[x]; --size[x]; return; }
            if (!l[x]||!r[x]) x=l[x]+r[x];
            else if (rnd[l[x]]<rnd[r[x]]) rturn(x),del(x,val);
            else lturn(x),del(x,val);
        }
        else {
            --size[x];
            if (val<v[x]) del(l[x],val); else del(r[x],val);
        }
    }
    // return the pointer
    int lower_bound(int x,ll rank) {
        int ans=-1;
        if (!x) return ans;
        if (v[x]<=rank) {
            ans=lower_bound(r[x],rank);
            if (ans==-1) ans=x;
        } else ans=lower_bound(l[x],rank);
        return ans;
    }
    int upper_bound(int x,ll rank) {
        int ans=-1;
        if (!x) return ans;
        if (v[x]>rank) {
            ans=upper_bound(l[x],rank);
            if (ans==-1) ans=x;
        } else ans=upper_bound(r[x],rank);
        return ans;
    }
    void pri(int x){
        if (l[x]) pri(l[x]);
        cout<<v[x]<<' ';
        if (r[x]) pri(r[x]);
    }
    int get_rank(int x,ll val) {
        if (!x) return 0;
        if (v[x]==val) return size[l[x]]+1;
        else if (val<v[x]) return get_rank(l[x],val);
        else return get_rank(r[x],val)+size[l[x]]+w[x];
    }
    int how_many_number_lower_than_x(int x,ll val) {
        if (!x) return 0;
        if (v[x]==val) return size[l[x]];
        else if (val<v[x]) return how_many_number_lower_than_x(l[x],val);
        else return how_many_number_lower_than_x(r[x],val)+size[l[x]]+w[x];
    }
    int get_kth(int x,int k) {
        if (!x) return 0;
        if (k<=size[l[x]]) return get_kth(l[x],k);
        else if (k<=size[l[x]]+w[x]) return x;
        else return get_kth(r[x],k-size[l[x]]-w[x]);
    }
}T;

const int maxn =60000;
int root[maxn<<2];
ll a[maxn];
void build(int l,int r,int o) {
	Fork(i,l,r) T.insert(root[o],a[i]);
    if (l==r) {
	    return ;
	}
	int m=(l+r)>>1;
	build(l,m,Lson),build(m+1,r,Rson);
}
void update(int l,int r,int o,int p,ll v) {
	T.del(root[o],a[p]);
    T.insert(root[o],v);
    if (l==r) {
		return;
	}
	int m=(l+r)>>1;
	if (p<=m) update(l,m,Lson,p,v); 
	else update(m+1,r,Rson,p,v);
}
ll tmp;
void query_lower_bound(int l,int r,int o,int L,int R,ll v) {
	if(L<=l && r<=R ) {int p=T.lower_bound(root[o],v); if (p!=-1) tmp=max(tmp,T.v[p]); return;}
	int m=(l+r)>>1;
	if(L<=m) query_lower_bound(l,m,Lson,L,R,v);
	if(m<R) query_lower_bound(m+1,r,Rson,L,R,v); 
}
void query_upper_bound(int l,int r,int o,int L,int R,ll v) {
	if(L<=l && r<=R ) {int p=T.upper_bound(root[o],v); if (p!=-1) tmp=min(tmp,T.v[p]); return;}
	int m=(l+r)>>1;
	if(L<=m) query_upper_bound(l,m,Lson,L,R,v);
	if(m<R) query_upper_bound(m+1,r,Rson,L,R,v); 
}
void query_rank(int l,int r,int o,int L,int R,ll v) {
	if(L<=l && r<=R ) {tmp+=T.how_many_number_lower_than_x(root[o],v); return;}
	int m=(l+r)>>1;
	if(L<=m) query_rank(l,m,Lson,L,R,v);
	if(m<R) query_rank(m+1,r,Rson,L,R,v); 
}
int query_kth(int L,int R,ll v) {
	int l=0,r=INF,ans;
    while(l<=r) {
        int m=(l+r)/2;
        tmp=0;query_rank(1,n,1,L,R,m);
        if (tmp<v) l=m+1,ans=m;else r=m-1;
    }
    return ans;
}
int main() {
    // freopen("bzoj3196.in","r",stdin);
    n=read();   m=read();
    For(i,n) a[i]=read();
    build(1,n,1);
    For(i,m) {
        int opt=read(),x=read(),y=read(); ll v;
        if (opt^3) v=read();
            // cout<<opt<<' '<<x<<' '<<y<<' '<<v<<endl;
        switch (opt) {
            case 1:tmp=1;query_rank(1,n,1,x,y,v);printf("%lld\n",tmp);break;
            case 2:tmp=1;printf("%d\n",query_kth(x,y,v));break;
            case 3:update(1,n,1,x,y);a[x]=y;break;
            case 4:tmp=-INF;query_lower_bound(1,n,1,x,y,v-1);printf("%lld\n",tmp);break;
            case 5:tmp=INF;query_upper_bound(1,n,1,x,y,v);printf("%lld\n",tmp);break;
        }
    }
   	return 0;
}