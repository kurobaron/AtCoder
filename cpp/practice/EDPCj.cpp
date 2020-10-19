#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,j,k,N,a,cnt1=0,cnt2=0,cnt3=0;
	cin >> N;
	vector<vector<vector<double>>> d(302,vector<vector<double>>(302,vector<double>(302)));
	for(i=0;i<N;++i){
		cin >> a;
		if(a==1) ++cnt1;
		else if(a==2) ++cnt2;
		else ++cnt3;
	}
	for(k=0;k<=300;++k){
		for(j=0;j<=300;++j){
			for(i=0;i<=300;++i){
				if(i==0&&j==0&&k==0) continue;
				if(i+j+k>300) continue;
				d.at(i).at(j).at(k) += (double)N/(double)(i+j+k);
				if(i>0) d.at(i).at(j).at(k) += (double)i/(double)(i+j+k)*d.at(i-1).at(j).at(k);
				if(j>0) d.at(i).at(j).at(k) += (double)j/(double)(i+j+k)*d.at(i+1).at(j-1).at(k);
				if(k>0) d.at(i).at(j).at(k) += (double)k/(double)(i+j+k)*d.at(i).at(j+1).at(k-1);
			}
		}
	}
	printf("%.10f\n", d.at(cnt1).at(cnt2).at(cnt3));
	return 0;
}
