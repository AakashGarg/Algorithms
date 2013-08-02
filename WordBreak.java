import java.io.*;
import java.util.*;

public class WordBreak{
	Boolean[] dp;
	
	Boolean isBreakAble(String input, HashSet<String> dict, int l, int n){
		for(int i=l; i<n-1; i++){
			if(dict.contains(input.substring(l,i+1)) && isBreakAble(input,dict,i+1,n))
				return(true);
		}
		return (dp[l]=false);
	}
	
	public static void main(String... s) throws IOException{
		WordBreak wb = new WordBreak();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		HashSet<String> dict = new HashSet<String>();
		String[] input = br.readLine().trim().split(", ");
		for(int i=0; i<input.length; i++)
			dict.add(input[i]);
		String str = br.readLine();
		wb.dp = new Boolean[str.length()];
		System.out.println(wb.isBreakAble(str, dict, 0, str.length()));
	}
}