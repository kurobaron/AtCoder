#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct SegmentTree{
	long long N = 1;
	SegmentTree(long long n=1e5){
		while(n>N) N *= 2;
		tree = vector<long long>(2*N-1);
	}		

	void Update(long long i, long long x, bool isMax=true){
		//i+1枚目の葉の値をxに更新する
		i = N-1+i;
		tree.at(i) = x;
		while(i>0){
			i = (i-1)/2;
			if(isMax) tree.at(i) = max(tree.at(i*2+1),tree.at(i*2+2));
			else tree.at(i) = min(tree.at(i*2+1),tree.at(i*2+2));
		}
	}

	long long Search(long long a, long long b, bool isMax=true){
		//[a,b)の範囲における最大値または最小値を返す
		if(b<=0||a>=N) return isMax ? -1 : INF; 
		else{
			if(isMax) return max(Search(a,b,isMax,0*2+1,0,(0+N)/2), Search(a,b,isMax,0*2+2,(0+N)/2,N));
			else return min(Search(a,b,isMax,0*2+1,0,(0+N)/2), Search(a,b,isMax,0*2+2,(0+N)/2,N));
		}
	}

	

private:
	vector<long long> tree;
	const long long INF = 1e18;

	long long Search(long long a, long long b, bool isMax, long long k, long long l, long long r){
		//オーバーロード
		//[a,b)の範囲における最大値または最小値を返す
		if(b<=l||a>=r) return isMax ? -1 : INF; 
		if(a<=l&&r<=b) return tree.at(k);
		else{
			if(isMax) return max(Search(a,b,isMax,k*2+1,l,(l+r)/2), Search(a,b,isMax,k*2+2,(l+r)/2,r));
			else return min(Search(a,b,isMax,k*2+1,l,(l+r)/2), Search(a,b,isMax,k*2+2,(l+r)/2,r));
		}
	}
};

int main(){
	ll i,N,now,ans=-1;
	cin >> N;
	vector<ll> h(N);
	vector<ll> a(N);
	SegmentTree st(N);
	for(i=0;i<N;++i) cin >> h.at(i);
	for(i=0;i<N;++i) cin >> a.at(i);
	for(i=0;i<N;++i){
		now = a.at(i);
		if(h.at(i)>1) now += st.Search(0,h.at(i)-1);
		ans = max(ans,now);
		st.Update(h.at(i)-1,now);
	}		
	cout << ans << endl;
	return 0;
}
