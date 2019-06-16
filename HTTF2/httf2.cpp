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

std::random_device rnd;
std::mt19937 mt(rnd());
std::uniform_int_distribution<int> rd1(0, 5), rd2(0, 5);
//rd1(mt);
auto start = chrono::system_clock::now();

inline uint32_t Xor128(){
	static uint32_t x=123456789;
	static uint32_t y=362436069;
	static uint32_t z=521288629;
	static uint32_t w=88675123;
	uint32_t t=x^(x<<11);
	x=y;y=z;z=w;
	return w=(w^(w>>19))^(t^(t>>8));
}

inline bool check_time() {
    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
    if (msec >= 2995) return false;
    return true;
}

int n, m, l;
char order[500][300];
vector<char> effectall = {'.', '#', 'D', 'T', 'L', 'R'};
vector<char> effectDTLR = {'.', 'D', 'T', 'L', 'R'};
vector<char> effectDLR = {'.', 'D', 'L', 'R'};
vector<char> effectLR = {'.', 'L', 'R'};
vector<char> effectL = {'.', 'L'};
vector<char> effectR = {'.', 'R'};
vector<char> effectDT = {'.', 'D', 'T'};
vector<char> effectLRS = {'.', '#', 'L', 'R'};
vector<char> dir = {'N', 'E', 'S', 'W'}; //0:北, 1:東, 2:南, 3:西

pair<int, int> next_pos(int d, int x, int y, int e, vector<vector<char>>& g) {
  int nx = x;
  int ny = y;
  if (dir[d] == 'N') {
    if (e == '.') {
      nx = x;
      ny = y - 1;
      if (g[ny][nx] == '#') return make_pair(x, y);
      return make_pair(nx, ny);
    }
    else if (e == 'D') {
      rep(i, 2) {
        nx = x;
        ny = y - 1;
        if (g[ny][nx] == '#') return make_pair(x, y);
        x = nx;
        y = ny;
      }
      return make_pair(nx, ny);
    }
    else if (e == 'T') {
      rep(i, 3) {
        nx = x;
        ny = y - 1;
        if (g[ny][nx] == '#') return make_pair(x, y);
        x = nx;
        y = ny;
      }
      return make_pair(nx, ny);
    }
    else {
      nx = x;
      ny = y - 1;
      if (g[ny][nx] == '#') return make_pair(x, y);
      return make_pair(nx, ny);
    }
  }

  if (dir[d] == 'E') {
    if (e == '.') {
      nx = x + 1;
      ny = y;
      if (g[ny][nx] == '#') return make_pair(x, y);
      return make_pair(nx, ny);
    }
    else if (e == 'D') {
      rep(i, 2) {
        nx = x + 1;
        ny = y;
        if (g[ny][nx] == '#') return make_pair(x, y);
        x = nx;
        y = ny;
      }
      return make_pair(nx, ny);
    }
    else if (e == 'T') {
      rep(i, 3) {
        nx = x + 1;
        ny = y;
        if (g[ny][nx] == '#') return make_pair(x, y);
        x = nx;
        y = ny;
      }
      return make_pair(nx, ny);
    }
    else {
      nx = x + 1;
      ny = y;
      if (g[ny][nx] == '#') return make_pair(x, y);
      return make_pair(nx, ny);
    }
  }

  if (dir[d] == 'S') {
    if (e == '.') {
      nx = x;
      ny = y + 1;
      if (g[ny][nx] == '#') return make_pair(x, y);
      return make_pair(nx, ny);
    }
    else if (e == 'D') {
      rep(i, 2) {
        nx = x;
        ny = y + 1;
        if (g[ny][nx] == '#') return make_pair(x, y);
        x = nx;
        y = ny;
      }
      return make_pair(nx, ny);
    }
    else if (e == 'T') {
      rep(i, 3) {
        nx = x;
        ny = y + 1;
        if (g[ny][nx] == '#') return make_pair(x, y);
        x = nx;
        y = ny;
      }
      return make_pair(nx, ny);
    }
    else {
      nx = x;
      ny = y + 1;
      if (g[ny][nx] == '#') return make_pair(x, y);
      return make_pair(nx, ny);
    }
  }

  if (dir[d] == 'W') {
    if (e == '.') {
      nx = x - 1;
      ny = y;
      if (g[ny][nx] == '#') return make_pair(x, y);
      return make_pair(nx, ny);
    }
    else if (e == 'D') {
      rep(i, 2) {
        nx = x - 1;
        ny = y;
        if (g[ny][nx] == '#') return make_pair(x, y);
        x = nx;
        y = ny;
      }
      return make_pair(nx, ny);
    }
    else if (e == 'T') {
      rep(i, 3) {
        nx = x - 1;
        ny = y;
        if (g[ny][nx] == '#') return make_pair(x, y);
        x = nx;
        y = ny;
      }
      return make_pair(nx, ny);
    }
    else {
      nx = x - 1;
      ny = y;
      if (g[ny][nx] == '#') return make_pair(x, y);
      return make_pair(nx, ny);
    }
  }
}

int calc_score(vector<vector<char>>& g) {
  vector<vector<int>> pos(m, vector<int>(m));
  int score = 0;
  rep(i, n) {
    int nowdir = 0;
    int nowx = 14;
    int nowy = 14;
    rep(j, l) {
      if (order[i][j] == 'S') {
        pii p = next_pos(nowdir, nowx, nowy, g[nowy][nowx], g);
        int nx = p.fi;
        int ny = p.se;
        nowdir = nowdir;
        nowx = nx;
        nowy = ny;
      }
      else if (order[i][j] == 'R') {
        if (g[nowy][nowx] == 'D') nowdir = (nowdir + 2) % 4;
        else if (g[nowy][nowx] == 'T') nowdir = (nowdir + 3) % 4;
        else if (g[nowy][nowx] == 'L') nowdir = (nowdir - 1 + 4) % 4;
        else nowdir = (nowdir + 1) % 4;
      }
      else {
        if (g[nowy][nowx] == 'D') nowdir = (nowdir - 2 + 4) % 4;
        else if (g[nowy][nowx] == 'T') nowdir = (nowdir - 3 + 4) % 4;
        else if (g[nowy][nowx] == 'R') nowdir = (nowdir + 1) % 4;
        else nowdir = (nowdir - 1 + 4) % 4;
      }
    }
    pos[nowy][nowx]++;
  }
  rep(i, m)rep(j, m) {
    //cout << i << " " << j << endl;
    if (pos[i][j] == 1) score += 10;
    else if (pos[i][j] == 2) score += 3;
    else if (pos[i][j] == 3) score += 1;
    else score += 0;
  }
  return score;
}

vector<vector<char>> make_g() {
  vector<vector<char>> ret(m, vector<char>(m));
  rep(j, m) {
    ret[0][j] = '#';
    ret[m - 1][j] = '#';
  }
  rep(i, m) {
    ret[i][0] = '#';
    ret[i][m - 1] = '#';
  }
  rep2(i, 1, m - 1)rep2(j, 1, m - 1) {
    //ret[i][j] = effectLR[Xor128() % 3];
    //ret[i][j] = '.';
    ret[i][j] = effectall[Xor128()%6];
  }
  return ret;
}

void solve() {
  vector<vector<char>> ans(m, vector<char>(m));
  int max_score = -INFLL;
  rep(i, 50) {
    vector<vector<char>> g = make_g();
    int tmp_score = calc_score(g);
    //cout << i << ":" << tmp_score << endl;

    if (max_score < tmp_score) {
      ans = g;
      max_score = tmp_score;
    }
  }
  //cout << max_score << endl;
  //ans = make_g();
  //max_score = calc_score(ans);
  int cnt = 0;
  //int t =
  while (check_time()) {
    int x = Xor128() % 28;
    int y = Xor128() % 28;
    while (x == 0 || y == 0) {
      x = Xor128() % 28;
      y = Xor128() % 28;
    }
    char tmpans = ans[y][x];
    ans[y][x] = effectLR[Xor128() % 3];

    int tmp_score = calc_score(ans);
    cout << cnt << ":" << tmp_score << endl;

    if (max_score < tmp_score) {
      max_score = tmp_score;
    }
    else {
      ans[y][x] = tmpans;
    }
    cnt++;
  }
  cout << max_score << endl;
  rep(i, m) {
    rep(j, m) cout << ans[i][j];
    cout << endl;
  }
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m >> l;
  //n=500命令の個数
  //m=29盤面の長さ(m x m)
  //l=300ひとつの命令列の長さ(S, L, Rからなる)
  rep(i, n)rep(j, l) cin >> order[i][j];
  //vector<vector<char>> g(m, vector<char>(m));
  solve();
  //rep(i, 100) cout << Xor128() << endl;
}
