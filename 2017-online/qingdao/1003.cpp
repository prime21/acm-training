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
#include <bitset>

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
	freopen("1003.in","r",stdin);
	freopen("1003.out","w",stdout);
}
void close()
{
	fclose(stdin);
	fclose(stdout);
}

const int MAXS = 101010;

int tot;
struct ac_node{
	int c[26];
	int fa;
	int fail;
	int id;
	bool vis;
}t[MAXS];
int root;

bool hh[MAXS];
int que[MAXS+1];

char str[101010];
char mx[101010];
int mxlen;
int n;
int cnt;

inline int newnode(){
	tot++;
	FOR(i,0,26) t[tot].c[i]=0;
	t[tot].id=0;
	t[tot].fa=0;
	t[tot].fail=0;
	t[tot].vis=0;
	return tot;
}

void insert(int id){
	int T=root;
	int len=strlen(str+1);
	int p;
	REP(i,1,len)
	{
		p=str[i]-'a';
		if (!t[T].c[p])
		{
			t[T].c[p]=newnode();
			t[p].fa=T;
		}
		T=t[T].c[p];
	}
	if (t[T].id==0)
	t[T].id=id;
	else
		cnt++;
	if (mxlen<len)
	{
		mxlen=len;
		REP(i,1,mxlen) 
			mx[i]=str[i];
		mx[mxlen+1]=0;
	}
}

void init(){
	RI(n);
	tot=-1;
	root=newnode();
	mxlen=0;
	cnt=0;
	REP(i,1,n)
	{
		hh[i]=0;
		RS(str+1);
		insert(i);
	}
}

void prepare(){
	int L=0,R=0;

	FOR(i,0,26)
	if (t[root].c[i])
		que[R++]=t[root].c[i];
	int now=0,pre;
	while (L!=R)
	{
		now=que[L++];
		pre=t[now].fail;
		FOR(i,0,26)
		if(t[now].c[i])
		{
			if (t[pre].c[i])
				t[t[now].c[i]].fail=t[pre].c[i];
			else
				t[t[now].c[i]].fail=root;
			que[R++]=t[now].c[i];
		}
		else
			t[now].c[i]=t[pre].c[i];
	}
}

void up(int p){
	if (t[p].vis) return; 
	t[p].vis=true;
	if (!hh[t[p].id] && t[p].id)
	{
		hh[t[p].id]=true;
		cnt++;
	}
	if (p!=t[p].fail)
		up(t[p].fail);
}

void work()
{
	int T=root;
	REP(i,1,mxlen)
	{
		T=t[T].c[mx[i]-'a'];
		up(T);
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
		prepare();
		work();
		if (cnt==n) 
			printf("%s\n",mx+1);
		else cout << "No" << endl; 
	}
	close();
	return 0;
}

