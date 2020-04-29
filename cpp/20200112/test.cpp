#include <iostream>
#include <stdlib.h>
using namespace std;

char **p1;
int M=5,i=0;
int main(void){
	p1 = (char **)calloc(M, sizeof(char *));
	for(i;i<M;i++){
		p1[i] = (char *)calloc(3, sizeof(char));
	}
	scanf("%s",p1[0]);
	cout << &p1[0] << &p1 << p1 << *p1[0] << p1[0] << endl;
	cout << *p1 << **p1 << (void*)&(**p1) << endl;
	return 0;
}
