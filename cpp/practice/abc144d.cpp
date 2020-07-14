#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	double a,b,x;
	cin >> a >> b >> x;
	if(x<=a*a*b/2) cout << fixed << setprecision(10) << 90-180/M_PI*atan(2*x/(a*pow(b,2))) << endl;
	else cout << fixed << setprecision(10) << 180/M_PI*atan((2*pow(a,2)*b-2*x)/pow(a,3)) << endl;
	return 0;
}
