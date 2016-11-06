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
#define ALL(a) (a).begin(), (a).end()
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

const double eps=1e-8;
int dcmp(double x) {
	if (fabs(x)<eps) return 0; else return x<0 ? -1 : 1; 
}
ld PI = 3.141592653589793238462643383;
class P{
public:
	double x,y;
	P(double x=0,double y=0):x(x),y(y){}
	friend long double dis2(P A,P B){return sqr(A.x-B.x)+sqr(A.y-B.y);	}
	friend long double Dot(P A,P B) {return A.x*B.x+A.y*B.y; }
	friend long double Length(P A) {return sqrt(Dot(A,A)); }
	friend long double Angle(P A,P B) {return acos(Dot(A,B) / Length(A) / Length(B) ); }
	friend P operator- (P A,P B) { return P(A.x-B.x,A.y-B.y); }
	friend P operator+ (P A,P B) { return P(A.x+B.x,A.y+B.y); }
	friend P operator* (P A,double p) { return P(A.x*p,A.y*p); }
	friend P operator/ (P A,double p) { return P(A.x/p,A.y/p); }
	friend bool operator< (const P& a,const P& b) {return dcmp(a.x-b.x)<0 ||(dcmp(a.x-b.x)==0&& dcmp(a.y-b.y)<0 );}
	
}; 
bool operator==(const P& a,const P& b) {
	return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y) == 0;
} 
typedef P V;

double Cross(V A,V B) {return A.x*B.y - A.y*B.x;}
double Area2(P A,P B,P C) {return Cross(B-A,C-A);}

P GetLineIntersection(P p,V v,P Q,V w){
	V u = p-Q;
	double t = Cross(w,u)/Cross(v,w);
	return p+v*t;
}
P GetLineIntersectionB(P p,V v,P Q,V w){
	return GetLineIntersection(p,v-p,Q,w-Q);
}

bool SegmentProperIntersection(P a1,P a2,P b1,P b2) { 
	double  c1 = Cross(a2-a1,b1-a1) , c2 = Cross(a2-a1,b2-a1),
			c3 = Cross(b2-b1,a1-b1) , c4 = Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
bool OnSegment(P p,P a1,P a2) {
	return dcmp(Cross(a1-p,a2-p)) == 0 && dcmp(Dot(a1-p,a2-p))<0;
}
P read_point() {
	P a;
	scanf("%lf%lf",&a.x,&a.y);
	return a;	
} 

typedef vector<P> Polygon;
double PolygonArea(Polygon &p) {
	double area=0;
	int n=p.size();
	For(i,n-2) area+=Cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2;
} 


struct Edge{
	int from,to;
	double ang;
	Edge(int _from,int _to,double _ang):from(_from),
		to(_to),ang(_ang){}
};
#define MAXN (11111+10)
struct PSLG {
	int n,m,face_cnt;
	ld x[MAXN],y[MAXN];
	vector<Edge> edges;
	vi G[MAXN];
	int vis[MAXN*2],left[MAXN*2],prev[MAXN*2];
	vector<Polygon> faces;
	double area[MAXN];
	void init(int n) {
		this->n=n;
		Rep(i,n) G[i].clear();
		edges.clear();
		faces.clear();
	}
	double getAngle(int from,int to) {
		return atan2(y[to]-y[from],x[to]-x[from]);
	}
	void AddEdge(int from,int to) {
		edges.pb(Edge(from,to,getAngle(from,to)));
		edges.pb(Edge(to,from,getAngle(to,from)));
		m=SI(edges);
		G[from].pb(m-2);
		G[to].pb(m-1);
	}
	void Build() { 
		Rep(u,n) {
			int d=SI(G[u]);
			Rep(i,d) {
				Fork(j,i+1,d-1) {
					if (edges[G[u][i]].ang>edges[G[u][j]].ang) {
						swap(G[u][i],G[u][j]);
					}
				}
			}
			Rep(i,d) {
				prev[G[u][(i+1)%d]]=G[u][i];
			}
		}
		MEM(vis)
		face_cnt=0;
		Rep(u,n) {
			Rep(i,SI(G[u])) {
				int e=G[u][i];
				if (!vis[e]) {
					face_cnt++;
					Polygon poly;
					while(1) {
						vis[e]=1;
						left[e]=face_cnt;
						int from = edges[e].from;
						P p(x[from],y[from]);
						poly.pb(p);
						e=prev[e^1];
						if (e==G[u][i]) break;
					}
					faces.pb(poly);
				}
			} 
		}
		Rep(i,face_cnt) {
			area[i]=PolygonArea(faces[i]);
		}
	}
}g;

int n, sz;
P p1[MAXN];
void find_path() {
	vector<P> v;
	vector<double> dis[MAXN];
	Rep(i,n) v.pb(p1[i]);
	Rep(i,n) {
		Fork(j,i+1,n-1)
			if (SegmentProperIntersection(p1[i],p1[(i+1)%n],p1[j],p1[(j+1)%n])) {
				P p=GetLineIntersectionB(p1[i],p1[(i+1)%n],p1[j],p1[(j+1)%n]);
				v.pb(p);
				dis[i].pb(Length(p-p1[i]));
				dis[j].pb(Length(p-p1[j]));
			}
	}
	sort(ALL(v));
	v.erase( unique(ALL(v)), v.end() );
	sz=SI(v);
	
	g.init(sz);
	Rep(i,sz) g.x[i]=v[i].x,g.y[i]=v[i].y;
	
	Rep(i,n) {
		V v1 = p1[(i+1)%n]-p1[i];
		double len=Length(v1);
		dis[i].pb(0); dis[i].pb(len);
		v1=v1/len;
		sort(ALL(dis[i]));	
		dis[i].erase(unique(ALL(dis[i])),dis[i].end());
		int tot=SI(dis[i]);
		Rep(j,tot-1) {
			P now=p1[i]+v1*dis[i][j];
			P now2=p1[i]+v1*dis[i][j+1];
			int id1=lower_bound(ALL(v),now)-v.begin();
			int id2=lower_bound(ALL(v),now2)-v.begin();
			if (id1==id2) continue;
			g.AddEdge(id1,id2);
		}
	}
	g.Build();
}
void simplify(Polygon& poly) {
	Polygon ans;
	int n=SI(poly);
	Rep(i,n) {
		if (dcmp(Cross(poly[i]-poly[(i+1)%n],poly[(i+1)%n]-poly[(i+2)%n]))!=0)
			ans.pb(poly[(i+1)%n]);
	}
	n=SI(ans);
	cout<<n<<endl;
	Rep(i,n) printf("%.4lf %.4lf\n",ans[i].x,ans[i].y);
}

int main()
{
//	freopen("la3218.in","r",stdin);
//	freopen("la3218.out","w",stdout);
	while(scanf("%d",&n)==1&&n) {
		Rep(i,n) {
			p1[i]=read_point();	
		}
		find_path();
		Polygon poly;
		Rep(i,g.face_cnt) if (dcmp(g.area[i])<0) {
			poly=g.faces[i];
			reverse(ALL(poly));
			break;
		}
		simplify(poly);
	}
	return 0;
}

