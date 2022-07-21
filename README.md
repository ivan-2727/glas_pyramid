### Glas pyramid
Algorithm: for a given time after the start of the process, we can use dynamic programming to find the amount of water which has moved through each glass, and therefore we know how full the glass is. For each glass, that is a monotonously incresing (or constant 0/1 in the beginning/end) function of time, so we can use binary search to find the moment when the glass becomes 100% full, ie the minimum time such as `dp[r-1][g-1] == 1`. Complexity is `O(r*g*log(answer))`. I suspect that there is a faster DP solution in `O(r*g)` but I wasn't able to find it. 
- from csharp folder, `dotnet run`  
- from java folder, `java GlassPyramid` 
- from python folder, `python GlassPyramid.py`
- from cpp folder, `./p.exe`
