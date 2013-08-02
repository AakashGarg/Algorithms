public class LISTopDown{
	private static boolean[] s;
	
	public static void LIS(int[] a){
		int maxLen = 0;
		int reqI = 0;
		boolean[] sol = null;
		for(int i=0; i<a.length; i++){
			s = new boolean[a.length];
			if(1+cost(i,a[i],a) > maxLen){
				reqI = i;
				maxLen = 1+cost(i,a[i],a);
				s[i] = true;
				sol = s;
			}
		}
		s = sol;
	}
	
	public static int cost(int j,int max, int[] a){
		if(j<0){
			return 0;
		}
		if(a[j] < max){
			s[j] = true;
			return cost(j-1,a[j],a)+1;
		}else{
			return cost(j-1,max,a);
		}
	}
	
	public static String printLIS(int[] a){
		String sol = "";
		for(int i=0; i<a.length; i++){
			sol += (s[i]==true ? a[i]+"," : "");
		}
		return sol;
	}
	
	public static void main(String... s){
		int[] a = new int[s.length];
		for(int i=0; i<s.length; i++){
			a[i] = Integer.parseInt(s[i]);
		}
		LIS(a);
		System.out.println("LIS : "+printLIS(a));
	}
}
	