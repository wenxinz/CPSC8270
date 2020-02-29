def f(x):
  if x>1 :
    return x*f(x-1)
  else:
    return 1

print f(6)
