# AtCoder「入力形式別」即戦力コードスニペット集

AtCoderの「問題文に書かれている入力形式」と「そのまま使える実装コード」を対応表形式でまとめる．
「どのコードを使えばいいか」が直感的にわかるよう，視認性を重視した構成とする．

---

## 0. 共通：最速テンプレート
コードの冒頭にこれらを記述することを前提とする．

**C++**
```cpp
#include <bits/stdc++.h>
using namespace std;
// 高速化
void fast_io() { ios::sync_with_stdio(false); cin.tie(nullptr); }
```

**Python**
```python
import sys
# 高速化
input = lambda: sys.stdin.readline().rstrip()
```
:::

---

## 1. 基本：変数・配列の読み込み

### A. 少数・単独の変数（ABC-A問題レベル）
| 問題文の形式 | C++ 実装 | Python 実装 |
| :--- | :--- | :--- |
| `N M` | `int n, m; cin >> n >> m;` | `N, M = map(int, input().split())` |
| `S` (文字列) | `string s; cin >> s;` | `S = input()` |

### B. 数列・リスト（ABC-B問題レベル）
| 問題文の形式 | C++ 実装 | Python 実装 |
| :--- | :--- | :--- |
| `A1 A2 ... An` | `vector<int> a(n);`<br>`for(int &x:a) cin >> x;` | `A = list(map(int, input().split()))` |
| `A1`<br>`A2`<br>`...`<br>`An` | `vector<int> a(n);`<br>`for(int &x:a) cin >> x;` | `A = [int(input()) for _ in range(N)]` |

---

## 2. 応用：ペア・行列・グラフ

### C. 縦に並ぶペア（辺のリスト，座標など）
| 問題文の形式 | C++ 実装 | Python 実装 |
| :--- | :--- | :--- |
| `U1 V1`<br>`U2 V2`<br>`...`<br>`Um Vm` | `for(int i=0; i<m; ++i) {`<br>&nbsp;&nbsp;`int u, v; cin >> u >> v;`<br>&nbsp;&nbsp;`// グラフなら G[u-1].push_back(v-1); など`<br>`}` | `for _ in range(M):`<br>&nbsp;&nbsp;`u, v = map(int, input().split())`<br>&nbsp;&nbsp;`# G[u-1].append(v-1) など` |

### D. 2次元グリッド（迷路・地図）
| 問題文の形式 | C++ 実装 | Python 実装 |
| :--- | :--- | :--- |
| `S1`<br>`S2`<br>`...`<br>`Sh` (各行W文字) | `vector<string> s(h);`<br>`for(string &x:s) cin >> x;` | `S = [input() for _ in range(H)]` |
| `A11 ... A1w`<br>`...`<br>`Ah1 ... Ahw` | `vector a(h, vector<int>(w));`<br>`for(auto &r:a) for(int &x:r) cin >> x;` | `A = [list(map(int, input().split())) for _ in range(H)]` |

---

## 3. 実践ケーススタディ：AtCoderの典型例

### ① 連結成分・最短経路の入力（グラフ）
```text
N M
U1 V1
...
Um Vm
```
:::flex
**C++**
```cpp
int n, m; cin >> n >> m;
vector<vector<int>> g(n);
for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    --u; --v; // 0-indexed化
    g[u].push_back(v);
    g[v].push_back(u);
}
```

**Python**
```python
N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    u, v = map(int, input().split())
    G[u-1].append(v-1)
    G[v-1].append(u-1)
```
:::

### ② クエリ形式の入力
```text
Q
T1 X1 (Y1)
...
Tq Xq (Yq)
```
:::flex
**C++**
```cpp
int q; cin >> q;
while (q--) {
    int type; cin >> type;
    if (type == 1) {
        int x, y; cin >> x >> y;
        // クエリ1の処理
    } else {
        int x; cin >> x;
        // クエリ2の処理
    }
}
```

**Python**
```python
Q = int(input())
for _ in range(Q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        x, y = query[1], query[2]
        # クエリ1の処理
    else:
        x = query[1]
        # クエリ2の処理
```
:::

---

## 4. 逆引き：知っておくと得するテクニック

### 数字が繋がっている入力（`12345`）をバラで受け取る
- **C++**: `char` で1文字ずつ読む，または `string` で受けて `s[i] - '0'` とする．
- **Python**: `list(input())` で文字列リストにし，`map(int, ...)` を適用する．

### 入力行数が不明な場合（EOF）
- **C++**: `while (cin >> x)`
- **Python**: `import sys; for line in sys.stdin:`

---

## 5. まとめ：ミスのない入力のために
- **C++**: `cin` は空白・改行を無視する性質がある．「1行に並んでいるか」「複数行か」をあまり気にしなくてよい．
- **Python**: 逆に `input().split()` は「1行の中身」を対象とするため，行数分だけループを回す必要がある．
- **共通**: 座標や頂点番号が「1から始まる（1-indexed）」場合は，受け取り時に `-1` して内部で扱いやすくする癖をつける．

#競技プログラミング #AtCoder #C++ #Python #Qiita
