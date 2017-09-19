#include <stdio.h>

const int mo = 998244353;

struct matrix{
	int a[2][2];
}I={0},A={0};

matrix operator *(matrix a,matrix b){
	matrix ret={0};
	for (int i=0;i<=1;i++)
	for (int j=0;j<=1;j++)
	for (int k=0;k<=1;k++)
				(ret.a[i][j]+=(a.a[i][k]*1ll*b.a[k][j])%mo)%=mo;
	return ret;
}

matrix power(matrix x,int k){
	matrix tmp=x;
	matrix ret=I;
	while (k)
	{
		if (k&1) ret=ret*tmp;
		tmp=tmp*tmp;
		k>>=1;
	}
	return ret;
}

int get_fib_n(int x){
	if (x<=2) return 1;
	else
	{
		matrix T={0};
		x-=2;
		T=power(A,x);
		return (T.a[0][1]+T.a[1][1])%mo;
	}
}

int main(){
	I.a[0][0]=1,I.a[1][1]=1;
	A.a[0][1]=A.a[1][1]=A.a[1][0]=1;
	int N;
	while (~scanf("%d",&N))
	{
	N+=2;
	printf ("%d\n",(get_fib_n(N*2-1)+mo-1)%mo);
	}
	return 0;
}
