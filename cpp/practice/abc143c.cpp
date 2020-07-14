#include <iostream>
using namespace std;

int main(){
	int n,i,ans=1;
	char s,spre;
	cin >> n;
	cin >> spre;
	for(i=1;i<n;++i){
		cin >> s;
		if(s==spre) continue;
		else{
			++ans;
			spre = s;
		}
	}	
	cout << ans << endl;
	return 0;
}
