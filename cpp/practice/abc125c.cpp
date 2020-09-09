#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,i,A,B,tmp,ans=0;
	cin >> n;
	vector<int> a(n);
	vector<int> l(n);
	vector<int> r(n);
	for(i=0;i<n;++i) cin >> a.at(i);
	for(i=0;i<n-1;++i){
		B = max(a.at(i),l.at(i));
		A = min(a.at(i),l.at(i));
		while(A!=0){
			tmp = B%A;
			B = A;
			A = tmp;
		}
		l.at(i+1) = B;
		B = max(a.at(n-1-i),r.at(n-1-i));
		A = min(a.at(n-1-i),r.at(n-1-i));
		while(A!=0){
			tmp = B%A;
			B = A;
			A = tmp;
		}
		r.at(n-2-i) = B;
	}
	for(i=0;i<n;++i){
		B = max(l.at(i),r.at(i));
		A = min(l.at(i),r.at(i));
		while(A!=0){
			tmp = B%A;
			B = A;
			A = tmp;
		}
		ans = max(ans, B);
	}
	cout << ans << endl;
	return 0;
}
		
