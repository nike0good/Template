#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
#include<iomanip> 
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<sstream>
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
#define MAXN (40000+10)
#define Sigmasize (26) 
typedef unsigned long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
class SAM {
public:
	char s[MAXN];
	int n;
	SAM():n(0){MEM(s) MEM(son) MEM(pre) MEM(step) last=tot=0;}
	SAM(char *_s){n=strlen(_s),memcpy(s,_s,sizeof(char)*(n+5)); MEM(son) MEM(pre) MEM(step) last=tot=0;}
	void mem(){n=0; MEM(s) MEM(son) MEM(pre) MEM(step) last=tot=0;}
	void mem(char *_s){n=strlen(_s);memcpy(s,_s,sizeof(char)*(n+5)); MEM(son) MEM(pre) MEM(step) last=tot=0; MEMI(l) MEMi(r) MEM(c) MEM(q)}
	
	int son[MAXN][Sigmasize+1],pre[MAXN],step[MAXN],last,tot;
	int l[MAXN],r[MAXN];
	void extend(char ch)
	{
		step[++tot]=step[last]+1;
		int p=last,np=tot;
		l[tot]=r[tot]=step[tot];
		
		for(;!son[p][ch];p=pre[p]) son[p][ch]=np;
		if (!p) pre[np]=1;
		else {
			int q=son[p][ch];
			if (step[q]==step[p]+1) pre[np]=q;
			else {
				step[++tot]=step[p]+1;
				int nq=tot;
				memcpy(son[nq],son[q],sizeof(son[q]));
				pre[nq]=pre[q];
				pre[q]=pre[np]=nq;
				for(;son[p][ch]==q;p=pre[p]) son[p][ch]=nq;
			}
		}
		last=np;
	}
	
	void build(){
		last=tot=1;
		Rep(i,n) extend(s[i]-'a');
	}
	int c[MAXN],q[MAXN],len[MAXN];
	void calc() {
		MEM(c)
		For(i,tot) c[step[i]]++;
		For(i,tot) c[i]+=c[i-1];
		For(i,tot) q[c[step[i]]--]=i;
		
		ForD(i,tot) {
			int u=q[i];
			l[pre[u]]=min(l[pre[u]],l[u]);
			r[pre[u]]=max(r[pre[u]],r[u]);
		}	
		MEM(len)
		For(i,tot) {
			len[i]=step[i]-step[pre[i]];
		}
		
	}
	int dfs(int x,int len) {
		For(i,len) {
			Rep(c,26) if (son[x][c]) {
				x=son[x][c]; break;
			}
		}
		return l[x];
	}

	
}S1; 
char s[MAXN];
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
int main()
{
	freopen("H.in","r",stdin);
	int T=read();
	while(T--) {
		scanf("%s",s);
		int n=strlen(s);
		strncpy(s+n,s,n); s[2*n]=0; 
		S1.mem(s);
		S1.build();
		S1.calc();
		printf("%d\n",S1.dfs(1,n)+1-n);
	}
	return 0;
}

