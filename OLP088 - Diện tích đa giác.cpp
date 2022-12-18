#include<bits/stdc++.h>
using namespace std;
struct dl{
	int x,y;
};
double s(double c1,double c2,double c3){
	double p=(c1+c2+c3)/2;
	p=p*(p-c1)*(p-c2)*(p-c3);
	p=sqrt(p);
	return p;
}
double d(dl a,dl b){
	double d1=a.x-b.x;
	d1*=d1;
	double d2=a.y-b.y;
	d2*=d2;
	return sqrt(d1+d2);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		double S=0;
		int n;
		cin>>n;
		dl a[n];
		for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y;
		double c1,c2,c3;
		for(int i=1;i<n-1;i++){
			c1=d(a[0],a[i]);
			c2=d(a[0],a[i+1]);
			c3=d(a[i],a[i+1]);
			S+=s(c1,c2,c3);
		}
		printf("%.3lf\n",S);
	}
}
