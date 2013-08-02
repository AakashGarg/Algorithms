import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Aakash
 */
class Solution {

    static void productArray(int a[], int n){
	int prod = 1,i, no;
	for(i=0; i<n; i++)
		prod = a[i] *= prod;
		
	prod = 1;
	for(i=n-1; i>0; i--){
		no = a[i]/a[i-1];
		a[i] = a[i]/no*prod;
		prod *= no;
	}
	a[0] = prod;
}
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
        // TODO code application logic here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
	int a[] = new int[n];
	for(int i=0;i<n;i++)
		a[i] = Integer.parseInt(br.readLine());
	productArray(a,n);
	for(int i=0; i<n; i++)
            System.out.println(a[i]);
    }
}