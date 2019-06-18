#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>

#include <iostream>
#include <algorithm>

#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <string>
#include <utility>
#include <array>
#include <complex>
#include <valarray>

#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <chrono>
#include <random>
#include <numeric>


using namespace std;
#define int long long

typedef long long ll;
typedef unsigned long long ull;
//typedef unsigned __int128 HASH;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pullull;
typedef pair<ll,int> plli;
typedef pair<double,int> pdi;
typedef pair<long double, int> pdbi;
typedef pair<int,pii> pipii;
typedef pair<ll,pll> plpll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vector<int>> mat;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

const ll hmod1 = 999999937;
const ll hmod2 = 1000000000 + 9;
const int INF = 1<<30;
const ll INFLL = 1LL<<62;
const long double EPS = 1e-12;
const ll mod = 1000000000 + 7;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const long double pi = 3.141592653589793;

#define addm(X, Y) (X) = ((X) + ((Y) % mod) + mod) % mod
#define inside(y, x, h, w) (0 <= (y) && (y) < (h) && 0 <= (x) && (x) < (w)) ? true : false

//debug
#define DEBUG

#define DUMPOUT cout

#ifdef DEBUG
#define dump(...) DUMPOUT<<#__VA_ARGS__<<" :["<<__FUNCTION__<<":"<<__LINE__<<"]"<<endl; DUMPOUT<<"    "; dump_func(__VA_ARGS__)
#else
#define dump(...)
#endif

void dump_func() {DUMPOUT << endl;};

template <class Head, class... Tail> void dump_func(Head&& head, Tail&&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) == 0) DUMPOUT << " ";
    else DUMPOUT << ", ";
    dump_func(std::move(tail)...);
}

//ostream
template<typename T> ostream& operator << (ostream& os, vector<T>& vec) {
    os << "["; for (int i = 0; i<vec.size(); i++) os << vec[i] << (i + 1 == vec.size() ? "" : ", "); os << "]";
    return os;
}

template<typename T, typename U> ostream& operator << (ostream& os, pair<T, U>& pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}

template<typename T, typename U> ostream& operator << (ostream& os, map<T, U>& map_var) {
    os << "[";
    for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
        os << "(" << itr->first << ", " << itr->second << ")"; itr++;  if(itr != map_var.end()) os << ", "; itr--;
    }
    os << "]";
    return os;
}

template<typename T> ostream& operator << (ostream& os, set<T>& set_var) {
    os << "[";
    for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
        os << *itr; ++itr; if(itr != set_var.end()) os << ", "; itr--;
    }
    os << "]";
    return os;
}



auto start = chrono::system_clock::now();

inline bool check_time() {
    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
    if (msec >= 18000) return false;
    return true;
}

/*
inline bool check_time1() {
    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
    if (msec >= 20000) return false;
    return true;
}

inline bool check_time2() {
    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
    if (msec >= 26000) return false;
    return true;
}
*/
inline void now_time() {
  auto end = chrono::system_clock::now();
  auto dur = end - start;
  auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
  cerr << "time : " << msec << " msec"<< endl;
}

unsigned long seed128[4]; //x,y,z,wとして利用
inline void seed(unsigned int s){
    for(int i=1; i<=4; i++){
        seed128[i-1] = s = 1812433253U * (s^(s>>30)) + i;
    }
}
inline unsigned long Xor128(){
  unsigned long t;
  t=(seed128[0]^(seed128[0]<<11));
  seed128[0]=seed128[1];
  seed128[1]=seed128[2];
  seed128[2]=seed128[3];
  return seed128[3]=(seed128[3]^(seed128[3]>>19))^(t^(t>>8));
}

int n, m;
vector<vector<int>> c(20, vector<int>(20, -1));

struct state {
  int sc;
  int t;
  vector<vector<int>> g;
  vector<tuple<int, int, int>> ans;
  state(int _sc, int _t, vector<vector<int>> _g, vector<tuple<int, int, int>> _ans) {
    sc = _sc;
    t = _t;
    g = _g;
    ans = _ans;
  }
  bool operator > (const state &st) const {
    return sc < st.sc;
  }
};

int calc_score(vector<vector<int>> &g) {
    int score = 0;
    rep(i, n/2)rep(j, n/2) {
      if (g[i][j] == 0) score++;
    }
    rep(i, n/2)rep2(j, n/2, n) {
      if (g[i][j] == 1) score++;
    }
    rep2(i, n/2, n)rep(j, n/2) {
      if (g[i][j] == 2) score++;
    }
    rep2(i, n/2, n)rep2(j, n/2, n) {
      if (g[i][j] == 3) score++;
    }
    return score;
}


void solve() {
  int cnt = 0;
  int seednum = 37;
  seed(seednum);
  vector<vector<int>> g = c;
  int mx_score = calc_score(g);
  priority_queue<state, vector<state>, greater<state>> pq; //{score, {turn, g}
  vector<tuple<int, int, int>> init_ans;
  pq.push(state(mx_score, 0, g, init_ans));
  while (cnt < m && check_time()) {
    cnt++;
    int limit = 30;
    int loop = 0;
    priority_queue<state, vector<state>, greater<state>> nxpq1;
    while (pq.size() > 0) {
      state S = pq.top();pq.pop();
      cerr << cnt << " " << S.sc << endl;
      while (loop < limit && check_time()) {
        vector<vector<int>> Sg = S.g;
        int s = 3 + Xor128() % n;
        int ro = Xor128() % n;
        int co = Xor128() % n;
        if (s - 1 + ro > n - 1 || s - 1 + co > n - 1) continue;
        loop++;
        vector<vector<int>> tmpg = Sg;
        int pi = ro;
        int pj = co;
        rep2(j, co, s + co) {
          rrep2(i, s + ro - 1, ro - 1) {
            tmpg[pi][pj] = Sg[i][j];
            pj++;
            if (pj == s+co) {
              pj = co;
              pi++;
            }
          }
        }
        int tmp_score = calc_score(tmpg);
        vector<tuple<int, int,  int>> nx_ans = S.ans;
        nx_ans.push_back(make_tuple(ro, co, s));
        //cerr << tmp_score << " " << S.sc << endl;

        nxpq1.push(state(tmp_score, S.t+1, tmpg, nx_ans));
      }
    }
    //cerr << nxpq1.size() << endl;
    priority_queue<state, vector<state>, greater<state>> nxpq2;
    int k = 3;
    while (nxpq1.size() > 0) {
      state x = nxpq1.top(); nxpq1.pop();
      if (nxpq2.size() >= k) break;
      nxpq2.push(x);
    }
    pq = nxpq2;
  }
  state S = pq.top();
  vector<tuple<int, int, int>> ans = S.ans;
  rep(i, ans.size()) {
    int r, c, s;
    tie(r, c, s) = ans[i];
    cout << r << " " << c << " " << s << endl;
  }
  return;
}

signed main() {
  cin >> n >> m;
  rep(i, n)rep(j, n) cin >> c[i][j];
  solve();
}
