#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1000000;

int main(){
	int N,M,i,a,b;
	cin >> N >> M;
	vector<vector<int>> r(100000);
	for(i=0;i<M;++i){
		cin >> a >> b;
		--a; --b;
		r[a].push_back(b);
		r[b].push_back(a);
	}
	queue<int> q;
	vector<int> dist(100000, INF);
	vector<int> pre(100000);
	q.push(0);
	while(!q.empty()){
		int idx = q.front(); q.pop();
		for(int e : r[idx]){
			if(dist[e]==INF){
				dist[e] = dist[idx] + 1;
				pre[e] = idx;
				q.push(e);
			}	
		}
	}
	cout << "Yes" << endl;
	for(i=1;i<N;++i) cout << pre[i]+1 << endl;
	return 0;
}
