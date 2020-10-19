#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int main(){
	ll K,n;
	cin >> K;
	queue<ll> q;
	for(int i=1;i<10;++i) q.push(i);
	while(1){
		n = q.front();
		q.pop(); --K;
		if(K==0){
			cout << n << endl;
			return 0;
		}
		if(n%10!=0) q.push(n*10+n%10-1);
		q.push(n*10+n%10);
		if(n%10!=9) q.push(n*10+n%10+1);
	}
}
