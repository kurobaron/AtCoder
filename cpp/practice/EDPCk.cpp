#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,N,K;
	cin >> N >> K;
	vector<int> a(N);
	vector<bool> ans(K+1);
	for(i=0;i<N;++i) cin >> a.at(i);
	for(i=0;i<N;++i) ans.at(a.at(i)) = true;
	for(i=a.at(0);i<=K;++i){
		if(ans.at(i)==true) continue;
		for(auto &e : a){
			if(i-e<0) break;
			if(ans.at(i-e)==false){
				ans.at(i) = true;
				break;
			}
		}
	}
	if(ans.at(K)==true) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}	
