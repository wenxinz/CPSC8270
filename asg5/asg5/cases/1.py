def f():
  x = 5.23
  y = 9
  def g():
    x = 8.92
    return x+y
  if(x>y):
    print x
  else:
    y = g()
  print y

f()
