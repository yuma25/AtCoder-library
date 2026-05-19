# 動的計画法 (Dynamic Programming)

## 1. ナップサックDP
### 【概要】
重さ $W$ 以下の制限で、価値の合計を最大化します。

### 【実装の流れ】
1.  `dp[i][j]`: $i$ 番目までの品物を使って、重さの合計が $j$ のときの最大価値。
2.  更新式: `chmax(dp[i+1][j], dp[i][j])` (選ばない), `chmax(dp[i+1][j+w], dp[i][j] + v)` (選ぶ)。

---

## 2. ビットDP (Traveling Salesman Problem等)
### 【概要】
「どの集合を訪問済みか」をビットで管理します。

### 【実装例 (C++)】
```cpp
// dp[集合][現在の頂点]
vvi dp((1 << n), vi(n, INF_INT));
rep(bit, (1 << n)) {
    rep(v, n) {
        if (!(bit & (1 << v))) continue;
        rep(u, n) {
            if (bit & (1 << u)) continue;
            chmin(dp[bit | (1 << u)][u], dp[bit][v] + cost[v][u]);
        }
    }
}
```
- **計算量**: $O(2^N \cdot N^2)$

---

## 3. 桁DP
### 【概要】
「$N$ 以下の整数で、条件を満たすものの個数」を上の桁から順に求めます。
- `dp[digit][less][condition]` : $less$ フラグ（既に $N$ より小さいことが確定しているか）が重要。
