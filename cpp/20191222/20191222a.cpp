#include <iostream>
using namespace std;

int main(void){
	int a,b;
	cin >> a;
	cin >> b;
	switch(a+b){
		case 3:
			cout << 3 << endl;
			break;
		case 4:
			cout << 2 << endl;
			break;
		case 5:
			cout << 1 << endl;
	}
	return 0;
}

