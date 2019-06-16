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

unsigned long seed128[4]; //x,y,z,wとして利用
void seed(unsigned int s){
    for(int i=1; i<=4; i++){
        seed128[i-1] = s = 1812433253U * (s^(s>>30)) + i;
    }
}

unsigned long Xor128(){
  unsigned long t;
  t=(seed128[0]^(seed128[0]<<11));
  seed128[0]=seed128[1];
  seed128[1]=seed128[2];
  seed128[2]=seed128[3];
  return seed128[3]=(seed128[3]^(seed128[3]>>19))^(t^(t>>8));
}

auto start = chrono::system_clock::now();

inline bool check_time() {
    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
    if (msec >= 2500) return false;
    return true;
}

int money = 1000;
int t, n, m;//turn数, スキル数, 依頼数
int st[30000], ed[30000], reward[30000];
int need_skill[30000][10];
int SkillLevel[10];
int trcnt[10];
//bool used[300000];
//int sum_skq[30000];
int sum_sknow = 0;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> ans(1000 + 5);
int max_money = 0;
bool ok[30000 + 5], used[30000 + 5];
vector<pii> order;

void train(int i) {
  trcnt[i]++;
  int cost = 10000 * (1<<(SkillLevel[i]+1));
  if (money < cost) return;
  money -= cost;
  if (trcnt[i] == SkillLevel[i] + 1) {
    trcnt[i] = 0;
    SkillLevel[i]++;
  }
}

void kill(int turn, int i) {
  double AddMoney = reward[i];
  AddMoney *= (1 + 9 * (double)(turn - st[i]) / (ed[i] - st[i]));
  int SkillLack = 0;
  for (int j = 0; j < n; j++) SkillLack += max(0LL, need_skill[i][j] - SkillLevel[j]);

  if (SkillLack == 0) AddMoney *= 10;
  else {
      AddMoney *= pow(0.5, SkillLack);
      AddMoney += 1e-9;
  }
  money += (long long)AddMoney;
}

void work() {
  money += 1000;
}

void output() {
  rep2(i, 1, t + 1) {
    if (ans[i].fi == 1) cout << 1 << " " << ans[i].se + 1 << endl;
    else if (ans[i].fi == 2) cout << 2 << " " << ans[i].se + 1 << endl;
    else cout << 3 << endl;
  }
}

void init() {
  money = 1000;
  rep(i, 10) {
    SkillLevel[i] = 0;
    trcnt[i] = 0;
  }
}

long long get_money(int turn, int i) {
  double AddMoney = reward[i];
  AddMoney *= (1 + 9 * (double)(turn - st[i]) / (ed[i] - st[i]));
  int SkillLack = 0;
  for (int j = 0; j < n; j++) SkillLack += max(0LL, need_skill[i][j] - SkillLevel[j]);

  if (SkillLack == 0) AddMoney *= 10;
  else {
      AddMoney *= pow(0.5, SkillLack);
      AddMoney += 1e-9;
  }
  //money += (long long)AddMoney;
  return (long long) AddMoney;
}


void solve4() {
  int seednum = 1;
  while (check_time()) {
    seed(seednum);
    seednum++;
    int turn = 0;
    vector<pii> tmp_ans(t + 1);
    init();
    rep(i, m) {
      ok[i] = false;
      used[i] = false;
    }
    while(turn < t) {
      //cout << turn << " : " << money << endl;
      turn++;
      rep(i, m) {
        if (st[i] <= turn && turn <= ed[i]) ok[i] = true;
        else ok[i] = false;
      }
      bool allok = true;
      rep(i, n) {
        if (SkillLevel[i] < 10) allok = false;
      }
      if (allok) {
        int idx = -1;
        int mx = 0;
        rep(i, m) {
          if (!used[i] && ok[i] && turn == ed[i]) {
            int tmp = get_money(turn, i);
            if (mx < tmp) {
              mx = tmp;
              idx = i;
            }
          }
        }
        if (idx == -1 || mx < 1000) {
          work();
          tmp_ans[turn] = {3, 3};
        }
        else {
          used[idx] = true;
          kill(turn, idx);
          tmp_ans[turn] = {2, idx};
        }
      }
      else {
        int skidx = Xor128() % 10;
        while (SkillLevel[skidx] == 10) skidx = Xor128() % 10;
        //int skidx = mxlv[0];
        int pre = SkillLevel[skidx];
        int cost = 10000 * (1<<(SkillLevel[skidx]+1));
        int mx = 0;
        int idx = -1;
        if (cost <= money) {
          train(skidx);
          tmp_ans[turn] = {1, skidx};
        }
        else {
          rep(i, m) {
            if (used[i]) continue;
            if (ok[i]) {
              int tmp = get_money(turn, i);
              if (mx < tmp) {
                mx = tmp;
                idx = i;
              }
            }
          }
          if (idx == -1 || mx < 1000) {
            work();
            tmp_ans[turn] = {3, 3};
          }
          else {
            used[idx] = true;
            kill(turn, idx);
            tmp_ans[turn] = {2, idx};
          }
        }
      }
      //cout << turn << " : " << money << endl;
    }
    if (max_money < money) {
      max_money = money;
      ans = tmp_ans;
    }
    cout << money << endl;
  }
  //output();
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> t >> n >> m;
  //vector<int> sum(10);
  rep(i, m) {
    cin >> st[i] >> ed[i] >> reward[i];
    rep(j, n) {
      cin >> need_skill[i][j];
      //sum_skq[i]++;
    }
    //pq.push({ed[i], i});
  }
  //rep(i, n) order.push_back({sum[i], i});
  //sort(rall(order));
  //rep(i, n) cout << i << " : " << sum[i] << endl;
  //solve();
  //solve2();
  //solve3();
  seed(4);
  solve4();
}
