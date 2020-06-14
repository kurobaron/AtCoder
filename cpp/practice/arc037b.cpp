#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
	int N,M,i,t1,t2,flg,idx,cnt=0;
	cin >> N >> M;
	vector<vector<int>> n(N, vector<int>());
	vector<int> seen(N);
	vector<int> pre(N, -1);
	stack<int> s;
	for(i=0;i<M;++i){
		cin >> t1 >> t2;
		--t1; --t2;
		n.at(t1).push_back(t2);
		n.at(t2).push_back(t1);
	}
	for(i=0;i<N;++i){
		flg = 0;
		if(seen.at(i)==1) continue;
		s.push(i);
		seen.at(i) = 1;
		while(!s.empty()){
			idx = s.top(); s.pop();
			auto itr = n.at(idx).begin();
			while(itr!=n.at(idx).end()){
				if(seen.at(*itr)!=1){
				       	s.push(*itr);
					seen.at(*itr) = 1;
					pre.at(*itr) = idx;
				}
				else if(*itr!=pre.at(idx)) flg = 1;
				++itr;
			}
		}
		if(!flg) cnt += 1;
	}
	cout << cnt << endl;
	return 0;
}
