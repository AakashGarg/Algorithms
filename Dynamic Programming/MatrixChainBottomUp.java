public class MatrixChainBottomUp{
	private static int[][] dp;
	private static int[][] s;
	
	static void matrixChainOrder(int[] p){
		int N = p.length-1;
		dp = new int[N][N];
		s = new int[N][N];
		
		for(int i=1; i<=N; i++){
			dp[i-1][i-1] = 0;
		}
		for(int l=2; l<=N; l++){
			for(int i=1; i<=N-l+1; i++){
				int j = i+l-1;
				dp[i-1][j-1] = Integer.MAX_VALUE;
				for(int k=i; k<=j-1; k++){
					if(dp[i-1][j-1] > (dp[i-1][k-1]+dp[k][j-1]+p[i-1]*p[k]*p[j])){
						dp[i-1][j-1] = dp[i-1][k-1]+dp[k][j-1]+p[i-1]*p[k]*p[j];
						s[i-1][j-1] = k;
					}
				}
			}
		}
	}
	
	public static void printOptimalParens(int i, int j){
		if(i==j){
			System.out.print("A"+i);
		}else{
			System.out.print("(");
			printOptimalParens(i,s[i-1][j-1]);
			printOptimalParens(s[i-1][j-1]+1,j);
			System.out.print(")");
		}
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