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
    if (msec >= 28000) return false;
    return true;
}
/*
inline bool check_time1() {
    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
    if (msec >= 10000) return false;
    return true;
}

inline bool check_time2() {
    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
    if (msec >= 20000) return false;
    return true;
}
*/

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
//---------------------------------global-----------------------------
int n, T;
vector<int> card(50); // 0 : ?, 1~n/2
//---------------------------------global-----------------------------

int read() {
  int a;
  cin >> a;
  return a;
}

void out(int q) {
  cout << q << endl;
}
void record(int idx, int a) {
  card[idx] = a;
}

void solve() {
  int now = 0;
  int sum_dist = 0;
  int seednum = 37;
  seed(seednum);
  bool select = false;
  while (true) {
    if (card[now] == 0) {
      out(now);
      int a = read();
      record(now, a);
      continue;
    }
    int nx = -1;
    assert(card[now] != 0);
    rep(i, n) {
      if (now == i) continue;
      if (card[i] <= 0 && !select) continue;
      if (card[now] == card[i]) {
        nx = i;
        /*
        if (select) select = false;
        break;
        */
      }
    }
    if (nx == -1) {
      int min_dist = 100;
      rep(i, n) {
        if (card[i] == 0) {
          int dist = abs(now - i);
          if (dist < min_dist) {
            min_dist = dist;
            nx = i;
          }
        }
      }
    }
    if (nx == -1) {
      rep(i, n) {
        select = true;
        rep(j, n) {
          if (i == j) continue;
          if (card[j] == card[i]) {
            if (abs(now - i) < abs(now - j)) {
              nx = i;
            }
            else {
              nx = j;
            }
            break;
          }
        }
      }
    }
    int dist = abs(nx - now);
    if (sum_dist + dist > T) {
      out(-1);
      return;
    }
    else {
      out(nx);
      int a = read();
      record(nx, a);
      sum_dist += dist;
      if (card[nx] == card[now]) {
        card[now] = 0;
        card[nx] = 0;
      }
      now = nx;
    }
  }
}

signed main() {
  cin >> n >> T;
  solve();
}
