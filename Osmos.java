/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 *
 * @author Aakash
 */
class Osmos {

    static Integer[][] dp;

    public static int solve(int A, int[] motes) {
        if (A == 1) {
            return motes.length;
        }
        int N = motes.length;
        int sum = 0;
        for (int i = 0; i < motes.length; i++) {
            sum += motes[i];
        }
        dp = new Integer[2*(sum + 1 + A)][N + 1];
        Arrays.sort(motes);
        int count = 0;
        int i = 0;
        for (i = 0; i < N; i++) {
            if (motes[i] < A) {
                A += motes[i];
            } else if (motes[i] - A < A) {
                count++;
                A += motes[i] - A + motes[i];
            } else {
                break;
            }
        }
        if (i == N) {
            return count;
        }
        return count + cost(A, i, motes, sum);
    }

    static int cost(int A, int i, int[] motes, int sum) {
        if (dp[A][i] == null) {
            if (A <= 1) {
                dp[A][i] = motes.length - i;
            } else if (i >= motes.length) {
                dp[A][i] = 0;
            } else {
                if (motes[i] < A) {
                    dp[A][i] = cost(A + motes[i], i + 1, motes, sum);
                } else {
                    int diff = motes[i] - A;
                    int add = (diff%(A-1)>0 ? diff/(A-1) + 1 : diff/(A-1) );
                    dp[A][i] = Math.min(
                            cost(A + diff + motes[i], i + 1, motes, sum) + add,
                            cost(A, i + 1, motes, sum) + 1);
                }
            }
        }
        return dp[A][i];
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int[] sol = new int[T];
        for (int t = 1; t <= T; t++) {
            String[] tok = br.readLine().split(" ");
            int A = Integer.parseInt(tok[0]);
            int N = Integer.parseInt(tok[1]);
            int[] motes = new int[N];
            int i = 0;
            tok = br.readLine().split(" ");
            for (i = 0; i < N; i++) {
                motes[i] = Integer.parseInt(tok[i]);
            }
            sol[t - 1] = solve(A, motes);
                       System.out.println("Case #" + t + ": " + sol[t - 1]);

        }
        for (int t = 1; t <= T; t++) {
    //        System.out.println("Case #" + t + ": " + sol[t - 1]);
        }
    }
}
