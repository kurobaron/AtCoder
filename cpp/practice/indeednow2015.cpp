#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,m,i,j,k,l,a,b,c;
	cin >> n >> m;
	vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101)));
	vector<vector<int>> cp(n, vector<int>(4));
	vector<vector<int>> pp(m, vector<int>(3));
	for(i=0;i<n;++i) cin >> cp.at(i).at(0) >> cp.at(i).at(1) >> cp.at(i).at(2) >> cp.at(i).at(3);
	for(i=0;i<m;++i) cin >> pp.at(i).at(0) >> pp.at(i).at(1) >> pp.at(i).at(2);
	sort(cp.begin(), cp.end(), [](const vector<int> &alpha, const vector<int> &beta){return alpha.at(3) > beta.at(3);});
	for(i=0;i<n;++i){
		a = cp.at(i).at(0);
		b = cp.at(i).at(1);
		c = cp.at(i).at(2);
		for(j=a;j<101;++j){
			if(dp.at(j).at(b).at(c)!=0) break;
			for(k=b;k<101;++k){
				if(dp.at(j).at(k).at(c)!=0) break;
				for(l=c;l<101;++l){
					if(dp.at(j).at(k).at(l)!=0) break;
					dp.at(j).at(k).at(l) = cp.at(i).at(3);
				}
			}
		}	
	}
	for(i=0;i<m;++i){
		cout << dp.at(pp.at(i).at(0)).at(pp.at(i).at(1)).at(pp.at(i).at(2)) << endl;
	}
	return 0;
}
