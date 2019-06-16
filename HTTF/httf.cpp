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
//#define int long long
 
typedef long long ll;
typedef unsigned long long ull;
//typedef unsigned __int128 HASH;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pullull;
typedef pair<ll,int> plli;
typedef pair<double, int> pdbi;
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
const double EPS = 1e-12;
const ll mod = 1000000000 + 7;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;
 
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

const int n = 50;
vector<vector<char>> g(n, vector<char> (n));
vector<vector<int>> T_num(n, vector<int>(n));
vector<pii> gate;
bool gate_find = true;
int turn = 0;
int money = 100;
int power = 100;

random_device rnd;
mt19937 mt(rnd());
uniform_int_distribution<int> rd(3, 45), rd2(1, 100), rd3(0, 6);

void update() {
    rep(i, n)rep(j, n) {
        if (g[i][j] == '#' || g[i][j] == 'W') continue;
        if (g[i][j] == 'T') {
            T_num[i][j]++;
        }
        else {
            rep(k, 4) {
                int ny = i + dy4[k];
                int nx = j + dx4[k];
                if (!inside(ny, nx, n, n)) continue;
                if (g[ny][nx] == 'T') {
                    T_num[i][j]++;
                    g[i][j] = 'T';
                    break;
                }
            }
        }
        if (T_num[i][j] > 100) {
                T_num[i][j] = 0;
                g[i][j] = '#';
            }
    }
    turn++;
}


struct edge{int to, cost;};

vector<int> dijkstra(int s, vector<vector<edge>>& eg, vector<int>& d){
    priority_queue<pii, vector<pii>, greater<pii>> pque;
    pque.push(plli(0, s));
    d[s] = 0;

    while (!pque.empty()){
        pii p = pque.top(); pque.pop();
        int fr = p.second;
        if (d[fr] < p.first) continue;
        for (edge e: eg[fr]){
            if (d[e.to] > d[fr] + e.cost){
                d[e.to] = d[fr] + e.cost;
                pque.push({d[e.to], e.to});
            }
        }
    }
    return d;

}
void road(int X1, int Y1, int X2, int Y2) {
    X1++;Y1++;X2++;Y2++;
    cout << "road" << " " << X1 << " " << Y1 << " " << X2 << " " << Y2 << endl;
    update();
    //turn++;
    if (turn == 1000) exit(0);
}

void harvest(int X1, int Y1, int X2, int Y2) {
    vector<vector<edge>> eg(n * n);
    rep(i, n)rep(j, n) {
        int tmpcost = 0;
        if (g[i][j] == '#') tmpcost = 50;
        else if (g[i][j] == 'R') tmpcost = 1;
        else tmpcost = 10;
        rep(k, 4) {
            int ny = i + dy4[k];
            int nx = j + dx4[k];
            if (!inside(ny, nx, n, n)) continue;
            eg[ny * n + nx % n].push_back({i * n + j % n, tmpcost});
        }
    }
    vector<int> d(n * n, INF);
    rep(i, gate.size()) {
        int y = gate[i].fi;
        int x = gate[i].se;
        dijkstra(y * n + x % n, eg, d);
    }
    int pre_power = power;
    rep2(i, Y1, Y2 + 1)rep2(j, X1, X2 + 1) {
        if (power - d[i * n + j % n] + 10 < 0) continue;
        if (g[i][j] == '#' || g[i][j] == '.' || g[i][j] == 'W') continue;
        power -= d[i * n + j % n];
        money += T_num[i][j];
        T_num[i][j] = 0;
        g[i][j] = '.';
    }
    power = pre_power;
    X1++;Y1++;X2++;Y2++;
    cout << "harvest" << " " << X1 << " " << Y1 << " " << X2 << " " << Y2 << endl;
    update();
    //turn++;
    if (turn == 1000) exit(0);
}

void destroy(int X1, int Y1, int X2, int Y2) {
    vector<vector<edge>> eg(n * n);
    rep(i, n)rep(j, n) {
        int tmpcost = 0;
        if (g[i][j] == '#') tmpcost = 50;
        else if (g[i][j] == 'R') tmpcost = 1;
        else tmpcost = 10;
        rep(k, 4) {
            int ny = i + dy4[k];
            int nx = j + dx4[k];
            if (!inside(ny, nx, n, n)) continue;
            eg[ny * n + nx % n].push_back({i * n + j % n, tmpcost});
        }
    }
    vector<int> d(n * n, INF);
    rep(i, gate.size()) {
        int y = gate[i].fi;
        int x = gate[i].se;
        dijkstra(y * n + x % n, eg, d);
    }
    rep2(i, Y1, Y2 + 1)rep2(j, X1, X2 + 1) {
        if (g[i][j] == '.' || g[i][j] == 'W') continue;
        if (d[i * n + j % n] - money < 0) continue;
        money -= d[i * n + j % n];
        g[i][j] = '.';
        T_num [i][j] = 0;
    }
    X1++;Y1++;X2++;Y2++;
    cout << "destroy" << " " << X1 << " " << Y1 << " " << X2 << " " << Y2 << endl;
    update();
    //turn++;
    if (turn == 1000) exit(0);
}

void plant(int X, int Y) {
    T_num[Y][X]++;
    g[Y][X] = 'T';
    X++;Y++;
    cout << "plant" << " " << X << " " << Y << endl;
    update();
    //turn++;
    if (turn == 1000) exit(0);
}

void warpgate(int X, int Y) {
    money -= 1000;
    g[Y][X] = 'W';
    T_num[Y][X] = 0;
    X++;Y++;
    cout << "warpgate" << " " << X << " " << Y << endl;
    update();
    //turn++;
    if (turn == 1000) exit(0);
}

void growup(int A) {
    cout << "growup" << " " << A << endl;
    update();
    //turn++;
    if (turn == 1000) exit(0);
}

void work() {
    money++;
    cout << "work" << endl;
    update();
    //turn++;
    if (turn == 1000) exit(0);
}

bool check[n][n] = {};

void action() {
    sort(all(gate));
    if (turn <= 80) {
        rep(i, gate.size()) {
            int y = gate[i].fi;
            int x = gate[i].se;
            destroy(max(0, x - 1), max(0, y - 1), min(n - 1, x + 1), min(n - 1, y + 1));
            rep(j, 8) {
                int ny = y + dy8[j];
                int nx = x + dx8[j];
                if (!inside(ny, nx, n, n) || g[ny][nx] == '#' || g[ny][nx] == 'W') continue;
                plant(nx, ny);
                /*
                g[ny][nx] = 'T';
                state[ny][nx]++;
                update();
                */
            }
        }
    }
    else {
        if (gate.size() <= 4) {
            rep(i, gate.size()) {
                int y = gate[i].fi;
                int x = gate[i].se;
                //destroy(max(0, x - 2), max(0, y - 2), min(n - 1, x + 2), min(n - 1, y + 2));

                rep(j, 4) {
                    int ny = y + dy4[j];
                    int nx = x + dx4[j];
                    if (!inside(ny, nx, n, n) || g[ny][nx] == '#' || g[ny][nx] == 'W') continue;
                    plant(nx, ny);
                }
            }
        }
        else {
            rep(_, 4) {
                int i = rd3(mt);
                int y = gate[i].fi;
                int x = gate[i].se;
                //destroy(max(0, x - 2), max(0, y - 2), min(n - 1, x + 2), min(n - 1, y + 2));

                rep(j, 4) {
                    int ny = y + dy4[j];
                    int nx = x + dx4[j];
                    if (!inside(ny, nx, n, n) || g[ny][nx] == '#' || g[ny][nx] == 'W') continue;
                    plant(nx, ny);
                }
            }
        }
    }
    //road(x, max(0, y - 5) , x, min(n - 1, y + 5));
    if (turn <= 80) rep(i, 80) work();
    /*
    rep(i, 70) {
        work();
        if (turn <= 200 && gate_find && money >= 1000) {
            bool gate_exist = false;
            int cnt = 0;
            while (!gate_exist && cnt < 2500) {
                cnt++;
                int newy = rd(mt);
                int newx = rd(mt);
                if (g[newy][newx] != '#' && g[newy][newx] != 'W') {
                    warpgate(newx, newy);
                    gate.push_back({newy, newx});
                    gate_exist = true;
                    break;
                }
            }
            gate_find = gate_exist;
        }
    }
    */
    if (turn <= 200) {
        rep(i, gate.size()) {
            int y = gate[i].fi;
            int x = gate[i].se;
            harvest(max(0, x - 2), max(0, y - 2), min(n - 1, x), min(n - 1, y));
            harvest(max(0, x), max(0, y - 2), min(n - 1, x + 2), min(n - 1, y));
            harvest(max(0, x - 2), max(0, y), min(n - 1, x), min(n - 1, y + 2));
            harvest(max(0, x), max(0, y), min(n - 1, x + 2), min(n - 1, y + 2));
        }
    }
    else {
        rep(i, gate.size()) {
            int y = gate[i].fi;
            int x = gate[i].se;
            int dd = min(5, turn / 100);
            harvest(max(0, x - dd), max(0, y - dd), min(n - 1, x), min(n - 1, y));
            harvest(max(0, x), max(0, y - dd), min(n - 1, x + dd), min(n - 1, y));
            harvest(max(0, x - dd), max(0, y), min(n - 1, x), min(n - 1, y + dd));
            harvest(max(0, x), max(0, y), min(n - 1, x + dd), min(n - 1, y + dd));
        }
    }
        /*
        if (turn <= 200) {
            harvest(max(0, x - 2), max(0, y - 2), min(n - 1, x), min(n - 1, y));
            harvest(max(0, x), max(0, y - 2), min(n - 1, x + 2), min(n - 1, y));
            harvest(max(0, x - 2), max(0, y), min(n - 1, x), min(n - 1, y + 2));
            harvest(max(0, x), max(0, y), min(n - 1, x + 2), min(n - 1, y + 2));
        }
        else harvest(max(0, x - 1), max(0, y - 1), min(n - 1, x + 1), min(n - 1, y + 1));
        */
    if (gate.size() >= 5) {
        rep(i, gate.size()) {
            int y = gate[i].fi;
            int x = gate[i].se;
            int num = rd2(mt);
            int dd = min(4, turn / 100);
            if (num <= 10) {
                destroy(max(0, x - dd), max(0, y - dd), min(n - 1, x + dd), min(n - 1, y + dd));
            }
        }
    }
    //cout << "money" << money << endl;
    if (gate_find && money >= 1000 && gate.size() <= 6) {
        bool gate_exist = false;
        while (money >= 1000) {
            //cout << "turn:" << turn << " " << y << " " << x << endl; 
            /*
            rep(i, gate.size()) {
                int nowy = gate[i].fi;
                int nowx = gate[i].se;
                rep(j, 4) {
                    int y = nowy + dy4[j];
                    int x = nowx + dx4[j];
                    if (!inside(y, x, n, n) || g[y][x] == '#' || g[y][x] == 'W') continue;
                    warpgate(x, y);
                    gate.push_back({y, x});
                    gate_exist = true;
                    //harvest(max(0, x - 1), max(0, y - 1), min(n - 1, x + 1), min(n - 1, y + 1));
                    harvest(max(0, x - 2), max(0, y - 2), min(n - 1, x), min(n - 1, y));
                    harvest(max(0, x), max(0, y - 2), min(n - 1, x + 2), min(n - 1, y));
                    harvest(max(0, x - 2), max(0, y), min(n - 1, x), min(n - 1, y + 2));
                    harvest(max(0, x), max(0, y), min(n - 1, x + 2), min(n - 1, y + 2));
                    break;
                }
                if (money < 1000) break;
                */
            int y = rd(mt);
            int x = rd(mt);
            if (g[y][x] == '#' || g[y][x] == 'W') continue; 
            warpgate(x, y);
            gate.push_back({y, x});
            gate_exist = true;
            //harvest(max(0, x - 1), max(0, y - 1), min(n - 1, x + 1), min(n - 1, y + 1));
            harvest(max(0, x - 2), max(0, y - 2), min(n - 1, x), min(n - 1, y));
            harvest(max(0, x), max(0, y - 2), min(n - 1, x + 2), min(n - 1, y));
            harvest(max(0, x - 2), max(0, y), min(n - 1, x), min(n - 1, y + 2));
            harvest(max(0, x), max(0, y), min(n - 1, x + 2), min(n - 1, y + 2));
            if (gate.size() >= 7) break;
        }
        gate_find = gate_exist;
    }
    
}

void solve() {
    while (turn < 1000) {
        action();
    }
}

signed main() {	
    cin.tie(0);
    ios::sync_with_stdio(false);
    rep(i, n)rep(j, n) {
        cin >> g[i][j];
        if (g[i][j] == 'W') gate.push_back({i, j});
    }
    solve();
}
