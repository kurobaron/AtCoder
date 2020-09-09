#include <iostream>
#include <string>
using namespace std;

int main(){
	int i,cnt_0=0,cnt_1=0;
	string s;
	cin >> s;
	for(i=0;i<s.length();++i){
		if(s[i]=='0') ++cnt_0;
		else ++cnt_1;
	}
	cout << 2*min(cnt_0,cnt_1) << endl;
	return 0;
}
