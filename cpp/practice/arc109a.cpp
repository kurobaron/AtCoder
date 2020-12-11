#include <iostream>
using namespace std;

int main(){
	int a,b,x,y,ans=0;
	cin >> a >> b >> x >> y;
	if(a>b) ans = min((abs(a-b)-1)*y+x,(abs(a-b)-1)*2*x+x);
	else ans = min(abs(a-b)*y+x,abs(a-b)*2*x+x);
	cout << ans << endl;
	return 0;
}
