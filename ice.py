t=int(input())
while(t):
    n=int(input())
    l=1
    u=n
    while(u-l>1):
        m=(l+u)//2
        if((m*(m-1))//2<=n):
            l=m
        
        else:
            u=m-1
    t=t-1 
    if((u*(u-1))//2<=n):
        l=u 
    # print (l)      
    print(l+n-(l*(l-1))//2)
   

