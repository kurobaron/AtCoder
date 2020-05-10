#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main(){
	int n,i=0,cnt=0;
	cin >> n;
	vector<int> li{istream_iterator<int>(cin), istream_iterator<int>()}; 
	while(i<li.size()){
		if(li[i]!=i+1){
			li.erase(li.begin()+i);
			cnt++;
		}else{
			i++;
		}
	}
	if(li.size()==0){
		cout << -1 << endl;
	}else{
		cout << cnt << endl;
	}
	return 0;
}
