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
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (1000000)
#define Sigma_size (1000)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
class SA
{
public:
	char s[MAXN];
	int sa[MAXN],t[MAXN],t2[MAXN],c[MAXN],n;	
	SA(){}
	SA(char *_s){strcpy(s,_s);n=strlen(s);MEM(sa) MEM(t) MEM(t2) MEM(c) }
	void mem(char *_s){strcpy(s,_s);n=strlen(s);MEM(sa) MEM(t) MEM(t2) MEM(c) }
	void build_sa(int m)
	{
		int *x=t,*y=t2;
		Rep(i,m) c[i]=0;
		Rep(i,n) c[x[i]=s[i]]++; 
		For(i,m-1) c[i]+=c[i-1];
		RepD(i,n-1) sa[--c[x[i]]]=i;
		for(int k=1;k<=n;k<<=1)
		{
			int p=0;
			ForkD(i,n-k,n-1) y[p++]=i;
			Rep(i,n) if (sa[i]>=k) y[p++]=sa[i]-k; 
			
			Rep(i,m) c[i]=0;
			Rep(i,n) c[x[y[i]]]++;  
			For(i,m-1) c[i]+=c[i-1];
			RepD(i,n-1) sa[--c[x[y[i]]]]=y[i];
			swap(x,y);  
			p=1; x[sa[0]]=0;
			For(i,n-1)
				x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i]+k]==y[sa[i-1]+k]) ? (p-1):(p++);
			if (p>=n) break;
			m=p;
		}
	}
	int rank[MAXN],height[MAXN];
	void make_height()
	{
		int k=0;
		Rep(i,n) rank[sa[i]]=i;
		Rep(i,n)
		{
			if (rank[i]-1<0) continue;
			if (k) k--;
			int j=sa[rank[i]-1];
			while(max(i,j)+k<n&&s[i+k]==s[j+k]) ++k;
			height[rank[i]]=k;
		}
	}
	int m; //模板串P的长度要事先赋值 
	int cmp_suffix(char *pattern,int p)
	{
		 return strncmp(pattern,s+sa[p],m);
	}
	
	int find(char *P)	
	{
		m=strlen(P); //这里赋值也行 
		if (cmp_suffix(P,0)<0||cmp_suffix(P,n-1)>0) return -1;
		int L=0,R=n-1;
		while(L<=R)
		{
			int M=(L+R)>>1;
			int res=cmp_suffix(P,M);
			if (!res) return M;
			else if (res<0) R=M-1;
			else L=M+1;
		}
		return -1;
	}
	#define MAXLog (20)
	int d[MAXN][MAXLog];
	void RMQ_init()
	{
		Rep(i,n) d[i][0]=height[i];
		for(int j=1;(1<<j)<=n;j++)
			for(int i=0;i + (1<<j) -1 < n; i++)
			{
				d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
			}
 	} 
 	int query(int L,int R)
 	{
 		if (L>R) swap(L,R);
 		int k=floor(log(R-L+1)/log(2));
		return min(d[L][k],d[R-(1<<k)+1][k]);
 	}
	int lcp(int x,int y) { //retrurn lcp(s[x..n-1],s[y..n-1]) 
		x=rank[x],y=rank[y];
		if (x>y) swap(x,y);
		return query(x+1,y);
	}	
}S;
char s[MAXN]="aabaa";
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
//	scanf("%s",s);
	S.mem(s);
	S.build_sa(Sigma_size);
	
	return 0;
}

