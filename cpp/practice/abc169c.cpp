#include <iostream>
using namespace std;

int main(){
	long long a;
	long double b;
	cin >> a >> b;
	cout << (long long)(a*(long long)(b*100+0.5))/100 << endl;
	return 0;
}
