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

constexpr int digits(int base) noexcept {
    return base <= 1 ? 0 : 1 + digits(base / 10);
}

constexpr int base = 1E9;
constexpr int base_digits = digits(base);

struct BigInt {
    // value == 0 is represented by empty z
    vi z; // digits

    // sign == 1 <==> value >= 0
    // sign == -1 <==> value < 0
    int sign;

    // must need
    BigInt(ll v = 0) {
        *this = v;
    }

    BigInt &operator=(ll v) {
        sign = v < 0 ? -1 : 1;
        v *= sign;
        z.clear();
        for (; v > 0; v = v / base)
        z.push_back((int)(v % base));
        return *this;
    }

    BigInt(const string &s) {
        read(s);
    }

    BigInt &operator+=(const BigInt &other) {
        if (sign == other.sign) {
            for (int i = 0, carry = 0; i < sz(other.z) || carry; ++i) {
                if (i == sz(z))
                z.push_back(0);
                z[i] += carry + (i < sz(other.z) ? other.z[i] : 0);
                carry = z[i] >= base;
                if (carry)
                z[i] -= base;
            }
        } else if (other != 0 /* prevent infinite loop */ ) {
            *this -= -other;
        }
        return *this;
    }

    friend BigInt operator+(BigInt a, const BigInt & b) {
        a += b;
        return a;
    }

    BigInt &operator-=(const BigInt & other) {
        if (sign == other.sign) {
            if ((sign == 1 && * this >= other) || (sign == -1 && * this <= other)) {
                for (int i = 0, carry = 0; i < sz(other.z) || carry; ++i) {
                    z[i] -= carry + (i < sz(other.z) ? other.z[i] : 0);
                    carry = z[i] < 0;
                    if (carry) z[i] += base;
                }
                trim();
            } else {
                *this = other - *this;
                this->sign = -this->sign;
            }
        } else {
            *this += -other;
        }
        return *this;
    }

    friend BigInt operator-(BigInt a,
        const BigInt & b) {
        a -= b;
        return a;
    }

    BigInt &operator*=(int v) {
        if (v < 0)
        sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < sz(z) || carry; ++i) {
            if (i == sz(z))
                z.push_back(0);
            ll cur = (ll) z[i] * v + carry;
            carry = (int)(cur / base);
            z[i] = (int)(cur % base);
        }
        trim();
        return *this;
    }

    BigInt operator*(int v) const {
        return BigInt(*this) *= v;
    }

    bool operator<(const BigInt &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (sz(z) != sz(v.z))
            return sz(z) * sign < sz(v.z) * v.sign;
        for (int i = sz(z) - 1; i >= 0; i--)
            if (z[i] != v.z[i])
                return z[i] * sign < v.z[i] * sign;
        return false;
    }

    bool operator>(const BigInt &v) const {
        return v < *this;
    }

    bool operator<=(const BigInt &v) const {
        return !(v < *this);
    }

    bool operator>=(const BigInt &v) const {
        return !(*this < v);
    }

    bool operator==(const BigInt &v) const {
        return sign == v.sign && z == v.z;
    }

    bool operator!=(const BigInt &v) const {
        return !(*this == v);
    }

    void trim() {
        while (!z.empty() && z.back() == 0) z.pop_back();
        if (z.empty()) sign = 1;
    }

    bool is_zero() const {
        return z.empty();
    }

    friend BigInt operator-(BigInt v) {
        if (!v.z.empty()) v.sign = -v.sign;
        return v;
    }

    BigInt abs() const {
        return sign == 1 ? *this : -*this;
    }

    ll long_value() const {
        ll res = 0;
        for (int i = sz(z) - 1; i >= 0; i--)
            res = res * base + z[i];
        return res * sign;
    }

    void read(const string &s) {
        sign = 1;
        z.clear();
        int pos = 0;
        while (pos < sz(s) && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = sz(s) - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            z.push_back(x);
        }
        trim();
    }

    friend istream &operator>>(istream &stream, BigInt &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream &operator<<(ostream &stream, const BigInt &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.z.empty() ? 0 : v.z.back());
        for (int i = (int) v.z.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.z[i];
        return stream;
    }

    BigInt operator*(const BigInt & v) const {
        return mul_simple(v);
    }

    BigInt mul_simple(const BigInt & v) const {
        BigInt res;
        res.sign = sign * v.sign;
        res.z.resize(sz(z) + sz(v.z));
        for (int i = 0; i < sz(z); ++i) {
            if (z[i]) {
                for (int j = 0, carry = 0; j < sz(v.z) || carry; ++j) {
                    ll cur = res.z[i + j] + (ll) z[i] * (j < sz(v.z) ? v.z[j] : 0) + carry;
                    carry = (int)(cur / base);
                    res.z[i + j] = (int)(cur % base);
                }
            }
        }
        res.trim();
        return res;
    }
};

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
