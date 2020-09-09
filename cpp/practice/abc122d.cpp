#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
	ll n,len,c1,c2,c3,c,ans=0;
	cin >> n;
	vector<vector<vector<vector<ll>>>> dp(n+1, vector<vector<vector<ll>>>(4, vector<vector<ll>>(4, vector<ll>(4))));
	dp.at(0).at(3).at(3).at(3) = 1;
	for(len=0;len<n;++len){
		for(c1=0;c1<4;++c1){
			for(c2=0;c2<4;++c2){
				for(c3=0;c3<4;++c3){
					if(dp.at(len).at(c1).at(c2).at(c3)==0) continue;
					for(c=0;c<4;++c){
						if(c2==0&&c1==1&&c==2) continue;
						if(c2==0&&c1==2&&c==1) continue;
						if(c2==1&&c1==0&&c==2) continue;
						if(c3==0&&c1==1&&c==2) continue;
						if(c3==0&&c2==1&&c==2) continue;
						dp.at(len+1).at(c).at(c1).at(c2) += dp.at(len).at(c1).at(c2).at(c3);
						dp.at(len+1).at(c).at(c1).at(c2) %= MOD;
					}
				}
			}
		}
	}
	for(c1=0;c1<4;++c1){
		for(c2=0;c2<4;++c2){
			for(c3=0;c3<4;++c3){
				ans += dp.at(n).at(c1).at(c2).at(c3);
				ans %= MOD;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
