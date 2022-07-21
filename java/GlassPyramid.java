import java.util.*;

public class GlassPyramid {

    public static Double DynProg(int r, int g, Double start) {
        var dp = new ArrayList<List<Double>>();
        for (int i = 0; i < r; i++) dp.add(Arrays.asList(new Double[i+1]));
        dp.get(0).set(0,start); 
        for (int i = 1; i < r; i++) {
            dp.get(i).set(0, Math.max(dp.get(i-1).get(0)-1, 0)/2);
            dp.get(i).set(i, Math.max(dp.get(i-1).get(i-1)-1, 0)/2);
            for (int j = 1; j < i; j++) {
                dp.get(i).set(j,Math.max(0, dp.get(i-1).get(j)-1)/2 + Math.max(0, dp.get(i-1).get(j-1)-1)/2); 
            }
        }
        return dp.get(r-1).get(g-1); 
    }

    public static Double UpperBound(int r, int g, Double target) {
        Double hi = 1.0;
        while(true) {
            hi *= 2.0;
            if (DynProg(r,g,hi) > target*1.1) break;
        }
        return hi; 
    }

    public static Double BinarySearch(int r, int g, Double target, Double acc) {
        Double lo = 0.0;  
        Double hi = UpperBound(r,g, target);
        Double ans = 0.0;
        while(true) {
            Double mid = (lo+hi)/2;
            ans = mid;
            Double res = DynProg(r,g,mid); 
            if (Math.abs(res - target) < acc) break; 
            if (res > target) hi = mid;
            else lo = mid; 
        }
        return 10*ans; 
    }

    public static void main(String[] args)
    {
		Scanner in = new Scanner(System.in);
        System.out.print("Rad = ");
        int r = in.nextInt();
        System.out.print("Glas = ");
        int g = in.nextInt();
        if (g > r) {
			System.out.println("Invalid input");
            return;
        }
        System.out.print("Tid = ");
        System.out.println(BinarySearch(r, g, 1.0, 1e-6));
    }
}


 
