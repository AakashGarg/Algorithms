class BalancedBST{
	private static Integer[][] dp;
	private static int[][] sol;
	
	public static int cost(int i, int j, int d, String[] S, int[] p){
		if(j<i){
			return 0;
		}else /*if(dp[i][j]==null)*/{
			dp[i][j] = Integer.MAX_VALUE;
			for(int k=i; k<=j; k++){
				if(dp[i][j] > (cost(i,k-1,d+1,S,p) + cost(k+1,j,d+1,S,p) + d*p[k])){
					dp[i][j] = (cost(i,k-1,d+1,S,p) + cost(k+1,j,d+1,S,p) + d*p[k]);
					sol[i][j] = k;
				}
			}
		}
		return dp[i][j];
	}
	
	public static void main(String... s){
		int N = s.length/2;
		dp = new Integer[N][N];
		sol = new int[N][N];
		String[] S = new String[N];
		int[] p = new int[N];
		for(int i=0; i<2*N; i += 2){
			S[i/2] = s[i];
			p[i/2] = Integer.parseInt(s[i+1]);
		}
		System.out.println("Cost : "+cost(0,p.length-1,1,S,p));
		for(int i=0; i<dp.length; i++){
			for(int j=0; j<dp.length; j++){	
				System.out.print(sol[i][j]+" ");
			}
			System.out.println("");
		}	
	}
}
			