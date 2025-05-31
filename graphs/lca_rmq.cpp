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

const int MAXN = 1E5 + 5;
const ll MOD = 1E9 + 7, INF = 1E18;
const double EPS = 1E-9;

vector<int> adj[MAXN];
int tin[MAXN], euler_tour[2 * MAXN];
int t[4 * MAXN];
int timer = 0;
int n;

void dfs(int node = 0, int parent = -1) {
	tin[node] = timer;
	euler_tour[timer++] = node;

	for (int i : adj[node]) {
		if (i != parent) {
			dfs(i, node);
			euler_tour[timer++] = node;
		}
	}
}

int mn_tin(int x, int y) {
	if (x == -1) {
		return y;
	}

	if (y == -1) {
		return x;
	}

	return (tin[x] < tin[y] ? x : y);
}

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = euler_tour[l];
		return;
	}

	int m = (l + r) / 2;
	build(i * 2, l, m);
	build(i * 2 + 1, m + 1, r);
	t[i] = mn_tin(t[i * 2], t[i * 2 + 1]);
}

int query(int i, int a, int b, int l, int r) {
	if (l > b || r < a) {
		return -1;
	}

	if (l >= a && r <= b) {
		return t[i];
	}

	int m = (l + r) / 2;

	return mn_tin(query(a, b, i * 2, l, m),
		query(a, b, i * 2 + 1, m + 1, r));
}

int lca(int a, int b) {
	if (tin[a] > tin[b]) {
		swap(a, b);
	}

	return query(1, tin[a], tin[b], 0, timer - 1);
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
