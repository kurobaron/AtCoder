#include <iostream>
using namespace std;

int main(){
	string n, ans, op="aaa";
	int i, j, cal, tmp;
	cin >> n;
	for(i=0;i<n.length();++i) ans.push_back(n[i]);
	ans.push_back('=');
	ans.push_back('7');
	for(i=0;i<(1<<3);++i){
		cal = (int)n[0] - 48;
		for(j=0;j<3;++j){
			if((i>>j)&1){
				tmp = (int)n[3-j] - 48;
				op[2-j] = '+';
			}else{
				tmp = -((int)n[3-j] -48);
				op[2-j] = '-';
			}
			cal += tmp;
		}
		if(cal==7){
			for(j=0;j<op.size();++j) ans.insert(1+2*j,1,op[j]);
			cout << ans << endl;
			break;
		}		
	}
	return 0;
}
