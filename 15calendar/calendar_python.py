import sys
from calendar import *
from datetime import *
y = int(raw_input('input year: '))
m = int(raw_input('input month: '))
w = ' Mo Tu We Th Fr Sa Su'
D = monthrange(y, m)[1] # last day of the month
F = weekday(y, m, 1)
s = '   ' * (F+1) + '  '.join(map(str,range(1, 10))) + ' ' + ' '.join(map(str,range(10,D+1)))
sys.stdout.write(w)
for i, e in enumerate(s):
  sys.stdout.write(e)
  if i % len(w) == 0 or i+1 == len(s): print
