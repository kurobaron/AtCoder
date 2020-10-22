#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
const ll MOD = 1e9+7;

vector<vector<long long>> matmal(vector<vector<long long>> &m1, vector<vector<long long>> &m2, long long r, long long c, long long h){
	long long i,j,k,elem,MOD = 1e9+7;
	vector<vector<long long>> matp(r, vector<long long>(c));
	for(i=0;i<r;++i){
		for(j=0;j<c;++j){
			elem = 0;
			for(k=0;k<h;++k){
				elem += m1.at(i).at(k)*m2.at(k).at(j);
				elem %= MOD;
			}
			matp.at(i).at(j) = elem;
		}
	}
	return matp;
}
			
vector<vector<long long>> matpow(vector<vector<long long>> &m, long long p, long long n){
	long long i,j,k,MOD = 1e9+7;
	vector<vector<long long>> m_p;
	if(p==1) return m;
	m_p = matpow(m, p/2, n);
	m_p = matmal(m_p, m_p, n, n, n);
	if(p%2==0) return m_p;
	else return matmal(m_p, m, n, n, n);
}

int main(){
	ll i,j,N,K,ans=0;
	cin >> N >> K;
	vector<vector<ll>> a(N,vector<ll>(N));
	vector<vector<ll>> dp(N,vector<ll>(N));
	for(i=0;i<N;++i){
		for(j=0;j<N;++j){
			cin >> a.at(i).at(j);
		}
	}

	dp = matpow(a, K, N);
	for(i=0;i<N;++i){
		for(j=0;j<N;++j){
			ans += dp.at(i).at(j);
			ans %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}
