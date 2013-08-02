class Trianguliation{
	public static Double[][] dp;
	public static int[][] sol;
	public static double[][] len;
	
	public static double cost(int i, int j){
		if(j-i <=2){
			dp[i][j] = 0.0;
		}else if(dp[i][j]==null){
			dp[i][j] = Double.MAX_VALUE;
			for(int k=i+2; k<j; k++){
				double cost = cost(i,k)+cost(k,j)+len[i][k]+len[k][j]+len[i][j];
				if(dp[i][j] > cost) {
					dp[i][j] = cost;
					sol[i][j] = k;
				}
			}
		}
		return dp[i][j];
	}
	
	public static String stepsToTriangularize(int i, int j){
		String ans = "";
		if(i<j){
			int k = sol[i][j];
			ans = "("+i+"-"+k+","+k+"-"+j+"),"+stepsToTriangularize(sol[i][k],sol[k][j]);
		}
		return ans;
	}
	
	public static void calcLength(int[] X, int[] Y){
		for(int i=0; i<X.length; i++){
			for(int j=0; j<Y.length; j++){
				len[i][j] = Math.sqrt(Math.pow(X[j]-X[i],2)+Math.pow(Y[j]-Y[i],2));
			}
		}
	}
	
	public static void main(String... s){
		int N = s.length/2;
		int[] X = new int[N];
		int[] Y = new int[N];
		for(int i=0; i<2*N; i += 2){
			X[i/2] = Integer.parseInt(s[i]);
			Y[i/2] = Integer.parseInt(s[i+1]);
		}
		len = new double[N][N];
		dp = new Double[N][N];
		sol = new int[N][N];
		calcLength(X,Y);
		System.out.println("Cost : "+cost(0,X.length-1));
		System.out.println("Sol : "+stepsToTriangularize(0,X.length-1));
	}
}
				