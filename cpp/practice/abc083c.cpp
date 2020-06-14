#include <iostream>
using namespace std;

int main(){
	long long x,y,cnt=0;
	cin >> x >> y;
	while(x<=y){
		++cnt;
		x *= 2;
	}
	cout << cnt << endl;
	return 0;
}
