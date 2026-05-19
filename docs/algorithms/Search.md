# 全探索 (Exhaustive Search)

## 1. ビット全探索 (Bit Brute-force Search)
### 【概要】
$2^N$ 通りの組み合わせ（要素を「選ぶ」か「選ばない」か）をすべて調べる手法です。

### 【実装例 (C++)】
```cpp
// N 個の要素から選ぶ組み合わせを全列挙
rep(bit, (1 << n)) {
    rep(i, n) {
        if (bit & (1 << i)) {
            // i 番目の要素を選んだ場合の処理
        }
    }
}
```

### 【仕様】
- **引数**: 要素数 $N$
- **計算量**: $O(N \cdot 2^N)$
- **使いどころ**: $N \le 20$ 程度で、すべての組み合わせを試したいとき。

---

## 2. 順列全探索 (Permutation Search)
### 【概要】
$N!$ 通りの並び順をすべて調べる手法です。

### 【実装例 (C++)】
```cpp
sort(all(a)); // 事前にソートが必要
do {
    // a は現在の順列
} while (next_permutation(all(a)));
```

### 【仕様】
- **引数**: 配列 $A$
- **戻り値**: `bool` (次の順列があれば `true`)
- **使いどころ**: $N \le 10$ 程度で、巡回セールスマン問題の全探索などに。

---

## 3. DFSによる全探索
### 【概要】
再帰関数を用いて、決定木を下るように探索します。

### 【実装例 (Python)】
```python
def dfs(pos, current_sum):
    if pos == n:
        return current_sum == target
    # 選ぶ場合
    if dfs(pos + 1, current_sum + a[pos]): return True
    # 選ばない場合
    if dfs(pos + 1, current_sum): return True
    return False
```
