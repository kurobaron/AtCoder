#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
	int N,i,cnt=0;
	double dist;
	cin >> N;
	vector<int> x(N);
	vector<int> y(N);
	vector<int> idx(N);
	for(i=0;i<N;i++){
		cin >> x[i] >> y[i];
		idx[i] = i;
	}
	do{
		for(i=0;i<N-1;i++){
			dist += sqrt(pow((x[idx[i+1]]-x[idx[i]]),2.0) + pow(y[idx[i+1]]-y[idx[i]],2.0));
		}
		cnt++;
	}while(next_permutation(idx.begin(),idx.end()));
	cout << fixed;
	cout << setprecision(7) << dist/cnt << endl;
	return 0;
}
