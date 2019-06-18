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

struct Operation {
  int op;
  int y;
  int x;
  Operation(int _op, int _y, int _x) {
    op = _op;
    y = _y;
    x = _x;
  }
};
int n, m;
vector<vector<int>> a(50, vector<int>(50));
vector<vector<pii>> num(11);
vector<Operation> ans;

void order_1(vector<Operation>& op, int cnt, int i, int j) {
  rep(_, cnt) op.push_back(Operation(1, i, j));
}

void order_2(vector<Operation>& op, int i, int j) {
  op.push_back(Operation(2, i, j));
}

int dfs(int k, int y, int x, vector<vector<bool>>& visited, vector<vector<int>>& tmp_a) {
  visited[y][x] = true;
  int ret = 0;
  rep(i, 4) {
    int ny = y + dy4[i];
    int nx = x + dx4[i];
    if (!inside(ny, nx, n, n)) continue;
    if (visited[ny][nx] || tmp_a[ny][nx] != k) continue;
    ret += k + dfs(k, ny, nx, visited, tmp_a);
  }
  return ret;
}

int calc_score(int y, int x, vector<vector<bool>>& visited, vector<vector<int>>& tmp_a) {
  int k = a[y][x];
  return dfs(k, y, x, visited, tmp_a);
}

void read() {
  cin >> n >> m;
  rep(i, n)rep(j, n) {
    cin >> a[i][j];
    num[a[i][j]].push_back({i, j});
  }
}
void out() {
  rep(i, 2500) {
    cout << ans[i].op << " " << ans[i].y << " " << ans[i].x << endl;
  }
}

vector<pii> modify_9(int& cnt, int limit, vector<Operation>& tmp_ans, vector<vector<bool>>& used, vector<vector<int>>& tmp_a) {
  priority_queue<pair<int, pii>, vector<pair<int, pii>>> pq;
  int size = num[9].size();
  int input_cnt = 0;
  vector<pii> ret;
  int lim = 60 + Xor128() % 50;
  while (input_cnt < lim) {
    int st = Xor128() % size;
    pii now = num[9][st];
    if (used[now.fi][now.se]) continue;
    pq.push({9, now});
    used[now.fi][now.se] = true;
    input_cnt++;
    ret.push_back(now);
  }
  int cnt_9 = 1;
  while (cnt <= 2400 && pq.size() > 0) {
    auto p = pq.top(); pq.pop();
    int val = p.fi;
    if (val <= limit) break;
    int y = p.se.fi;
    int x = p.se.se;
    order_1(tmp_ans, 9 - val, y, x);
    cnt += 9 - val;
    tmp_a[y][x] = 9;
    cnt_9++;
    rep(k, 4) {
      int ny = y + dy4[k];
      int nx = x + dx4[k];
      if (!inside(ny, nx, n, n)) continue;
      if (used[ny][nx]) continue;
      pq.push({a[ny][nx], {ny, nx}});
      used[ny][nx] = true;
    }
  }
  return ret;
}

void solve() {
  int mx_score = -1;
  int seednum = 37;
  seed(seednum);
  while (check_time()) {
    vector<vector<bool>> used(n, vector<bool>(n, false));
    vector<Operation> tmp_ans;
    vector<vector<int>> tmp_a = a;
    int tmp_score = 0;
    int cnt = 0;

    /*
    pii now;
    while (cnt <= 2400) {
      while (true) {
        int st = Xor128() % size;
        now = num[9][st];
        if (used[now.fi][now.se]) continue;
        else break;
      }
      modify_9(cnt, now, 3, tmp_ans ,used, tmp_a);
    }
    */
    vector<pii> st_9 = modify_9(cnt, 3, tmp_ans ,used, tmp_a);
    /*
    while (cnt <= 240) {
      int adjcnt9 = 0;
      int x = Xor128() % n;
      int y = Xor128() % n;
      if (tmp_a[y][x] == 9) continue;
      rep(k, 4) {
        int ny = x + dy4[k];
        int nx = y + dx4[k];
        if (!inside(ny, nx, n, n)) continue;
        if (tmp_a[ny][nx] == 9) adjcnt9++;
      }
      if (adjcnt9 >= 4) {
        //cout << tmp_a[y][x] << " " << y << " " << x << endl;
        cnt += 9 - tmp_a[y][x];
        tmp_a[y][x] = 9;
      }
    }
    */

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    rep(i, st_9.size()) {
      if (cnt >= 2500) break;
      pii now = st_9[i];
      order_2(tmp_ans, now.fi, now.se);
      tmp_score += calc_score(now.fi, now.se, visited, tmp_a);
      cnt++;
    }
    while (cnt <= 2500) {
      int r = Xor128() % n;
      int c = Xor128() % n;
      if (visited[r][c]) continue;
      order_2(tmp_ans, r, c);
      tmp_score += calc_score(r, c, visited, tmp_a);
      cnt++;
    }
    //dump(a);
    /*
    rep(i, n) {
      rep(j, n) cout << tmp_a[i][j] << " ";
      cout << endl;
    }
    return;
    */
    //cout << tmp_score << endl;
    if (mx_score < tmp_score) {
      mx_score = tmp_score;
      //cout << mx_score << endl;
      ans = tmp_ans;
    }
  }
  out();
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  read();
  solve();
}
