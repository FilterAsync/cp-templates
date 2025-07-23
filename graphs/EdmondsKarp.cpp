#include <bits/stdc++.h>

using namespace std;

#pragma region TEMPLATE
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define FOR(i, l, r) for (int i = l; i <= (r); i++)
#define FOD(i, l, r) for (int i = l; i >= (r); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define by(x) [](auto const &a, auto const &b) { return a.x < b.x; }
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define PROBLEM ""

using db = long double;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

template<class T> bool chmax(T &a, T const &b) { return (a < b ? (a = b, true) : false); }

template<class T> bool chmin(T &a, T const &b) { return (a > b ? (a = b, true) : false); }

#define LOCAL
#ifdef LOCAL
// https://codeforces.com/blog/entry/125435
namespace __DEBUG_UTIL__ {
    using namespace std;
    /* Primitive Datatypes Print */
    void print(const char *x) { cerr << x; }
    void print(bool x) { cerr << (x ? "T" : "F"); }
    void print(char x) { cerr << '\'' << x << '\''; }
    void print(signed short int x) { cerr << x; }
    void print(unsigned short int x) { cerr << x; }
    void print(signed int x) { cerr << x; }
    void print(unsigned int x) { cerr << x; }
    void print(signed long int x) { cerr << x; }
    void print(unsigned long int x) { cerr << x; }
    void print(signed long long int x) { cerr << x; }
    void print(unsigned long long int x) { cerr << x; }
    void print(float x) { cerr << x; }
    void print(double x) { cerr << x; }
    void print(long double x) { cerr << x; }
    void print(string x) { cerr << '\"' << x << '\"'; }
    template <size_t N>
    void print(bitset<N> x) { cerr << x; }
    void print(vector<bool> v) {
        /* Overloaded this because stl optimizes vector<bool> by using
          _Bit_reference instead of bool to conserve space. */
        int f = 0;
        cerr << '{';
        for (auto &&i : v)
            cerr << (f++ ? "," : "") << (i ? "T" : "F");
        cerr << "}";
    }
    /* Templates Declarations to support nested datatypes */
    template <typename T>
    void print(T &&x);
    template <typename T>
    void print(vector<vector<T>> mat);
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]);
    template <typename F, typename S>
    void print(pair<F, S> x);
    template <typename T, size_t N>
    struct Tuple;
    template <typename T>
    struct Tuple<T, 1>;
    template <typename... Args>
    void print(tuple<Args...> t);
    template <typename... T>
    void print(priority_queue<T...> pq);
    template <typename T>
    void print(stack<T> st);
    template <typename T>
    void print(queue<T> q);
    /* Template Datatypes Definitions */
    template <typename T>
    void print(T &&x) {
        /*  This works for every container that supports range-based loop
            i.e. vector, set, map, oset, omap, dequeue */
        int f = 0;
        cerr << '{';
        for (auto &&i : x)
            cerr << (f++ ? "," : ""), print(i);
        cerr << "}";
    }
    template <typename T>
    void print(vector<vector<T>> mat) {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat) {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]) {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat) {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename F, typename S>
    void print(pair<F, S> x) {
        cerr << '(';
        print(x.first);
        cerr << ',';
        print(x.second);
        cerr << ')';
    }
    template <typename T, size_t N>
    struct Tuple {
        static void printTuple(T t) {
            Tuple<T, N - 1>::printTuple(t);
            cerr << ",", print(get<N - 1>(t));
        }
    };
    template <typename T>
    struct Tuple<T, 1> {
        static void printTuple(T t) { print(get<0>(t)); }
    };
    template <typename... Args>
    void print(tuple<Args...> t) {
        cerr << "(";
        Tuple<decltype(t), sizeof...(Args)>::printTuple(t);
        cerr << ")";
    }
    template <typename... T>
    void print(priority_queue<T...> pq) {
        int f = 0;
        cerr << '{';
        while (!pq.empty())
            cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
        cerr << "}";
    }
    template <typename T>
    void print(stack<T> st) {
        int f = 0;
        cerr << '{';
        while (!st.empty())
            cerr << (f++ ? "," : ""), print(st.top()), st.pop();
        cerr << "}";
    }
    template <typename T>
    void print(queue<T> q) {
        int f = 0;
        cerr << '{';
        while (!q.empty())
            cerr << (f++ ? "," : ""), print(q.front()), q.pop();
        cerr << "}";
    }
    /* Printer functions */
    void printer(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail) {
        /* Using && to capture both lvalues and rvalues */
        int i = 0;
        for (size_t bracket = 0; names[i] != '\0' && (names[i] != ',' || bracket != 0); i++)
            if (names[i] == '(' || names[i] == '<' || names[i] == '{')
                bracket++;
            else if (names[i] == ')' || names[i] == '>' || names[i] == '}')
                bracket--;
        cerr.write(names, i) << " = ";
        print(head);
        if (sizeof...(tail))
            cerr << " ||", printer(names + i + 1, tail...);
        else
            cerr << "]\n";
    }
    /* PrinterArr */
    void printer_arr(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printer_arr(const char *names, T arr[], size_t N, V... tail) {
        size_t ind = 0;
        for (; names[ind] && names[ind] != ','; ind++)
            cerr << names[ind];
        for (ind++; names[ind] && names[ind] != ','; ind++)
            ;
        cerr << " = {";
        for (size_t i = 0; i < N; i++)
            cerr << (i ? "," : ""), print(arr[i]);
        cerr << "}";
        if (sizeof...(tail))
            cerr << " ||", printer_arr(names + ind + 1, tail...);
        else
            cerr << "]\n";
    }
}
#define debug(...) std::cerr << "L" << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debug_arr(...) std::cerr << "L" << __LINE__ << ": [", __DEBUG_UTIL__::printer_arr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debug_arr(...)
#endif
#pragma endregion TEMPLATE

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

constexpr int MAXN = 1E3 + 5;
constexpr int INF = 1E9 + 7;
constexpr ll MOD = 1E9 + 7, INFLL = 1E18 + 7;
constexpr double EPS = 1E-9;

vi adj[MAXN];
int c[MAXN][MAXN], f[MAXN][MAXN], trace[MAXN];
int res = 0;
int n, m, s, t;

void augment_path() {
    memset(trace, 0x00, sizeof trace);
    trace[s] = -1;
    queue<int> q;
    q.push(s);
    while (sz(q)) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (trace[v] || f[u][v] - c[u][v] == 0) continue;
            trace[v] = u;
            q.push(v);
        }
    }
}

void inc_flow() {
    int v = t, delta = INF;
    while (v != s) {
        int u = trace[v];
        chmin(delta, c[u][v] - f[u][v]);
        v = u;
    }
    res += delta;
    v = t;
    while (v != s) {
        int u = trace[v];
        f[u][v] += delta;
        f[v][u] -= delta;
        v = u;
    }
}

void max_flow() {
    do {
        augment_path();
        if (trace[t]) inc_flow();
    } while (trace[t]);
}

void solve() {
    // Edmonds-Karp algorithm
    cin >> n >> m >> s >> t;
    while (m--) {
        int u, v;
        cin >> u >> v >> c[u][v];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    max_flow();
    cout << res;
}

int main() {
    fast_io
    #ifndef LOCAL
    freopen(PROBLEM ".INP", "r", stdin);
    freopen(PROBLEM ".OUT", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
