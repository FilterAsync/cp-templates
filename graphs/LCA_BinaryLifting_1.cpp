// Finding LCA by Binary Lifting only
#include <bits/stdc++.h>

using namespace std;

template<class T> bool chmax(T &a, T const &b) {
	return (a < b ? (a = b, true) : false);
}

template<class T> bool chmin(T &a, T const &b) {
	return (a > b ? (a = b, true) : false);
}

using ll = long long;

#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FOD(i, l, r) for (ll i = l; i >= r; i--)

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);

#define LOCAL

const int MAXN = 2E5 + 5;
const int MAX_EXP = 20;
const ll MOD = 1E9 + 7, INF = 1E18;
const double EPS = 1E-9;

vector<int> adj[MAXN];
int lift[MAXN][MAX_EXP + 1], depth[MAXN];

void dfs(int u, int p = 0) {
	lift[u][0] = p;

	for (int v : adj[u]) {
		if (v != p) {
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}

	FOD(e, MAX_EXP, 0) {
		if (depth[u] - (1 << e) >= depth[v]) {
			u = lift[u][e];
		}
	}

	if (u == v) {
		return u;
	}

	FOD(e, MAX_EXP, 0) {
		if (lift[u][e] && lift[u][e] != lift[v][e]) {
			u = lift[u][e];
			v = lift[v][e];
		}
	}

	return lift[u][0];
}

void solve() {

}

int main() {
	fast_io
	#ifndef LOCAL
		freopen("INPUT.INP", "r", stdin);
		freopen("OUTPUT.OUT", "w", stdout);
	#endif

	int t = 1;
	// cin >> t;
	while (t--) solve();
}
