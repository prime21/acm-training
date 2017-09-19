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
	freopen("1008.in","r",stdin);
	freopen("1008.out","w",stdout);
}
void close()
{
	fclose(stdin);
	fclose(stdout);
}

const int MAXN = 101010;
const int MAXM = 402020;
const int MAXQ = 101010;
const int inf = 1e9;

int n;
int tot;
int hd[MAXN];
int vl[MAXM];
int nxt[MAXM];
int to[MAXM];
int mn[MAXN];
int dp[MAXN][2]; 
inline void add(const int &x,const int &y,const int&v){
	tot++;
	to[tot]=y;
	vl[tot]=v;
	nxt[tot]=hd[x];
	hd[x]=tot;
}

void init(){
	RI(n);
	tot=0;
	MS(hd,0);
	int u,v,z;
	REP(i,1,n) RI(mn[i]);
	FOR(i,1,n)
	{
		RIII(u,v,z);
		add(u,v,z);
		add(v,u,z);
	}
}

void dfs(int p,int fa=0){
	dp[p][0]=inf;
	dp[p][1]=-inf;
	int t0,t1;
	for (int i=hd[p];i;i=nxt[i])
		if (to[i]!=fa)
		{
			dfs(to[i],p);
			t0=min(dp[to[i]][0]+vl[i],mn[to[i]]+vl[i]);
			t1=max(dp[to[i]][1]-vl[i],mn[to[i]]-vl[i]);
			dp[p][0]=min(dp[p][0],t0);
			dp[p][1]=max(dp[p][1],t1);
		}
}

int main()
{
	open();
	int _=0;
	RI(_);
	REP(__,1,_)
	{
		init();
		dfs(1);
		int ans=-(inf*2);
		REP(i,1,n)
		{
			ans=max(ans,-dp[i][0]+dp[i][1]);
			ans=max(ans,-dp[i][0]+mn[i]);
			ans=max(ans,dp[i][1]-mn[i]);
		}
		printf("%d\n",ans);
	}
	close();
	return 0;
}

