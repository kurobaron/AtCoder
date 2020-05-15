#include <iostream>
using namespace std;

int main(){
	int N;
	string S;
	cin >> N;
	cin >> S;
	if(S.length()%2==0 && S.substr(0,S.length()/2)==S.substr(S.length()/2)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}
