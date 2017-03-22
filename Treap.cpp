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
#define MAXN (123456)
int n;
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
    int get_kth(int x,int k) {
        if (!x) return 0;
        if (k<=size[l[x]]) return get_kth(l[x],k);
        else if (k<=size[l[x]]+w[x]) return x;
        else return get_kth(r[x],k-size[l[x]]-w[x]);
    }
}T;
int main() {
    // freopen("tyvjP1728.in","r",stdin);
    
    n=read();
    int rot=0;
    For(i,n) {
        int opt=read(),x=read();
        // cout<<opt<<" "<<x<<endl;
        switch (opt) {
            case 1:T.insert(rot,x);break;
            case 2:T.del(rot,x);break;
            case 3:printf("%d\n",T.get_rank(rot,x));break;
            case 4:printf("%lld\n",T.v[T.get_kth(rot,x)]);break;
            case 5:printf("%lld\n",T.v[T.lower_bound(rot,x-1)]);break;
            case 6:printf("%lld\n",T.v[T.upper_bound(rot,x)]);break;
        }
        // T.pri(rot);puts("");
    }
   	return 0;
}