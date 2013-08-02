//Sol : 2493893
//Sol2 : 2595819

public class KnapsackBottomUp{
	private static Long[][] dp;
	
	public static Long calculateCost(int[] v, int[] w, int W){
		int N = v.length;
		dp = new Long[N+1][W+1];
		sol = new boolean[N+1];
		
		for(int i=0; i<W; i++){
			dp[0][i] = 0L;
		}
		for(int i=0; i<N; i++){
			dp[i][0] = 0L;
		}
		
		for(int j=1; j<=N; j++){
			for(int x =1; x<=W; x++){
				long a = Long.MIN_VALUE;
                if (x - w[i - 1] >= 0) {
                    a = dp[i-1][x - w[i - 1]] + v[i - 1];
                }
                dp[i][x] = Math.max(dp[i-1][x], a);
			}
		}
		return dp[N][W];
	}
	
	public static void main(String... s) throws IOException{
	}
}