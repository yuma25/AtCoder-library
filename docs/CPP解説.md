# Template.cpp 完全解体新書：上から下まで徹底解説

`Template.cpp` の全行を、具体的なコード例、引数、戻り値、使いどころを交えて徹底的に解説します。

---

## 1. 基本設定・型エイリアス (L1 - L20)

```cpp
#include <bits/stdc++.h>
using namespace std;
```
- **処理**: 全標準ライブラリの読み込みと名前空間の省略。
- **使いどころ**: 競技プログラミングの標準的な開始定型文。

```cpp
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
// ...その他エイリアス
```
- **仕様**: 長い型名を短縮。
- **具体例**: `vi a(n);` は `vector<int> a(n);` と同義。
- **引数・戻り値**: なし（型定義）。

---

## 2. 定数 (L22 - L30)

```cpp
const ll INF = 1e18;
const int INF_INT = 1e9;
const int MOD = 998244353;
const double PI = acos(-1);
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
```
- **処理**: 無限大、法、円周率、移動方向の定義。
- **具体例**: `nx = x + dx[i]; ny = y + dy[i];` で 4/8 方向移動をループ処理可能。

---

## 3. 便利マクロ (L32 - L43)

```cpp
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
```
- **引数**: `i` (ループ変数), `n` (回数)
- **具体例**: `rep(i, 10) cout << i << endl;` で 0〜9 を出力。

```cpp
#define all(v) (v).begin(), (v).end()
```
- **戻り値**: コンテナの開始と終了イテレータのペア。
- **具体例**: `sort(all(a));` で配列を一括ソート。

---

## 4. 入出力高速化 (L45 - L52)

```cpp
struct FastIO { ... } fast_io;
```
- **処理**: `cin` と `cout` の同期を切り、実行速度を極限まで高める。
- **仕様**: 小数点出力を 15 桁固定にする設定も含む。

---

## 5. 便利関数 (L54 - L58)

```cpp
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
```
- **引数**: `a` (既存の値の参照), `b` (新しい値)
- **戻り値**: `bool` (値が更新されたら `true`)
- **具体例**: `chmax(ans, x);` で `ans` を最大値に保つ。

---

## 6. 入出力オーバーロード (L60 - L70)

```cpp
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &x : v) is >> x; return is; }
```
- **引数**: `cin`, `vector`
- **処理**: `cin >> v;` だけで配列全要素を読み込む。
- **戻り値**: `istream` の参照（連鎖入力用）。

---

## 7. デバッグ用マクロ (L72 - L78)

```cpp
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << endl
#else
#define debug(x)
#endif
```
- **処理**: 自分のパソコンでのみ変数の内容を表示。提出時は無視される。
- **具体例**: `debug(ans);` と書くと `ans: 123` のように標準エラー出力に出る。

---

## 8. 数学・アルゴリズム集 (L80 - L106)

### `pow_mod(a, n, m)`
- **引数**: `a` (底), `n` (指数), `m` (法)
- **戻り値**: `ll` (計算結果)
- **処理**: 繰り返し二乗法で `a^n % m` を計算。

### `Combination` クラス
- **コンストラクタ引数**: `n` (事前計算する最大値)
- **`nCr` 引数**: `n`, `r`
- **戻り値**: `ll` (組合せの数 % MOD)
- **具体例**: `Combination comb(100); cout << comb.nCr(5, 2);` で 10 を出力。

---

## 9. 標準ライブラリ 完全チートシート (L110 - 末尾)

テンプレート末尾にコメントとして記載されている「標準ライブラリ 操作一覧」の全項目を詳細に解説します。

### [1] vector / deque / string (シーケンス系)
- **`.size()`**: 【引数:無, 戻り値:size_t】 要素数を返します。
- **`.empty()`**: 【引数:無, 戻り値:bool】 空なら true。
- **`.clear()`**: 【引数:無, 戻り値:無】 全消去。
- **`.resize(n, x)`**: 【引数:サイズn, 埋める値x, 戻り値:無】 サイズを変更。
- **`.push_back(x)`**: 【引数:要素x, 戻り値:無】 末尾に追加。
- **`.emplace_back(args)`**: 【引数:引数, 戻り値:無】 末尾に直接構築して追加（高速）。
- **`.pop_back()`**: 【引数:無, 戻り値:無】 末尾を1つ削除。
- **`.front() / .back()`**: 【引数:無, 戻り値:参照】 先頭・末尾の要素。
- **`.at(i)`**: 【引数:インデックスi, 戻り値:参照】 範囲外チェック付きアクセス。
- **`[dequeのみ] .push_front(x) / .pop_front()`**: 先頭への追加・削除 (O(1))。
- **`[stringのみ] .substr(pos, len)`**: 【引数:位置, 長さ, 戻り値:string】 部分文字列。
- **`[stringのみ] .find(str)`**: 【引数:探す文字列, 戻り値:size_t】 検索。なければ `npos`。

### [2] set / map / multiset (平衡二分探索木)
- **`.insert(x)`**: 【引数:要素, 戻り値:pair<it, bool>】 追加。
- **`.erase(x)`**: 【引数:値, 戻り値:size_t】 その値をすべて削除。
- **`.erase(it)`**: 【引数:イテレータ, 戻り値:無】 その場所を1つだけ削除。
- **`.contains(x)`**: 【C++20〜】存在判定 (true/false)。
- **`.count(x)`**: 【引数:値, 戻り値:size_t】 存在判定。
- **`.find(x)`**: 【引数:値, 戻り値:iterator】 見つからなければ `.end()`。
- **`.lower_bound(x)`**: 【引数:値, 戻り値:iterator】 x 以上の最初の要素。
- **`*st.begin() / *st.rbegin()`**: 最小値・最大値。
- **[multiset] 特定の値を1つだけ消す**: `if (auto it = st.find(x); it != st.end()) st.erase(it);`
- **`mp[key]`**: 【引数:キー, 戻り値:値の参照】 map の要素アクセス。

### [3] stack / queue / priority_queue (コンテナアダプタ)
- **`.push(x) / .pop()`**: 追加と取り出し。
- **`.top()`**: stack/priority_queue の先頭。
- **`.front() / .back()`**: queue の先頭・末尾。

### [4] bitset (ビット集合)
- **`.set(i) / .reset(i) / .flip(i)`**: ビット操作。
- **`.count()`**: 1 の個数を数える (popcount)。
- **`.any() / .none()`**: 1があるか、全0か。
- **`.to_ullong() / .to_string()`**: 型変換。

### [5] pair / tuple (組)
- **`.first / .second`**: pair の要素。
- **`get<N>(t)`**: tuple の N 番目の要素。
- **`auto [a, b] = p`**: 構造化束縛での分解。

### [6] iterator操作
- **`distance(it1, it2)`**: 2つの間の要素数。
- **`advance(it, n)`**: イテレータを n 個進める。
- **`prev(it) / next(it)`**: 前後のイテレータ。

### [7] algorithm / numeric (標準アルゴリズム)
- **`sort(all(v))`**: 【引数:範囲, 戻り値:無】 O(N log N) ソート。
- **`reverse(all(v))`**: 【引数:範囲, 戻り値:無】 反転。
- **`unique(all(v))`**: 【引数:範囲, 戻り値:iterator】 重複削除（ソート必須）。
- **`lower_bound(all(v), x)`**: 【引数:範囲, 値, 戻り値:iterator】 二分探索（x以上）。
- **`upper_bound(all(v), x)`**: 【引数:範囲, 値, 戻り値:iterator】 二分探索（x超）。
- **`count(all(v), x)`**: 【引数:範囲, 値, 戻り値:size_t】 個数を数える。
- **`next_permutation(all(v))`**: 【引数:範囲, 戻り値:bool】 次の順列生成。
- **`min_element / max_element`**: 最小値・最大値を指すイテレータ。
- **`iota(all(v), x)`**: 【引数:範囲, 開始値, 戻り値:無】 連番で埋める。
- **`accumulate(all(v), 0LL)`**: 【引数:範囲, 初期値, 戻り値:合計値】 配列の合計。
- **`gcd(a, b) / lcm(a, b)`**: 最大公約数・最小公倍数。

---

## 10. 実践的なヒント (VS Code)

### スニペットの活用
本環境では、`スニペット.cpp` に便利な定型文を登録しています。エディタ上で以下のキーワードを入力して `Enter` または `Tab` を押すことで、一瞬でコードを展開できます。

- **`cp`**: 本テンプレートの全体（ヘッダー、マクロ、チートシート等）を展開します。
- **`UnionFind`**: グラフの連結性を管理する Union-Find データ構造を展開します。
  - **使用例**:
    ```cpp
    UnionFind uf(n);
    uf.unite(1, 2); // 1 と 2 をつなげる
    if (uf.isSame(1, 2)) cout << "Same!" << endl;
    ```

### ローカル環境での実行
`.vscode/tasks.json` の設定により、コンパイル時に `-DLOCAL` フラグが付与されます。これにより、`debug(x)` マクロが動作し、手元の環境でのみ変数の中身を確認しながら開発が可能です。

---

このマニュアルに従えば、テンプレートの全機能を迷わず使いこなせます。
