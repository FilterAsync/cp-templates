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
struct Point {
	double x, y;

	Point(double x = 0, double y = 0) : x(x), y(y) {}

	// Input and output operators
	friend istream &operator>>(istream &is, Point &p) {
		return is >> p.x >> p.y;
	}

	friend ostream &operator<<(ostream &os, const Point &p) {
		return os << "(" << p.x << ", " << p.y << ")";
	}

	// Comparison operators
	bool operator==(const Point &p) const {
		return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
	}

	bool operator!=(const Point &p) const {
		return !(*this == p);
	}

	// Arithmetic operators
	Point operator+(const Point &p) const {
		return Point(x + p.x, y + p.y);
	}

	Point operator-(const Point &p) const {
		return Point(x - p.x, y - p.y);
	}

	Point operator-() const {
		return Point(-x, -y);
	}

	Point operator*(double k) const {
		return Point(x * k, y * k);
	}

	Point operator/(double k) const {
		return Point(x / k, y / k);
	}

	// Dot and cross product
	double dot(const Point &p) const {
		return x * p.x + y * p.y;
	}

	double cross(const Point &p) const {
		return x * p.y - y * p.x;
	}

	// Distance functions
	double distance(const Point &p) const {
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}

	double length() const {
		return sqrt(x * x + y * y);
	}
};

// Function to read a vector of points
vector<Point> read_points(int n) {
	vector<Point> points(n);
	for (int i = 0; i < n; ++i) {
		cin >> points[i];
	}
	return points;
}

// Function to print a vector of points
void print_points(const vector<Point> &points) {
	for (const auto &p : points) {
		cout << p << " ";
	}
	cout << el;
}

// Line structure for representing a line in 2D space
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
