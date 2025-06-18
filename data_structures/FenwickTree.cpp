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

struct BIT {
    int n;
    vector<ll> bit;

    BIT(int n) : n(n) {
        bit.assign(n + 1, 0);
    }

    void update(int i, ll val) {
        for (; i <= n; i += i & -i) {
            bit[i] += val;
        }
    }

    ll query(int i) {
        ll res = 0;
        for (; i >= 1; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }

    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }

    int lower_bound(ll val) {
        int idx = 0;
        ll sum = 0;
        for (int i = 1 << 20; i > 0; i >>= 1) {
            if (idx + i <= n && sum + bit[idx + i] < val) {
                idx += i;
                sum += bit[idx];
            }
        }
        return idx + 1;
    }
};

void solve() {
    BIT bit(10);
    bit.update(1, 5);
    bit.update(2, 3);
    bit.update(3, 2);
    ll val = 9;
    int idx = bit.lower_bound(val);
    cout << "The first index with cumulative sum >= " << val << " is: " << idx << el;
    cout << "Cumulative sum at idx: " << bit.query(idx) << el;
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
