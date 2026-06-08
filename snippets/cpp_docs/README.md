# C++ スニペット解説

このディレクトリでは、`snippets/CPPスニペット.json` に登録されている各スニペットの詳細な使い方と処理内容を解説します。

## スニペット一覧

1.  **[Competitive Programming Template Complete (cp)](#1-competitive-programming-template-complete-cp)**
    - 競技プログラミングの基本テンプレートと、標準ライブラリのチートシート。

---

## 1. Competitive Programming Template Complete (cp)
**プレフィックス:** `cp`

競技プログラミングを開始する際のベースとなるテンプレートです。

### 構成要素
- **型エイリアス**: `ll` (long long), `vi` (vector<int>) などの短縮型。
- **定数**: `INF`, `MOD` (998244353), `dx/dy` (方向配列)。
- **マクロ**: `rep(i, n)` (0からn-1までのループ), `all(v)` (v.begin(), v.end())。
- **入出力高速化**: `FastIO` 構造体により `cin/cout` を高速化。
- **便利関数**: `chmax(a, b)`, `chmin(a, b)` (値を更新しつつ成否を返す)。
- **オーバーロード**: `vector` や `pair` を直接 `cin >> v` や `cout << v` できるように拡張。
- **デバッグ**: `LOCAL` マクロが有効な場合のみ `debug(x)` で標準エラー出力。
- **数学関数**: `pow_mod` (繰り返し二乗法), `inv_mod` (逆元), `Combination` 構造体 (nCr)。
- **チートシート**: 文末のコメントに主要な標準ライブラリ（vector, set, priority_queue等）の計算量と使い方がまとめられています。

### 使い方
VS Codeで `cp` と入力して補完を確定させると、これらすべてが含まれたコードが展開されます。
