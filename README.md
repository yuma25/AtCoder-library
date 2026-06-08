# 競技プログラミング：アルゴリズム百科事典

このレポジトリは、競技プログラミング（AtCoder等）で必要となるテンプレート、データ構造、アルゴリズムを網羅的にまとめた完全ガイドです。

---

## 🚀 テンプレートと基本解説
まずはここから！環境構築と基本操作の解説です。

- [AtCoder 完全自動化環境 構築ガイド](./tools/環境構築ガイド.md)
- [AtCoder 自動化環境 使い方ガイド](./docs/使い方ガイド.md)
- [C++ 最強テンプレート解説](./docs/CPP解説.md)
- [Python 競技プログラミングテンプレート解説](./docs/Python解説.md)

---

## ⚡ 基本ワークフロー (クイックコマンド)
コンテスト中に最も頻繁に使用するコマンドです。

### 1. 問題の取得
```bash
# ABCディレクトリへ移動
cd ABC

# 例: ABC350 の全問題をダウンロード
acc new abc350
cd abc350/a
```

### 2. サンプルテスト
```bash
# 自動でコンパイルしてサンプルケースを検証 (エイリアス設定済み)
atest
```

### 3. コードの提出
```bash
# テストが通ればそのまま提出
acc submit
```

---

## 📚 アルゴリズム・データ構造 詳細解説
各リンク先では、**「概要」「実装例」「引数・戻り値」「具体的な処理の流れ」**を詳しく解説しています。

### 1. [全探索 (Exhaustive Search)](./docs/algorithms/Search.md)
- ビット全探索, 順列全探索, DFS/BFS による全探索

### 2. [数学 (Mathematics)](./docs/algorithms/Math.md)
- 素数判定, 約数列挙, 素因数分解, べき乗, 組合せ(nCr)

### 3. [動的計画法 (Dynamic Programming)](./docs/algorithms/DP.md)
- ナップサックDP, ビットDP, 桁DP, 区間DP

### 4. [グラフ・木 (Graph & Tree)](./docs/algorithms/Graph.md)
- ダイクストラ法, ベルマンフォード法, Union-Find, LCA, 木の直径

### 5. [データ構造 (Data Structures)](./docs/algorithms/DataStructures.md)
- セグメント木, Binary Indexed Tree (BIT)

### 6. [重要テクニック (Techniques)](./docs/algorithms/Techniques.md)
- 二分探索, 累積和, 座標圧縮, ダブリング, 半分全列挙

---

## 🛠️ VS Code スニペット
以下のファイルの内容を VS Code の「ユーザースニペット」に登録することで、`cp` や `pycp` などのキーワードで最強テンプレートを瞬時に呼び出せます。

- [C++ 用スニペット](./snippets/CPPスニペット.json)
- [Python 用スニペット](./snippets/Pythonスニペット.json)
