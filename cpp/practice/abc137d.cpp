#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int n,m,i,a,b,ans=0;
	priority_queue<int> q;
	cin >> n >> m;
	vector<vector<int>> v(100000);
	for(i=0;i<n;++i){
		cin >> a >> b;
		--a;
		v.at(a).push_back(b);
	}
	for(i=0;i<m;++i){
		for(auto e : v.at(i)) q.push(e);
		if(!q.empty()){
			ans += q.top();
			q.pop();
		}
	}
	cout << ans << endl;
	return 0;
}	
