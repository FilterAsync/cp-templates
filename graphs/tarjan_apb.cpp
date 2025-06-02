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
int low[MAXN], num[MAXN];
bool joint[MAXN];
vector<pii> bridges;
int counter = 0;

void tarjan(int u, int pre = 0) {
	low[u] = num[u] = ++counter;
	int children = 0;

	for (int v : adj[u]) {
		if (!num[v]) {
			children++;
			tarjan(v, u);

			chmin(low[u], low[v]);

			if (pre && low[v] >= num[u]) {
				joint[u] = true;
			}
			if (low[v] == num[v]) {
				bridges.emplace_back(u, v);
			}
		} else if (v != pre) {
			chmin(low[u], num[v]);
		}
	}

	if (!pre) {
		joint[u] = children >= 2;
	}
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
