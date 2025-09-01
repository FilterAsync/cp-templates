// #pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define sqr(x) ((x) * (x))
#define FOR(i, l, r) for (int i = l; i <= (r); i++)
#define FOD(i, l, r) for (int i = l; i >= (r); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);

using db = long double;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vbool = vector<bool>;
using vvbool = vector<vbool>;

template<class T> inline bool chmax(T &a, T const &b) { return (a < b ? (a = b, true) : false); }
template<class T> inline bool chmin(T &a, T const &b) { return (a > b ? (a = b, true) : false); }

// #define DEBUG
#ifdef DEBUG
#include "D:\cpp\debug.h"
#else
#define debug(...)
#define debug_arr(...)
#endif

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 1E5 + 5;
constexpr int INF = 1E9 + 7;
constexpr ll INFLL = 1E18;
constexpr int MOD = 1E9 + 7; // 998244353
constexpr double EPS = 1E-10;

string add(string a, string b) {
    int m = sz(a), n = sz(b);
    string res = "";
    int i = m - 1, j = n - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry != 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i--] - '0';
        }
        if (j >= 0) {
            sum += b[j--] - '0';
        }
        res += sum % 10 + '0';
        carry = sum / 10;
    }
    reverse(all(res));
    return res;
}

string sub(string a, string b) {
    int m = sz(a), n = sz(b);
    string res = "";
    int i = m - 1, j = n - 1, borrow = 0;
    while (i >= 0 || j >= 0) {
        int diff = borrow;
        if (i >= 0) {
            diff += a[i--] - '0';
        }
        if (j >= 0) {
            diff -= b[j--] - '0';
        }
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res += diff + '0';
    }
    reverse(all(res));
    while (sz(res) > 1 && res[0] == '0') {
        res.erase(res.begin());
    }
    return res;
}

string mul(string a, string b) {
    int m = sz(a), n = sz(b);
    vi nums(m + n);
    FOD(i, m - 1, 0) {
        FOD(j, n - 1, 0) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + nums[i + j + 1];
            nums[i + j] += sum / 10;
            nums[i + j + 1] = sum % 10;
        }
    }
    string res = "";
    for (int num : nums) {
        if (sz(res) == 0 && num == 0) {
            continue;
        }
        res += num + '0';
    }
    return sz(res) ? res : "0";
}

void solve() {
    
}

int main() {
    fast_io
    #define LOCAL
    #ifndef LOCAL
    #define PROBLEM ""
    freopen(PROBLEM ".INP", "r", stdin);
    freopen(PROBLEM ".OUT", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
