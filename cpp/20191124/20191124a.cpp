#include <iostream>
#include <map>
using namespace std;

int main(){
	string day;
	map<string, int> m;
	m["SAT"] = 1;
	m["FRI"] = 2;
	m["THU"] = 3;
	m["WED"] = 4;
	m["TUE"] = 5;
	m["MON"] = 6;
	m["SUN"] = 7;
	cin >> day;
	cout << m[day] << endl;
	return 0;
}
