import sys

sys.stdin = open("GHH.INP", "r")
sys.stdout = open("GHH.OUT", "w")

N=int(1e6+5)
sum=[1]*N
a=b=[]
ans=0

def sanguoc():
    for i in range(2,N-2):
        for j in range(i,N-2,i):
            sum[j]+=i

sanguoc()
n=int(input())
for i in range(n):
    m=int(input())
    if m*2<=sum[m]:
        ans+=1
        b.append(m)

print(ans)
for i in range(ans):
    print(b[i])
#Truong Thanh Nghi