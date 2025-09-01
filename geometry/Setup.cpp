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

// Geometry set up for geometry problems
using T = ll;

struct Point {
    T x, y;

    Point(T x = 0, T y = 0) : x(x), y(y) {}

    friend istream &operator>>(istream &is, Point &p) {
        return is >> p.x >> p.y;
    }

    friend ostream &operator<<(ostream &os, const Point &p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }

    bool operator==(const Point &p) const {
        return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
    }

    bool operator!=(const Point &p) const {
        return !(*this == p);
    }

    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    Point operator-() const {
        return Point(-x, -y);
    }

    Point operator*(T k) const {
        return Point(x * k, y * k);
    }

    Point operator/(T k) const {
        return Point(x / k, y / k);
    }

    T dot(const Point &p) const {
        return x * p.x + y * p.y;
    }

    T cross(const Point &p) const {
        return x * p.y - y * p.x;
    }

    double distance(const Point &p) const {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }

    double magnitude() const {
        return sqrt(x * x + y * y);
    }
};

struct Line { // Ax + By = C
    double a, b, c;

    Line(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) {}
    Line(Point A, Point B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = a * A.x + b * A.y;
    }

    bool contains(const Point &p) const {
        return fabs(a * p.x + b * p.y - c) < EPS;
    }
};

struct Polygon {
    int n;
    vector<Point> vertices;

    Polygon(Point a, Point b, Point c) {
        vertices.push_back(a);
        vertices.push_back(b);
        vertices.push_back(c);
        n = 3;
    }

    Polygon(vector<Point> __vertices) {
        vertices = __vertices;
        n = sz(__vertices);
    }

    T db_area() const {
        T res = 0;
        FOR(i, 0, n - 1) {
            int j = (i + 1) % n;
            res += vertices[i].cross(vertices[j]);
        }
        return abs(res);
    }

    double area() const {
        return (double)db_area() / 2;
    }
};

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
