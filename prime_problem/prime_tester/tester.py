#!/bin/python3
import sys
import subprocess
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
        try:
            subprocess.run(
                ["bash", "/home/bachra/Desktop/test_run/x.sh", testcase], timeout=3)
        except subprocess.TimeoutExpired:
            stop = timeit.default_timer()
            print("TLE in test", t," time=",stop-start)
            exit(0)

        stop = timeit.default_timer()
        print("time for this test",stop-start)
        if(stop-start > 3):
            print("TLE in test", t)
            exit(0)


print("execution finsished")
print("------------------------")
