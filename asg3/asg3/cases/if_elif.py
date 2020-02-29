def h(x):
  if x < 0:
    return 0.0
  elif 0 <= x < 1:
    return x
  elif 1 <= x < 2:
    return 2-x
  elif x > 2:
    return 0.0

def g(x,y):
   for x in range(8):
      if y < 4:
        print x+y;
      else:
        print y*x;
  

h(3)
g(8,13) 


