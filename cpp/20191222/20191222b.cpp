#include <iostream>
using namespace std;

int main(void){
	string s,t;
	int n,i;
	cin >> n;
	cin >> s >> t;
	for(i=0;i<n;i++){
		cout << s[i] << t[i];
		if (i==n-1){
			cout << endl;
		}
	}
	return 0;
}
