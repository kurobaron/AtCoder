#include <iostream>
#include <vector>
using namespace std;

struct UnionFind{
	UnionFind(long long n) : p(n),size(n,1),rank(n,1){
		for(long long i=0;i<n;++i) p.at(i) = i;
	}

	//xが属している木構造の根ノードを返す
	long long Root(long long x){
		return p.at(x)==x ? x : p.at(x) = Root(p.at(x));
	}
	
	//xが属している木構造とyが属している木構造を結合する
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

	//xが属している木構造のノードの総数を返す
	long long Size(long long x){
		x = Root(x);
		return size.at(x);
	}

	//xが属している木構造の深さを返す
	long long Rank(long long x){
		x = Root(x);
		return rank.at(x);
	}

private:
	vector<long long> p;
	vector<long long> size;
	vector<long long> rank;

};

int main(){
	int i,j,N,M,ai,bi,cnt=0;
	cin >> N >> M;
	vector<pair<int,int>> pr(M);
	for(i=0;i<M;++i){
		cin >> ai >> bi;
		--ai; --bi;
		pr.at(i) = {ai,bi};
	}
	for(i=0;i<M;++i){
		UnionFind uf(N);
		for(j=0;j<M;++j){
			if(i==j) continue;
			uf.Unite(pr.at(j).first,pr.at(j).second);
		}
		int cr = uf.Root(0);
		for(j=1;j<N;++j){
			if(uf.Root(j)!=cr){
				++cnt;
				break;
			}
		}
	}
	cout << cnt << endl;
	return  0;
}
