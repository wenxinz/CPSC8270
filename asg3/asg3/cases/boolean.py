
def f():
  for x in range(10):
    for y in range(26):
      if x < 3 and y > 9:
        print y-x
      elif x < 6 or y > 5:
        print x+y

def g(n):
  x = 0
  while x < n:
    if x < 3 and n > 5:
      print x
    else:
      print x+1
    x += 1

f()
g(3)

