#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 9
#define a 0.
#define b M_PI/2
#define alpha -0.3
#define beta -0.1

void main()
{
	double h,x, A[N], B[N], C[N], D[N], l[N], u[N], z[N], w[N+1], m[N][N];
	int i,j;
	
	h=(b-a)/(N+1);
	x= a+h;
	A[1]=2+h*h*2;
	B[1]=-1+(h/2);
	D[1]=-h*h*cos(x) + (1+(h/2))*alpha;
	
	for(i=2; i<=N-1; i++)
	{
		x=a+i*h;
		A[i]=2+h*h*2;
		B[i]= -1+(h/2);
		C[i]= -1-(h/2);
		D[i]= -h*h*cos(x);
	}
	
	x=b-h;
	A[N]=2+h*h*2;
	C[N]=-1-(h/2);
	D[N]=-h*h*cos(x)+(1-(h/2))*beta;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(i=j)
				m[i][j]=A[i];
			if(i>j && (i+j)%2!=0)
				m[i][j]=C[i];
			if(i<j && (i+j)%2!=0)
				m[i][j]=B[i];
		}
	}
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%f\t", m[i][j]);
		}
		printf("\n");
	}
	
	
	l[1]=A[1];
	u[1]=B[1]/A[1];
	z[1]=D[1]/l[1];
	
	for(i=2; i<=N-1; i++)
	{
		l[i]=A[i]-C[i]*u[i-1];
		u[i]=B[i]/l[i];
		z[i]=(D[i]-C[i]*z[i-1])/l[i];
	}
	
	l[N]=A[N]-C[N]*u[N-1];
	z[N]=(D[N]-C[N]*z[N-1])/l[N];
	
	w[0]=alpha;
	w[N+1]=beta;
	w[N]=z[N];
	
	for(i=N-1; i>=1; i--)
		w[i]=z[i]-u[i]*w[i+1];
	for(i=0; i<N+1; i++)
		x=a+i*h;
			
}
	
	
		
