#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main(){
	int i,j,ri,ci,r,c,k;
	ll v;
	cin >> r >> c >> k;
	vector<vector<vector<ll>>> dp(r+1, vector<vector<ll>>(c+1, vector<ll>(4)));
	vector<vector<ll>> mp(r+1, vector<ll>(c+1));
	vector<vector<ll>> val(r+1, vector<ll>(c+1));
	for(i=0;i<k;++i){
		cin >> ri >> ci >> v;
		mp.at(ri).at(ci) = v;
	}
	for(i=1;i<r+1;++i){
		for(j=1;j<c+1;++j){
			for(k=0;k<4;++k){
				if(mp.at(i).at(j)==0){
					if(k==0){
						dp.at(i).at(j).at(k) = max(dp.at(i).at(j-1).at(k), val.at(i-1).at(j));
					}else{
						dp.at(i).at(j).at(k) = dp.at(i).at(j-1).at(k);
					}
				}else{
					if(k==0){
						dp.at(i).at(j).at(k) = max(dp.at(i).at(j-1).at(k), val.at(i-1).at(j));
					}else if(k==1){
						dp.at(i).at(j).at(k) = max(dp.at(i).at(j-1).at(k), dp.at(i).at(j).at(k-1)+mp.at(i).at(j));	
					}else{
						dp.at(i).at(j).at(k) = max(dp.at(i).at(j-1).at(k), dp.at(i).at(j-1).at(k-1)+mp.at(i).at(j));
					}
				}
				val.at(i).at(j) = max(val.at(i).at(j), dp.at(i).at(j).at(k));
			}	
		}
	}
	cout << val.at(r).at(c) << endl;
	return 0;
}
