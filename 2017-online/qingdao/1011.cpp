#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>

#define REP(I,A,B) for (int I=(A),I##_END_=(B);I<=I##_END_;I++)
#define REPD(I,A,B) for (int I=(A),I##_END_=(B);I>=I##_END_;I--)
#define FOR(I,A,B) for (int I=(A),I##_END_=(B);I<I##_END_;I++)
#define RI(X) scanf("%d",&X)
#define RII(X,Y) RI(X),RI(Y)
#define RIII(X,Y,Z) RI(X),RI(Y),RI(Z)
#define RL(X) X=Readint()
#define RLL(X,Y) RL(X),RL(Y)
#define RLLL(X,Y,Z) RL(X),RL(Y),RL(Z)
#define RS(X) scanf("%s",X)
#define RD(X) scanf("%lf",&X)
#define GCH getchar()
#define PCH(X) putchar(X)
#define MS(X,Y) memset(X,Y,sizeof(X))
#define MC(X,Y,var,len) memcpy(X,Y,sizeof(var)*(len))
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define pb(X) push_back(X)
#define mp(A,B) make_pair(A,B)
#define fr first
#define sc second
#define lch(p) (p+p)
#define rch(p) (p+p+1)
#define lowbit(X) ((X)&(-(X)))

using namespace std;

typedef pair<int,int> poi;
typedef vector<int> vi;

inline long long Readint()
{
	long long ret=0;
	int f=1;
	char ch;
	do
	{
		ch=GCH;
		if (ch=='-') f*=-1;
	}while(ch>=0 && (ch<'0' || ch>'9'));

	while ('0'<=ch && ch<='9')
	{
		ret=ret*10+ch-'0';
		ch=GCH;
	}
	return ret*f;
}

void open()
{
	freopen("1011.in","r",stdin);
	freopen("1011.out","w",stdout);
}
void close()
{
	fclose(stdin);
	fclose(stdout);
}

set<long long> S;

char a[][20]={"NO","YES"};
long long k;

void init(){
	long long tmp=1;
	long long now;
	REP(i,2,580000)
	{
		now=i;
		now=now*now*now;
		S.insert(now-tmp);
		tmp=now;
	}
}

bool check(long long x){
	return S.count(x);
}

int main()
{
	open();
	int _=0;
	RI(_);
		init();
	REP(__,1,_)
	{
		cin >> k;
		if (check(k)) cout << "YES" <<endl;
		else cout << "NO" << endl;
	}
	close();
	return 0;
}
