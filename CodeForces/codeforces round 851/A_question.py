
n = int(input())
x= 10000
for i in range(1, x+1):
    for j in range(i, x+1):
        l=1
        r=x
        while l<r:
            mid = (l+r)//2
            if i*i*i+j*j*j+mid*mid*mid>=n:
                r=mid
            else:
                l=mid+1
        if(i*i*i+j*j*j+l*l*l==n):
            print("YES")
            exit(0)
print("NO")