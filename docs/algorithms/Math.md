# 数学 (Mathematics)

## 1. 素数判定・約数列挙
### 【概要】
ある数 $N$ が素数か判定したり、約数をすべてリストアップします。 $O(\sqrt{N})$ で計算可能です。

### 【実装例 (C++)】
```cpp
// 約数列挙
vl get_divisors(ll n) {
    vl res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.pb(i);
            if (i * i != n) res.pb(n / i);
        }
    }
    sort(all(res));
    return res;
}
```

---

## 2. べき乗 (pow_mod)
### 【概要】
$a^n \pmod{M}$ を高速に求めます。

### 【仕様】
- **引数**: 底 $a$, 指数 $n$, 法 $M$
- **計算量**: $O(\log n)$
- **実装**: `Template.cpp` の `pow_mod` を参照。

---

## 3. 組合せ (Combination)
### 【概要】
$nCr \pmod{MOD}$ を求めます。

### 【実装例】
```cpp
Combination comb(200000);
ll ans = comb.nCr(n, r);
```
- **事前計算**: $O(N)$
- **取得**: $O(1)$
