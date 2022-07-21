#include <bits/stdc++.h>
using namespace std; 

class GlassPyramid {
public:
	GlassPyramid() {}
	double maxd(double x, double y) {
		if (x>y) return x;
		return y; 
	}
	double DynProg(int r, int g, double start) {
        vector<vector<double>> dp;
		for (int i = 0; i < r; i++) dp.push_back(vector<double>(i+1)); 
        dp[0][0] = start; 
        for (int i = 1; i < r; i++) {
            dp[i][0] = maxd(dp[i-1][0]-1, 0)/2;
            dp[i][i] = maxd(dp[i-1][i-1]-1, 0)/2;
            for (int j = 1; j < i; j++) {
                dp[i][j] = maxd(0, dp[i-1][j]-1)/2 + maxd(0, dp[i-1][j-1]-1)/2; 
            }
        }
        return dp[r-1][g-1]; 
    }
	double UpperBound(int r, int g, double target) {
        double hi = 1;
        while(true) {
            hi *= 2;
            if (DynProg(r,g,hi) > target*1.1) break;
        }
        return hi; 
    }
	double BinarySearch(int r, int g, double target, double acc) {
        double lo = 0;  
        double hi = UpperBound(r,g, target);
        double ans = 0;
        while(true) {
            double mid = (lo+hi)/2;
            ans = mid;
            double res = DynProg(r,g,mid); 
            if (fabs(res - target) < acc) break; 
            if (res > target) hi = mid;
            else lo = mid; 
        }
        return 10*ans; 
    }
	
	void solve() {
		int r, g;
		printf("Rad = "); scanf("%d", &r);
		printf("Glas = "); scanf("%d", &g);
		if (g>r) {
			printf("Invalid input\n");
			return;
		}
		printf("Tid = %.6f\n", BinarySearch(r,g,1.0,1e-6)); 
	}
	
};

int main(void) {
	GlassPyramid solver = GlassPyramid();
	solver.solve(); 
	return 0; 
}


 
