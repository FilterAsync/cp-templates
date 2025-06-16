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
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)
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
    Node* children[26];
    bool is_word;

    Node() : is_word(false) {
        fill(begin(children), end(children), nullptr);
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char const &c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Node();
            }
            node = node->children[idx];
        }
        node->is_word = true;
    }

    void remove(const string &word) {
        Node* node = root;
        stack<Node*> nodes;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return;
            nodes.push(node);
            node = node->children[idx];
        }
        if (!node->is_word) return;
        node->is_word = false;

        FOD(i, sz(word) - 1, 0) {
            Node* parent = nodes.top();
            nodes.pop();
            int idx = word[i] - 'a';
            if (node->is_word || any_of(begin(node->children), end(node->children), [](Node* child) { return child != nullptr; })) {
                break;
            }
            delete parent->children[idx];
            parent->children[idx] = nullptr;
            node = parent;
        }
    }

    bool search(const string &word) {
        Node* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->is_word;
    }

    bool find(const string &prefix) {
        Node* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

void solve() {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    cout << (trie.search("hello") ? "Found 'hello'" : "Not found 'hello'") << el;
    cout << (trie.search("hell") ? "Found 'hell'" : "Not found 'hell'") << el;
    cout << (trie.find("he") ? "Found prefix 'he'" : "Not found prefix 'he'") << el;
    cout << (trie.find("wo") ? "Found prefix 'wo'" : "Not found prefix 'wo'") << el;
    cout << (trie.search("world") ? "Found 'world'" : "Not found 'world'") << el;
    cout << (trie.search("word") ? "Found 'word'" : "Not found 'word'") << el;
    cout << (trie.find("worl") ? "Found prefix 'worl'" : "Not found prefix 'worl'") << el;
    cout << (trie.find("helloworld") ? "Found prefix 'helloworld'" : "Not found prefix 'helloworld'") << el;
    cout << (trie.search("helloworld") ? "Found 'helloworld'" : "Not found 'helloworld'") << el;
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
