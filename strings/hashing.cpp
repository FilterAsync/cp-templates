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
#define by(x) [](auto const &a, auto const &b) { return a.x < b.x; }

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);

#define LOCAL

const int MAXN = 1E5 + 5;
const ll MOD = 1E9 + 7, INF = 1E18;
const double EPS = 1E-9;

// note: this is zero-indexed
class HashedString {
  private:
    const ll MOD = 1E9 + 7;
    const ll BASE = 311;
    vector<ll> power;
    vector<ll> p_hash;
  public:
    HashedString(string const &s) : p_hash(sz(s) + 1) {
        power.push_back(1);
        while (sz(power) <= sz(s)) {
            power.push_back(power.back() * BASE % MOD);
        }
        p_hash[0] = 0;
        FOR(i, 1, sz(s)) {
            p_hash[i] = (p_hash[i - 1] * BASE % MOD + s[i - 1] - 'a' + 1) % MOD;
        }
    }

    ll get_hash(int l, int r) {
        ll raw_val = p_hash[r + 1] - p_hash[l] * power[r - l + 1];
        return (raw_val % MOD + MOD) % MOD;
    }
};

void solve() {
    string s = "hello world";
    HashedString hs(s);
    cout << "Hash of the whole string: " << hs.get_hash(0, sz(s) - 1) << el;
    cout << "Hash of substring 'hello': " << hs.get_hash(0, 4) << el;
    // s[0..0] -> 'h'
    // s[0..1] -> 'he'
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
