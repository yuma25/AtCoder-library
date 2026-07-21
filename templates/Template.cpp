#include <bits/stdc++.h>
// #include <atcoder/all> 
using namespace std;
using namespace std::views;
// using namespace atcoder;

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
#define se second                                               // pair of 第2要素

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
  ▼ 作成・初期化・サイズ変更
    .resize(n, x)  : O(N) サイズ変更 (増えた分は x で埋める) | 例: dp.resize(N + 1, -1);
    .assign(n, x)  : O(N) サイズ n，値 x で初期化 (上書き) | 例: v.assign(N, 0);
    .reserve(n)    : O(N) メモリの事前確保 (push_back 高速化) | 例: v.reserve(N);

  ▼ 情報取得
    .size()        : O(1) 要素数 (size_t型，引き算時アンダーフロー注意) | 例: int n = (int)v.size();
    ssize(v)       : O(1) 【C++20】符号付きサイズ取得 (ssize(v)-1 も安全) | 例: rep(i, ssize(v)-1)
    .empty()       : O(1) 空なら true | 例: if (v.empty()) return 0;

  ▼ 要素へのアクセス
    v[i]           : O(1) i番目の要素の参照 | 例: v[i] = 100;
    .at(i)         : O(1) 範囲外チェック付きアクセス | 例: v.at(i) = 100;
    .front()       : O(1) 先頭要素の参照 | 例: int first = v.front();
    .back()        : O(1) 末尾要素の参照 | 例: int last = v.back();

  ▼ 要素の追加・削除
    .push_back(x)  : O(1)※ 末尾に追加 (※平均) | 例: v.push_back(10);
    .pop_back()    : O(1) 末尾を削除 (空のとき使用注意) | 例: v.pop_back();
    .emplace_back() : O(1)※ 末尾に直接構築 (高速) | 例: v.emplace_back(1, 2);
    .push_front(x) : O(1) 先頭に追加 [dequeのみ] | 例: deq.push_front(5);
    .pop_front()   : O(1) 先頭を削除 [dequeのみ] | 例: deq.pop_front();
    .clear()       : O(N) 全要素消去 (メモリ容量は維持) | 例: v.clear();

  ▼ 挿入・部分削除・検索
    .insert(it, x) : O(N) イテレータの示す位置に挿入 | 例: v.insert(v.begin() + 1, 99);
    .erase(it)     : O(N) イテレータの示す位置を削除 | 例: v.erase(v.begin() + 3);
    std::erase(v, x): O(N) 【C++20】値 x をすべて削除 | 例: std::erase(v, 7);
    std::erase_if(v, pred): O(N) 【C++20】条件に合う要素をすべて削除 | 例: std::erase_if(v, [](int x){ return x % 2 == 0; });

  ▼ string 特有の操作
    .substr(pos, len) : O(len) 部分文字列の取得 | 例: string sub = s.substr(2, 3);
    stoi(s)        : 文字列を int 型数値に変換 | 例: int val = stoi(s);
    to_string(x)   : 数値を文字列に変換 | 例: string str = to_string(123);

[2] set / multiset / map (連想コンテナ)
------------------------------------------------------------------------------
  ▼ 要素の追加・更新
    .insert(x)     : O(log N) 要素の追加 | 例: st.insert(5);
    mp[key]        : O(log N) キーを指定した代入・更新 (自動生成に注意) | 例: mp["apple"] = 100;

  ▼ 要素の削除
    .erase(x)      : O(log N) 値 x を削除 (※multisetでは一致する「全て」が削除される) | 例: st.erase(5);
    .erase(it)     : O(1) イテレータ指定での削除 (※multisetで1つだけ消す際の基本手法) | 例: st.erase(st.find(x));
    .clear()       : O(N) 全要素消去 | 例: st.clear();

  ▼ 要素の検索・存在確認
    .contains(x)   : O(log N) 【C++20】存在判定 (bool) | 例: if (st.contains(5))
    .count(x)      : O(log N) 存在数 (setでは 0 or 1，multisetでは要素数) | 例: int num = st.count(5);
    .find(x)       : O(log N) イテレータの取得 (存在しなければ .end()) | 例: auto it = st.find(5);

  ▼ 最大値・最小値・順序関連
    *st.begin()    : O(1) 最小値の参照 (空のとき注意) | 例: int min_val = *st.begin();
    *st.rbegin()   : O(1) 最大値の参照 (空のとき注意) | 例: int max_val = *st.rbegin();
    .lower_bound(x): O(log N) x 以上の最初の要素を指すイテレータ | 例: auto it = st.lower_bound(5);
    .upper_bound(x): O(log N) x より大きい最初の要素を指すイテレータ | 例: auto it = st.upper_bound(5);

  ▼ ループ・その他
    for (auto [k, v] : mp) : O(N) 【C++17】構造化束縛を用いた全要素ループ | 例: for (auto [k, v] : mp) { ... }
    greater<T>     : 降順（大きい順）ソート用の型指定 | 例: set<int, greater<int>> st;

[3] stack / queue / priority_queue (コンテナアダプタ)
------------------------------------------------------------------------------
  ▼ 基本操作
    .push(x)       : O(1) / O(log N) 要素の追加 | 例: q.push(x);
    .emplace(args) : O(1) / O(log N) 直接構築して追加 (高速) | 例: q.emplace(x, y);
    .pop()         : O(1) / O(log N) 要素の削除 (戻り値は void) | 例: q.pop();
    .empty()       : O(1) 空なら true | 例: while (!q.empty())
    .size()        : O(1) 要素数 | 例: int rem = q.size();
    q = {}         : 全要素消去 (.clear がないため空オブジェクトを代入) | 例: q = queue<int>();

  ▼ 要素の参照
    .top()         : O(1) 先頭要素 of 参照 [stack / priority_queue のみ] | 例: int cur = pq.top();
    .front()       : O(1) 先頭要素の参照 [queue のみ] | 例: int cur = q.front();
    .back()        : O(1) 末尾要素の参照 [queue のみ] | 例: int last = q.back();

  ▼ priority_queue のカスタマイズ
    greater<T>     : 昇順（最小値から取り出す最小ヒープ）での宣言 | 例: priority_queue<int, vector<int>, greater<int>> pq;

[4] bitset (ビット集合・高速化)
------------------------------------------------------------------------------
  ▼ 初期化
    bitset<N> b    : すべて0で初期化 (※Nは定数) | 例: bitset<2005> b;
    bitset<N> b(val): 整数から下位ビットを初期化 | 例: bitset<8> b(13); // "00001101"
    bitset<N> b(str): "0" と "1" の文字列から初期化 | 例: bitset<4> b("1010");

  ▼ ビット操作
    .set(i)        : iビット目を1にする (引数なしで全ビットを1) | 例: b.set(3);
    .reset(i)      : iビット目を0にする (引数なしで全ビットを0) | 例: b.reset(3);
    .flip(i)       : iビット目を反転する (引数なしで全ビットを反転) | 例: b.flip(3);

  ▼ 状態取得
    .test(i)       : iビット目が1か判定 (範囲外例外ありで安全) | 例: if (b.test(3))
    .count()       : 1の個数を数える (popcountを高速命令で実行) | 例: int cnt = b.count();
    .all()         : 全て1なら true | 例: if (b.all())
    .any()         : 1つでも1があれば true | 例: if (b.any())
    .none()        : 全て0なら true | 例: if (b.none())

  ▼ 型変換・演算
    .to_ullong()   : unsigned long long 型へ変換 | 例: ull val = b.to_ullong();
    .to_string()   : "0101..." 形式の文字列へ変換 | 例: string s = b.to_string();
    &, |, ^, ~, << : 高速なビット論理演算・シフト演算 (ナップサック等) | 例: b |= (b << w);

  ▼ C++20 ビット関連関数 (std::)
    popcount(x)    : O(1) 立っているビット数 (1の数) をカウントする | 例: int cnt = popcount(x);
    countr_zero(x) : O(1) 右端から連続する0の数をカウントする | 例: int z = countr_zero(x);
    bit_width(x)   : O(1) 値を表現するのに必要な最小ビット幅を返す | 例: int w = bit_width(x);
    has_single_bit(x): O(1) 値が2のべき乗（1, 2, 4, 8...）か判定する | 例: if (has_single_bit(x))

[5] pair / tuple (組)
------------------------------------------------------------------------------
  ▼ 要素の参照・操作
    p.first        : pairの第1要素を取得 | 例: p.first = 10;
    p.second       : pairの第2要素を取得 | 例: p.second = "hello";
    get<N>(t)      : tupleのN番目の要素を取得 | 例: int val = get<0>(t);

  ▼ 代入・分解
    auto [a, b] = p: 【C++17】構造化束縛 (分解代入でバグを防止) | 例: auto [cost, to] = edge;
    tie(a, b) = p  : 既存の変数への分解代入 | 例: tie(x, s) = p;

  ▼ 比較・ソート
    比較演算子     : 辞書順で比較されるため，そのままソート可能 | 例: sort(all(points));

[6] iterator操作 (非メンバ関数)
------------------------------------------------------------------------------
  ▼ 基本イテレータ操作
    prev(it)       : 1つ前（小さい方）のイテレータを取得 (it != begin で使用) | 例: auto pit = prev(it);
    next(it)       : 1つ後（大きい方）のイテレータを取得 | 例: auto nit = next(it);
    advance(it, n) : itをn個進める (vector等はO(1)，set等はO(n)) | 例: advance(it, 3);
    distance(it1,it2): イテレータ間の要素数を取得 (vector等はO(1)) | 例: int idx = distance(v.begin(), it);

  ▼ 逆順操作
    rbegin()       : 末尾の要素を指す逆順イテレータ | 例: auto rit = v.rbegin();
    rend()         : 先頭の前の仮想位置を指す逆順イテレータ | 例: auto rit = v.rend();

[7] algorithm / numeric (標準アルゴリズム)
------------------------------------------------------------------------------
  ▼ ソート・並び替え
    ranges::sort(v): O(N log N) 【C++20】全範囲を昇順ソート | 例: ranges::sort(v);
    ranges::sort(v, proj): 【C++20】構造体の特定メンバ変数をキーにソート | 例: ranges::sort(v, {}, &Member::score);
    sort(all(v))   : 従来の全範囲昇順ソート (C++17以前) | 例: sort(all(v));
    reverse(all(v)): O(N) 配列を物理的に反転する | 例: reverse(all(v));
    shuffle(all(v), eng): O(N) ランダムシャッフル | 例: shuffle(all(v), engine);

  ▼ 検索・カウント
    ranges::contains(v, x): O(N) 【C++23】値 x が含まれているか判定 | 例: if (ranges::contains(v, 7))
    count(all(v), x): O(N) 値が x の要素の個数をカウントする | 例: int cnt = count(all(v), 7);
    min_element(all(v)): 最小値を示すイテレータを返す | 例: auto it = min_element(all(v));
    max_element(all(v)): 最大値を示すイテレータを返す | 例: auto it = max_element(all(v));
    minmax(a, b)   : {最小値, 最大値} の pair を返す | 例: auto [mn, mx] = minmax(a, b);

  ▼ 二分探索 (※配列がソート済みであること)
    lower_bound(all(v), x): x以上の最初の要素を指すイテレータ | 例: auto it = lower_bound(all(v), x);
    upper_bound(all(v), x): xより大きい最初の要素を指すイテレータ | 例: auto it = upper_bound(all(v), x);
    ranges::lower_bound(v, val, proj): 【C++20】二分探索 (構造体等に対応) | 例: auto it = ranges::lower_bound(members, 80, {}, &Member::score);
    midpoint(ok, ng): O(1) 【C++20】オーバーフローのない安全な中間値 | 例: int mid = midpoint(ok, ng);
    next_permutation(all(v)): 順列を辞書順で1つ進める．全順列探索に便利 | 例: do { ... } while (next_permutation(all(v)));

  ▼ 要素の操作・加工
    unique(all(v)) : 隣接重複の削除 (ソート後使用)．不要な末尾の開始イテレータを返す | 例: v.erase(unique(all(v)), v.end());
    iota(all(v), x): xから始まる連番で埋める | 例: iota(all(v), 0);
    clamp(v, lo, hi): vを[lo, hi]の範囲に収める | 例: int x = clamp(val, 0, W - 1);

  ▼ 数値計算 (numeric)
    accumulate(all(v), 0LL): 配列の合計 (※0LLを指定してオーバーフロー回避) | 例: ll sum = accumulate(all(v), 0LL);
    partial_sum(all(v), it): 累積和を計算して別コンテナへ出力する | 例: partial_sum(all(v), s.begin() + 1);
    gcd(a, b)      : 最大公約数 (C++17以上) | 例: ll g = gcd(a, b);
    lcm(a, b)      : 最小公倍数 (C++17以上) | 例: ll l = lcm(a, b);

[8] テンプレート独自の便利機能・数学ライブラリ
------------------------------------------------------------------------------
  ▼ 基本マクロ・関数
    chmax(a, b)    : a < b なら a = b と更新し true を返す (DP多用) | 例: chmax(ans, x);
    chmin(a, b)    : a > b なら a = b と更新し true を返す (DP多用) | 例: chmin(ans, x);
    in_grid(r,c,h,w): グリッドの範囲内判定 (r, c が 0〜h-1, 0〜w-1 の間か) | 例: if (in_grid(nr, nc, H, W))
    debug(x)       : LOCALマクロ有効時のみ，変数名と値を表示するマクロ | 例: debug(dp);

  ▼ 数学ライブラリ
    pow_mod(a, n)  : a の n 乗を MOD で割った余りを計算 (O(log n)，負数対応) | 例: ll val = pow_mod(a, n);
    inv_mod(a)     : a の MOD における逆元を計算 (※MODが素数のときのみ) | 例: ll inv = inv_mod(a);
    Combination c(N): nCr を O(1) で求めるクラス (法を変更可能なテンプレート引数) | 例: Combination comb(200005); ll ans = comb.nCr(n, r);

[9] C++20/23 モダンレンジ・ビュー操作 (std::views / std::ranges)
------------------------------------------------------------------------------
  ※ std::views:: は省略可能 (例: views::filter -> filter)
  ▼ 基本View操作 (遅延評価)
    v | filter(pred)       : 条件に合う要素だけを抽出する | 例: auto evens = v | filter([](int x){ return x % 2 == 0; });
    v | take(K)            : 先頭からK個を取得する | 例: auto head = v | take(5);
    v | drop(K)            : 先頭からK個を除外する | 例: auto tail = v | drop(3);
    v | transform(f)       : 各要素に一斉加工処理を適用する | 例: auto doubled = v | transform([](int x){ return x * 2; });
    v | reverse            : 逆順にアクセスする | 例: for (int x : v | reverse)
    v | keys / v | values  : pairの左(key) / 右(val)だけを抽出する | 例: for (auto k : mp | keys)

  ▼ C++23 応用View操作
    zip(v1, v2)            : 【C++23】複数配列の要素を同時にループする | 例: for (auto [x, y] : zip(A, B))
    v | enumerate          : 【C++23】インデックス付きループ (0始まり) | 例: for (auto [i, val] : v | enumerate)
    v | chunk(K)           : 【C++23】K個ずつのサブグループに分割する | 例: for (auto sub : v | chunk(3))
    v | slide(K)           : 【C++23】長さKの連続区間をスライドさせる | 例: for (auto window : v | slide(3))
    v | chunk_by(pred)     : 【C++23】隣接要素が条件を満たす間グループ化 (ランレングス等) | 例: auto groups = v | chunk_by(equal_to{});
    cartesian_product(r1,r2): 【C++23】直積ループを生成 (グリッド走査の平坦化) | 例: for (auto [r, c] : cartesian_product(iota(0,H), iota(0,W)))

  ▼ Viewの実体化
    v | ranges::to<vector>(): 【C++23】Viewの遅延評価結果を実体化 (vector等に変換) | 例: vector<int> res = v | filter(pred) | ranges::to<vector>();
    ⚠️ 遅延評価の注意点    : views は要素アクセスごとに再計算するため，ランダムアクセスや再利用をする場合は必ず実体化（ranges::to）を行うこと．

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

3. AtCoder Library (ACL) 活用チートシート (要: #include <atcoder/all> と using namespace atcoder;)
------------------------------------------------------------------------------
① dsu (Union-Find)
  dsu d(N)                : O(α(N)) N頂点のUnion-Findを作成する | 例: dsu d(N);
  d.unite(u, v)           : O(α(N)) uとvの属するグループを併合する | 例: d.unite(1, 2);
  d.same(u, v)            : O(α(N)) uとvが同じグループか判定する | 例: if (d.same(1, 2))
  d.leader(u)             : O(α(N)) uの属するグループの代表元（親）を返す | 例: int root = d.leader(1);
  d.size(u)               : O(α(N)) uの属するグループのサイズを返す | 例: int sz = d.size(1);
  d.groups()              : O(N) 全グループの要素リストを返す | 例: auto gps = d.groups(); // vector<vector<int>>

② segtree (セグメント木)
  segtree<S, op, e> seg(N): O(N) サイズNで初期化，値はすべて単位元 e() | 例: segtree<int, op, e> seg(N);
  seg.set(i, x)           : O(log N) i番目の値を x に更新する | 例: seg.set(3, 10);
  seg.get(i)              : O(1) i番目の値を取得する | 例: int val = seg.get(3);
  seg.prod(l, r)          : O(log N) 区間 [l, r) の総積（演算結果）を取得する | 例: int res = seg.prod(0, N);
  seg.all_prod()          : O(1) 全区間の総積を取得する | 例: int res = seg.all_prod();
  💡 標準的な宣言方法:
    int op(int a, int b) { return max(a, b); }
    int e() { return -INF_INT; }
    segtree<int, op, e> seg(N);

③ fenwick_tree (BIT: 内部で1-indexed処理を行うため，呼び出しは0-indexedでOK)
  fenwick_tree<T> fw(N)   : O(N) サイズN，初期値0で作成する | 例: fenwick_tree<ll> fw(N);
  fw.add(i, x)            : O(log N) i番目の値に x を加算する | 例: fw.add(3, 10);
  fw.sum(l, r)            : O(log N) 区間 [l, r) の合計を返す | 例: ll total = fw.sum(0, N);

④ lazy_segtree (遅延評価セグメント木)
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(N): 区間一括更新に対応するセグ木
  💡 標準的な宣言方法 (区間加算・区間最小値の例):
    int op(int a, int b) { return min(a, b); }
    int e() { return INF_INT; }
    int mapping(int f, int x) { return x + f; }
    int composition(int f, int g) { return f + g; }
    int id() { return 0; }
    lazy_segtree<int, op, e, int, mapping, composition, id> seg(N);
  seg.apply(l, r, f)      : O(log N) 区間 [l, r) に作用素 f を適用する | 例: seg.apply(0, N, 5);

⑤ scc_graph (強連結成分分解)
  scc_graph g(N)          : N頂点の有向グラフを作成する | 例: scc_graph g(N);
  g.add_edge(u, v)        : uからvへの有向辺を追加する | 例: g.add_edge(1, 2);
  g.scc()                 : O(N + M) 強連結成分分解を行い，トポロジカルソート順の強連結成分のリストを返す | 例: auto scc = g.scc(); // vector<vector<int>>

⑥ maxflow / mincostflow (最大流・最小費用流)
  mf_graph<Cap> g(N)      : N頂点のネットワークを作成する | 例: mf_graph<ll> g(N);
  g.add_edge(u, v, cap)   : 容量capの辺を追加し，辺番号を返す | 例: int id = g.add_edge(0, 1, 10);
  g.flow(s, t)            : O(M * min(N, √M)) sからtへの最大流量を返す | 例: ll flow = g.flow(s, t);
  g.min_cut(s)            : O(N + M) 最小カットに対応する，sから到達可能な頂点集合を vector<bool> で返す | 例: auto cut = g.min_cut(s);
  mcf_graph<Cap, Cost> g  : 最小費用流．g.add_edge(u, v, cap, cost) で辺追加し，auto [flow, cost] = g.flow(s, t) で計算 | 例: auto [f, c] = g.flow(s, t); (C++17構造化束縛)

⑦ two_sat (2-SAT)
  two_sat ts(N)           : N個の変数を持つ2-SATインスタンスを作成する | 例: two_sat ts(N);
  ts.add_clause(i, f, j, g): クローズ (x_i == f) ∨ (x_j == g) を追加する | 例: ts.add_clause(1, true, 2, false); // (x_1) ∨ (￢x_2)
  ts.satisfiable()        : O(N + M) 矛盾なく割り当て可能か判定する | 例: if (ts.satisfiable())
  ts.answer()             : O(N) 割り当てられた真偽値 vector<bool> を返す | 例: auto ans = ts.answer();

⑧ modint
  using mint = modint998244353 / modint1000000007 / static_modint<MOD>;
  mint a = 10              : 四則演算時に自動で剰余（余り）を計算する型 | 例: mint a = 10; mint b = a + 5;
  a.val()                  : 保持している生の整数値を取得する（C++20 std::format や出力時に必須） | 例: cout << a.val() << "\n";
  a.pow(n)                 : a の n 乗を計算する | 例: mint b = a.pow(10);
  a.inv()                  : a の逆元を計算する | 例: mint inv = a.inv();
  ※ ストリーム入力時は一度 int/ll で受けてから代入する | 例: int x; cin >> x; mint a = x;

⑨ convolution (畳み込み)
  convolution(a, b)       : O(N log N) 数列 a と b の畳み込み（多項式の掛け算）を計算する | 例: auto c = convolution(a, b);
  convolution<mint>(a, b) : modint型での畳み込み（FFT/NTT）を行う | 例: auto c = convolution<mint>(a, b);

⑩ math (ACL数学ライブラリ)
  pow_mod(x, n, m)        : O(log n) x^n mod m を計算する（負のxにも対応） | 例: ll val = pow_mod(x, n, m);
  inv_mod(x, m)           : O(log m) x の mod m における逆元を返す（gcd(x, m)=1 が必要） | 例: ll inv = inv_mod(x, m);
  crt(r, m)               : 中国剰余定理を解く（r, mは同じ長さの配列）．解が存在すれば {値, 最小公倍数}，なければ {0, 0} を返す | 例: auto [r_ans, m_lcm] = crt(r, m); (C++17構造化束縛)
  floor_sum(n, m, a, b)   : O(log m) ∑_{i=0}^{n-1} floor((a*i + b)/m) を高速に計算する | 例: ll sum = floor_sum(n, m, a, b);

⑪ string (ACL文字列ライブラリ)
  suffix_array(s)         : O(N) 文字列 s の接尾辞配列（辞書順ソートされたインデックス）を返す | 例: auto sa = suffix_array(s);
  lcp_array(s, sa)        : O(N) suffix_array を用いて，隣り合う接尾辞同士の最長共通接頭辞 (LCP) の長さを返す | 例: auto lcp = lcp_array(s, sa);
  z_algorithm(s)          : O(N) 各 i について，s と s[i..N-1] の最長共通接頭辞 of 長さを返す | 例: auto z = z_algorithm(s);

==============================================================================
【VS Code C++ スニペット呼び出しショートカット一覧】
==============================================================================
  VS Code上で以下のショートカットキー（Prefix）を入力することで，
  AtCoderで頻出する各種宣言や定番アルゴリズムを瞬時に展開できる．

  ▼ テンプレート・基本宣言
    cp                     : テンプレートファイル全体の展開
    v1                     : 1次元ベクトルの宣言 | vector<int> v(N, 0);
    v2                     : 2次元ベクトルの宣言 | vector<vector<int>> v(H, vector<int>(W, 0));
    pqmax                  : 降順優先度付きキュー（最大値取り出し）の宣言 | priority_queue<int> pq;
    pqmin                  : 昇順優先度付きキュー（最小値取り出し）の宣言 | priority_queue<int, vector<int>, greater<int>> pq;
    set_init               : 集合の宣言 | set<int> st;
    map_init               : 連想配列の宣言 | map<string, int> mp;

  ▼ 典型アルゴリズム
    binsearch              : 二分探索（判定問題用 ok / ng テンプレート）
    bfs                    : グラフの幅優先探索（最短経路）
    gridbfs                : 2Dグリッド上の幅優先探索（最短経路）
    dijkstra               : 単一始点最短経路（ダイクストラ法）
    compression            : 座標圧縮（重複排除と座標値のマッピング）
    rle                    : ランレングス圧縮（文字列の連程圧縮）
    primefactor            : 素因数分解（O(√N)での分解処理）
    divisors               : 約数列挙（O(√N)での全約数列挙）

  ▼ ACL（AtCoder Library）定型
    segtree_max            : セグメント木（点更新・区間最大値）のop/e定義用
    lazy_segtree_add_min   : 遅延評価セグメント木（区間加算・区間最小値）の定義用

==============================================================================
*/