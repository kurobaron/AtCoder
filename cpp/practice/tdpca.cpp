#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,i,j,cnt=0;
	cin >> n;
	vector<int> v(n);
	vector<vector<bool>> b(n+1, vector<bool>(n*100+1));
	for(i=0;i<n;++i){
		cin >> v.at(i);
	}
	for(i=1;i<n+1;++i){
		for(j=1;j<n*100+1;++j){
			if(j>v.at(i-1)){
				b.at(i).at(j) = b.at(i-1).at(j) || b.at(i-1).at(j-v.at(i-1)) || j==v.at(i-1);
			}else b.at(i).at(j) = b.at(i-1).at(j) || j==v.at(i-1);
		}
	}
	for(i=1;i<n*100+1;++i) if(b.at(n).at(i)) ++cnt;
	cout << cnt+1 << endl;
	return 0;
}
