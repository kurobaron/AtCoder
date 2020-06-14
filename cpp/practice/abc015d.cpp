#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int w,n,k,i,j,l,tmp1,tmp2;
	cin >> w;
	cin >> n >> k;
	vector<pair<int, int>> ab(n);
	vector<vector<vector<int>>> v(n+1, vector<vector<int>>(w+1, vector<int>(k+1)));
	for(i=0;i<n;++i){
		cin >> tmp1 >> tmp2;
		ab.at(i) = make_pair(tmp1, tmp2);
	}
	for(i=1;i<n+1;++i){
		for(j=0;j<w+1;++j){
			for(l=0;l<k+1;++l){
				if(ab.at(i-1).first<=j and l>0) v.at(i).at(j).at(l) = max(v.at(i-1).at(j-ab.at(i-1).first).at(l-1)+ab.at(i-1).second, v.at(i-1).at(j).at(l));
				else v.at(i).at(j).at(l) = v.at(i-1).at(j).at(l);	
			}
		}
	}
	cout << v.at(n).at(w).at(k) << endl;
	return 0;
}
