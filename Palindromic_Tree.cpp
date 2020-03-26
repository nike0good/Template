#include<bits/stdc++.h>
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
#define MAXN (600000+10)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}

namespace Palindromic_Tree {
	int s[MAXN],n;
	int tot,next[MAXN][26],link[MAXN],len[MAXN],last;
	int cnt[MAXN];
	
	int newnode(int l)
	{
		len[tot]=l;
		return tot++;
	}
	void mem() {
		MEM(s) MEM(next) MEM(link) MEM(len) MEM(cnt)
		n=tot=0;
		newnode(0); newnode(-1);
		link[0]=link[1]=1; s[0]=27;
		last=0;
	}
	
	int getnode(int x)
	{
		while (s[ n - len[x]-1 ]  != s[n] ) x=link[x];
		return x; 
	}
	
	void add(int c) {
		s[++n]=c;
//		cout<<"1";
		int cur=getnode(last);
		if (!next[cur][c])
		{
			int now=newnode(len[cur]+2);
			int tmp=getnode(link[cur]);
			link[now]=next[tmp][c];
			next[cur][c] = now;
			
		}		
		last=next[cur][c];
		cnt[last]++;
	}
	
	void work()
	{
		RepD(i,tot) cnt[link[i]]+=cnt[i];
	
		ll ans=0;
		Fork(i,2,tot) {
			ans=max(ans,1LL*cnt[i]*len[i]);
			
		} 
		cout<<ans<<endl;

	}
	
}
using namespace Palindromic_Tree;

char S[MAXN];
int N;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	Palindromic_Tree::mem();
	
	scanf("%s",S);
	int N=strlen(S);
	Rep(i,N) Palindromic_Tree::add(S[i]-'a');
	
	Palindromic_Tree::work(); 
	
	return 0;
}

