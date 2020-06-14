#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
using namespace std;

int main(){
	int i,j,u,idx;
	long long t=0;
	string s;
	cin >> s;
	for(i=0;i<(1<<(s.length()-1));++i){
		j=1;
		u=0;
		idx=0;
		while(j<=(1<<(s.length()-1))){
			t += ((int)s[s.length()-1-idx]-48)*pow(10,u);
			++u;
			if(i&j) u = 0;	
			j <<= 1;
			++idx;
		}
	}
	cout << t << endl;
	return 0;
}
