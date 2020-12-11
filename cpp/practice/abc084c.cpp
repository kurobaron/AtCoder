#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,j,N,cnt;
	cin >> N;
	vector<int> C(N-1);
	vector<int> S(N-1);
	vector<int> F(N-1);
	for(i=0;i<N-1;++i) cin >> C.at(i) >> S.at(i) >> F.at(i);
	for(i=0;i<N-1;++i){
		cnt = C.at(i)+S.at(i);
		for(j=i+1;j<N-1;++j){	
			if(cnt<=S.at(j)){
				cnt += S.at(j)-cnt+C.at(j);
			}else{
				if(cnt%F.at(j)==0) cnt += C.at(j);
				else cnt += F.at(j)-cnt%F.at(j)+C.at(j);
			}
		}
		cout << cnt << endl;
	}
	cout << 0 << endl;
	return 0;
}
