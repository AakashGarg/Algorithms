import java.io.*;

class MergeSortedArrays{	

	public static void mergeArrays(int[] a, int[] b){
		int N = a.length;
		int M = b.length-N;
		int i = N-1, j=M-1, k = N+M-1;
		while( k>=0 && i>=0 && j>=0){
			if(a[i]>b[j]){
				b[k--] = a[i];
				i--;
			}else{
				b[k--] = b[j];
				j--;
			}
		}
		while(i>=0){
			b[k--] = a[i--];
		}
		while(j>=0){
			b[k--] = b[j--];
		}
	}
	
	public static void main(String... s) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] tok = br.readLine().trim().split(" ");
		int N = Integer.parseInt(tok[0]);
		int M = Integer.parseInt(tok[1]);
		int[] a = new int[N];
		int[] b = new int[N+M];
		tok = br.readLine().trim().split(" ");
		for(int i=0; i<N; i++){
			a[i] = Integer.parseInt(tok[i]);
		}
		tok = br.readLine().trim().split(" ");
		for(int i=0; i<M; i++){
			b[i] = Integer.parseInt(tok[i]);
		}
		mergeArrays(a,b);
		for(int i=0; i<N+M; i++){
			System.out.print(b[i]+" ");
		}
	}
}