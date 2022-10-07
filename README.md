### Glas pyramid
Task is in the pdf file.
#### Algorithm
For a known time after the start of the process, we can use dynamic programming to find the amount of water which has moved through each glass, and therefore we know how full the glass is. For each glass, this is a monotonously incresing (or constant 0/1 in the beginning/end) function of time, so we can use binary search to find the moment when the glass becomes 100% full, ie the minimum time such as `dp[r-1][g-1] == 1`. This approach can be used to find any `target` degree of filling any of the glasses.  Complexity is `O(r*g*log(answer))`. I suspect that there is a faster DP solution in `O(r*g)` but I wasn't able to find it. 

#### Implementation
Implementations in C#, Java, C++ and Python are in corresponding folders. The C# version can be run by `dotnet run` from the `csharp` folder. For C++, the executable file is already there. 
