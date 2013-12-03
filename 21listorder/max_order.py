# 配列に負でない整数が格納されている。
# これらの整数の中から大きい順に3つの数字とその添字を出力せよ

arr = [12, 6, 8, 3, 10, 1, 0, 9]

a = zip(range(len(arr)), arr)
a.sort(cmp=lambda x,y: cmp(x[1], y[1]), reverse=True)
print('\n'.join('%d -> %d' % (x, y) for x, y in a[:3]))

# 0 -> 12
# 4 -> 10
# 7 -> 9
