#include<iostream>
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
struct point{
	double a;
	double b;
	double c;
	double b_a;
	double b_b;
	double b_c;
	double v_a;
	double v_b;
	double v_c;
	double best;
};

point p[50];
double c1=2,c2=2;
double g_a,g_b,g_c,g_best;
int main(){
	p[0].a=rand()%1000;
	p[0].b=rand()%1000;
	p[0].c=rand()%1000;
	p[0].b_a=p[0].a;
	p[0].b_b=p[0].b;
	p[0].b_c=p[0].c;
	p[0].v_a=0;
	p[0].v_b=0;
	p[0].v_c=0;
	p[0].best=p[0].a*p[0].a+p[0].b*p[0].b+p[0].c*p[0].c;
	g_best=p[0].best;
	for(int i=1;i<50;i++){
		p[i].a=rand()%1000;
		p[i].b=rand()%1000;
		p[i].c=rand()%1000;
		p[i].b_a=p[i].a;
		p[i].b_b=p[i].b;
		p[i].b_c=p[i].c;
		p[i].v_a=0;
		p[i].v_b=0;
		p[i].v_c=0;
		p[i].best=p[i].a*p[i].a+p[i].b*p[i].b+p[i].c*p[i].c;
		if(p[i].best<g_best){
			g_best=p[i].best;
			g_a=p[i].a;
			g_b=p[i].b;
			g_c=p[i].c;
		}
	}

int iterations=1000;
double w=1;
for(int j=0;j<iterations;j++){
	for(int i=0;i<50;i++){
		p[i].v_a=w*p[i].v_a+c1*(rand()%1000)*0.001*(p[i].b_a-p[i].a)+c2*(rand()%1000)*0.001*(g_a-p[i].a);
		p[i].v_b=w*p[i].v_b+c1*(rand()%1000)*0.001*(p[i].b_b-p[i].b)+c2*(rand()%1000)*0.001*(g_b-p[i].b);
		p[i].v_c=w*p[i].v_c+c1*(rand()%1000)*0.001*(p[i].b_c-p[i].c)+c2*(rand()%1000)*0.001*(g_c-p[i].c);
		p[i].a=p[i].a+p[i].v_a;
		p[i].b=p[i].b+p[i].v_b;
		p[i].c=p[i].c+p[i].v_c;
	if(p[i].best>(p[i].a*p[i].a+p[i].b*p[i].b+p[i].c*p[i].c)){
		p[i].best=p[i].a*p[i].a+p[i].b*p[i].b+p[i].c*p[i].c;
			p[i].b_a=p[i].a;
			p[i].b_b=p[i].b;
			p[i].b_c=p[i].c;
	}
	if(p[i].best<g_best){
		g_best=p[i].best;
		g_a=p[i].a;
		g_b=p[i].b;
		g_c=p[i].c;
	}
	}
	w=w*0.99;
cout<<g_a<<" "<<g_b<<" "<<g_c<<endl;
}
}
