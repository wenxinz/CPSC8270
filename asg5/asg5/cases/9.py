def f():
  print x

def g():
  x = 10
  def f():
    print x
  f()

x = 5
g()
