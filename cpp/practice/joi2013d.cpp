#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int d,n,t_low,t_high,p,i,j,k,tmp;
	cin >> d >> n;
	vector<vector<int>> li(d);
	vector<vector<int>> pmax(d, vector<int>(n));
	vector<int> t(d);
	for(i=0;i<d;++i) cin >> t.at(i);
	for(i=0;i<n;++i){
		cin >> t_low >> t_high >> p;
		for(j=0;j<d;++j) if(t_low<=t.at(j) && t.at(j)<=t_high) li.at(j).push_back(p);
	}
	for(i=1;i<d;++i){
		for(j=0;j<li.at(i).size();++j){
			tmp = 0;
			for(k=0;k<li.at(i-1).size();++k){
				if(tmp<pmax.at(i-1).at(k)+abs(li.at(i).at(j)-li.at(i-1).at(k))) tmp = pmax.at(i-1).at(k)+abs(li.at(i).at(j)-li.at(i-1).at(k));
			}
			pmax.at(i).at(j) = tmp;
		}
	}
	sort(pmax.at(d-1).begin(), pmax.at(d-1).end());
	cout << *(pmax.at(d-1).end()-1) << endl;
	return 0;
}
