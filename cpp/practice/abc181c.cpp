#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N,i,j,k,x,y,x1,y1,x2,y2,x3,y3;
	cin >> N;
	vector<pair<int, int>> d(N);
	for(i=0;i<N;++i){
		cin >> x >> y;
		d.at(i) = {x, y};
	}
	for(i=0;i<N-2;++i){
		for(j=i+1;j<N-1;++j){
			for(k=j+1;k<N;++k){
				x1 = d.at(i).first; y1 = d.at(i).second;
				x2 = d.at(j).first; y2 = d.at(j).second;
				x3 = d.at(k).first; y3 = d.at(k).second;
				if((y3-y1)*(x2-x1)==(y2-y1)*(x3-x1)){
					cout << "Yes" << endl;
					return 0;
				}		
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
