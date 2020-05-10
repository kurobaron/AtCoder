#include <iostream>
using namespace std;

int main(){
	int i,cnt=0;
	string s;
	cin >> s;
	for(i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-1-i]){
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
