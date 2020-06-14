#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int i,j,idx,flg;
	string s,t;
	cin >> s;
	cin >> t;
	for(i=0;i<s.length()-t.length()+1;++i){
		flg = 0;
		idx = s.length()-t.length()-i;
		for(j=0;j<t.length();++j){
			if(s[idx+j]!='?' && s[idx+j]!=t[j]){
				flg = 1;
				break;
			}
		}
		if(flg==1) continue;
		else for(j=0;j<t.length();++j) s[idx+j] = t[j];
		break;
	}
	if(flg==0){
		for(i=0;i<s.length();++i) if(s[i]=='?') s[i] = 'a';
		cout << s << endl;
	}else cout << "UNRESTORABLE" << endl;
	return 0;
}
