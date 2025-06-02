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
int low[MAXN], num[MAXN], scc[MAXN];
bool in_stack[MAXN];
stack<int> st;
int counter = 0, scc_cnt = 0;

void tarjan(int u) {
	low[u] = num[u] = ++counter;
	st.push(u);
	in_stack[u] = true;

	for (int v : adj[u]) {
		if (!num[v]) {
			tarjan(v);
			chmin(low[u], low[v]);
		} else if (in_stack[v]) {
			chmin(low[u], num[v]);
		}
	}

	if (low[u] == num[u]) {
		scc_cnt++;
		int v;
		do {
			v = st.top(); st.pop();
			scc[v] = scc_cnt;
			in_stack[v] = false;
		} while (v != u);
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
