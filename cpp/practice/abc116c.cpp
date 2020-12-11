#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,N,tot=0,ans=0;
	cin >> N;
	vector<int> h(N);
	for(i=0;i<N;++i){
		cin >> h.at(i);
		tot += h.at(i);
	}
	while(tot>0){
		for(i=0;i<N;++i){
			if(i==N-1){
				if(h.at(i)>0){
					++ans;
					--h.at(i);
					--tot;
				}
				break;
			}
			if(h.at(i)>0){
				if(h.at(i+1)==0) ++ans;
				--h.at(i);
				--tot;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
