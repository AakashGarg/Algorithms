public class LCSTopDown{
	private static Integer[][] dp;
	private static String[][] s;
	
	public static Integer cost(int i, int j, char[] a, char[] b){
		if(dp[i][j]!=null){
			if(a[i-1]==b[j-1]){
				dp[i][j] = cost(i-1,j-1,a,b)+1;
				s[i-1][j-1] = "d";					//up-left
			}else if(cost(i-1,j,a,b) >= cost(i,j-1,a,b)){
				dp[i][j] = cost(i-1,j,a,b);
				s[i-1][j-1] = "u";					//up
			}else{
				dp[i][j] = cost(i,j-1,a,b);
				s[i-1][j-1] = "-";					//left
			}
		}
		return dp[i][j];
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
		dp = new Integer[a.length+1][b.length+1];
		s = new String[a.length][b.length];
		for(int i=0; i<dp.length; i++){
			dp[i][0] = 0;
		}
		for(int j=0; j<dp[0].length; j++){
			dp[0][j] = 0;
		}
		cost(a.length, b.length,a,b);
		System.out.println("LCS : "+printLCS(a.length-1,b.length-1,a,b));
		System.out.println("Cost : "+dp[a.length][b.length]);
	}
}