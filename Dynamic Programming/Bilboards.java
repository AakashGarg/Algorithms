public class Bilboards{
	private static Integer[][] dp;
	private int[][] sol;
	private static int kMax;
	
	public static int cost(int j, int K, int[] p){
		if(j<0){
			return 0;
		}else if(dp[j][K]==null){
			dp[j][K] = Integer.MIN_VALUE;
			for(int i=0; i<=j; i++){
				for(int k = 0; k<=K; k++){
					if(k==0){
						if(dp[j][K] < cost(j-1,kMax-1,p)){
							dp[j][K] = cost(j-1,kMax-1,p);
						}
					}else if(dp[j][K] < cost(j-1,k-1,p)+p[j]){
						dp[j][K] = cost(j-1,k-1,p) + p[j];
					}else if(dp[j][K] < cost(j-1,kMax-1,p)){
						dp[j][K] = cost(j-1,kMax-1,p);
					}
				}
			}
		}
		return dp[j][K];
	}
	
	public static void main(String... s){
		kMax = Integer.parseInt(s[0]);
		int[] p = new int[s.length-1];
		for(int i=0; i<p.length; i++){
			p[i] = Integer.parseInt(s[i+1]);
		}
		dp = new Integer[p.length][kMax];
		for(int i=0; i<dp.length; i++){
			for(int j=0; j<kMax; j++){
				System.out.print(dp[i][j]+" ");
			}
			System.out.println("");
		}
	}
}