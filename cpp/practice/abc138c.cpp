#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n,i;
	float tmp,v1,v2;
	cin >> n;
	priority_queue<float,vector<float>,greater<float>> v;
	for(i=0;i<n;++i){
		cin >> tmp;
		v.push(tmp);
	}
	while(1){
		v1 = v.top();
		v.pop();	
		v2 = v.top();
		v.pop();
		v.push((v1+v2)/2.0);
		if(v.size()==1) break;
	}
	cout << v.top() << endl;
	return 0;
}

