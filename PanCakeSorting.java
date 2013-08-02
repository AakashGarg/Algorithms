import java.io.*;

class PanCakeSorting{	

	public static void flip(int[] a, int i){
		for(int k=0; k<i/2; k++){
			int t = a[k];
			a[k] = a[i-k];
			a[i-k] = t;
		}
	}
	
	public static void sort(int[] a){
		int N = a.length;
		for(int i= N-1; i>0; i--){
			int max = a[i];
			int reqI = i;
			for(int j=0; j<=i; j++){
				if(a[j]>max){
					reqI = j;
					max = a[j];
				}
			}
			flip(a,reqI);
			flip(a,i);
		}
	}
	
	public static void main(String... s) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] tok = br.readLine().trim().split(" ");
		int N = Integer.parseInt(tok[0]);
		int[] a = new int[N];
		tok = br.readLine().trim().split(" ");
		for(int i=0; i<N; i++){
			a[i] = Integer.parseInt(tok[i]);
		}
		for(int i=0; i<N; i++){
		//	System.out.print(a[i]+" ");
		}
		sort(a);
		System.out.println();
		System.out.print("Sorted Array : ");
		for(int i=0; i<N; i++){
			System.out.print(a[i]+" ");
		}
	}
}