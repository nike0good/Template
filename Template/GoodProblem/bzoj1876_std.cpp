#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,l,r) for (int i=l;i<=r;++i)
const int Mx=1252,MOD=100000000;
struct BIGN{
	int a[Mx+10];
	BIGN(){memset(a,0,sizeof a);}
	int &operator [](int i){return a[i];}
	void operator /=(int x){
		for (int i=Mx;i>=1;--i)
			a[i-1]+=a[i]%x*MOD,a[i]/=x;
		}
	void operator -=(BIGN &b){
		for (int i=1;i<Mx;++i)
			a[i]=a[i]-b[i]+(a[i-1]+MOD)/MOD -1,a[i-1]=(a[i-1]+MOD)%MOD;
		}
	void operator *=(int x){
		for (int i=1;i<Mx;++i)
			a[i]=a[i]*x+a[i-1]/MOD,a[i-1]%=MOD;
		}
	bool operator <(BIGN &b){
		for (int i=Mx;i>=1;--i)
			if (a[i]!=b[i]) return a[i]<b[i];
		return false;
		}
	bool iszero(){
		for (int i=1;i<Mx;++i) if (a[i]!=0) return false;
		return true;
		}
	void read(){
		char tp[10005]={'0','0','0','0','0','0','0','0'};
		scanf("%s",tp+8);
		int len=strlen(tp+1),p=1;
		while (len-8*p+1>0)
			sscanf(tp+len-8*p+++1,"%8d",&a[p]);
		}
	void print(){
		int p=Mx;
		while (!a[p]&&p>0) p--;
		printf("%d",a[p--]);
		while (p>0) printf("%08d",a[p--]);
		printf("\n");
		}
};
BIGN gcd(BIGN x,BIGN y){
	int g=0;bool x1,y1;
	while (!x.iszero() && !y.iszero()){
		x1=!(x[1]&1),y1=!(y[1]&1);
		if (x1 && y1){g++;x/=2,y/=2;}else
		if (x1 || y1){if (x1) x/=2;else y/=2;}else
		if (y<x) x-=y;else y-=x;
		}
	if (x<y) x=y;
	while (g--) x*=2;
	return x;
}
BIGN a,b;
int main(){
	freopen("bzoj1876.in","r",stdin);
	a.read();
	b.read();
	gcd(a,b).print();
}

