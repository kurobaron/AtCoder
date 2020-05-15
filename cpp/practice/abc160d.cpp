#include <iostream>
#include <vector>
#include <queue>
#define rep(a,b) for(int a=0;a<(int)b;a++)
const int INF = 1000000000;
using namespace std;

int main(){
	int N,X,Y;
	cin >> N >> X >> Y;
	--X; --Y;
	vector<int> ans(N); 
	queue<int> q;
	rep(idx, N){
		vector<int> dist(N, INF);
		auto push = [&](int ix, int dt){
			if (dist[ix]!=INF) return;
			dist[ix] = dt;
			q.push(ix);
		};
		push(idx, 0);
		while(!q.empty()){
			int v = q.front();
			q.pop();
			int d = dist[v];
			if(v-1>=0) push(v-1, d+1);
			if(v+1<N) push(v+1, d+1);
			if(v==X) push(Y, d+1);
			if(v==Y) push(X, d+1);
		}
		rep(i, N) ans[dist[i]]++;
	}		
	rep(i,N) ans[i]/=2;
	for(int i=1;i<N;i++) cout << ans[i] << endl;
	return 0;
}
