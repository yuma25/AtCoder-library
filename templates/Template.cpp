#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 競技プログラミング用テンプレート (最強チートシート版)
 * 
 * 頻出の型、マクロ、関数、入出力高速化、デバッグ用ツールを網羅。
 * C++20 推奨。
 */

// --- 型エイリアス ---
using ll = long long;         // 64bit整数 (例: ll a = 1e12;)
using ull = unsigned long long;
using ld = long double;       // 高精度浮動小数点
using vi = vector<int>;       // 1次元配列 (例: vi v(n);)
using vl = vector<ll>;
using vvi = vector<vi>;       // 2次元配列 (例: vvi g(n, vi(m));)
using vvl = vector<vl>;
using pii = pair<int, int>;   // 2つの値の組 (例: pii p = {1, 2};)
using pll = pair<ll, ll>;
using vpii = vector<pii>;     // pairの配列
using vpll = vector<pll>;

// --- 定数 ---
const ll INF = 1e18;
const int INF_INT = 1e9;
const int MOD = 998244353; // AtCoderで主流のMOD
const int MOD_OLD = 1e9 + 7;
const double PI = acos(-1);

/* 
 * 方向配列: グリッド探索などで隣接マスを走査する際に使用
 * 4方向: for(int i=0; i<4; i++) { int nx = x + dx[i], ny = y + dy[i]; }
 * 8方向: for(int i=0; i<8; i++) { ... }
 */
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}; // 右, 下, 左, 上, 右下, 右上, 左下, 左上
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

// --- 便利マクロ ---
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)        // 0からn-1まで (例: rep(i, n) cin >> v[i];)
#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i) // sからn-1まで
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; --i)   // n-1から0まで逆順
#define all(v) (v).begin(), (v).end()                        // 全範囲 (例: sort(all(v));)
#define rall(v) (v).rbegin(), (v).rend()                     // 逆順全範囲
#define pb push_back                                         // 末尾追加 (例: v.pb(x);)
#define eb emplace_back                                      // 高速末尾追加
#define fi first                                             // pairの第1要素
#define se second                                            // pairの第2要素

// --- 入出力高速化 ---
struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(15);
    }
} fast_io;

// --- 便利関数 ---
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

// --- デバッグ用出力 (LOCALマクロが有効な場合のみ) ---
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << endl
#else
#define debug(x)
#endif

// --- 数学・アルゴリズム集 ---
ll pow_mod(ll a, ll n, ll m = MOD) {
    ll res = 1;
    a %= m;
    while (n > 0) {
        if (n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

ll inv_mod(ll a, ll m = MOD) {
    return pow_mod(a, m - 2, m);
}

// 組合せ (nCr) 計算用クラス
struct Combination {
    vl fact, inv;
    Combination(int n) : fact(n + 1), inv(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
        inv[n] = inv_mod(fact[n]);
        for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
    ll nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
    }
};

// --- メイン処理 ---
int main() {
    
    
    return 0;
}

/*
==============================================================================
  【標準ライブラリ メンバ関数・操作 完全チートシート】
==============================================================================

[1] vector / deque / string (シーケンス系)
------------------------------------------------------------------------------
 [共通: 基本操作]
  .size()        : O(1) 要素数 (戻り値は size_t なので引き算時のアンダーフロー注意)
  .empty()       : O(1) 空ならtrue
  .clear()       : O(N) 全消去 (capacityは減らない)
  .resize(n, x)  : O(N) サイズ変更 (増えた分は x で埋める)
  .assign(n, x)  : O(N) サイズ n, 値 x で初期化
  .push_back(x)  : O(1)※ 末尾に追加 (※平均)
  .pop_back()    : O(1) 末尾を削除
  .front() / .back() : 先頭/末尾の参照
  v[i] / v.at(i) : i番目へのアクセス (.atは範囲外チェックあり)

 [共通: イテレータ系]
  v.begin() / v.end()   : 先頭 / 末尾の次 を指すイテレータ
  v.rbegin() / v.rend() : 末尾 / 先頭の前 を指す逆順イテレータ
  v.erase(it)           : O(N) 指定位置の要素を削除
  v.insert(it, x)       : O(N) 指定位置に要素を挿入

 [deque 特有]
  .push_front(x) : O(1) 先頭に追加
  .pop_front()   : O(1) 先頭を削除

 [string 特有]
  .substr(pos, len) : O(len) 部分文字列の抽出
  stoi(s) / to_string(x) : 数値変換

[2] set / multiset / map (連想コンテナ)
------------------------------------------------------------------------------
 [共通: 基本操作]
  .insert(x)     : O(log N) 追加
  .erase(x)      : O(log N) 値 x を削除 (※multisetでは一致する "全て" が消えるので注意！)
  .erase(it)     : O(1)     イテレータ指定で削除

 [共通: 検索系]
  .contains(x)   : O(log N) 【C++20〜】存在判定 (true/falseを返す。countより直感的)
  .count(x)      : O(log N) 存在判定 (1 or 0, multisetは個数。C++17以前の主流)
  .find(x)       : O(log N) イテレータ取得 (なし: .end())
  .lower_bound(x): O(log N) x "以上" の最初の要素へのイテレータ
  .upper_bound(x): O(log N) x "より大きい" 最初の要素へのイテレータ

 [イテレータ操作・値の取得]
  *st.begin()    : O(1) 最小値
  *st.rbegin()   : O(1) 最大値
  prev(it)       : O(1) 1つ前（小さい方）のイテレータを取得 (※itがbegin()でない時のみ有効)
  next(it)       : O(1) 1つ次（大きい方）のイテレータを取得

 [multiset 特有の実踐テクニック] ★鉄則
  // 値xを "1つだけ" 消したい場合の定石
  if (auto it = st.find(x); it != st.end()) st.erase(it);

 [mapのみ]
  mp[key]        : O(log N) アクセス (※なければ自動生成・0や空文字が入る。バグの温床に注意)
  mp.at(key)     : O(log N) アクセス (※なければ例外送出・安全)
  for(auto [k,v]:mp): O(N)  C++17 構造化束縛での全要素ループ

  💡 実戦テクニック: 降順（キーが大きい順）に並ぶ map/set を作る
  map<int, string, greater<int>> mp; // キーの大きい順に格納される
  set<int, greater<int>> st;         // 値の大きい順に格納される

 [💡 発展: unordered_set / unordered_map] ★汎用性とリスク
  ・内部でハッシュテーブルを使用。自動ソートされない（順番はバラバラ）。
  ・各操作が「平均 O(1)」と爆速だが、最悪 O(N) になる。
  ・競技プログラミングでは「意図的にハッシュ衝突を起こす入力」でTLE（時間切れ）
   にされるリスクがあるため、速度が厳しくない限り通常の set/map が推奨される。

[3] stack / queue / priority_queue (コンテナアダプタ)
------------------------------------------------------------------------------
 [共通の注意点] ★鉄則
  ※これらには .clear() が存在しません。空にしたい場合は
   「q = queue<int>();」のように空のオブジェクトを再代入するのが定石です。

  .empty()       : O(1) 空判定
  .size()        : O(1) 要素数

 [stack (LIFO) / queue (FIFO)]
  .push(x)       : O(1) 追加
  .emplace(args) : O(1) 追加 (高速版)
  .pop()         : O(1) 削除 (戻り値はvoidなので、値を使う場合は先に取得する)
  .top()         : O(1) 一番上の値を取得 [stackのみ]
  .front()       : O(1) 先頭の値を取得   [queueのみ]
  .back()        : O(1) 末尾の値を取得   [queueのみ]

 [priority_queue (優先度付きキュー / ヒープ)]
  .push(x)       : O(log N) 追加 (内部でツリーを再構築するため O(1) ではない)
  .emplace(args) : O(log N) 追加 (高速版)
  .pop()         : O(log N) 最大値（または最小値）を削除
  .top()         : O(1) 最大値（または最小値）を参照
  
  💡 実戦テクニック: 最小値から取り出す（昇順）キューを作る呪文
  priority_queue<int, vector<int>, greater<int>> pq;
  // 構造体などで使う場合: std::greater<型名> ※比較演算子 > のオーバーロードが必要
  
  💡 比較関数の指定 (sort, priority_queue)
  - sort(all(v), greater<int>()) : 降順ソート
  - priority_queue<T, vector<T>, greater<T>> : 昇順 (最小値が top)
  - priority_queue<T, vector<T>, less<T>>    : 降順 (最大値が top) ※デフォルト
  - 構造体で比較: bool operator>(const T& a, const T& b) { return a.val > b.val; } // greater用

[4] bitset (ビット集合・高速化)
------------------------------------------------------------------------------
 [初期化のバリエーション]
  bitset<N> b          : すべて0で初期化 (※Nは定数である必要あり。変数Nは不可)
  bitset<N> b(数値)    : 整数から下位ビットを初期化
  bitset<N> b("1010")  : "0" と "1" の文字列から初期化 (右端が0ビット目になる)

 [ビット操作]
  .set(i)        : iビット目を1にする (引数なしで 全ビットを1にする)
  .reset(i)      : iビット目を0にする (引数なしで 全ビットを0にする)
  .flip(i)       : iビット目を反転    (引数なしで 全ビットを反転)

 [状態判定]
  .test(i)       : iビット目が1か判定 (b[i]と同じだが範囲外アクセス時に例外で安全)
  .all()         : 全て1ならtrue (C++11)
  .any()         : 1つでも1があればtrue
  .none()        : 全て0ならtrue
  .count()       : 1の個数 (popcount)

 [変換・演算]
  .to_ullong()   : unsigned long long 型数値へ変換
  .to_string()   : "0101..." 文字列へ変換
  (演算子)       : &, |, ^, ~, <<, >> がそのまま使える
  💡 メリット    : ループで1つずつ判定する処理が、ビット演算により
                   定数倍で約 64倍 高速化される (O(N / 64) のようなイメージ)


[5] pair / tuple (組)
------------------------------------------------------------------------------
  .first / .second : pairの要素アクセス
  get<N>(t)        : tupleのN番目にアクセス
  auto [a, b] = p  : C++17 構造化束縛 (分解代入)
  tie(a, b) = p    : 構造化束縛前の古い書き方(古い環境や特定用途で現役)
  (比較演算子)     : pair/tupleは辞書順比較が定義済み (ソート時に便利)

[6] iterator操作 (非メンバ関数)
------------------------------------------------------------------------------
  distance(it1, it2) : it1からit2までの距離を返す
  advance(it, n)     : itをn個進める (※set/map等はO(n), vector等はO(1))
  prev(it)           : 1つ前のイテレータ (※it != begin であること)
  next(it)           : 1つ後のイテレータ
  rbegin() / rend()  : 逆順ループ用イテレータ (例: for(auto it = v.rbegin(); it != v.rend(); ++it))

[7] algorithm / numeric (標準アルゴリズム)
------------------------------------------------------------------------------
  sort(all(v))           : O(N log N) 昇順ソート
  reverse(all(v))        : O(N) 反転
  unique(all(v))         : 重複削除(ソート後に使用)。末尾イテレータを返す
  lower_bound(all(v), x) : x以上の最初の要素のイテレータ
  upper_bound(all(v), x) : xより大きい最初の要素のイテレータ
  count(all(v), x)       : O(N) 値がxである要素の個数
  next_permutation(all(v)): 次の順列を生成(あればtrue)。do { ... } while (next_permutation(all(v))) で全順列を列挙可能（※要ソート）
  min_element(all(v))    : 最小値を指すイテレータ
  max_element(all(v))    : 最大値を指すイテレータ
  minmax(a, b)           : {最小, 最大}のpairを返す
  clamp(v, lo, hi)       : vを[lo, hi]の範囲に収める (C++17)
  iota(all(v), x)        : x, x+1, x+2... のように連番で埋める
  accumulate(all(v), 0LL): 合計値 (初期値 0LL を指定してオーバーフロー防止)
  partial_sum(all(v), ...) : 累積和を計算して別コンテナに出力
  is_sorted(all(v))      : ソートされているか判定
  shuffle(all(v), engine): O(N) ランダムシャッフル (要: <random>ヘッダ)
  gcd(a, b) / lcm(a, b)  : 最大公約数 / 最小公倍数 (C++17以上)

[8] テンプレート独自の便利機能・数学ライブラリ
------------------------------------------------------------------------------
 💡 便利関数 (値の更新)
  chmax(a, b)    : a < b なら a = b とし true を返す。例: chmax(ans, x);
  chmin(a, b)    : a > b なら a = b とし true を返す。例: chmin(ans, x);

 💡 デバッグ
  debug(x)       : 変数名と値を表示。例: debug(ans); (※-DLOCAL環境のみ有効)

 💡 数学・アルゴリズム
  pow_mod(a, n)  : a の n 乗を MOD で割った余りを計算 (O(log n))
  inv_mod(a)     : a の MOD における逆元 (割り算の代わり) を計算
  Combination c(N): nCr を O(1) で求めるクラス。例: Combination comb(100005); comb.nCr(n, r);

==============================================================================

【標準ライブラリ 活用ガイド (正式表記版)】
「降順」「昇順」という表現を統一し、マクロを使わずに標準ライブラリの正式な表記だけで解説します。

1. 各コンテナ単体での入出力
------------------------------------------------------------------------------
① 配列・シーケンス系 (vector, deque, string)
  // vector
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  for (int i = 0; i < n; ++i) cout << v[i] << (i == n - 1 ? "" : " ");

② 平衡二分探索木系 (set, map, multiset)
  // set (自動で昇順ソート)
  set<int> st;
  for (int i = 0; i < n; ++i) { int x; cin >> x; st.insert(x); }
  for (int x : st) cout << x << " ";

  // map (キーが辞書順の昇順でソート)
  map<string, int> mp;
  for (int i = 0; i < n; ++i) { string s; int x; cin >> s >> x; mp[s] = x; }
  for (const auto& [key, value] : mp) cout << key << ":" << value << "\n";

③ 特殊なコンテナ (stack, queue, priority_queue)
  // priority_queue (デフォルトは降順)
  priority_queue<int> pq;
  while (!pq.empty()) { cout << pq.top() << " "; pq.pop(); }

④ ビット・組・イテレータ操作
  bitset<8> b; cin >> b;
  pair<int, int> p; cin >> p.first >> p.second;
  tuple<int, int, int> t; cin >> get<0>(t) >> get<1>(t) >> get<2>(t);
  advance(it, 2); // イテレータを2進める

2. 定番の組み合わせパターン
------------------------------------------------------------------------------
パターンA：グラフ表現の隣接リスト (vector<vector<int>>)
  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v;
      graph[u].push_back(v); graph[v].push_back(u); // 無向グラフ
  }

パターンB：複数属性のソート (vector<pair<int, int>>)
  vector<pair<int, int>> points(n);
  sort(points.begin(), points.end()); // firstの昇順 -> secondの昇順

パターンC：属性ごとのデータ集計 (map<string, vector<int>>)
  map<string, vector<int>> database;
  database[name].push_back(score);

パターンD：ダイクストラ法で用いる昇順キュー
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  // コスト(first)が小さい順（昇順）に取り出せる

==============================================================================
*/
