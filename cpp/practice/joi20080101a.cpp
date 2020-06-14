#include <iostream>
#include <vector>
using namespace std;

int main(){
	int p,r,cnt=0;
	vector<int> v = {500, 100, 50, 10, 5, 1};
	cin >> p;
	r = 1000 - p;
	for(int e: v){
		cnt += r/e;
		r = r%e;
	}
	cout << cnt << endl;
	return 0;
}
