import sys
import math
import bisect
import itertools
import collections
import heapq

# --- 再帰上限の引き上げ (Pythonで競技プログラミングをする際の必須設定) ---
sys.setrecursionlimit(10**7)

# --- 定数 ---
INF = 10**18
MOD = 998244353
MOD_OLD = 10**9 + 7
dx = [0, 1, 0, -1, 1, 1, -1, -1]
dy = [1, 0, -1, 0, 1, -1, 1, -1]

# --- 入出力高速化 ---
# sys.stdin.readline を使うことで、Pythonの遅い input() を高速化します
input = lambda: sys.stdin.readline().rstrip()
# 文字列の入力
sinput = lambda: sys.stdin.readline().rstrip()
# 1つの整数を入力
I = lambda: int(input())
# 複数整数の入力 (例: A B C = MI())
MI = lambda: map(int, input().split())
# リストとして入力 (例: A = LI())
LI = lambda: list(map(int, input().split()))

# --- 便利関数 ---
def chmax(a, b):
    """aとbを比較し、bの方が大きければbを返す。Pythonでは値渡しのため、a = chmax(a, b) のように使う"""
    return b if a < b else a

def chmin(a, b):
    """aとbを比較し、bの方が小さければbを返す。a = chmin(a, b) のように使う"""
    return b if a > b else a

# --- 数学・アルゴリズム集 ---
# 繰り返し二乗法 (Pythonでは組み込みの pow(a, n, m) が最速で提供されています)
# pow_mod = lambda a, n, m=MOD: pow(a, n, m)

class Combination:
    """O(N)で前計算し、nCr を O(1) で求めるクラス"""
    def __init__(self, n, mod=MOD):
        self.mod = mod
        self.fact = [1] * (n + 1)
        self.inv = [1] * (n + 1)
        for i in range(1, n + 1):
            self.fact[i] = (self.fact[i - 1] * i) % mod
        
        # 逆元はフェルマーの小定理で計算
        self.inv[n] = pow(self.fact[n], mod - 2, mod)
        for i in range(n - 1, -1, -1):
            self.inv[i] = (self.inv[i + 1] * (i + 1)) % mod

    def nCr(self, n, r):
        if r < 0 or n < r:
            return 0
        return self.fact[n] * self.inv[r] % self.mod * self.inv[n - r] % self.mod

# --- メイン処理 ---
def main():
    # ここにコードを記述
    pass

if __name__ == '__main__':
    main()

'''
==============================================================================
  【Python 標準ライブラリ・操作 完全チートシート】
==============================================================================

[1] リスト (list) / 文字列 (str) [C++の vector / string 相当]
------------------------------------------------------------------------------
  len(A)         : O(1) 要素数
  A.append(x)    : O(1) 末尾追加
  A.pop()        : O(1) 末尾削除
  A.pop(i)       : O(N) i番目を削除 (先頭削除は A.pop(0) だが遅いので deque を使う)
  A.sort()       : O(N log N) 昇順ソート (破壊的、Noneを返す)
  A.sort(reverse=True) : 降順ソート
  sorted(A)      : O(N log N) 昇順ソートした新しいリストを返す
  A.reverse()    : O(N) 反転 (破壊的)
  A[::-1]        : O(N) 反転した新しいリストを返す
  A.count(x)     : O(N) xの個数
  S.find(str)    : 見つかったインデックスを返す。なければ -1
  S[pos:pos+len] : 部分文字列 (スライス)

[2] デック (collections.deque)
------------------------------------------------------------------------------
  from collections import deque
  dq = deque(A)
  dq.append(x)     : O(1) 末尾追加
  dq.appendleft(x) : O(1) 先頭追加
  dq.pop()         : O(1) 末尾削除
  dq.popleft()     : O(1) 先頭削除

[3] 辞書 (dict) / 集合 (set) [C++の map / set 相当]
------------------------------------------------------------------------------
  # pythonのdict/setはハッシュテーブル(O(1))であり、平衡二分探索木(O(log N))ではない
  S = set()
  S.add(x)       : O(1) 追加
  S.discard(x)   : O(1) 削除 (なければ何もしない)
  x in S         : O(1) 存在判定
  
  D = dict()     # または D = {}
  D[key] = val   : O(1) 追加・更新
  val = D.get(k, 0): キーkがなければデフォルト値0を返す (安全なアクセス)

  # defaultdict (キーが存在しない場合のデフォルト値を設定できる)
  from collections import defaultdict
  D = defaultdict(int) # アクセス時になければ 0 になる

[4] 優先度付きキュー (heapq) [C++の priority_queue 相当]
------------------------------------------------------------------------------
  import heapq
  hq = []
  heapq.heappush(hq, x) : O(log N) 追加
  heapq.heappop(hq)     : O(log N) 最小値を取り出して削除
  hq[0]                 : O(1) 最小値を参照
  heapq.heapify(A)      : O(N) 既存のリストAをヒープ化
  # ※Pythonのheapqは「最小値」を取り出す (C++の MinPQ 相当)。
  # 最大値を取り出したい場合は要素に -1 を掛けて push / pop する。

[5] 二分探索 (bisect) [C++の lower_bound / upper_bound 相当]
------------------------------------------------------------------------------
  import bisect
  # Aはソート済みであること
  bisect.bisect_left(A, x)  : O(log N) x以上の最初の要素のインデックス (lower_bound)
  bisect.bisect_right(A, x) : O(log N) xより大きい最初の要素のインデックス (upper_bound)

[6] 順列・組合せ (itertools) [C++の next_permutation 相当]
------------------------------------------------------------------------------
  import itertools
  itertools.permutations(A)    : Aの要素の順列をすべて生成
  itertools.combinations(A, r) : Aからr個選ぶ組合せをすべて生成
  # 使い方: for p in itertools.permutations(A): print(p)

[7] 数学 (math) / その他
------------------------------------------------------------------------------
  import math
  math.gcd(a, b) : 最大公約数
  math.lcm(a, b) : 最小公倍数 (Python 3.9+)
  sum(A)         : Aの要素の合計 (C++のaccumulate)
  max(A) / min(A): 最大値 / 最小値

==============================================================================
'''