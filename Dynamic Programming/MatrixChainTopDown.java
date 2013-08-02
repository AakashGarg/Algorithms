public class MatrixChainTopDown{
	private static Integer[][] dp;
	private static Integer[][] s;
	
	static int matrixChainOrder(int i, int j, int[] p){
		if(i==j){
			return 0;
		}else if(dp[i-1][j-1]!=null){
			return dp[i-1][j-1];
		}else{
			dp[i-1][j-1] = Integer.MAX_VALUE;
			for(int k=i; k<=j-1; k++){
				if(dp[i-1][j-1] > matrixChainOrder(i,k,p)+matrixChainOrder(k+1,j,p)+p[i-1]*p[k]*p[j]){
					dp[i-1][j-1] = matrixChainOrder(i,k,p)+matrixChainOrder(k+1,j,p)+p[i-1]*p[k]*p[j];
					s[i-1][j-1] = k;
				}
			}
			return dp[i-1][j-1];
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
		int N = p.length-1;
		dp = new Integer[N][N];
		s = new Integer[N][N];
		matrixChainOrder(1,N,p);
		System.out.print("Sol : ");
		printOptimalParens(1,p.length-1);
		System.out.println("");
		System.out.print("Cost : "+dp[0][p.length-2]);
		for(int i=0; i<s.length; i++){
		System.out.println("");		
			for(int j=0; j<s[i].length; j++){
				System.out.print((s[i][j]!=null? s[i][j]: "-")+" ");
			}
		}
	}
}