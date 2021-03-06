#!/usr/bin/python

import os, sys
import fnmatch
import subprocess
import filecmp

def testCode( retcode, msg ):
  if retcode > 0:
    print msg
    sys.exit( 1 )

def checkResult(myres, stdres):
   infile1 = open(stdres, 'r')
   standard = []
   for line in infile1:
     words = line.split();
     standard.append(words[0])
   infile1.close() 
   stdlength = len(standard) 
   
   infile2 = open(myres, 'r')
   i = 0
   for line in infile2:
     if(i > stdlength) : 
       return False
     words = line.split()
     if(words[1] != standard[i]) :
       if(words[0] == "INT") :
          return False
       elif(words[0] == "FLOAT") :
          if(abs(float(words[1])-float(standard[i])) > 0.0001) :
           return False
     i += 1
   if( i != stdlength) :
     return False
   infile2.close()

   return True

testDir = os.path.join( os.getcwd(), 'cases')
if not os.path.isdir( testDir ):
  print testDir, "isn't a directory"
  sys.exit( 1 )

executable = os.path.join(os.getcwd(), "run")
if not os.path.isfile( executable ):
  retcode = subprocess.call("make",shell=True)
  testCode( retcode, "\tFAILED to make the scanner" )

files = os.listdir( testDir )
for x in files:
  if fnmatch.fnmatch(x, "*.py"):
    testcase = os.path.join(testDir, x)
    output = testcase[:-3]+".out"
    retcode = subprocess.call("./run < "+testcase+"> "+output,shell=True)
    if retcode != 0:
      testCode( retcode, "\tFAILED to run test case "+x)
    else:
      retcode = subprocess.call("python "+testcase+"> /tmp/out",shell=True)
      if not os.path.isfile( output ):
        print "test case", x[:-3]+'.out', "doesn't exist"
        sys.exit( 1 )
      #if not filecmp.cmp("/tmp/out", output): 
      if not checkResult(output,"/tmp/out") :
        print "\tTEST CASE FAILED", x
      else :
        print "testcase:", x, "passed"


