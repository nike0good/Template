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
#define MAXN (100000+10) 
typedef long long ll;
int p[MAXN],tot;
bool b[MAXN]={0};
int mul[MAXN];
ll i2muli[MAXN],s[MAXN];
void make_prime(int n)
{
    tot=0; mul[1]=1;
    Fork(i,2,n)
    {
        if (!b[i]) p[++tot]=i,mul[i]=-1;
        For(j,tot)
        {
            if (i*p[j]>n) break;
            b[i*p[j]]=1;
            mul[i*p[j]]=-mul[i];
            if (i%p[j]==0) {
                mul[i*p[j]]=0;
                break;
            }  
        }
    }
    For(i,n) i2muli[i]=(ll)i*i%modp*mul[i];
    s[0]=0;
    For(i,n) s[i]=(s[i-1]+i2muli[i]+modp)%modp;
}
int main()
{
	
	
	return 0;
}

