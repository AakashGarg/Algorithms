import java.io.*;

class FibDP{
	static int[] dp;

	public static void getFibSequence(int n){
		dp[0] = 1;
		dp[1] = 1;
		for(int i=2; i<n; i++){
			dp[i] = dp[i-1]+dp[i-2];
		}
	}
		
	public static void main(String... s){
		int n = Integer.parseInt(s[0]);
		dp = new int[n];
		getFibSequence(n);
		for(int i=0; i<n; i++){
			System.out.print(dp[i]+",");
		}
	}
}
		