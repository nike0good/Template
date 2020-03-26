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
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (10000+10)
#define Sp_char1 ('*')
#define Sp_char2 ('$')
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
class manacher
{
public:
	int n;
	char s[MAXN];
	int p[2*MAXN+2];
	manacher(){n=0; MEM(s) MEM(p)}
	manacher(char *_s){n=0; MEM(s) if (_s) memcpy(s,_s,sizeof(char)*(strlen(_s)+1)),n=strlen(s); MEM(p)}
	void mem(char *_s){n=0; MEM(s) if (_s) memcpy(s,_s,sizeof(char)*(strlen(_s)+1)),n=strlen(s); MEM(p)}
	char str[MAXN*2+2];
	void work()
	{
		str[0]=Sp_char1;
		Rep(i,n) str[2*i+1]=Sp_char2,str[2*i+2]=s[i]; 
		str[2*n+1]=Sp_char2; str[2*n+2]='\0';
		
		n=2*n+2; MEM(p) 
		int mx=0,id=0;
		For(i,n-1) 
		{
			if (i<mx) p[i]=min(p[2*id-i],mx-i);
			
			while(str[i-p[i]]==str[i+p[i]]) ++p[i];
			if (mx<i+p[i]) //mx为已查明的最右端 
			{
				mx=i+p[i];
				id=i;
			}
		}
	}
}S;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
		
	return 0;
}

