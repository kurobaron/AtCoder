#include <iostream>
#include <vector>
using namespace std;

bool dfs(int n, int v, int N, int K, vector<vector <int>> &T){
	if(n==N) return v==0;
	for(int i=0;i<K;++i){
		if(dfs(n+1, v^T[n][i], N, K, T)) return true;
	}
	return false;
}

int main(){
	int N,K,i,j;
	cin >> N >> K;
	vector<vector<int>> T(N, vector<int>(K));
	for(i=0;i<N;++i){
		for(j=0;j<K;++j){
			cin >> T[i][j];
		}
	}

	
	if(dfs(0, 0, N, K, T)) cout << "Found" << endl;
	else cout << "Nothing" << endl;
	return 0;
}
	
	
