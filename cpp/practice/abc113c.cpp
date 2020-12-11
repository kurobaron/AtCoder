#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int i,N,M,p,y;
	cin >> N >> M;
	vector<vector<pair<int,int>>> dt(N+1);
	vector<int> ans1(M);
	vector<int> ans2(M);
	for(i=0;i<M;++i){
		cin >> p >> y;
		ans1.at(i) = p;
		dt.at(p).push_back({y,i});
	}
	for(i=0;i<=N;++i){
		if(dt.at(i).size()==0) continue;
		sort(dt.at(i).begin(),dt.at(i).end());
		auto it = dt.at(i).begin();
		while(it!=dt.at(i).end()){
			pair<int,int> p = *it;
			ans2.at(p.second) = distance(dt.at(i).begin(),it)+1;
			++it;
		}
	}
	for(i=0;i<M;++i){
		printf("%06d",ans1.at(i));
		printf("%06d\n",ans2.at(i));
	}
	return 0;
}
