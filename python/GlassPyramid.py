class GlassPyramid(object):
    def DynProg(self, r, g, start):
        dp = [[0 for _ in range(i+1)] for i in range(r)]
        dp[0][0] = start
        for i in range(1,r):
            dp[i][0] = max(0, dp[i-1][0]-1)/2
            dp[i][i] = max(0, dp[i-1][i-1]-1)/2
            for j in range(1,i):
                dp[i][j] = max(0, dp[i-1][j]-1)/2 + max(0, dp[i-1][j-1]-1)/2
        return dp[r-1][g-1]
       
    def UpperBound(self,r, g, target):
        hi = 1.0
        while True:
            hi *= 2
            if (self.DynProg(r,g,hi) > target*1.1): break
        return hi
    
    def BinarySearch(self,r,g,target,acc):
        lo = 0.0
        hi = self.UpperBound(r,g,target)
        ans = 0.0
        while True:
            mid = (lo+hi)/2
            ans = mid
            res = self.DynProg(r,g,mid)
            if (abs(res-target) < acc): break
            if (res > target): hi = mid
            else: lo = mid
        
        return 10*ans
    
    def main(self):
        print("Rad = ", end="")
        r = int(input())
        print("Glas = ", end="")
        g = int(input())
        if g > r: 
            print("Invalid input")
            return
        print("Tid =", self.BinarySearch(r,g, 1.0, 1e-6))
        
GlassPyramid().main()


 
