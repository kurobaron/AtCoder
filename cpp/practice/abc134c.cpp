#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,i,firstNum=0,secondNum=0;
	cin >> n;
	vector<int> a(n);
	for(i=0;i<n;++i){
		cin >> a.at(i);
		if(a.at(i)>=firstNum){
			secondNum = firstNum;
			firstNum = a.at(i);
		}else if(a.at(i)>secondNum) secondNum = a.at(i);
	}
	if(firstNum==secondNum) for(i=0;i<n;++i) cout << firstNum << endl;
	else{
		for(i=0;i<n;++i){
			if(a.at(i)==firstNum) cout << secondNum << endl;
			else cout << firstNum << endl;
		}
	}
	return 0;
}

