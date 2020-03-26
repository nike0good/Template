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
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case #%d: %lld\n",kcase,ans);
#define PRi(a,n) For(i,n-1) cout<<a[i]<<' '; cout<<a[n]<<endl;
#define PRi2D(a,n,m) For(i,n) { \
						For(j,m-1) cout<<a[i][j]<<' ';\
						cout<<a[i][m]<<endl; \
						} 
#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
typedef long double ld;
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
ll sqr(ll a){return a*a;}
ld sqr(ld a){return a*a;}
double sqr(double a){return a*a;}

ld PI = 3.141592653589793238462643383;
const double eps=1e-10;
int dcmp(double x) {
	if (fabs(x)<eps) return 0; else return x<0 ? -1 : 1; 
}
struct P3{
	double x,y,z;
	P3(double x=0,double y=0,double z=0):x(x),y(y),z(z){}
}; 
typedef P3 V3;
V3 operator+(V3 A,V3 B) {
	return V3(A.x+B.x, A.y+B.y ,A.z+B.z);
}	
V3 operator-(V3 A,V3 B) {
	return V3(A.x-B.x, A.y-B.y ,A.z-B.z );
}
V3 operator*(V3 A,double p) {
	return V3(A.x*p, A.y*p, A.z*p);
}
V3 operator/(V3 A,double p) {
	return V3(A.x/p, A.y/p, A.z/p);
}
double Dot(V3 A,V3 B) {return A.x*B.x + A.y*B.y + A.z*B.z; }
double Length(V3 A) {return sqrt(Dot(A,A));}
double Angle(V3 A,V3 B){return acos(Dot(A, B)) / Length(A) / Length(B); }
bool operator==(const P3& a,const P3& b) {
	return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y) == 0 && dcmp(a.z-b.z) == 0;
} 
double DistanceToPlane(const P3& p,const P3& p0,const V3& n) {
	return fabs(Dot(p-p0,n));
}
P3 GetPlaneProjection(const P3& p,const P3 &p0, const V3 &n) {
	return p-n*Dot(p-p0, n);
}
P3 LinePlaneProjection(P3 p1,P3 p2,P3 p0,V3 n) {
	V3 v=p2-p1;
	double t = (Dot(n,p0-p1) / Dot(n,p2-p1));
	return p1+v*t;
}
V3 Cross(V3 A,V3 B) {
	return V3(A.y*B.z - A.z*B.y , A.z*B.x - A.x * B.z, A.x*B.y - A.y*B.x );
} 
double Area2(P3 A,P3 B,P3 C) {return Length(Cross(B-A,C-A));}
bool PointInTri(P3 p,P3 p0,P3 p1,P3 p2) {
	double area1 = Area2(p,p0,p1);
	double area2 = Area2(p,p1,p2);
	double area3 = Area2(p,p2,p0);
	return dcmp(area1+area2+area3 - Area2(p0, p1, p2) ) == 0;
}
bool TriSegIntersection(P3 p0, P3 p1 ,P3 p2, P3 A, P3 B, P3 &p) {
	V3 n = Cross(p1-p0,p2-p0);
	if (dcmp(Dot(n, B-A) ) ==0 ) return 0; //平行，共面  
	else {
		double t = Dot(n,p0-A) / Dot(n, B-A );
		if (dcmp(t)<0 || dcmp(t-1)>0 ) return 0;
		p = A + (B-A) * t;
		return PointInTri(p,p0,p1,p2);
	}
}
double DistanceToLine(P3 p,P3 A,P3 B) {
	V3 v1= B-A , v2 = p-A;
	return Length(Cross(v1,v2))/Length(v1);
}
double DistanceToSegment(P3 p,P3 A,P3 B) {
	if (A==B) return Length(p-A);
	V3 v1 = B - A , v2 = p - A , v3 = p - B ;
	if (dcmp(Dot(v1, v2) < 0)) return Length(v2);
	else if (dcmp(Dot(v1, v3)) > 0) return Length(v3);
	else return Length(Cross(v1,v2)) / Length(v1);
}
double Volume6(P3 A, P3 B, P3 C, P3 D) {
	return Dot(D-A, Cross(B-A ,C-A));
}
struct Face{
	int v[3];
	V3 normal(P3 *p) const {
		return Cross(p[v[1]]-p[v[0]], p[v[2]]-p[v[0]]);
	}
	int cansee(P3 *p, int i) const {
		return Dot(p[i] - p[v[0]], normal(p))>0? 1 : 0; 
	}
};
bool vis[1000][1000];
vector<Face> CH3D(P3 *p, int n) {
	MEM(vis);
	vector<Face> cur;
	cur.pb((Face){{0,1,2}});
	cur.pb((Face){{2,1,0}});
	Fork(i,3,n-1) {
		vector<Face> next;
		int sz=SI(cur);
		Rep(j,sz) {
			Face &f = cur[j];
			int res = f.cansee(p, i);
			if (!res) next.pb(f);
			Rep(k,3) vis[f.v[k]][f.v[(k+1)%3]] = res;
		}
		Rep(j,sz) 
			Rep(k,3) {
				int a=cur[j].v[k], b=cur[j].v[(k+1)%3];
				if (vis[a][b]!= vis[b][a] && vis[a][b]) {
					next.pb((Face) {a, b, i});
				}
			}
		cur = next;
	}
	return cur;
}
double rand01() {return rand()/(double)RAND_MAX;}
double randeps() {return (rand01()-0.5)*eps; }
P3 add_noise(P3 p) {
	return P3(p.x+randeps(),p.y+randeps(),p.z+randeps());
}
bool TriTriIntersection(P3 *T1, P3 *T2) {
	P3 p;
	Rep(i,3) {
		if (TriSegIntersection(T1[0],T1[1],T1[2],T2[i],T2[(i+1)%3],p)) return 1;
		if (TriSegIntersection(T2[0],T2[1],T2[2],T1[i],T1[(i+1)%3],p)) return 1;
		return 0;
	}
}
P3 read_point3() {
	P3 a;
	scanf("%lf%lf%lf",&a.x,&a.y,&a.z);
	return a;	
} 
bool LineDistance3D(P3 p1, V3 u, P3 p2, V3 v, double &s) {
	double b = Dot(u,u)*Dot(v,v) - Dot(u,v) * Dot(u,v);
	if (dcmp(b) == 0 ) return 0;
	double a = Dot(u,v)*Dot(v,p1-p2) - Dot(v,v) * Dot(u,p1-p2); 	
	s=a/b;
	return 1;
} 

//prism centroid
P3 Centroid(P3 A,P3 B,P3 C,P3 D){
	return (A+B+C+D)/4.0;
}
//3d-convex hulls centroid
P3 Centroid(vector<Face>& v,P3* p) {
	int n=v.size();
	P3 C=v[0].v[0], tot;
	double totv=0;
	Rep(i,n) {
		P3 p0=p[v[i].v[0]],p1=p[v[i].v[1]],p2=p[v[i].v[2]];
		double v = -(Volume6(p0,p1,p2,C));
		totv+=v;
		tot = tot + Centroid(p0,p1,p2,C)*v;
	}
	P3 C2=tot/totv;
	return C2;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	
	
	return 0;
}

