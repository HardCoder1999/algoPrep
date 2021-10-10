def maxSubArraySum(a,size):
     
    max_so_far =a[0]
    curr_max = a[0]
     
    for i in range(1,size):
        curr_max = max(a[i], curr_max + a[i])
        max_so_far = max(max_so_far,curr_max)
         
    return max_so_far

for _ in range(int(input())):
    n,q=map(int,input().split())
    u=list(map(int,input().split()))
    t=list(map(int,input().split()))
    val=[]
    maxi=0
    ans=0
    maxel=u[0]+t[0]*q 
    for i in range(n):
        val.append(u[i]+t[i])
        if u[i]+t[i]*q>maxel:
            maxi=i
    if t[i]>0:
        ans+=t[maxi]*q
    ans+=maxSubArraySum(u,n)


    print(ans)