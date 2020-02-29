#python function test cases

## baic fxn with return 

def f():
    x = 111
    return x

print f()

def f():
    x = y = z = 222
    return z

print f()

def fasdfa():
    x = 333
    return x

print fasdfa()

def fas_dfa():
    x = 444
    return x

print fas_dfa()

def f():
    x = 001
    return 

print f()

def f():
    x = 005
    return x**2

print f()

def f():
    x = 005
    return x*2

print f()

def f():
    x = 005
    return x-2

print f()

def f():
    x = 005
    return x+2

print f()

def f():
    x = 5.0
    return x/2

print f()

def f():
    x = 5.0
    if x == 5:
        return x

print f()

def f():
    x = 5.0
    if x < 5:
        return x

print f()

def f():
    x = 5.0
    if x > 5:
        return x

print f()

def f():
    x = 5.0
    if x != 5:
        return x

print f()

def f():
    x = 5.0
    if x <= 5:
        return x

print f()

def f():
    x = 5.0
    if x >= 5:
        return x

print f()

def f():
    x = 5.0
    if x == 6:
        return x

print f()

def f():
    x = 5.0
    if x == 6:
        print 62
    return x

print f()

def f():
    x = 5.0
    if x == 5:
        print 62
    if x:
        print 1
    else:
        print 0
    return x

print f()

def f():
    x = 5.0
    if x == 6:
        print 62
    if x:
        print 1
        return x
    else:
        print 0


print f()

def jlaskdfj_jasld_fj():
    x = 1.0
    if x == 1:
        print 100
    if x:
        print 1
        return x
    else:
        print 0


print jlaskdfj_jasld_fj()
print 100

def f():
    x = 5.0
    if x == 6:
        print 62
    if x:
        print 1
    else:
        print 0


f()

def f():
    x = 5.0
    if x == 5:
        print 555
    if x:
        print 1
    else:
        print 0


f()

def f():
    x = y = z = 7.0
    if x == z:
        print 777
    if x:
        print 1
    else:
        print 0


f()

def f():
    x = y = z = 7.0
    i = 5
    if x == z:
        print 777
    if y > i:
        print 57575

f()

def f():
    x = y = z = 7.0
    i = 5
    if x == z:
        return x
    if y > i:
        return i

print f()

def f():
    x = y = z = 7.0
    i = 5
    if x == z:
        return x
    if y < i:
        return i

print f()

def f():
    x = y = z = 7.0
    i = 5
    if x <= z:
        return x
    if y < i:
        return i

print f()

def f():
    x = y = z = 7.0
    i = 5
    if x < z:
        return x
    if y < i:
        return i

print f()

def f():
    x = y = z = 7.0
    i = 5
    if x >= z:
        return x
    if y < i:
        return i

print f()

def f():
    x = y = z = 7.0
    i = 5
    if x > z:
        return x
    if y < i:
        return i

print f()

def f():
    x = y = z = 7.0
    i = 5
    if x > i:
        if y < i:
            print i

f()

def f():
    x = y = z = 7.0
    i = 5
    if x > i:
        if y > i:
            print i*x

f()

def f():
    x = y = z = 6.0
    i = j = k = 5
    if x > i:
        if y > j:
            if z > k:
                print i*x

f()

def foo_bar():
    x=5
    print 555
    def foobar():
       y=6
       print y*6
       def foo__bar():
           z=75
           if x<z:
               print 1
    foobar()
    

foo_bar()

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

def foo_bar():
    x=676
    print 111
    def foobar():
       y=500
       print y*6
    
foo_bar()


def foo_bar():
    x=676
    print 111
    def foobar():
       y=600
       print y*6
       if x>50:
           return x
    print foobar()
    
foo_bar()

def foo_bar():
    x=5000
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

def foo_bar():
    x=5000
    print 111
    def foobar():
       y=600
       print y*6
       if x==5000:
           print 0
       else:
           return x
    print foobar()
    
foo_bar()


def f():
    def g():
        def h():
            print 1111111
        h()
    g()

f()

def f():
    x=1
    def g():
        y=2
        def h():
            z=3
            print x+y+z
        h()
    g()

f()


def f():
    x=1
    def g():
        y=2
        def h():
            z=3
            if z>1:
                print x*y**z
        h()
    g()

f()

def f():
    x=1
    def g():
        y=2
        def h():
            z=3
            if z<1:
                print x*y**z
            else:
                print x**y**z
        h()
    g()


f()

def f():
    x=1
    def g():
        y=2
        k=7*y
        #return x
        def h():
            z=3
            if z<1:
                i=x*y**z
                return i
            else:
                j=y**y**z
                return j
        print h()
    g()

f()
