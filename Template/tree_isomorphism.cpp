#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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
#define F (100000007)
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case %d: %lld\n",kcase,ans);
typedef long long ll;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
#define MAXN (3000+10)
string s1="same",s2="different";
struct Str{
	vector<int> e[MAXN];
	string s,ans;
	int len,tot;
	void mem() {
		s='0' + s + '1';
		len=s.size();
		tot=len/2;
		For(i,tot) e[i].clear();
		tot=0;
	}	
	int build(int &x) { // suppose s[x]=0
		int now= ++tot;
		++x;
		while (s[x]!='1') {
			e[now].pb(build(x));
		}
		x++;
		return now;
	}
	string get_str(int x) {
		vector<string> tmp;
		int m=SI(e[x]);
		Rep(i,m) tmp.pb(get_str(e[x][i]));
		sort(tmp.begin(),tmp.end());
		string ans;
		Rep(i,m) ans+=(tmp[i]);
		return '0'+ans +'1';
	}
}t[2];
int main()
{
//	freopen(".in","r",stdin);
	int T=read();
	For(kcase,T) {
		cin>>t[0].s >> t[1].s;
		t[0].mem(); t[1].mem();
		int p;
		t[0].build(p=0);
		t[1].build(p=0);
		if (t[0].get_str(1) == t[1].get_str(1) ) cout<<s1;
		else cout<<s2; 
		cout<<endl;
		
		
	}
	
	
	return 0;
}

