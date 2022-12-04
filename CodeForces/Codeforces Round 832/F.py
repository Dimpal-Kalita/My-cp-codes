def check(mid, s):
   temp = 0
   for i in range(len(s)-1,0,-1):
         while s[i]>mid and s[i] % 2 == 0:
            s[i]//=2
            temp +=1
         if s[i]>mid:
            return 0
   return s[0]<=mid



n = int(input())
s = list(map(int, input().split()))

l=1
r=int(1e9+7)
while l<r:
   mid= (l+r)//2
   if check(mid, s.copy()):
         r=mid
   else: l=mid+1
print(r)
            
