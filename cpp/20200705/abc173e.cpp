#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,k,i,idx,cnt_m=0,cnt_p=0;
	long long tmp,ans=1;
	cin >> n >> k;
	vector<long long> a(n);
	vector<long long> b;
	for(i=0;i<n;++i){
		cin >> tmp;
		a.at(i) = tmp;
		if(tmp<0){
			++cnt_m;
			b.push_back(abs(tmp));
		}
		if(tmp>0) ++cnt_p;
	}
	sort(a.begin(),a.end(),greater<long long>());
	sort(b.begin(),b.end(),greater<long long>());
	if(k<cnt_p){
		idx_p = 0;
		while(1){
			if(ans*a.at(idx_p)/(1000000000+7)>=1) ans = (ans*a.at(idx_p))%(1000000000 + 7);	
			else ans *= a.at(idx_p);
			++idx_p;
			if(idx_p==k) break;
		}
	}else if((k-cnt_p)%2==0){
		idx_m = 0;
		idx_p = 0;
		while(1){
			if(a.at(idx_p)>=b.at(idx_m)&&flg==0){
				if(k-(idx_p+idx_m)==2){
					flg = 1;
					continue;
				}
				if(ans*a.at(idx_p)/(1000000000+7)>=1) ans = (ans*a.at(idx_p))%(1000000000+7);
				else ans *= a.at(idx_p);
				++idx_p;
			}else{
				if(ans*b.at(idx_m)/(1000000000+7)>=1) ans = (ans*b.at(idx_m))%(1000000000+7);
				else ans *= b.at(idx_m);
				++idx_m;
				if(ans*b.at(idx_m)/(1000000000+7)>=1) ans = (ans*b.at(idx_m))%(1000000000+7);
				else ans *= b.at(idx_m);
				++idx_m;
			}
			if(idx_p+idx_m==k) break;
		}
	}else

				
				
			if(ans*b.at(idx_m)>1000000000+7) ans = (ans*b.at(idx))%(1000000000 + 7);	
			else ans = ans*b.at(idx);
			if(idx+1==k) break;
			++idx;
		}
	}else{
		idx = 0;
		sort(a.begin(),a.end());
		while(1){
			if(a.at(idx)==0) continue;
			if(ans*b.at(idx)>1000000000+7) ans = (ans*b.at(idx))%(1000000000 + 7);	
			else ans = ans*b.at(idx);
			if(idx+1==k) break;
			++idx;
		}
	}
	cout << ans << endl;
	return 0;
}

