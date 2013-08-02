public class LCSBottomUp{
	private static int[][] dp;
	private static String[][] s;
	
	public static void calculateCost(char[] a, char[] b){
		dp = new int[a.length+1][b.length+1];
		s = new String[a.length][b.length];
		
		for(int i=0; i<dp.length; i++){
			dp[i][0] = 0;
		}
		for(int j=0; j<dp[0].length; j++){
			dp[0][j] = 0;
		}
		for(int i=1; i<=a.length; i++){
			for(int j=1; j<=b.length; j++){
				if(a[i-1]==b[j-1]){
					dp[i][j] = dp[i-1][j-1]+1;
					s[i-1][j-1] = "d";					//up-left
				}else if(dp[i-1][j] >= dp[i][j-1]){
					dp[i][j] = dp[i-1][j];
					s[i-1][j-1] = "u";					//up
				}else{
					dp[i][j] = dp[i][j-1];
					s[i-1][j-1] = "-";					//left
				}
			}
		}
	}
	
	public static String printLCS(int i, int j, char[] a, char[] b){
		if(i<0 || j<0){
			return "";
		}else if(s[i][j] == "d"){
			return printLCS(i-1,j-1,a,b)+a[i];
		}else if(s[i][j] == "u"){
			return printLCS(i-1,j,a,b);
		}else{
			return printLCS(i,j-1,a,b);
		}
	}
	
	public static void main(String... s1){
		char[] a = s1[0].toCharArray();
		char[] b = s1[1].toCharArray();
		calculateCost(a,b);
		System.out.println("LCS : "+printLCS(a.length-1,b.length-1,a,b));
		System.out.println("Cost : "+dp[a.length][b.length]);
	}
}