#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#include<bits/stdc++.h>

struct BigInteger {
    typedef unsigned long long LL;

    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    BigInteger& clean(){while(!s.back()&&s.size()>1)s.pop_back(); return *this;}
    BigInteger(LL num = 0) {*this = num;}
    BigInteger(string s) {*this = s;}
    BigInteger& operator = (long long num) {
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);
        return *this;
    }
    BigInteger& operator = (const string& str) {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++) {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start,end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return (*this).clean();
    }

    BigInteger operator + (const BigInteger& b) const {
        BigInteger c; c.s.clear();
        for (int i = 0, g = 0; ; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if (i < s.size()) x += s[i];
            if (i < b.s.size()) x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    BigInteger operator - (const BigInteger& b) const {
        assert(b <= *this); // ??那y2??邦∩車車迆㊣???那y
        BigInteger c; c.s.clear();
        for (int i = 0, g = 0; ; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = s[i] + g;
            if (i < b.s.size()) x -= b.s[i];
            if (x < 0) {g = -1; x += BASE;} else g = 0;
            c.s.push_back(x);
        }
        return c.clean();
    }
    BigInteger operator * (const BigInteger& b) const {
        int i, j; LL g;
        vector<LL> v(s.size()+b.s.size(), 0);
        BigInteger c; c.s.clear();
        for(i=0;i<s.size();i++) for(j=0;j<b.s.size();j++) v[i+j]+=LL(s[i])*b.s[j];
        for (i = 0, g = 0; ; i++) {
            if (g ==0 && i >= v.size()) break;
            LL x = v[i] + g;
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c.clean();
    }
    BigInteger operator / (const BigInteger& b) const {
        assert(b > 0);  // 3y那y㊣?D?∩車車迆0
        BigInteger c = *this;       // 谷足:?¯辰a那?豕?c.so赤(*this).s米?vector辰??迄∩車
        BigInteger m;               // 車角那y:3?那??‘?a0
        for (int i = s.size()-1; i >= 0; i--) {
            m = m*BASE + s[i];
            c.s[i] = bsearch(b, m);
            m -= b*c.s[i];
        }
        return c.clean();
    }
    BigInteger operator % (const BigInteger& b) const { //﹞?﹞“車?3y﹞“?角赤?
        BigInteger c = *this;
        BigInteger m;
        for (int i = s.size()-1; i >= 0; i--) {
            m = m*BASE + s[i];
            c.s[i] = bsearch(b, m);
            m -= b*c.s[i];
        }
        return m;
    }
    // ?t﹞?﹞“?辰3??迆℅?bx<=m米?℅?∩車米?x
    int bsearch(const BigInteger& b, const BigInteger& m) const{
        int L = 0, R = BASE-1, x;
        while (1) {
            x = (L+R)>>1;
            if (b*x<=m) {if (b*(x+1)>m) return x; else L = x;}
            else R = x;
        }
    }
    BigInteger& operator += (const BigInteger& b) {*this = *this + b; return *this;}
    BigInteger& operator -= (const BigInteger& b) {*this = *this - b; return *this;}
    BigInteger& operator *= (const BigInteger& b) {*this = *this * b; return *this;}
    BigInteger& operator /= (const BigInteger& b) {*this = *this / b; return *this;}
    BigInteger& operator %= (const BigInteger& b) {*this = *this % b; return *this;}

    bool operator < (const BigInteger& b) const {
        if (s.size() != b.s.size()) return s.size() < b.s.size();
        for (int i = s.size()-1; i >= 0; i--)
            if (s[i] != b.s[i]) return s[i] < b.s[i];
        return false;
    }
    bool operator >(const BigInteger& b) const{return b < *this;}
    bool operator<=(const BigInteger& b) const{return !(b < *this);}
    bool operator>=(const BigInteger& b) const{return !(*this < b);}
    bool operator!=(const BigInteger& b) const{return b < *this || *this < b;}
    bool operator==(const BigInteger& b) const{return !(b < *this) && !(b > *this);}
};

ostream& operator << (ostream& out, const BigInteger& x) {
    out << x.s.back();
    for (int i = x.s.size()-2; i >= 0; i--) {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++) out << buf[j];
    }
    return out;
}

istream& operator >> (istream& in, BigInteger& x) {
    string s;
    if (!(in >> s)) return in;
    x = s;
    return in;
}

#define For(i,n) for(int i=1;i<=n;i++)
const int HASH=30007;
const int STATE=1000010;
const int MAXD=25;
int N,M;
int code[MAXD];
char maze[MAXD][MAXD];
typedef BigInteger ll; 
struct HASHMAP
{
    int head[HASH],next[STATE],state[STATE],size;
    ll f[STATE];
    void init()
    {
        size=0;
        memset(head,-1,sizeof(head));
    }
    void push(int st,ll ans)
    {
        int i,h=st%HASH;
        for(i=head[h];i!=-1;i=next[i])
          if(st==state[i])
          {
              f[i]+=ans;
              return;
          }
        f[size]=ans;
        state[size]=st;
        next[size]=head[h];
        head[h]=size++;
    }
}hm[2];

void decode(int *code,int m,int st)
{
    int i;
    for(i=m;i>=0;i--)
    {
        code[i]=st&3;
        st>>=2;
    }
}
int encode(int *code,int m)
{
    int i,st=0;
    for(int i=0;i<=m;i++)
    {
        st<<=2;
        st|=code[i];
    }
    return st;
}
void init()
{
    scanf("%d%d",&N,&M);
    if (N<M)swap(N,M);
    For(i,N) For(j,M) maze[i][j]=1;
    for(int i=1;i<=N;i++)maze[i][M+1]=0;
    for(int i=1;i<=M;i++)maze[N+1][i]=0;
}

void shift(int *code,int m)//?-?﹞車辰辰? 
{
    int i;
    for(i=m;i>0;i--)
      code[i]=code[i-1];
    code[0]=0;
}
#include<stack>
int seq[MAXD];
void prs(int *code,int m,int *seq) {
    stack<int> st;
    for(int i=0;i<=m;i++) {
        if (code[i]==1) st.push(i);
        if (code[i]==2) {
            int f=st.top(); st.pop();
            seq[f]=i;seq[i]=f;
        }
    }
}
int ex,ey;
void dpblank(int i,int j,int cur)
{
    int k,left,up;
    for(k=0;k<hm[cur].size;k++)
    {
        decode(code,M,hm[cur].state[k]);
        prs(code,M,seq);
        left=code[j-1];
        up=code[j];
        if(left&&up)//11  -> 00
        {
            if (left==1&&up==1) {
                code[j-1]=code[j]=0;
                code[seq[j]]=1;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].f[k]);
            }
            if (left==1&&up==2) if (i==ex&&j==ey){
                code[j-1]=code[j]=0;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].f[k]);
            }
            if (left==2&&up==1) {
                code[j-1]=code[j]=0;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].f[k]);
            }
            if (left==2&&up==2) {
                code[j-1]=code[j]=0;
                code[seq[j-1]]=2;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].f[k]);
            }
        }
        else if(left+up)
        {
            if(maze[i][j+1])
            {
                code[j-1]=0;
                code[j]=left|up;
                hm[cur^1].push(encode(code,M),hm[cur].f[k]);
            }
            if(maze[i+1][j])
            {
                code[j-1]=left|up;
                code[j]=0;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].f[k]);
            }
        }
        else
        {
            if(maze[i][j+1]&&maze[i+1][j])
            {
                code[j-1]=1,code[j]=2;
                hm[cur^1].push(encode(code,M),hm[cur].f[k]);
            }
        }
    }
}

void dpblock(int i,int j,int cur)
{
    int k;
    for(k=0;k<hm[cur].size;k++)
    {
        decode(code,M,hm[cur].state[k]);
        code[j-1]=code[j]=0;
        if(j==M)shift(code,M);
        hm[cur^1].push(encode(code,M),hm[cur].f[k]);
    }
}

void solve()
{
    ex=N,ey=M;
    if(M==1) {
        puts("1");return;
    }

    int i,j,cur=0;
    ll ans=0;
    hm[cur].init();
    hm[cur].push(0,1);
    for(i=1;i<=N;i++)
      for(j=1;j<=M;j++)
      {
          hm[cur^1].init();
          if(maze[i][j])dpblank(i,j,cur);
          else dpblock(i,j,cur);
          cur^=1;
      }
    for(i=0;i<hm[cur].size;i++)
      ans+=hm[cur].f[i];
    cout<<(ans+ans)<<endl; 
}
int main()
{
//  freopen("bzoj1210.in","r",stdin);
    init();
    solve();
    return 0;
}
