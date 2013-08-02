class LongestPalindrome{
		
	public static void main(String... s){
		String a = s[0];
		String b = (new StringBuffer(s[0])).reverse().toString();
		LCSBottomUp.main(a,b);
	}
}