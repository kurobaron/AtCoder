#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

int N,M,cnt1=0,cnt2=0,i,j;
int *p1,*flg;
char **p2;

int main(void){
	cin >> N >> M;
	p1 = (int *)calloc(M, sizeof(int));
	p2 = (char **)calloc(M, sizeof(char *));
	for(i=0;i<M;i++){
		p2[i] = (char *)calloc(3, sizeof(char));
	}
	flg = (int *)calloc(N, sizeof(int));
	for(i=0;i<M;i++){
		cin >> p1[i] >> p2[i];
		if((string)p2[i]=="AC" && flg[p1[i]]==0){
			flg[p1[i]] = 1;
			cnt1 += 1;
			for(j=0;j<i;j++){
				if(p1[j]==p1[i] && (string)p2[j]=="WA"){
					cnt2 += 1;
				}
			}
		}

	} 
	
	cout << cnt1 << " " << cnt2 << endl;
	
	for(i=0;i<M;i++){
		free(p2[i]);
	}
	free(p2);
	free(p1);
	free(flg);
	return 0;
}
