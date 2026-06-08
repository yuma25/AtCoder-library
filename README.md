# 競技プログラミング：アルゴリズム百科事典

このレポジトリは、競技プログラミング（AtCoder等）で必要となるテンプレート、データ構造、アルゴリズムを網羅的にまとめた完全ガイドです。

---

## 🚀 テンプレートと基本解説
まずはここから！環境構築と基本操作の解説です。

- [AtCoder 完全自動化環境 構築ガイド](./tools/環境構築ガイド.md)
- [AtCoder 自動化環境 使い方ガイド](./docs/使い方ガイド.md)
- [C++ 最強スニペット解説 (cp)](./snippets/cpp_docs/README.md)
- [Python 最強スニペット解説 (pycp)](./snippets/python_docs/README.md)
- [競技プログラミング：コンテナ選択ガイド](./docs/containers_guide/README.md)
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

## 🛠️ VS Code スニペット
以下のファイルの内容を VS Code の「ユーザースニペット」に登録することで、`cp` や `pycp` などのキーワードで最強テンプレートを瞬時に呼び出せます。

- [C++ 用スニペット](./snippets/CPPスニペット.json)
- [Python 用スニペット](./snippets/Pythonスニペット.json)
