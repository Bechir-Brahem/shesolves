#!/bin/python3
import sys
import os
import timeit

print("execution started...")
print("------------------------")
os.system("rm output")
os.system("touch output")
n = int(input())
for t in range(1, n+1):
        testcase = input()
        print(t, testcase)
        start = timeit.default_timer()
        os.system("echo \""+testcase+"\"| ./do >> output")
        #  os.system("echo \"\" >> output")
        stop = timeit.default_timer()
        print("time for this test",stop-start)
        if(stop-start > 3):
            print("TLE in test", t)
            exit(0)


print("execution finsished")
print("------------------------")
