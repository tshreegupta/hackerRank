#!/bin/python3
#https://www.hackerrank.com/challenges/tutorial-intro/
#Author:Tanushree Gupta<tanushreegupta@gmail.com>
V =int(input())
n =int(input())
inp =input()
lst = inp.split()
lst =list(map(int,lst))

for i in range(0,n):
    if(V==lst[i]):
        break
print(i)