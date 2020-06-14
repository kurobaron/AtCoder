#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sort_at_second(pair<int, int> a, pair<int, int> b){
	if(a.second!=b.second) return a.second < b.second;
	else return a.first < b.first;
}

int main(){
	int n,m,i,t1,t2,cnt=0,cut_point=-1;
	cin >> n >> m;
	vector<pair<int, int>> r;
	for(i=0;i<m;++i){
		cin >> t1 >> t2;
		--t1; --t2;
		r.push_back(make_pair(t1, t2));
	}
	sort(r.begin(), r.end(), sort_at_second);
	for(i=0;i<m;++i){
		if(r.at(i).first>cut_point){
			cut_point = r.at(i).second - 1;
			++cnt;
		}
	}
	cout << cnt << endl;
	return 0;
}
