//#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
//#pragma warning(disable:4996)

using namespace std;

#define LL long long
#define ULL unsigned long long
#define LD long double

#define Rep(x,y,i) for (int i=x;i<y;i++) //[x,y)
#define RepD(x,y,i) for (int i=x;i>y;i--) //(y,x]
#define Mem(X) memset(X,0,sizeof(X));
#define Pr(X) cout<<" "<<#X<<"="<<X<<" ";
#define PrL(X) cout<<#X<<" = "<<X<<endl;
#define PrLL cout<<endl;
using namespace std;
const double EPS = 1e-10;


#define IntMod 10000
struct BigInt
{
private:
	vector<int> A;
	bool Positive;
	int VecNum;

public:
	//Constructors
	inline int GetLength(LL a) {int t=0; while (a>0) {a/=IntMod; t++;} return t;}
	BigInt() { Positive = 1; VecNum = 0; }
	BigInt(const BigInt &a) { A = a.A; VecNum = a.VecNum; Positive = a.Positive; }
	BigInt(string s)
	{
		A.reserve(100);
		if (s == "-0") { A.push_back(0); Positive = 1; VecNum = 1; return; }
		int kk = 3; int kl = 0;
		int l = s.length();
		int j = l - 1;
		if (s[0] == '-') { Positive = 0; kk++; kl++; }
		else Positive = 1;
		while (j>kk)
		{
			int t = 0;
			Rep(0, 4, i) { t *= 10; t += s[j - (3 - i)] - '0'; }
			j -= 4;
			A.push_back(t);
		}
		int t = 0;
		int k = j + 1;
		Rep(kl, k, i) { t *= 10; t += s[i] - '0'; }
		A.push_back(t);
		VecNum = A.size();
	}
	BigInt(const LL &b)
	{
		LL a=b;
		Positive=(a>=0);
		VecNum=GetLength(abs(a));
		A.resize(VecNum);
		Rep(0,VecNum,i)
		{
			A[i]=a%IntMod;
			a/=IntMod;
		}
	}
	//BigInt& operator = (BigInt& a) { VecNum=a.VecNum; Positive=a.Positive; A=a.A; }
	BigInt& operator = (const string s) { BigInt x(s); *this=x; }
	BigInt& operator = (LL s) { BigInt x(s); *this = x; }
	
	//Basic Math Functions
	friend BigInt abs(BigInt a) { a.Positive=1; return a; }
	friend bool isnegative(BigInt &a) { return a.Positive; }
	BigInt& operator - () { Positive = !(Positive); return *this; }
	
	// Ostream and Instream
	friend ostream& operator << (ostream &out, BigInt &a)
	{
		if (a.VecNum==0)
		{
			out<<"0";
			return out;
		}   //Bug Fixed if there is a BigInt constructed by the default constructor
		if (!a.Positive) out << "-";
		out << a.A[a.VecNum - 1];
		RepD(a.VecNum - 2, -1, i)
		{
			if (a.A[i] == 0) { out << "0000"; continue; }
			Rep(0, (int)(4 - log(a.A[i]) / log(10) - EPS), j) out << '0';
			out << a.A[i];
		}
		return out;
	}
	friend istream& operator >> (istream &in, BigInt &a)
	{
		string s;
		in >> s;
		int L = s.length() - 1;int i = 0;bool flag = 0;
		if (s[i] == '-') { i++; flag = 1; }
		while (s[i] == '0' && i < L) i++;
		string b(s.begin() + i, s.end());
		if (flag) b.insert(0, "-");
		a = BigInt(b);
		return in;
	}

	//Bool Operators
	bool operator < (const BigInt &b) const
	{
		if (Positive &&  b.Positive)
		{
			if (VecNum != b.VecNum) return (bool)(VecNum<b.VecNum);
			RepD(VecNum-1, -1, i)
				if (A[i] != b.A[i])
					return (bool)(A[i]<b.A[i]);
			//Bug Fixed that there should be a RepD rather that Rep
			return 0;
		}
		if (!Positive &&  b.Positive) return 1;
		if (Positive && !b.Positive)  return 0;
		BigInt a = b;
		BigInt c = (*this);
		if (!c.Positive && !a.Positive) return !((-c) < (-a));
		return 1;
	}
	bool operator >  (const BigInt &b) const { return !((*this)<b); }
	bool operator == (const BigInt &b) const { return (Positive == b.Positive && A == b.A && VecNum == b.VecNum); }
	bool operator <= (const BigInt &b) const { return (*this == b) || (*this < b); }
	bool operator >= (const BigInt &b) const { return (*this == b) || !(*this < b);}
	bool operator != (const BigInt &b) const { return !(*this == b); }
	
	bool operator <  (const string b) const { BigInt x(b); return (*this) < x; }
	bool operator == (const string b) const { BigInt x(b); return x==(*this) < x; }
	bool operator >  (const string b) const 
	bool operator <= (const string b) const
	bool operator >= (const string b) const
	bool operator != (const string b) const 
	
	bool operator <  (const LL& b) const { BigInt x(b); return *this < x; }
	bool operator == (const LL& b) const { BigInt x(b); return *this == x; }
	bool operator >  (const LL& b) const 
	bool operator <= (const LL& b) const
	bool operator >= (const LL& b) const
	bool operator != (const LL& b) const 
	
	//Function of Plus and Minus
	BigInt operator - (const BigInt &b) const
	{
		BigInt x=*this;
		BigInt y=b;
		
		if (!x.Positive &&  y.Positive) return -(-x + y);
		if ( x.Positive && !y.Positive) return x + y;
		if (!x.Positive && !y.Positive) return (-y) - (-x);
		if (x<y) return  -(y - x);
		
		int L = max(x.VecNum, y.VecNum);
		y.A.resize(L);
		x.A.resize(L);
		Rep(0, L, i)
		{
			x.A[i] -= y.A[i];
			if (x.A[i]<0) { x.A[i] += IntMod; x.A[i + 1]--; }
		}
		while (x.A[L - 1] == 0 && ((L-1)!=0) ) { x.VecNum--; x.A.pop_back(); L--; }
		return x;
	}
	BigInt operator + (const BigInt &b) const
	{
		BigInt x=*this;
		BigInt y=b;
		
		if (!x.Positive &&  y.Positive) return y - (-x);
		if (!x.Positive && !y.Positive) return -(-x + (-y));
		if ( x.Positive && !y.Positive)  return x - (-y);
		int L = max(x.VecNum, y.VecNum);
		x.A.resize(L + 1);
		y.A.resize(L + 1);
		for (int i = 0; i<L; i++) x.A[i] += y.A[i];
		for (int i = 0; i<L; i++)
		{ x.A[i + 1] += x.A[i] / IntMod; x.A[i] %= IntMod; }
		x.VecNum = L;
		if (x.A[L]) x.VecNum++;
		else x.A.erase(x.A.begin() + L);
		return x;
	}
	BigInt operator - (const LL &b) const { BigInt y(b); return *this - y; }
	BigInt operator + (const LL &b) const { BigInt y(b); return *this + y; }
	BigInt operator - (const string b) const { BigInt y(b); return *this - y; }
	BigInt operator + (const string b) const { BigInt y(b); return *this + y; }
	BigInt operator += (const BigInt& b) { *this=*this+b; return *this; }
	BigInt operator += (const LL& b)     { *this=*this+b; return *this; }
	BigInt operator -= (const BigInt& b) { *this=*this-b; return *this; }
	BigInt operator -= (const LL& b)     { *this=*this-b; return *this; }
	
	
	//Function of Multiply and Division
	BigInt operator * (const BigInt& b) const
	{
		BigInt x=*this;
		BigInt y=b;
		BigInt ans;
		if ((x.Positive && y.Positive) || (!x.Positive && !y.Positive)) ans.Positive=1;
		else ans.Positive=0;
		int m=x.VecNum,n=y.VecNum;
		int L=m+n+1;
		ans.VecNum=L;
		ans.A.resize(L+3);
		Rep(0,m,i)
			Rep(0,n,j)
			{
				int pos=i+j;
				LL t=x.A[i]*y.A[j];
				int post=0;
				while (t>0)
				{
					ans.A[pos+post]+=t%IntMod;
					t/=IntMod;
					post++;
				}
			}
		Rep(0,L,i) { ans.A[i + 1] += ans.A[i] / IntMod; ans.A[i] %= IntMod; }
		while (ans.A[L - 1] == 0 && ((L-1)!=0) ) { ans.VecNum--; ans.A.pop_back(); L--; }
		return ans;
	}
	BigInt operator * (const LL &b) const    { BigInt x(b); return (*this) * x; }
	BigInt operator * (const string b) const { BigInt x(b); return (*this) * x; }
	BigInt operator *= (const BigInt& b){ *this = *this * b; return *this; }
	BigInt operator *= (const LL &b)    { *this = *this * b; return *this; }
	BigInt operator *= (const string b) { *this = *this * b; return *this; }
	
	BigInt operator / (const BigInt& b) const
	{
		
	}
	
	//Function of Remainder
	BigInt operator % (const BigInt& b) const
	{
		
	}
	
	//Function of BITS
};

int main()
{
	//freopen("D:\\YA.in","r",stdin);
	//freopen("mul.in","r",stdin);
	//freopen("mul.out","w",stdout);
	BigInt a(123456);
	
	BigInt b=(string)"123456";
	
	BigInt c=a*"123456";
	cout<<c<<endl;
	//BigInt c=a*b;
	//cout<<c<<endl;
}

//Equals A/B
struct BigDec:public BigInt
{
private:
	BigInt A;
	BigInt B;
	bool Positive;
	
public:
	BigDec() { Positive=1; A="0"; B="1"; }
	BigDec(string s) { }
	BigDec(double t) { } 
	BigDec(LL t) { }
};




