def f():
  print x

def g():
  x = 10
  def f():
    print x
  def h():
    x = 12
    f()
  h()

x = 5
g()
