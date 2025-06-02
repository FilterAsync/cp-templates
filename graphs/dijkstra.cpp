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

struct Edge {
	int v, w;
};

struct Node {
	int id, dist;

	friend bool operator<(Node const &a, Node const &b) {
		return a.dist > b.dist;
	}
};

vector<Edge> adj[MAXN];
priority_queue<Node> pq;

void dijkstra(int s) {
	pq.emplace(s, 0);
	vector<int> d(MAXN, INF);
	d[s] = 0;

	while (!pq.empty()) {
		auto [u, dist] = pq.top();
		pq.pop();

		if (dist > d[u]) {
			continue;
        }

		for (auto [v, w] : adj[u]) {
			int alt = d[u] + w;
			if (chmin(d[v], alt)) {
				pq.emplace(v, alt);
			}
		}
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
