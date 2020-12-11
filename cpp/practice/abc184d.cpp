#include <iostream>
#include <vector>
using namespace std;

double Solve(int i, int j, int k, vector<vector<vector<double>>> &memo){
	if(memo.at(i).at(j).at(k)!=-1) return memo.at(i).at(j).at(k);
	if(i==100||j==100||k==100){
		memo.at(i).at(j).at(k) = 0.0;
		return 0.0;
	}
	double ret;
	ret = ((Solve(i+1,j,k,memo)+1)*(double)i+(Solve(i,j+1,k,memo)+1)*(double)j+(Solve(i,j,k+1,memo)+1)*(double)k)/(double)(i+j+k);
	memo.at(i).at(j).at(k) = ret;
	return ret;
}

int main(){
	int A,B,C;
	double ans;
	cin >> A >> B >> C;
	vector<vector<vector<double>>> memo(101,vector<vector<double>>(101,vector<double>(101,-1)));
	ans = Solve(A,B,C,memo);
	printf("%.9f\n",ans);
	return 0;
}
