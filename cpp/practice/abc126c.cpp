#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int i,p;
	double n,k,prob_eye,prob=0;
	cin >> n >> k;
	for(i=1;i<n+1;++i){
		p = 0;
		prob_eye = 1.0/n;
		if(i<k){
			while(i*pow(2.0,p)<k) ++p;
			prob_eye *= 1.0/pow(2.0,p);
		}
		prob += prob_eye;
	}
	printf("%.10lf\n",prob);
	return 0;
}
