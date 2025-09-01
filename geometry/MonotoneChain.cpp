// Monotone Chain algorithm for finding the convex hull

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

using T = ll;

struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    Point(Point const &a, Point const &b): x(b.x - a.x), y(b.y - a.y) {}

    friend istream &operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }
    friend ostream &operator<<(ostream &os, Point const &p) { return os << p.x << " " << p.y; }

    bool operator==(Point const &p) const { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; }
    bool operator!=(Point const &p) const { return !(*this == p); }

    Point operator+(Point const &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(Point const &p) const { return Point(x - p.x, y - p.y); }
    Point operator-() const { return Point(-x, -y); }
    Point operator*(T k) const { return Point(x * k, y * k); }
    Point operator/(T k) const { return Point(x / k, y / k); }

    Point &operator+=(Point const &p) { x += p.x; y += p.y; return *this; }
    Point &operator-=(Point const &p) { x -= p.x; y -= p.y; return *this; }
    Point &operator*=(T k) { x *= k; y *= k; return *this; }
    Point &operator/=(T k) { x /= k; y /= k; return *this; }

    Point unit() const { return *this / (*this).norm(); }
    double norm() const { return hypot(x, y); }
    T dot(Point const &p) const { return x * p.x + y * p.y; }
    T cross(Point const &p) const { return x * p.y - y * p.x; }
};

bool ccw(Point const &a, Point const &b, Point const &c) {
    return (b - a).cross(c - a) > 0;
}

vector<Point> monotone_chain(vector<Point> &points) {
    int n = sz(points);
    if (n < 3) return points;

    sort(all(points), [](Point const &a, Point const &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    vector<Point> lower, upper;
    FOR(i, 0, n - 1) {
        while (sz(lower) >= 2 && !ccw(lower[sz(lower) - 2], lower[sz(lower) - 1], points[i])) {
            lower.pop_back();
        }
        lower.push_back(points[i]);
    }

    FOD(i, n - 1, 0) {
        while (sz(upper) >= 2 && !ccw(upper[sz(upper) - 2], upper[sz(upper) - 1], points[i])) {
            upper.pop_back();
        }
        upper.push_back(points[i]);
    }

    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(), all(upper));
    return lower;
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
