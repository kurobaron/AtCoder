#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	int i,j,k,l,K;
	string s,sub;
	cin >> s;
	cin >> K;
	vector<string> S(5,"zzzzzz");
	for(i=0;i<s.length();++i){
		sub = "";
		for(j=0;j<5;++j){
			if(i-j<0) break;
			sub = s[i-j]+sub;
			for(k=0;k<5;++k){
				if(S.at(k)<sub) continue;
				if(S.at(k)==sub) break;
				for(l=4;l>k;--l){
					S[l] = S[l-1];
				}
				S[k] = sub;
				break;
			}
		}
	}
	cout << S.at(K-1) << endl;
	return 0;
}
