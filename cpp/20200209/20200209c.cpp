#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int N;
	int i;
	string A[200000+1];
	string c;
	cin >> N;
	while(cin >> c){
		A[i] = c;
		i++;
		if(i >= N){
			break;
		}
	}
	sort(A, A+N);
	for(i=0;i<N-1;i++){
		if(A[i] == A[i+1]){
			cout << "NO" << "\n";
			exit(0);
		}
	}
	cout << "YES" << "\n";
	return 0;
}
