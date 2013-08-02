public class Parenthesize{
	private static char[][];
	private static Integer[][];
	private static final char NULL = '\u0000';
	
	public static char parenthesize(int i, int j, char[] a){
		if(i==j){
			return a[i];
		}else if(dp[i][j]!=null){
			return dp[i][j];
		}else{
			dp[i][j] = 