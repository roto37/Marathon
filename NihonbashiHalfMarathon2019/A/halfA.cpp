//#include <bits/stdc++.h>

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
//const ll mod = 998244353;
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
    if (msec >= 1980) return false;
    return true;
}

inline bool check_time1() {
    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
    if (msec >= 1000) return false;
    return true;
}

inline void now_time() {
  auto end = chrono::system_clock::now();
  auto dur = end - start;
  auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
  cout << "time : " << msec << " msec"<< endl;
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

int n;
int x[200], y[200];
vector<vector<double>> g(200, vector<double>(200));
vector<int> ans;



int calc_score(vector<double>& dist_list) {
  double sumdist = 0;
  for (auto d : dist_list) {
    sumdist += d;
  }
  double ave = sumdist / n;
  double variance = 0;
  for (auto v : dist_list) {
    variance += (v - ave) * (v - ave);
  }
  variance /= n;
  int ret = ceil(1000000 / (1 + variance));
  return ret;
}


void read() {
  cin >> n;
  rep(i, n) {
    cin >> x[i] >> y[i];
  }
}

void dist_all() {
  rep(i, n) {
    rep(j, n) {
      int xx = (x[i] - x[j]) * (x[i] - x[j]);
      int yy = (y[i] - y[j]) * (y[i] - y[j]);
      g[i][j] = sqrt(xx + yy);
    }
  }
}

void out() {
  for (auto i : ans) {
    cout << i << endl;
  }
}

void solve() {
  int seednum = 37;
  int mx_score = -INF;
  vector<double> dist_list;
  while (check_time()) {
    seednum++;
    seed(seednum);
    int base = Xor128() % 1000;
    int st = Xor128() % n;
    int now = st;
    bool used[n] = {};
    used[now] = true;
    vector<int> tmp_ans;
    tmp_ans.push_back(now);
    vector<double> tmp_distlist;
    rep(i, n) {
      rep(j, n - 1) {
        double mn = INF;
        int nx = -1;
        rep(k, n) {
          if (used[k]) continue;
          double tmpmn = abs(g[now][k] - base);
          if (mn > tmpmn) {
            nx = k;
            mn = tmpmn;
          }
        }
        tmp_distlist.push_back(g[now][nx]);
        now = nx;
        used[now] = true;
        tmp_ans.push_back(now);
      }
      tmp_distlist.push_back(g[now][st]);
      int tmp_score = calc_score(tmp_distlist);
      if (mx_score < tmp_score) {
        mx_score = tmp_score;
        dist_list = tmp_distlist;
        cout << mx_score << endl;
        ans = tmp_ans;
      }
    }
  }
  /*
  int seednum = 37;
  seed(seednum);
  while (check_time()) {
    int i1 = 1 + Xor128() % (n-2);
    int i2 = 1 + Xor128() % (n-2);
    if (i1 == i2 || i1 == n || i2 == n) continue;
    vector<double> swap_distlist = dist_list;
    swap_distlist[i1 - 1] = g[ans[i1 - 1]][ans[i1]];
    swap_distlist[i1] = g[ans[i1]][ans[i1 + 1]];
    swap_distlist[i2 - 1] = g[ans[i2 - 1]][ans[i2]];
    swap_distlist[i2] = g[ans[i2]][ans[i2 + 1]];
    int tmp_score = calc_score(swap_distlist);
    cout << tmp_score << endl;
    if (mx_score < tmp_score) {
      mx_score = tmp_score;
      dist_list = swap_distlist;
      cout << mx_score << endl;
      swap(ans[i1], ans[i2]);
    }
  }
  */
  //out();
}

void solve1() {
  double all_ave = 0;
  int e_cnt = 0;
  rep(i, n) {
    rep2(j, i + 1, n) {
      e_cnt++;
      all_ave += g[i][j];
    }
  }
  all_ave /= e_cnt;
  int mx_score = -INF;
  vector<double> dist_list;
  rep(i, n) {
    int now = i;
    bool used[n] = {};
    used[now] = true;
    vector<int> tmp_ans;
    tmp_ans.push_back(now);
    vector<double> tmp_distlist;
    rep(j, n - 1) {
      double mn = INF;
      int nx = -1;
      rep(k, n) {
        if (used[k]) continue;
        double tmpmn = abs(g[now][k] - all_ave);
        if (mn > tmpmn) {
          nx = k;
          mn = tmpmn;
        }
      }
      tmp_distlist.push_back(g[now][nx]);
      now = nx;
      used[now] = true;
      tmp_ans.push_back(now);
    }
    tmp_distlist.push_back(g[now][i]);
    int tmp_score = calc_score(tmp_distlist);
    if (mx_score < tmp_score) {
      mx_score = tmp_score;
      dist_list = tmp_distlist;
      //cout << mx_score << endl;
      ans = tmp_ans;
    }
  }
  int seednum = 37;
  seed(seednum);
  while (check_time()) {
    int i1 = 1 + Xor128() % (n-2);
    int i2 = 1 + Xor128() % (n-2);
    if (i1 == i2 || i1 == n || i2 == n) continue;
    vector<double> swap_distlist = dist_list;
    swap_distlist[i1 - 1] = g[ans[i1 - 1]][ans[i1]];
    swap_distlist[i1] = g[ans[i1]][ans[i1 + 1]];
    swap_distlist[i2 - 1] = g[ans[i2 - 1]][ans[i2]];
    swap_distlist[i2] = g[ans[i2]][ans[i2 + 1]];
    int tmp_score = calc_score(swap_distlist);
    cout << tmp_score << endl;
    if (mx_score < tmp_score) {
      mx_score = tmp_score;
      dist_list = swap_distlist;
      cout << mx_score << endl;
      swap(ans[i1], ans[i2]);
    }
  }
  out();
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  read();
  dist_all();
  solve();
  //solve1();
}
