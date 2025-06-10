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

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1E5 + 5;
const int INF = 1E9 + 7;
const ll MOD = 1E9 + 7, INFLL = 1E18;
const double EPS = 1E-9;
const string NAME = "template"; // program name
const int NTEST = 100; // number of test cases

// find random number in [l, r]
ll Rand(ll l, ll r) {
    assert(l <= r);
    return l + rng() % (r - l + 1);
}

int main() {
    srand(time(NULL));
    FOR(_tc, 1, NTEST) {
        ofstream inp((NAME + ".INP").c_str());
		// generate test cases here
        inp.close();

        system((NAME + ".exe").c_str());
        system((NAME + "_sol.exe").c_str());

        if (system(("fc " + NAME + ".OUT " + NAME + ".ANS").c_str()) != 0) {
            cout << "Test " << _tc << ": WA" << el;
			return 0;
        }

    	cout << "Test " << _tc << ": AC" << el;
    }
}
