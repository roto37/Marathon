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

#include<memory>


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

const int dx3[3] = {0, 1, -1};
const int dy3[3] = {0, 1, -1};
const int dz3[3] = {0, 1, -1};

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
    //cerr << msec << endl;
    if (msec >= 1000) return false;
    return true;
}

inline bool check_time1() {
    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
    //cerr << msec << endl;
    if (msec >= 2800) return false;
    return true;
}

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

struct pair_ball {
  double val;
  double base_a, base_b;
  double bonus;
  int a, b;
  int ra, rb;
  int dia_a, dia_b;
  int dia_ab;

  pair_ball(int _a, int _b, int _ra, int _rb, int _base_a, int _base_b, int _bonus) {
    a = _a;
    b = _b;
    bonus = (double)_bonus;
    base_a = (double)_base_a;
    base_b = (double)_base_b;
    ra = _ra;
    rb = _rb;
    dia_a = 2 * _ra;
    dia_b = 2 * _rb;
    dia_ab = dia_a + dia_b;
    val = (double)(bonus + _base_a + _base_b);
    //val = dia_ab;
  }

  bool operator < (const pair_ball &pb) const {
    if (val == pb.val) return dia_ab < pb.dia_ab;
    return val < pb.val;
  }
};
struct BALL {
  int id;
  int r;
  int dia;

  BALL(int _a, int _r) {
    id = _a;
    r = _r;
    dia = 2 * _r;
    //val = bonus;
  }
};

int L, N, M;
vector<int> R(1000), P(1000), A(100000), B(100000), C(100000), D(100000);
vector<vector<vector<pii>>> bonus(1000, vector<vector<pii>>(1000));
vector<vector<int>> total_bonus(1000, vector<int>(1000));
vector<pair_ball> pairb;
vector<vector<pair_ball>> nx_pb(1000);
vector<BALL> Ball;
//vector<bool> used_b(1000);
//vector<vector<bool>> used_pb(1000, vector<bool>(1000, false));
vector<tuple<int, int, int>> ans(1000);

void out() {
  rep(i, N) {
    int x, y, z;
    tie(x, y, z) = ans[i];
    //if (x == -1) continue;

    //cerr << "i : " << i  << " R : " << R[i] << endl;
    cout << x << " " << y << " " << z << endl;
    //cerr << "-----------------" << endl;

  }
}

double distance(int x1, int x2, int y1, int y2, int z1, int z2) {
  return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2) + pow(abs(z1 - z2), 2));
}

bool is_valid(vector<tuple<int, int, int>> &v) {
  rep(i, N) {
    int x1, y1, z1;
    tie(x1, y1, z1) = v[i];
    if (x1 == -1) continue;
    if (x1 - R[i] < 0 || y1 - R[i] < 0 || z1 - R[i] < 0) {
      cerr << i << " minus" << endl;
      return false;
    }
    if (x1 + R[i] > L || y1 + R[i] > L || z1 + R[i] > L) {
      cerr << i << " over" << endl;
      cerr << x1 << " " << R[i] << endl;
      return false;
    }
    rep2(j, i + 1, N) {
      int x2, y2, z2;
      tie(x2, y2, z2) = v[j];
      if (x2 == -1) continue;
      if (x2 - R[j] < 0 || y2 - R[j] < 0 || z2 - R[j] < 0) {
        cerr << j << " minus" << endl;
        return false;
      }
      if (x2 + R[j] > L || y2 + R[j] > L || z2 + R[j] > L) {
        cerr << j << " over" << endl;
        cerr << x2 << " " << R[j] << endl;
        return false;
      }
      double dist = distance(x1, x2, y1, y2, z1, z2);
      if (R[i] + R[j] > dist) {
        cerr << "dist error : " << R[i] + R[j] << " " << dist << endl;
        return false;
      }
    }
  }
  return true;
}

int calc_score(vector<tuple<int, int, int>> &v, vector<bool>& used) {
  int ret = 0;
  rep(i, N) {
    if (used[i]) ret += P[i];
  }
  rep(i, N) {
    rep2(j, i + 1, N) {
      if (!used[i] || !used[j]) continue;
      int x1, y1, z1;
      tie(x1, y1, z1) = v[i];
      int x2, y2, z2;
      tie(x2, y2, z2) = v[j];
      double dist = distance(x1, x2, y1, y2, z1, z2);
      for (auto p : bonus[i][j]) {
        int point = p.se;
        double limit = p.fi;
        if (dist <= limit) {
          ret += point;
        }
      }
    }
  }
  return ret;
}

bool do_put(int x, int y, int z, pair_ball balls) {
  if (balls.dia_ab + x > L) return false;
  if (balls.dia_a + y > L || balls.dia_b + y > L) return false;
  if (balls.dia_a + z > L || balls.dia_b + z > L) return false;
  return true;
}

bool do_put(int x, int y, int z, int idx) {
  if (2*R[idx] + x > L) return false;
  if (2*R[idx] + y > L || 2*R[idx] + y > L) return false;
  if (2*R[idx] + z > L || 2*R[idx] + z > L) return false;
  return true;
}

void push_ball(int st, int& nowx, int& nowy, int& nowz, int& mxy, int& mxz, vector<tuple<int, int, int>>& kouho, vector<bool>& used) {
  int now = st;
  while (check_time()) {
    int sz = nx_pb[now].size();
    //bool select = false;
    bool update = false;
    used[now] = true;
    int nx = -1;
    double val = 0;
    rep(i, sz) {
      if (!check_time) return ;
      int a = nx_pb[now][i].a;
      int b = nx_pb[now][i].b;
      val = nx_pb[now][i].val;
      if (used[a] && used[b]) {
        continue;
      }
      if (now != a) nx = a;
      else nx = b;
      if (!do_put(nowx, nowy, nowz, nx)) continue;
      cerr << nowx << " " << nowy << " " << nowz << " " << 2*R[nx]  << " " << val <<endl;
      int x1 = nowx + R[nx];
      int y1 = nowy + R[nx];
      int z1 = nowz + R[nx];
      ans[nx] = make_tuple(x1, y1, z1);
      nowx += 2 * R[nx];
      mxy = max(mxy, nowy + 2*R[nx]);
      mxz = max(mxz, nowz + 2*R[nx]);
      break;
    }
    //となりにペアを見つけられなかったとき
    cerr << " nx : " << now << endl;
    if (nx == -1) {
      rep(i, N) {
        if (used[i]) continue;
        if (do_put(nowx, nowy, nowz, i)) {
          nx = i;
          cerr << nowx << " " << nowy << " " << nowz << " " << 2*R[nx]  << " " << val <<endl;
          int x1 = nowx + R[nx];
          int y1 = nowy + R[nx];
          int z1 = nowz + R[nx];
          ans[nx] = make_tuple(x1, y1, z1);
          nowx += 2 * R[nx];
          mxy = max(mxy, nowy + 2*R[nx]);
          mxz = max(mxz, nowz + 2*R[nx]);
          break;
        }
      }
    }
    //もうこれ以上x軸方向に置けないとき
    if (nx == -1) {
      if (nowx == 0) { // x軸方向に更新なし -> 1こ上
        if (nowy == 0) { // y軸方向に更新なし → 終了
          break;
        }
        else {
          nowx = 0;
          nowy = 0;
          nowz = mxz;
        }
      }
      else {
        nowx = 0;
        nowy = mxy;
      }
    }
    now = nx;
  }
  return;
}
void solve1() {
  rep(i, N) {
    sort(rall(nx_pb[i]));
  }
  int seednum = 37;
  int bestscore = 0;
  while (check_time()) {
    seed(seednum++);
    int nowx = 0;
    int nowy = 0;
    int nowz = 0;
    vector<bool> used_ball(N);
    vector<tuple<int, int, int>> kouho(N);
    rep(i, N) kouho[i] = make_tuple(-1, -1, -1);

    int now_ball = Xor128() % N;
    used_ball[now_ball] = true;
    int x0 = nowx + R[now_ball];
    int y0 = nowy + R[now_ball];
    int z0 = nowz + R[now_ball];
    kouho[now_ball] = make_tuple(x0, y0, z0);
    nowx += 2 * R[now_ball];
    int mxy = 2 * R[now_ball];
    int mxz = 2 * R[now_ball];

    push_ball(now_ball, nowx, nowy, nowz, mxy, mxz, kouho, used_ball);
    int score = calc_score(kouho, used_ball);
    cerr << "score : " << score << endl;
    if (bestscore < score) {
      bestscore = score;
      ans = kouho;
    }
  }
  /*
  while (true) {

    pair_ball balls = pairb[i];
    if (used_b[balls.a] || used_b[balls.b]) continue;
    if (!do_put(nowx, nowy, nowz, balls)) continue;
    int x1 = nowx + balls.ra;
    int y1 = nowy + balls.ra;
    int z1 = nowz + balls.ra;
    int x2 = nowx + balls.dia_a + balls.rb;
    int y2 = nowy + balls.rb;
    int z2 = nowz + balls.rb;
    //cerr << "get : " << balls.a << " " <<  balls.b << " " << balls.val << endl;
    cerr << nowx << " " << nowy << " " << nowz << " " << balls.dia_a << " " << balls.dia_b << " " << balls.val <<endl;
    ans[balls.a] = make_tuple(x1, y1 ,z1);
    ans[balls.b] = make_tuple(x2, y2, z2);
    nowx += balls.dia_ab;
    used_pb[balls.a][balls.b] = true;
    used_b[balls.a] = true;
    used_b[balls.b] = true;
    mxy = max({mxy, nowy + balls.dia_a, nowy + balls.dia_b});
    mxz = max({mxz, nowz + balls.dia_a, nowz + balls.dia_b});
  }
  if (nowx == 0) { // x軸方向に更新なし -> 1こ上
    if (nowy == 0) { // y軸方向に更新なし → 終了
      break;
    }
    else {
      nowx = 0;
      nowy = 0;
      nowz = mxz;
    }
  }
  else {
    nowx = 0;
    nowy = mxy;
  }
  */
  assert(is_valid(ans));
  cerr << "bestscore : " << bestscore << endl;
  //out();
}


void solve2() {
  int dl = 200;
  int box = L / dl;
  sort(rall(nx_pb));
  vector<BALL> v;
  rep(i, N) {
    if (Ball[i].dia <= dl) {
      v.push_back(Ball[i]);
    }
  }
  int sz = v.size();

  int seednum = 37;
  seed(seednum);
  int bestscore = 0;
  vector<vector<vector<int>>> pos(box, vector<vector<int>>(box, vector<int>(box, -1)));
  vector<bool> used(N);
  while (check_time()) {
    vector<vector<vector<int>>> tmppos(box, vector<vector<int>>(box, vector<int>(box, -1)));
    vector<bool> used_b(N);
    while (check_time()) {
      int posi = Xor128() % box;
      int posj = Xor128() % box;
      int posk = Xor128() % box;
      while (tmppos[posi][posj][posk] != -1 && check_time()) {
        posi = Xor128() % box;
        posj = Xor128() % box;
        posk = Xor128() % box;
      }
      int mx_score = -1;
      int nx_id = 0;
      if (!check_time()) break;
      rep(l, sz) {
        int kouho_id = v[l].id;
        if (used_b[kouho_id]) continue;
        int nx_score = 0;
        rep(ii, 3) {
          rep(jj, 3) {
            rep(kk, 3) {
              if (ii == 0 && jj == 0 && kk == 0) continue;
              int nx = posk + dx3[kk];
              int ny = posj + dy3[jj];
              int nz = posi + dz3[ii];
              if (nx < 0 || ny < 0 || nz < 0) continue;
              if (nx >= box || ny >= box || nz >= box) continue;
              if (tmppos[nz][ny][nx] == -1) continue;
              int b_id = tmppos[nz][ny][nx];
              if (kouho_id > b_id) {
                nx_score += total_bonus[b_id][kouho_id];
              }
              else {
                nx_score += total_bonus[kouho_id][b_id];
              }
            }
          }
        }
        if (mx_score < nx_score) {
          mx_score = nx_score;
          nx_id = kouho_id;
        }
      }
      tmppos[posi][posj][posk] = nx_id;
      used_b[nx_id] = true;
      bool ok = true;
      rep(i, box)rep(j, box)rep(k, box) {
        if (tmppos[i][j][k] == -1) ok = false;
      }
      if (ok) break;
    }
    vector<tuple<int, int, int>> kouho(N);
    rep(i, N) kouho[i] = make_tuple(-1, -1, -1);
    rep(i, box)rep(j, box)rep(k, box) {
      int b_id = tmppos[i][j][k];
      int x = k * dl + dl / 2;
      int y = j * dl + dl / 2;
      int z = i * dl + dl / 2;
      //cerr << "x : " << x << " y : " << y << " z : " << z << endl;
      kouho[b_id] = make_tuple(x, y, z);
    }
    int tmp_score = calc_score(kouho, used_b);
    assert(is_valid(kouho));
    cerr << "tmp_score : " << tmp_score << endl;
    if (bestscore < tmp_score) {
      pos = tmppos;
      bestscore = tmp_score;
      used = used_b;
      ans = kouho;
    }
  }
  while (check_time1()) {
    int i1 = Xor128() % box;
    int j1 = Xor128() % box;
    int z1 = Xor128() % box;
    int i2 = Xor128() % box;
    int j2 = Xor128() % box;
    int z2 = Xor128() % box;
    int id1 = pos[i1][j1][z2];
    int id2 = pos[i2][j2][z2];
    vector<tuple<int, int, int>> kouho = ans;
    swap(kouho[id1], kouho[id2]);
    int tmp_score = calc_score(kouho, used);
    assert(is_valid(kouho));
    cerr << "tmp_score : " << tmp_score << endl;
    if (bestscore < tmp_score) {
      bestscore = tmp_score;
      ans = kouho;
    }
  }
  assert(is_valid(ans));
  cerr << "bestscore : " << bestscore << endl;
  //out();
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> L >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> R[i] >> P[i];
    Ball.push_back(BALL{i, R[i]});
  }
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    A[i]--; B[i]--;
    bonus[A[i]][B[i]].push_back({C[i], D[i]});
    total_bonus[A[i]][B[i]] += D[i];
  }
  rep(i, N)rep2(j, i + 1, N) {
    total_bonus[i][j] += P[i] + P[j];
  }
  rep(i, M) {
    pairb.push_back(pair_ball{A[i], B[i], R[A[i]], R[B[i]], P[A[i]], P[B[i]], total_bonus[A[i]][B[i]]});
    nx_pb[A[i]].push_back(pair_ball{A[i], B[i], R[A[i]], R[B[i]], P[A[i]], P[B[i]], total_bonus[A[i]][B[i]]});
    nx_pb[B[i]].push_back(pair_ball{A[i], B[i], R[A[i]], R[B[i]], P[A[i]], P[B[i]], total_bonus[A[i]][B[i]]});
  }
  /*
  rep(i, N) {
    cerr << i << endl;
    rep(j, nx_pb.size()) {
      int p = nx_pb[i].a;
      if (p == i) p = nx_pb[i].b;
      cerr << "p : " << p << " bonus : " << nx_pb[i][j].total_bonus << endl;
    }
  }
  */

  rep(i, N) ans[i] = make_tuple(-1, -1, -1);
  /*
  //int bestPair = 0;
  long long bestPoint = 0;
  vector<int> point;
  for (int i = 0; i < M; i++)
  {
    long long pt = P[A[i]] + P[B[i]] + C[i];
    point.push_back(pt);
    if (pt > bestPoint) {
      //bestPair = i;
      bestPoint = pt;
    }
  }
  sort(rall(point));
  for (int i = 0; i<M; i++) {
    cerr << point[i] << endl;
  }
  */
  //solve1();
  solve2();
}
