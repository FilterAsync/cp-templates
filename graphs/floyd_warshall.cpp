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

const int MAXN = 1E3 + 5;
const ll MOD = 1E9 + 7, INF = 1E18;
const double EPS = 1E-9;

vector<int> reconstruct_path(int i, int j, vector<vector<int>> &path) {
	if (i == j) return {i};
	if (!path[i][j]) return {i, j};

	int k = path[i][j];
	auto left = reconstruct_path(i, k, path);
	auto right = reconstruct_path(k, j, path);
	left.pop_back();
	left.insert(left.end(), all(right));

	return left;
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, INF));
	while (m--) {
		int u, v; ll weight;
		cin >> u >> v >> weight;
		adj[u][v] = adj[v][u] = min(adj[u][v], weight);
	}

	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			dp[i][j] = adj[i][j];
		}
	}
	FOR(i, 1, n) {
		dp[i][i] = 0;
	}

	vector<vector<int>> path(n + 1, vector<int>(n + 1, 0x00));
	FOR(k, 1, n) {
		FOR(i, 1, n) {
			FOR(j, 1, n) {
				if (dp[i][k] != INF && dp[k][j] != INF) {
					chmin(dp[i][j], dp[i][k] + dp[k][j]);
					if (dp[i][j] == dp[i][k] + dp[k][j]) {
						path[i][j] = k;
					}
				}
			}
		}
	}
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
