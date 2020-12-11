#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(){
	int i,N,ans = 1e6;
	string S;
	cin >> N;
	cin >> S;
	map<char, int> mr;
	map<char, int> ml;
	for(i=0;i<S.length();++i){
		if(S[i]=='E') ++mr['E'];
		else ++mr['W'];
	}
	for(i=0;i<S.length();++i){
		if(S[i]=='E'){
			--mr['E'];
			ans = min(ans, mr['E']+ml['W']);
			++ml['E'];
		}else{
			--mr['W'];
			ans = min(ans, mr['E']+ml['W']);
			++ml['W'];
		}
	}
	cout << ans << endl;
	return 0;
}
