#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(int a, int b, int e, vector<int> &c){
	--c.at(a); --c.at(b); --c.at(e);
	if(c.at(a)>=0&&c.at(b)>=0&&c.at(e)>=0){
		cout << "Yes" << endl;
		++c.at(a); ++c.at(b); ++c.at(e);
		return true;
	}
	++c.at(a); ++c.at(b); ++c.at(e);
	return false;
}

int main(){
	string S;
	int i,idx,num;
	cin >> S;
	vector<int> c(10);
	for(i=0;i<S.length();++i){
		++c.at(S[i]-'0');
	}
	if(S.length()<3){
		if(S.length()==1){
			if((int)(S[0]-'0')%8==0) cout << "Yes" << endl;
			else cout << "No" << endl;
		}else{
			if(((int)(S[0]-'0')*10+(int)(S[1]-'0'))%8==0||((int)(S[1]-'0')*10+(int)(S[0]-'0'))%8==0) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		return 0;
	}
	idx = 14;
	while(1){
		num = 8*idx;
		if(num>999) break;
		if(check(num/100,(num/10)%10,num%10,c)) return 0;
		++idx;
	}
	cout << "No" << endl;
	return 0;
}
