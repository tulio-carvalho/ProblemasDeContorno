#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define b 1.
#define a 0.
#define N 2
#define M 2
#define NP 100

FILE *fp;

typedef double (*sistfunc)();

double f(double y[], double t)
{
	return y[1];
}

double g(double y[],double t)
{
	double ym;
	ym=3*y[1]-2*y[0]+6*exp(-t);
	return ym;
}

double rk(sistfunc func[], double y[], double t, double h)
{
	double k1[N], k2[N], k3[N], k4[N], yp[N];
	int i;
	//k1
	for( i=0; i<N; i++) 
		k1[i] = func[i](y,t);
	for( i=0; i<N; i++) 
		yp[i]=y[i]+(k1[i]*(h/2));

	//k2
	for( i=0; i<N; i++) 
		k2[i] = func[i](yp,t + (h/2));	
	for( i=0; i<N; i++) 
		yp[i]=y[i]+(k2[i]*(h/2));
	
        //k3
	for( i=0; i<N; i++) 
		k3[i] = func[i](yp,t + (h/2));
	for( i=0; i<N; i++) 
		yp[i] = y[i]+(k3[i]*h);
	
        //k4
	for( i=0; i<N; i++) 
		k4[i] = func[i](yp,t + h);	
	for( i=0; i<N; i++) 
		y[i] = y[i] + (h/6.0)*(k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
	
	return y[0];
}

void main()
{
		double h,t=0.0,y[N],y1[NP+1];
		sistfunc eq[2]={f,g};
		int i=1,j;
                
		y[0]=2;
		y[1]=2;
		h=(b-a)/NP;
		
		fp=fopen("dados.dat","w");
		
		while(t<b)
		{
			
			y1[0]=rk(eq,y,t,h);
			fprintf(fp,"%f\t%f\n",t,y1[0]);
			t=t+h;
			i++;
			
		}
	fclose(fp);
}
