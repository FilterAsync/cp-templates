#include <bits/stdc++.h>

using namespace std;

template<class T> bool chmax(T &a, T const &b) {
    return (a < b ? (a = b, true) : false);
}

template<class T> bool chmin(T &a, T const &b) {
    return (a > b ? (a = b, true) : false);
}

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

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

#define LOCAL
#ifdef LOCAL
template<typename T> void _print(const char* name, T&& x) {
    cerr << name << " = " << x << el;
}
#define debug(x) _print(#x, x)
#else
#define debug(x)
#endif

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const string NAME = "PROBLEM";
const int MAXN = 1E5 + 5;
const int INF = 1E9 + 7;
const ll MOD = 1E9 + 7, INFLL = 1E18;
const double EPS = 1E-9;

struct Node {
    Node* child[26];
    int exist, cnt;

    Node() {
        fill(begin(child), end(child), nullptr);
        exist = cnt = 0;
    }
};

struct Trie {
private:
    bool _remove(Node* p, string& s, int i) {
        if (i != sz(s)) {
            int c = s[i] - 'a';
            bool is_removed = _remove(p->child[c], s, i + 1);
            if (is_removed) {
                p->child[c] = nullptr;
            }
        } else {
            p->exist--;
        }

        if (p != root) {
            p->cnt--;
            if (p->cnt == 0) {
                delete(p);
                return true;
            }
        }

        return false;
    }
public:
    Node* root;
    Trie() {
        root = new Node();
    };

    void insert(string s) {
        Node* p = root;
        for (auto f : s) {
            int c = f - 'a';
            if (p->child[c] == nullptr) {
                p->child[c] = new Node();
            }
            p = p->child[c];
            p->cnt++;
        }
        p->exist++;
    }

    void erase(string s) {
        if (find(s)) {
            _remove(root, s, 0);
        }
    }

    bool find(string s) {
        Node* p = root;

        for (auto f : s) {
            int c = f - 'a';
            if (p->child[c] == nullptr) {
                return false;
            }
            p = p->child[c];
        }

        return p->exist != 0;
    }
};

void solve() {
    
}

int main() {
    fast_io
    #ifndef LOCAL
    freopen((NAME + ".INP").c_str(), "r", stdin);
    freopen((NAME + ".OUT").c_str(), "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
