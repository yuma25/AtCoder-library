# 競技プログラミング：アルゴリズム百科事典

このリポジトリは，競技プログラミング（AtCoder等）で必要となるテンプレート，データ構造，アルゴリズムを網羅的にまとめた完全ガイドである．

---

## 🚀 テンプレートと基本解説
まずはここから！環境構築と基本操作の解説である．

- [AtCoder 完全自動化環境 構築ガイド](./tools/setup_guide.md)
- [AtCoder 自動化環境 使い方ガイド](./tools/usage_guide.md)
- [競技プログラミング：コンテナ選択ガイド](./docs/container_guide.md)
- [AtCoder「入力形式別」即戦力コードスニペット集](./docs/input_snippets.md)

---

## ⚡ コマンドリファレンス (逆引き・チートシート)

### 1. コンテスト・問題操作（基本フロー）
```bash
# ① ABCディレクトリへ移動
cd ~/github/atcoder-library/ABC

# ② コンテストの問題＆テストケースをダウンロードして準備
acc new abc350             # デフォルト言語(C++)で作成
acc new abc350 --template python  # Pythonで作成する場合

# ③ 問題ディレクトリへ移動 (例: A問題)
cd abc350/a

# ④ サンプルケースで自動テスト
atest      # C++用 (コンパイル + ojテスト)
atest-py   # Python用 (ojテスト)

# 【手動実行・デバッグ】手入力で直接実行したい場合
g++ -std=c++20 -O2 -Wall -Wextra -DLOCAL main.cpp -o a.out && ./a.out

# ⑤ 提出
acc submit
```


### 2. テンプレートファイルの更新
`templates/` 配下のテンプレートを修正後、`atcoder-cli` の自動展開先へ反映させるコマンド：
```bash
# C++ のテンプレートを反映
cp ~/github/atcoder-library/templates/Template.cpp ~/.config/atcoder-cli-nodejs/cpp/main.cpp

# Python のテンプレートを反映
cp ~/github/atcoder-library/templates/Template.py ~/.config/atcoder-cli-nodejs/python/main.py
```

### 3. デフォルト言語の切り替え
```bash
# C++ をデフォルトに設定
acc config default-template cpp

# Python をデフォルトに設定
acc config default-template python
```

### 4. ログイン・セッション確認
```bash
# atcoder-cli のログイン確認
acc login

# online-judge-tools のログイン確認
oj login --check https://atcoder.jp/
```

### 5. 便利コマンド（エイリアス）の再読み込み
```bash
# .bashrc の変更を即時反映
source ~/.bashrc
```

---

## 🛠️ VS Code スニペット
VS Code のユーザースニペット（`snippets/cpp.json`, `snippets/python.json`）を登録することで、コーディング中にプレフィックス（接頭辞）を入力して `Tab` または `Enter` を押すだけで、定番の型定義やアルゴリズムの雛形を瞬時に呼び出すことができます。

- [C++ 用スニペット定義ファイル](./snippets/cpp.json)
- [Python 用スニペット定義ファイル](./snippets/python.json)

### 主なスニペット一覧 (Prefix)

| Prefix | 呼び出されるコード・機能 | 対象言語 |
| :--- | :--- | :--- |
| `inp_i` / `inp_mi` | 単一変数 / 複数変数の入力 | C++ / Python |
| `inp_v1` / `inp_li` | 1次元配列（vector / list）の入力 | C++ / Python |
| `inp_v2` / `inp_col` | 2次元配列 / 縦並び整数の入力 | C++ / Python |
| `inp_grid` | グリッド文字列の入力 | C++ / Python |
| `inp_graph` | グラフ隣接リスト（0-indexed）の入力 | C++ / Python |
| `v1` / `l1` | 1次元配列の初期化宣言（vector / list） | C++ / Python |
| `v2` / `l2` | 2次元配列の初期化宣言（vector / list） | C++ / Python |
| `pqmax` / `pqmin` | 優先度付きキュー（最大値 / 最小値）の宣言 | C++ |
| `set_init` / `map_init` | `set` / `map` の基本宣言 | C++ |
| `binsearch` | 二分探索テンプレート（判定問題用 `ok` / `ng`） | C++ / Python |
| `bfs` / `gridbfs` | グラフ / 2次元グリッドの幅優先探索（最短経路） | C++ / Python |
| `dijkstra` | 単一始点最短経路（ダイクストラ法） | C++ / Python |
| `unionfind` | 素集合データ構造（Union-Find / DSU） | C++ / Python |
| `combination` | 二項係数 $n\text{C}r$ 高速計算クラス・構造体 | C++ / Python |
| `compression` | 座標圧縮 | C++ / Python |
| `rle` | ランレングス圧縮（連程圧縮） | C++ / Python |
| `primefactor` / `divisors`| 素因数分解 / 約数列挙 | C++ / Python |
| `segtree_max` | ACL セグメント木（区間最大値）定義 | C++ |
| `lazy_segtree_add_min` | ACL 遅延セグメント木（区間加算・区間最小値）定義 | C++ |
| `cp` / `pycp` | 競技プログラミング用フルテンプレート展開 | C++ / Python |

### スニペットの登録方法
1. VS Code で `Ctrl + Shift + P`（Mac: `Cmd + Shift + P`）を開く
2. `Preferences: Configure User Snippets`（基本設定: ユーザースニペットの構成）を選択
3. `cpp.json` または `python.json` を開き、上記ファイルの内容をコピー＆ペーストして保存




