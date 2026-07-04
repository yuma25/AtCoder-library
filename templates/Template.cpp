#include <bits/stdc++.h>
using namespace std;
using namespace std::views;

// --- 型エイリアス ---
using ll = long long;           // 64bit整数 (例: ll a = 1e12;)
using ull = unsigned long long;
using ld = long double;         // 高精度浮動小数点
using vi = vector<int>;         // 1次元配列 (例: vi v(n);)
using vl = vector<ll>;
using vvi = vector<vi>;         // 2次元配列 (例: vvi g(n, vi(m));)
using vvl = vector<vl>;
using pii = pair<int, int>;     // 2つの値の組 (例: pii p = {1, 2};)
using pll = pair<ll, ll>;
using vpii = vector<pii>;       // pairの配列
using vpll = vector<pll>;

// --- 定数 ---
const ll INF = 1e18;
const int INF_INT = 1e9;
const int MOD = 998244353;
const int MOD_OLD = 1e9 + 7;
const double PI = std::numbers::pi;

/* 
 * 方向配列: グリッド探索などで隣接マスを走査する際に使用
 */
const int dx4[] = {0, 1, 0, -1}; // 4方向 (右, 下, 左, 上)
const int dy4[] = {1, 0, -1, 0};
const int dx8[] = {0, 1, 0, -1, 1, 1, -1, -1}; // 8方向 (4方向 + 斜め)
const int dy8[] = {1, 0, -1, 0, 1, -1, 1, -1};

// --- 便利マクロ ---
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)            // 0からn-1まで (例: rep(i, n) cin >> v[i];)
#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i) // sからn-1まで
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; --i)      // n-1から0まで逆順
#define all(v) (v).begin(), (v).end()                           // 全範囲 (例: sort(all(v));)
#define rall(v) (v).rbegin(), (v).rend()                        // 逆順全範囲
#define pb push_back                                            // 末尾追加 (例: v.pb(x);)
#define eb emplace_back                                         // 高速末尾追加
#define fi first                                                // pairの第1要素
#define se second                                               // pairの第2要素

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

// グリッドの範囲内判定 (r: 行, c: 列, h: 高さ, w: 幅)
inline bool in_grid(int r, int c, int h, int w) {
    return 0 <= r && r < h && 0 <= c && c < w;
}


// --- 数学・アルゴリズム集 ---
// 繰り返し二乗法 (負の数 a にも対応)
ll pow_mod(ll a, ll n, ll m = MOD) {
    ll res = 1;
    a = (a % m + m) % m;
    while (n > 0) {
        if (n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

// 逆元 (m が素数の時のみ有効)
ll inv_mod(ll a, ll m = MOD) {
    return pow_mod(a, m - 2, m);
}

// 組合せ (nCr) 計算用クラス (MODをテンプレート引数で受け取ることで書き換えバグを防ぐ)
template<int m = MOD>
struct Combination {
    vl fact, inv;
    Combination(int n) : fact(n + 1), inv(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % m;
        inv[n] = pow_mod(fact[n], m - 2, m); // inv_mod と同等
        for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % m;
    }
    ll nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * inv[r] % m * inv[n - r] % m;
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
  .size()        : O(1) 要素数 (戻り値は size_t なので引き算時のアンダーフロー注意) | 例: int n = (int)v.size();
  ssize(v)       : O(1) 【C++20】符号付きサイズ取得。ssize(v) - 1 も安全 | 例: for(int i=0; i<ssize(v)-1; ++i)
  .empty()       : O(1) 空ならtrue | 例: if (v.empty()) return 0;
  .clear()       : O(N) 全消去 (capacityは減らない) | 例: v.clear();
  .resize(n, x)  : O(N) サイズ変更 (増えた分は x で埋める) | 例: dp.resize(N + 1, -1);
  .assign(n, x)  : O(N) サイズ n, 値 x で初期化 | 例: v.assign(N, 0);
  .push_back(x)  : O(1)※ 末尾に追加 (※平均) | 例: v.push_back(10);
  .pop_back()    : O(1) 末尾を削除 (※空コンテナ注意) | 例: v.pop_back();
  .front() / .back() : 先頭/末尾の参照 (※空コンテナ注意) | 例: int first = v.front(); int last = v.back();
  v[i] / v.at(i) : i番目へのアクセス (.atは範囲外チェックあり) | 例: v[i] = 100;
  v.begin() / v.end()   : 先頭 / 末尾の次 を指すイテレータ | 例: sort(v.begin(), v.end());
  v.rbegin() / v.rend() : 末尾 / 先頭の前 を指す逆順イテレータ | 例: sort(v.rbegin(), v.rend());
  v.erase(it)           : O(N) 指定位置の要素を削除 | 例: v.erase(v.begin() + 3);
  v.insert(it, x)       : O(N) 指定位置に要素を挿入 | 例: v.insert(v.begin() + 1, 99);
  std::erase(v, x)      : O(N) 【C++20〜】値 x をすべて削除 (Erase-Removeの代替) | 例: std::erase(v, 7);
  std::erase_if(v, pred): O(N) 【C++20〜】条件を満たす要素をすべて削除 | 例: std::erase_if(v, [](int x){ return x % 2 == 0; });
  .push_front(x) : O(1) 先頭に追加 [deque 特有] | 例: deq.push_front(5);
  .pop_front()   : O(1) 先頭を削除 [deque 特有] | 例: deq.pop_front();
  .substr(pos, len) : O(len) 部分文字列の抽出 [string 特有] | 例: string sub = s.substr(2, 3);
  stoi(s) / to_string(x) : 数値変換 [string 特有] | 例: int val = stoi("123"); string str = to_string(456);

[2] set / multiset / map (連想コンテナ)
------------------------------------------------------------------------------
  .insert(x)     : O(log N) 追加 | 例: st.insert(5);
  .erase(x)      : O(log N) 値 x を削除 (※multisetでは一致する "全て" が消えるので注意！) | 例: st.erase(5);
  .erase(it)     : O(1)     イテレータ指定で削除 (※multisetで1つだけ消す用の定石) | 例: st.erase(st.find(x));
  .contains(x)   : O(log N) 【C++20〜】存在判定 (true/falseを返す。countより直感的) | 例: if (st.contains(5))
  .count(x)      : O(log N) 存在判定 (1 or 0, multisetは個数。C++17以前の主流) | 例: int num = st.count(5);
  .find(x)       : O(log N) イテレータ取得 (なし: .end()) | 例: auto it = st.find(5); if (it != st.end())
  .lower_bound(x): O(log N) x "以上" の最初の要素へのイテレータ | 例: auto it = st.lower_bound(5);
  .upper_bound(x): O(log N) x "より大きい" 最初の要素へのイテレータ | 例: auto it = st.upper_bound(5);
  *st.begin()    : O(1) 最小値 (※空コンテナ注意) | 例: int min_val = *st.begin();
  *st.rbegin()   : O(1) 最大値 (※空コンテナ注意) | 例: int max_val = *st.rbegin();
  prev(it)       : O(1) 1つ前（小さい方）のイテレータを取得 (※it != begin 用) | 例: auto prev_it = prev(it);
  next(it)       : O(1) 1つ次（大きい方）のイテレータを取得 | 例: auto next_it = next(it);
  mp[key]        : O(log N) アクセス (※なければ自動生成・0や空文字が入る副作用に注意) | 例: mp["apple"] = 100;
  mp.at(key)     : O(log N) アクセス (※なければ例外送出・安全) | 例: int price = mp.at("apple");
  for(auto [k,v]:mp): O(N)  C++17 構造化束縛での全要素ループ | 例: for (auto [key, val] : mp) { ... }
  greater<T>     : map/set を降順（大きい順）に並べ替える呪文 | 例: set<int, greater<int>> st;
  unordered_map  : 平均O(1) ハッシュテーブル使用 (※撃撃墜TLE対策には custom_hash 推奨) | 例: unordered_map<ll, int, custom_hash> mp;

[3] stack / queue / priority_queue (コンテナアダプタ)
------------------------------------------------------------------------------
  q = queue<T>() : これらには .clear() が無いため空オブジェクトを再代入する | 例: q = queue<int>();
  .empty()       : O(1) 空判定 | 例: while (!q.empty())
  .size()        : O(1) 要素数 | 例: int rem = q.size();
  .push(x)       : O(1) 追加 | 例: stk.push(x);
  .emplace(args) : O(1) 追加 (高速版) | 例: q.emplace(x, y);
  .pop()         : O(1)/O(log N) 削除 (戻り値void、値は事前に取得する) | 例: q.pop();
  .top()         : O(1) 一番上の値を取得 [stack / priority_queue のみ] | 例: int cur = stk.top();
  .front()       : O(1) 先頭の値を取得 [queue のみ] | 例: int cur = q.front();
  .back()        : O(1) 末尾の値を取得 [queue のみ] | 例: int last = q.back();
  greater<T>     : 最小値から取り出す（昇順 / 最小ヒープ） priority_queue の定義 | 例: priority_queue<int, vector<int>, greater<int>> pq;

[4] bitset (ビット集合・高速化)
------------------------------------------------------------------------------
  bitset<N> b    : すべて0で初期化 (※Nは定数) | 例: bitset<2005> b;
  bitset<N> b(val): 整数から下位ビットを初期化 | 例: bitset<8> b(13); // "00001101"
  bitset<N> b(str): "0" と "1" の文字列から初期化 (右端が0ビット目) | 例: bitset<4> b("1010");
  .set(i)        : iビット目を1にする (引数なしで 全1) | 例: b.set(3);
  .reset(i)      : iビット目を0にする (引数なしで 全0) | 例: b.reset(3);
  .flip(i)       : iビット目を反転    (引数なしで 全反転) | 例: b.flip(3);
  .test(i)       : iビット目が1か判定 (b[i]と同じだが範囲外アクセス時に例外で安全) | 例: if (b.test(3))
  .all()         : 全て1ならtrue | 例: if (b.all())
  .any()         : 1つでも1があればtrue | 例: if (b.any())
  .none()        : 全て0ならtrue | 例: if (b.none())
  .count()       : 1の個数 (popcountをCPU高速命令で処理) | 例: int cnt = b.count();
  .to_ullong()   : unsigned long long 型数値へ変換 | 例: ull val = b.to_ullong();
  .to_string()   : "0101..." 文字列へ変換 | 例: string s = b.to_string();
  &, |, ^, ~, << : 論理演算やシフト演算がそのまま高速動作 | 例: b |= (b << weight); // ナップサック等で約64倍高速化
  popcount(x)    : O(1) 【C++20〜】立っているビット数(1の数)を高速カウント | 例: int cnt = popcount(x);
  countr_zero(x) : O(1) 【C++20〜】右端(下位)から連続する0の数をカウント | 例: int trail = countr_zero(x);
  bit_width(x)   : O(1) 【C++20〜】値を表すのに必要な最小ビット幅を返す (MSB位置特定用) | 例: int w = bit_width(x);
  has_single_bit(x): O(1) 【C++20〜】値が2のべき乗(1, 2, 4, 8...)であるかを判定 | 例: if (has_single_bit(x))

[5] pair / tuple (組)
------------------------------------------------------------------------------
  .first / .second : pairの要素アクセス | 例: p.first = 10; p.second = "hello";
  get<N>(t)        : tupleのN番目にアクセス | 例: int x = get<0>(t);
  auto [a, b] = p  : C++17 構造化束縛 (分解代入。可読性向上・バグ防止) | 例: auto [cost, to] = edge;
  tie(a, b) = p    : 構造化束縛前の古い書き方(既存の変数に代入したい時現役) | 例: tie(x, s) = p;
  比較演算子       : pair/tupleは辞書順比較が自動定義済み (ソートで便利) | 例: sort(all(points));

[6] iterator操作 (非メンバ関数)
------------------------------------------------------------------------------
  distance(it1, it2) : it1からit2までの距離を返す (※vector等はO(1), set等はO(N)) | 例: int idx = distance(v.begin(), it);
  advance(it, n)     : itをn個進める (※vector等はO(1), set等はO(n)) | 例: advance(it, 3);
  prev(it)           : 1つ前のイテレータ (※it != begin 用) | 例: auto prev_it = prev(it);
  next(it)           : 1つ後のイテレータ | 例: auto next_it = next(it);
  rbegin() / rend()  : 逆順ループ用イテレータ | 例: for(auto it = v.rbegin(); it != v.rend(); ++it)

[7] algorithm / numeric (標準アルゴリズム)
------------------------------------------------------------------------------
  ranges::sort(v)        : O(N log N) 【C++20〜】begin/end不要で昇順ソート | 例: ranges::sort(v);
  ranges::sort(v, proj)  : 【C++20〜】構造体の特定メンバ変数などをキーとしてソート | 例: ranges::sort(members, {}, &Member::score);
  sort(all(v))           : 従来の昇順ソート (C++17以前) | 例: sort(all(v));
  reverse(all(v))        : O(N) メモリ上の物理的配列反転 | 例: reverse(all(v));
  unique(all(v))         : 重複削除(ソート後に使用)。末尾イテレータを返す (座標圧縮の基本) | 例: v.erase(unique(all(v)), v.end());
  lower_bound(all(v), x) : x以上の最初の要素のイテレータ | 例: auto it = lower_bound(all(v), x);
  ranges::lower_bound(v) : 【C++20〜】二分探索 (プロジェクション使用可能) | 例: auto it = ranges::lower_bound(members, 80, {}, &Member::score);
  upper_bound(all(v), x) : xより大きい最初の要素のイテレータ | 例: auto it = upper_bound(all(v), x);
  ranges::contains(v, x) : O(N) 【C++23〜】値xが含まれるかをboolで返す | 例: if (ranges::contains(v, 7))
  count(all(v), x)       : O(N) 値がxである要素の個数 | 例: int cnt = count(all(v), 7);
  ranges::count(v, x)    : O(N) 【C++20〜】同上 | 例: int cnt = ranges::count(v, 7);
  ranges::max/min(v)     : O(N) 【C++20〜】最大値/最小値を直接返す (※空配列エラー) | 例: int mx = ranges::max(v);
  midpoint(ok, ng)       : O(1) 【C++20〜】足し算オーバーフローなしの安全中間値 (二分探索用) | 例: int mid = midpoint(ok, ng);
  next_permutation(all(v)): 次の順列を生成(あればtrue)。全順列探索に便利 | 例: do { ... } while (next_permutation(all(v)));
  min_element(all(v))    : 最小値を指すイテレータ | 例: auto it = min_element(all(v));
  max_element(all(v))    : 最大値を指すイテレータ | 例: auto it = max_element(all(v));
  minmax(a, b)           : {最小, 最大}のpairを返す | 例: auto [mn, mx] = minmax(a, b);
  clamp(v, lo, hi)       : vを[lo, hi]の範囲に収める (境界チェック省略用) | 例: int x = clamp(val, 0, W - 1);
  iota(all(v), x)        : x, x+1, x+2... のように連番で埋める | 例: iota(all(v), 0);
  accumulate(all(v), 0LL): 合計値 (※0LLを指定してオーバーフロー回避する) | 例: ll sum = accumulate(all(v), 0LL);
  partial_sum(all(v), it) : 累積和を計算して別コンテナに出力 | 例: partial_sum(all(v), s.begin() + 1);
  is_sorted(all(v))      : ソートされているか判定 | 例: if (is_sorted(all(v)))
  shuffle(all(v), engine) : O(N) ランダムシャッフル | 例: shuffle(all(v), engine);
  gcd(a, b) / lcm(a, b)  : 最大公約数 / 最小公倍数 (C++17以上) | 例: ll g = gcd(a, b);

[8] テンプレート独自の便利機能・数学ライブラリ
------------------------------------------------------------------------------
  chmax(a, b)    : a < b なら a = b とし true を返す (DP等で多用) | 例: chmax(ans, x);
  chmin(a, b)    : a > b なら a = b とし true を返す (DP等で多用) | 例: chmin(ans, x);
  in_grid(r,c,h,w): O(1) グリッドの範囲内判定 (r, c が 0〜h-1, 0〜w-1 の間か) | 例: if (in_grid(nr, nc, H, W))
  debug(x)       : 変数名と値を表示 (多次元配列・コンテナ・pair自動展開) | 例: debug(dp);
  pow_mod(a, n)  : a の n 乗を MOD で割った余りを計算 (O(log n)、負の数対応) | 例: ll val = pow_mod(a, n);
  inv_mod(a)     : a の MOD における逆元を計算 (※MODが素数の時のみ) | 例: ll inv = inv_mod(a);
  Combination c(N): nCr を O(1) で求めるクラス (MOD変更バグ防止テンプレート引数) | 例: Combination comb(200005); ll ans = comb.nCr(n, r);

[9] C++20/23 モダンレンジ・ビュー操作 (std::views / std::ranges) (※C++23機能は動作環境に注意)
------------------------------------------------------------------------------
  ※ std::views:: は namespace エイリアスにより省略可能 (例: views::filter -> filter)
  v | filter(pred)       : 条件に合うものだけ抽出 (遅延評価・メモリコピーなし) | 例: auto evens = v | filter([](int x){ return x % 2 == 0; });
  v | take(K)            : 先頭K個だけ取得 | 例: auto head = v | take(5);
  v | drop(K)            : 先頭K個を無視 | 例: auto tail = v | drop(3);
  v | transform(f)       : 全要素を一斉に加工 | 例: auto doubled = v | transform([](int x){ return x * 2; });
  v | reverse            : 逆順に読み込む | 例: for (int x : v | reverse)
  zip(v1, v2)            : 【C++23】複数配列の同時ループ (添字バグを防止) | 例: for (auto [x, y] : zip(A, B))
  v | enumerate          : 【C++23】インデックス付きループ (0始まり) | 例: for (auto [i, val] : v | enumerate)
  v | keys / v | values  : pairの左(key)/右(val)だけ抽出 | 例: for (auto name : mp | keys)
  cartesian_product(r1,r2):【C++23】直積（多重ループ）の平坦化 (グリッド走査など) | 例: for (auto [r, c] : cartesian_product(iota(0,H), iota(0,W)))
  v | chunk(K)           : 【C++23】K個ずつの組に分割 | 例: for (auto sub : v | chunk(3))
  v | slide(K)           : 【C++23】K個の連続区間をずらす (スライド窓) | 例: for (auto window : v | slide(3))
  v | chunk_by(pred)     : 【C++23】隣接要素が条件を満たす間グループ化 (ランレングス等) | 例: auto groups = v | chunk_by(equal_to{});
  v | ranges::to<vector>():【C++23】Viewから vector 等のコンテナへ変換 (実体化) | 例: vector<int> res = v | filter(pred) | ranges::to<vector>();
  ⚠️ 遅延評価の注意点    : views はアクセス毎に再計算するため、[i]でのアクセスや使い回しをする時は必ず `| ranges::to<vector>()` する。

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
