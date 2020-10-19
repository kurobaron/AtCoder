#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,j,N;
	double ans=0.0;
	cin >> N;
	vector<double> p(N);
	for(i=0;i<N;++i) cin >> p.at(i);
	vector<vector<double>> dp(N+1,vector<double>(N+1));
	dp.at(0).at(0) = 1;
	for(i=1;i<=N;++i){
		for(j=0;j<=i;++j){
			if(j==0) dp.at(i).at(j) = dp.at(i-1).at(j)*(1.0-p.at(i-1));
			else dp.at(i).at(j) = dp.at(i-1).at(j-1)*p.at(i-1)+dp.at(i-1).at(j)*(1.0-p.at(i-1));
		}
	}
	for(i=N/2+1;i<=N;++i) ans += dp.at(N).at(i);
	printf("%.10f\n", ans);
	return 0;
}
