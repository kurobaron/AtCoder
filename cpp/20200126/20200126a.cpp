#include <iostream>
using namespace std;

int main(void){
	int H,A;
	cin >> H >> A;
	if(H%A != 0){
		cout << H/A+1 << endl;
	}else{
		cout << H/A << endl;
	}	
	return 0;
}
