#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,i,j,tmp;
	cin >> n;
	vector<int> s(1, 100000);
	for(i=0;i<n;++i){
		cin >> tmp;
		for(j=0;j<s.size();++j){
		       	if(s[j]>=tmp){
				s[j] = tmp;
				break;
			}
			if(j==s.size()-1) s.push_back(tmp);
		}
	}
	cout << s.size() << endl;
	return 0;
}	
