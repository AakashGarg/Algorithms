public class SqSubBottomUp{
	private static int[][] dp;
	
	static int matrixChainOrder(int[] a){
		int N = p.length;
		dp = new int[N+1][N+1];
		s = new int[N][N];
		
		for(int i=1; i<=N; i++){
			dp[i-1][i-1] = 0;
			dp[i-1][N] = 0;
		}
		for(int l=2; l<=N; l++){
			for(int i=1; i<=N-l+1; i++){
				int j = i+l-1;
				dp[i-1][j-1] = 0;
				for(int k=i; k<=j-1; k++){
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
						dp[i-1][j-1] += dp[i-1][k-1]+dp[k][j-1]+p[i-1]*p[k]*p[j];
					}
			}
		}
		return dp[0][N-1];
	}
	
	public static void main(String... s1){
		int[] p = new int[s1.length];
		for(int i=0; i<p.length; i++){
			p[i] = Integer.parseInt(s1[i]);
		}
		matrixChainOrder(p);
		System.out.print("Sol : ");
		printOptimalParens(1,p.length-1);
		System.out.println("");
		System.out.print("Cost : "+dp[0][p.length-2]);
		for(int i=0; i<s.length; i++){
		System.out.println("");		
			for(int j=0; j<s[i].length; j++){
				System.out.print(s[i][j]+" ");
			}
		}
	}
}