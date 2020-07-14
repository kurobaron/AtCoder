#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using ll = long long;
using namespace std;

int main(){
	int n,m,i;
	ll tmp,ans = 0;
	cin >> n >> m;
	priority_queue<ll> q;
	for(i=0;i<n;++i){
		cin >> tmp;
		q.push(tmp);
	}
	for(i=0;i<m;++i){
		q.push(q.top()/2);
		q.pop();
	}
	while(!q.empty()){
		ans += q.top();
		q.pop();
	}
	cout << ans << endl;
	return 0;
}
