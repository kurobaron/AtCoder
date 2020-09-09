#include <iostream>
#include <vector>
using namespace std;

struct UnionFind{
	vector<long long> p;
	vector<long long> size;
	vector<long long> rank;
	UnionFind(long long n) : p(n),size(n,1),rank(n,1){
		for(long long i=0;i<n;++i) p.at(i) = i;
	}

	long long Root(long long x){
		return p.at(x)==x ? x : p.at(x) = Root(p.at(x));
	}
	
	void Unite(long long x, long long y){
		x = Root(x);
		y = Root(y);
		if(x==y) return;
		if(rank.at(x) < rank.at(y)){
			p.at(x) = y;
			size.at(y) += size.at(x);
		}
		else{
			p.at(y) = x;
			size.at(x) += size.at(y);
			if(rank.at(x)==rank.at(y)) ++rank.at(x);
		}
	}

	long long Size(long long x){
		x = Root(x);
		return size.at(x);
	}

	long long Rank(long long x){
		x = Root(x);
		return rank.at(x);
	}
};

int main(){
	int i,N,M,K,A,B;
	cin >> N >> M >> K;
	vector<vector<int>> f(N);
	vector<int> b(N);
	UnionFind uf(N);
	for(i=0;i<M;++i){
		cin >> A >> B;
		--A; --B;
		f.at(A).push_back(B);
		f.at(B).push_back(A);
		uf.Unite(A,B);
	}	
	for(i=0;i<K;++i){
		cin >> A >> B;
		--A; --B;
		if(uf.Root(A)==uf.Root(B)){ ++b.at(A); ++b.at(B);}
	}
	for(i=0;i<N;++i) cout << uf.Size(i)-f.at(i).size()-b.at(i)-1 << " ";
	cout << endl;
	return 0;
}
