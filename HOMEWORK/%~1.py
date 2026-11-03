import sys
import math

test="SDB"
sys.stdin = open(test+".INP", "r")
sys.stdout = open(test+".OUT", "w")

def sangnt():
    global f
    f=[0]*int(1e6+2)
    temp=0
    check=[True]*int(1e6+5)
    check[0]=check[1]=False
    for i in range(2,int((int(1e6))**0.5)):
        if check[i]:
            for j in range(i*i,int(1e6)+1,i):
                check[j]=False
    
    for i in range(int(1e6),0,-1):
        if check[i]:
            temp=i
        f[i]=temp

n=int(input())
sangnt()
a=list(map(int,input().split()))
for i in range(n):
    print(f[math.ceil(a[i]**0.5)]**2,end=" ")
