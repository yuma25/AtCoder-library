#include <bits/stdc++.h>
using namespace std;

using ll = long long;             // int(20億)を超える整数に使用
using vi = vector<int>;           // 整数の動的配列
using vl = vector<ll>;            // llの動的配列
using vs = vector<string>;        // 文字列のリスト
using vvi = vector<vector<int>>;  // 2次元配列 (int)
using vvl = vector<vector<ll>>;   // 2次元配列 (ll)
using pii = pair<int, int>;       // 座標や(値, 番号)のペア
using pll = pair<ll, ll>;         // llのペア
using map_ii = map<int, int>;     // int -> int の連想配列
using map_si = map<string, int>;  // string -> int の連想配列

const ll INF = 1e18;              // 無限大 (DP初期化用)
const int MOD = 1e9 + 7;          // MOD
const double PI = acos(-1);       // 円周率
const int dx[] = {0, 1, 0, -1};   // 方向: 右, 下, 左, 上
const int dy[] = {1, 0, -1, 0};   // (グリッド探索用)

template<typename T> using MinPQ = priority_queue<T, vector<T>, greater<T>>; // 昇順
template<typename T> using MaxPQ = priority_queue<T, vector<T>, less<T>>;    // 降順
using prijkstra = MinPQ<pii>;     // ダイクストラ用 {コスト, 頂点}

#define rep(i, n)      for(int i = 0; i < (n); ++i)     // rep(i, 10) { ... } -> 0から9までループ
#define reps(i, a, n)  for(int i = (a); i < (n); ++i)   // reps(i, 1, 10) { ... } -> 1から9までループ
#define rrep(i, n)     for(int i = (n)-1; i >= 0; --i)  // rrep(i, 10) { ... } -> 9から0まで逆順ループ
#define fore(x, a)     for(auto& (x) : (a))             // for(auto x : v) { ... } -> 配列の全要素にアクセス
#define all(v)         (v).begin(), (v).end()           // sort(all(v)); -> 配列全体を指す
#define rall(v)        (v).rbegin(), (v).rend()         // sort(rall(v)); -> 配列全体を逆順に指す (降順ソートなど)
#define pb             push_back                        // v.pb(10); -> ベクトルの末尾に追加
#define pob            pop_back                         // v.pob(10); -> vector末尾削除
#define fi             first                            // p.fi, p.se -> ペアの要素アクセス
#define se             second
#define YES            cout << "Yes" << endl
#define NO             cout << "No" << endl
#define SORT(v)        sort(all(v))                             // SORT(v); -> 昇順ソート [1, 5, 3] -> [1, 3, 5]
#define RSORT(v)       sort(rall(v))                            // RSORT(v); -> 降順ソート [1, 5, 3] -> [5, 3, 1]
#define REV(v)         reverse(all(v))                          // REV(v); -> 配列を反転 [1, 2, 3] -> [3, 2, 1]
#define UNI(v)         (v).erase(unique(all(v)), (v).end())     // UNI(v); -> 重複削除 (必ずソート後に使用) [1, 1, 2] -> [1, 2]
#define MIN_IDX(v)     (min_element(all(v)) - (v).begin())      // MIN_IDX(v); -> 最小値のインデックスを取得
#define MAX_IDX(v)     (max_element(all(v)) - (v).begin())      // MAX_IDX(v); -> 最大値のインデックスを取得
#define LB(v, x)       lower_bound(all(v), (x))                 // LB(v, x); -> 二分探索: x「以上」の最初の位置(イテレータ)
#define UB(v, x)       upper_bound(all(v), (x))                 // UB(v, x); -> 二分探索: x「より大きい」最初の位置(イテレータ)
#define COUNT(v, x)    count(all(v), (x))                       // COUNT(v, x); -> 配列内の x の個数を数える
#define OUT(x)         cout << (x) << "\n"                      // OUT(ans); -> 改行付き出力
#define FIXED(n)       cout << fixed << setprecision(n)         // FIXED(10); -> 小数点以下10桁表示にする

template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }     // chmin(ans, new_val); -> もし new_val の方が小さければ ans を更新
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }     // chmax(ans, new_val); -> もし new_val の方が大きければ ans を更新
template<typename T> inline ll SUM(const vector<T>& v) { return accumulate(all(v), 0LL); }          // SUM(v); -> 配列の総和 (long longで返すのでオーバーフローしない)
inline ll gcd(ll a, ll b) { return __gcd(a, b); }                                                   // gcd(12, 18); -> 最大公約数 (6)
inline ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }                                           // lcm(12, 18); -> 最小公倍数 (36)

template<typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (T& x : v) is >> x; return is;
}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << (i == v.size() - 1 ? "" : " ");
    }
    return os;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}


/*
==============================================================================
  【標準ライブラリ メンバ関数・操作 完全チートシート】
==============================================================================

[1] vector / deque / string (シーケンス系)
------------------------------------------------------------------------------
  .size()        : O(1) 要素数 (戻り値は size_t なので unsigned 注意)
  .empty()       : O(1) 空ならtrue
  .clear()       : O(N) 全消去 (capacityは減らない)
  .resize(n, x)  : O(N) サイズ変更 (増えた分は x で埋める)
  .assign(n, x)  : O(N) サイズ n, 値 x で初期化 (上書き)
  .push_back(x)  : O(1) 末尾追加 (コピー発生)
  .emplace_back(): O(1) 末尾追加 (コンストラクタ直接呼出・高速)
  .pop_back()    : O(1) 末尾削除 (void)
  .front()       : O(1) 先頭参照
  .back()        : O(1) 末尾参照
  .at(i)         : O(1) 安全なアクセス (範囲外例外送出)
  [dequeのみ]
  .push_front(x) : O(1) 先頭追加
  .pop_front()   : O(1) 先頭削除
  [stringのみ]
  .substr(pos, len): O(N) 部分文字列 (len省略で末尾まで)
  .find(str)     : O(N) 検索。見つかればindex, なければ string::npos
  .rfind(str)    : O(N) 後ろから検索
  .c_str()       : O(1) C言語形式(char*)への変換 (printf等で使用)
  to_string(num) : 数値 -> string (非メンバ関数)
  stoi(s)/stoll(s): string -> 数値 (非メンバ関数)

[2] set / map / multiset (平衡二分探索木)
------------------------------------------------------------------------------
  .insert(x)     : O(log N) 追加
  .emplace(args) : O(log N) 追加 (高速版)
  .erase(x)      : O(log N) 値 x を全て削除 (multiset注意)
  .erase(it)     : O(1)     イテレータ指定で削除 (multisetで1つ消す用)
  .count(x)      : O(log N) 存在判定 (1 or 0, multisetは個数)
  .find(x)       : O(log N) イテレータ取得 (なし: .end())
  .lower_bound(x): O(log N) x "以上" の最初の要素
  .upper_bound(x): O(log N) x "より大きい" 最初の要素
  [*it アクセス]
  *st.begin()    : 最小値
  *st.rbegin()   : 最大値
  [mapのみ]
  mp[key]        : O(log N) アクセス (なければ自動生成・危険)
  mp.at(key)     : O(log N) アクセス (なければ例外・安全)
  for(auto [k,v]:mp): C++17 構造化束縛でのループ

[3] stack / queue / priority_queue (コンテナアダプタ)
------------------------------------------------------------------------------
  .push(x)       : 追加
  .emplace(args) : 追加 (高速版)
  .pop()         : 削除 (void)
  .empty()       : 空判定
  .size()        : 要素数
  [stack / priority_queue]
  .top()         : O(1) 先頭(最大値)参照
  [queue]
  .front()       : O(1) 先頭参照
  .back()        : O(1) 末尾参照

[4] bitset (ビット集合・高速化)
------------------------------------------------------------------------------
  bitset<N> b    : Nビットのフラグ管理 (Nは定数)
  .set(i)        : iビット目を1にする
  .reset(i)      : iビット目を0にする
  .flip(i)       : iビット目を反転 (引数なしで全反転)
  .test(i)       : iビット目が1か判定 (b[i]と同じだが安全)
  .count()       : 1の個数 (popcount)
  .any()         : 1つでも1があればtrue
  .none()        : 全て0ならtrue
  .to_ullong()   : unsigned long long 型数値へ変換
  .to_string()   : "0101..." 文字列へ変換
  (演算子)       : &, |, ^, ~, <<, >> がそのまま使える

[5] pair / tuple (組)
------------------------------------------------------------------------------
  .first / .second : pairの要素アクセス
  get<N>(t)      : tupleのN番目にアクセス
  auto [a, b] = p: C++17 構造化束縛 (分解)

[6] iterator操作 (非メンバ関数)
------------------------------------------------------------------------------
  distance(it1, it2) : it1からit2までの距離を返す
  advance(it, n)     : itをn個進める (set/mapではO(n)かかるので注意)
  prev(it)           : 1つ前のイテレータ
  next(it)           : 1つ後のイテレータ

==============================================================================
*/