def f(x):
    print x

f(5)

def f(x):
    x=x**2
    print x

f(6)

def f(x):
    return x

print f(3)

def f(x):
    if x>5:
        print 1
    else:
        print 0

f(6)

def f(x):
    if x>=5:
        print 1
    else:
        print 0

f(6)

def f(x):
    if x<5:
        print 1
    else:
        print 0

f(6)

def f(x):
    if x<=5:
        print 1
    else:
        print 0

f(6)

def f(x):
    if x==5:
        print 1
    else:
        print 0

f(6)

def f(x):
    i=j=k=z=y=x
    print j

f(7)

def f(x):
    if x:
        print 1
    else:
        print 0

f(1)

def f(x):
    if x<0:
        return x
    else:
        x=-x
        return x

print f(-5)
print f(6)

def jlaskdfj_jasld_fj(x):
    if x == 1:
        print 100
    if x:
        print 1
        return x
    else:
        print 0

print jlaskdfj_jasld_fj(5)

def f(x):
    y = z = 7.0
    i = 5
    if x == z:
        return x
    if y > i:
        return i

print f(9.0)

def f(x):
    y = z = 7.0
    i = 5
    if x >= z:
        return x
    if y < i:
        return i

print f(8.12764983754)
    
def f(x):
    z = 7.0
    i = 5
    y=x-z*2.372
    if x == z:
        return x
    if y > i:
        return i

print f(5892.8873923e-3)

def f(x):
    return x
    
print f(73892.8873923e-3)

def f(x,y,z):
    i = j = k = 5
    if x > i:
        if y > j:
            if z > k:
                print i*x
                print j*y
                print k*z

f(7,9,34)

def f(x,y,z):
    i = j = k = 5
    if x < i:
        if y < j:
            if z < k:
                print i*x
                print j*y
                print k*z

f(-13.87761,0.89122,-9.90121)

def f(x,y,z):
    i = j = k = 5
    if x < i:
        if y == j:
            if z < k:
                print i*x
                print j*y
                print k*z

f(-13.87761,5,-9.90121)

def f(x,y,z,i,j,k):
    x = y = z = 60.0
    i = j = k = 5
    if x > i:        
        if y < j:
            if z > k:
                print i*x
        else:
            print i**x

f(60.0,72.17923,98.23732,0.1721,8.7732,0.123712)

def f(x,y,z,i=42.54,j=52.4,k=5.2):
    x = y = z = 60.0
    i = j = k = 5
    if x > i:        
        if y < j:
            if z > k:
                return i*x
        else:
            return i**x

print f(2,92.17123923,989.23732,i=1.1721,k=88.7732,j=0.12371781232)

def foo_bar(x):
    print 555
    def foobar():
       y=6
       print y*6
       def foo__bar():
           z=75
           if x<z:
               print 1
    foobar()
    

foo_bar(7.6)

def foo_bar():
    x=550
    print 555
    def foobar():
       y=6
       print y*6
       def fbar():
           z=75
           if x<z:
               print 1
    foobar()

foo_bar()

def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n-1)

factorial(7)

def rec1(x):
    if x>1:
        return x - rec1(x-1)
    else:
        return x

print rec1(748)


def f(x):
    def g():
        y=2
        def h():
            z=3
            print x+y+z
        h()
    g()

f(77.84902)

def f(x):
    def g(y):
        def h(z):
            if z<1:
                print x*y**z
            else:
                print x**y**z
        h(2)
    g(3)


f(8.888)

def f(x):
    def g(y):
        k=7*y
        def h(z):
            if z<1:
                i=x*y**z
                return i
            else:
                j=y**y**z
                return j
        print h(3.71293)
    g(2.3472)

f(1.093284)

def rec0(x):
    def rec1(y):
        if y>1:
            return x - rec1(y-1)
        else:
            return y-x
    rec1(1-rec0(x))

print rec1(938)

def foo_bar(x=600):
    print 111
    def foobar():
       y=600
       print y*6
       if x<50:
           print 0
       else:
           return x
    print foobar()
    
foo_bar()

def foo_bar(x=600):
    print 111
    def foobar():
       y=600
       print y*6
       if x<50:
           print 0
       else:
           return x
    print foobar()
    
foo_bar(700)

def foo_bar(x,y=9.346723,z=4.237293):
    print 111
    def foobar():
       y=600
       print y*6-x+z
       if x<50:
           print 0
       else:
           return x
    print foobar()
    
foo_bar(78.883)

def f(x=1):
    def g(y=2):
        k=7*y
        def h(z=3):
            if z<1:
                i=x*y**z
                return i
            else:
                j=y**y**z
                return j
        print h()
    g()

f()

def f(y=82.7129):
    z = x = y
    return rec1(z)

print f(788.8894293e-1)
