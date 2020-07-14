#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,k,i,idx,cnt_m=0,cnt_p=0;
	long long tmp,ans=1;
	cin >> n >> k;
	vector<long long> a(n);
	vector<long long> c(n);
	vector<long long> b;
	for(i=0;i<n;++i){
		cin >> tmp;
		a.at(i) = tmp;
		c.at(i) = abs(tmp);
		if(tmp<0){
			++cnt_m;
			b.push_back(abs(tmp));
		}
		if(tmp>0) ++cnt_p;
	}
	sort(a.begin(),a.end(),greater<long long>());
	sort(b.begin(),b.end(),greater<long long>());
	sort(c.begin(),c.end());
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
			if(k-(idx_p+idx_m)==2) flg = 1;
			if(a.at(idx_p)>=b.at(idx_m)&&flg==0){
				if(ans*a.at(idx_p)/(1000000000+7)>=1) ans = (ans*a.at(idx_p))%(1000000000+7);
				else ans *= a.at(idx_p);
				++idx_p;
			}
			if(a.at(idx_p)<b.at(idx_m)&&flg==0){
				for(i=0;i<2;++i){
					if(ans*b.at(idx_m)/(1000000000+7)>=1) ans = (ans*b.at(idx_m))%(1000000000+7);
					else ans *= b.at(idx_m);
					++idx_m;
				}
			}
			if(flg==1){
				ans1 = ans;
				ans2 = ans;
				for(i=0;i<2;++i){
					if(ans1*a.at(idx_p)/(1000000000+7)>=1) ans1 = (ans1*a.at(idx_p))%(1000000000+7);
					else ans1 *= a.at(idx_p);
					++idx_p;
				}
				for(i=0;i<2;++i){
					if(ans2*b.at(idx_m)/(1000000000+7)>=1) ans2 = (ans2*b.at(idx_m))%(1000000000+7);
					else ans2 *= b.at(idx_m);
					++idx_m;
				}
				ans = max(ans1, ans2);
				break;
			}
		}
	}else{
		idx_m = 0;
		while(1){
			if(ans*c.at(idx_m)/(1000000000+7)>=1) ans = (ans*c.at(idx_m))%(1000000000 + 7);	
			else ans *= c.at(idx_m);
			++idx_m;
			if(idx_m==k){
				ans *= -1;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

