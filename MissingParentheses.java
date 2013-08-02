/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package topcoder;

/**
 *
 * @author Aakash
 */
public class MissingParentheses {

    public int countCorrections(String par) {
        int lP = 0;
        if (par == null) {
            return 0;
        } else {
            char[] arr = par.toCharArray();
            for (int i = 0; i < arr.length; i++) {
                if (arr[i] == '(') {
                    lP++;
                } else if (arr[i] == ')') {
                    lP--;
                }
            }
        }
        return Math.abs(lP);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
    }
}
