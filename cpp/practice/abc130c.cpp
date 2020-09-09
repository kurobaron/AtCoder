#include <iostream>
using namespace std;
using ll = long long;

int main(){
	ll w,h,x,y,jud=0;
	cin >> w >> h >> x >> y;
	if(x==w/2.0&&y==h/2.0) jud = 1;
	cout << (w*h)/2.0 << " " << jud << endl;
	return 0;
}	
