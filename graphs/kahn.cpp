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
int n;

list<int> kahn() {
	vector<int> in_degree(n + 1);
	list<int> ret;
	FOR(u, 1, n) {
		for (int v : adj[u]) {
			in_degree[v]++;
		}
	}

	queue<int> q;
	FOR(i, 1, n) {
		if (in_degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front(); q.pop();
		ret.push_back(u);

		for (int v : adj[u]) {
			if (--in_degree[v] == 0) {
				q.push(v);
			}
		}
	}

	return ret;
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
