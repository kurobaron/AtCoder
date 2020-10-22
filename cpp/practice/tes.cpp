#include <iostream>
using namespace std;

struct s{
	s(int a=1){
		b=a+1;
	}

	int increment(int x=this->b){
		cout << x+1 << endl;
	}

private:
	int b;
};
