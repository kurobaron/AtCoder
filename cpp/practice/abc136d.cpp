#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	string s;
	int i,idxR,idxL,cnt=1;
	cin >> s;
	vector<int> v(s.length());
	for(i=1;i<s.length();++i){
		++cnt;
		if(s[i-1]=='R'&&s[i]=='L'){
			idxR = i-1;
			idxL = i;
			v.at(i-1) += cnt/2;
			v.at(i) += cnt - cnt/2;
			cnt = 0;
		}
		else if(s[i-1]=='L'&&s[i]=='R'){
			--cnt;
			v.at(idxL) += cnt/2;
			v.at(idxR) += cnt - cnt/2;
			cnt = 1;
		}
	}
	if(cnt>0){
		v.at(idxL) += cnt/2;
		v.at(idxR) += cnt - cnt/2;
	}
	for(i=0;i<v.size();++i) cout << v.at(i) << " ";
	cout << endl;
	return 0;
}	
