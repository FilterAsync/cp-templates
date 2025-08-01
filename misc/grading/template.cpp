#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define FOR(i, l, r) for (int i = l; i <= (r); i++)
#define FOD(i, l, r) for (int i = l; i >= (r); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);

template<class T> bool chmax(T &a, T const &b) { return (a < b ? (a = b, true) : false); }

template<class T> bool chmin(T &a, T const &b) { return (a > b ? (a = b, true) : false); }

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

constexpr int NTEST = 100; // number of test cases

#define NAME ""

// find random number in [l, r]
ll Rand(ll l, ll r) {
    assert(l <= r);
    return l + rng() % (r - l + 1);
}

int main() {
    srand(time(NULL));
    FOR(_tc, 1, NTEST) {
        ofstream inp(NAME ".INP");
        // generate test cases here
        inp.close();

        // answer comparison procedure
        system(NAME ".exe");
        system(NAME "_sol.exe");
        cout << "Test " << _tc << ": ";
        if (system("fc " NAME ".OUT " NAME ".ANS") != 0) {
            cout << "WA" << el;
            return 0;
        }
        cout << "AC" << el;
    }
}
