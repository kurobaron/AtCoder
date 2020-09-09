#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main(){
	int Q,T,F,i,inv=0;
	char C;
	string S;
	cin >> S;
	cin >> Q;
	queue<char> qB;
	queue<char> qE;
	for(i=0;i<Q;++i){
		cin >> T;
		if(T==1){
			inv = (inv+1)%2;
		}else{
			cin >> F >> C;
			if(!inv&&F==1||inv&&F==2) qB.push(C);
			else qE.push(C);
		}
	}
	queue<char> q1;
	queue<char> q2;
	vector<char> v;
	if(inv){
		for(i=0;i<S.length();++i){
			v.push_back(S[i]);
		}
		q1 = qE;
		q2 = qB;
	}else{
		for(i=S.length()-1;i>=0;--i){
			v.push_back(S[i]);
		}
		q1 = qB;
		q2 = qE;
	}
	while(!q1.empty()){
		v.push_back(q1.front());
		q1.pop();
	}
	reverse(v.begin(),v.end());
	while(!q2.empty()){
		v.push_back(q2.front());
		q2.pop();
	}
	for(i=0;i<v.size();++i) cout << v.at(i);
	cout << endl;
	return 0;
}	
