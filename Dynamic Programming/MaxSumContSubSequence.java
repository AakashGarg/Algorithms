public class MaxSumContSubSequence{
	
	public static int cost(int[] a){
		int reqI = 0, reqJ = 0, maxSum = 0;
		for(int i=0; i<a.length; i++){
			int maxSumI = 0,sum = 0, J = i;
			for(int j=i; j<a.length; j++){
				sum += a[j];
				if(sum > maxSumI){
					maxSumI = sum;
					J = j;
				}
			}
			if(maxSumI > maxSum){
				maxSum = maxSumI;
				reqI = i;
				reqJ = J;
			}
		}
		System.out.print("Sol : ");
		for(int i=reqI; i<=reqJ; i++){
			System.out.print(a[i]+",");
		}
		System.out.println("");
		return maxSum;
	}
	
	public static void main(String... s){
		int[] a = new int[s.length];
		for(int i=0; i<s.length; i++){
			a[i] = Integer.parseInt(s[i]);
		}
		System.out.println("Max Sum : "+cost(a));
	}
}