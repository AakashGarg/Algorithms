public class SquareSubsequence{
	private static Long[][] dp;
	
	public static long cost(int i, int j, char[] a){
		if(i>=j){
			return 0L;
		}else if(dp[i][j]==null){
			dp[i][j] = 0L;
			for(int k=i; k<=j; k++){
				int m = k+1;
				for(; m<=j && a[m]!=a[k]; m++);
				if(m==j+1){
					dp[i][j] += cost(i,k-1,a);
				}else{
					if(cost(i,k-1,a)!=0 && cost(m+1,j,a)!=0){
						dp[i][j] += cost(i,k-1,a)*cost(m+1,j,a);
					}else if(cost(i,k-1,a)!=0){
						dp[i][j] += cost(i,k-1,a);
					}else if(cost(m+1,j,a)!=0){
						dp[i][j] += cost(m+1,j,a);
					}else{
						dp[i][j] += 1;
					}
				}
			}
		}
		return dp[i][j];
	}
	
	public static void main(String... s){
		char[] a = s[0].toCharArray();
		dp = new Long[a.length][a.length];
		System.out.println(cost(0,a.length-1,a));
	}
}