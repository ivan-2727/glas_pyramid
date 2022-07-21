public class GlassPyramid {

    public static double DynProg(int r, int g, double start) {
        double[][] dp = new double[r][];
		for (int i = 0; i < r; i++) dp[i] = new double[i+1];
        dp[0][0] = start; 
        for (int i = 1; i < r; i++) {
            dp[i][0] = Math.Max(dp[i-1][0]-1, 0)/2;
            dp[i][i] = Math.Max(dp[i-1][i-1]-1, 0)/2;
            for (int j = 1; j < i; j++) {
                dp[i][j] = Math.Max(0, dp[i-1][j]-1)/2 + Math.Max(0, dp[i-1][j-1]-1)/2; 
            }
        }
        return dp[r-1][g-1]; 
    }

    public static double UpperBound(int r, int g, double target) {
        double hi = 1;
        while(true) {
            hi *= 2;
            if (DynProg(r,g,hi) > target*1.1) break;
        }
        return hi; 
    }

    public static double BinarySearch(int r, int g, double target, double acc) {
        double lo = 0;  
        double hi = UpperBound(r,g, target);
        double ans = 0;
        while(true) {
            double mid = (lo+hi)/2;
            ans = mid;
            double res = DynProg(r,g,mid); 
            if (Math.Abs(res - target) < acc) break; 
            if (res > target) hi = mid;
            else lo = mid; 
        }
        return 10*ans; 
    }

    public static void Main()
    {
        Console.Write("Rad = ");
        int r = Convert.ToInt32(Console.ReadLine());
        Console.Write("Glas = ");
        int g = Convert.ToInt32(Console.ReadLine());
        if (g > r) {
            Console.WriteLine("Invalid input");
            return;
        }
        Console.Write("Tid = ");
        Console.WriteLine(BinarySearch(r, g, 1, 1e-6));
    }
}


 
