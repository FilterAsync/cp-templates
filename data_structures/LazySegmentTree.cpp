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

// segment tree with lazy propagation
// assuming range sum query
struct SegmentTree {
    int n;
    vector<ll> tree, lazy;

    SegmentTree(int n) : n(n) {
        tree.resize(4 * n + 5);
        lazy.resize(4 * n + 5);
    }

    void push(int i, int l, int r) {
        if (!lazy[i]) return;
        tree[i] += lazy[i] * (r - l + 1);
        if (l != r) {
            lazy[i * 2] += lazy[i];
            lazy[i * 2 + 1] += lazy[i];
        }
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int ql, int qr, ll val) {
        push(i, l, r);
        if (l > r || l > qr || r < ql) return;
        if (l >= ql && r <= qr) {
            lazy[i] += val;
            push(i, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(i * 2, l, m, ql, qr, val);
        update(i * 2 + 1, m + 1, r, ql, qr, val);
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    ll get(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (l > r || l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) return tree[i];
        int m = (l + r) / 2;
        return get(i * 2, l, m, ql, qr) + get(i * 2 + 1, m + 1, r, ql, qr);
    }
};

void solve() {
	cout << __cplusplus;
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
