# TLE solution 
n=int(input())
k=1
while(n!=0):
    k*=n
    n-=1
cnt=0
while(k%10==0):
    cnt+=1
    k//=10

print(cnt)

