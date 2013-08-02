/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import static java.lang.Math.*;

public class Diamonds {

    public static double solve(int N, int X, int Y) {
        double prob = 1;
       
        double n = (int) ((1 + Math.sqrt(1 + 8 * N)) / 2) - 1;
        int Nnew = N - (int) n;
        if(abs(X)>N || Y > N){
            prob = 0;
        }
        if (abs(X) <= n / 2 && Y <= n / 2) {
            prob = 1;
        } else if (abs(X) > (n / 2 + 1) || Y > (n / 2 + 1)) {
            prob = 0;
        } else if ((abs(X) + Y) % 2 == 1) {
            prob = 0;
        } else if (Nnew == 0) {
            return 0;
        } else {
            int count = 0;
            int y = 0;
            for (int x = (int) (-1 * (n / 2 + 1)); count < Nnew; x++) {
                prob *= 0.5;
                if (x == X && Y == y) {
                    break;
                } else {
                    x++;
                    y++;
                }
                if (x == 0) {
                    prob = 1;
                }
            }
        }
        return prob;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        double[] sol = new double[T];
        for (int t = 1; t <= T; t++) {
            String[] tok = br.readLine().split(" ");
            int N = Integer.parseInt(tok[0]);
            int X = Integer.parseInt(tok[1]);
            int Y = Integer.parseInt(tok[2]);
            tok = br.readLine().split(" ");
            sol[t - 1] = solve(N, X, Y);
            System.out.println("Case #" + t + ": " + sol[t - 1]);

        }
        for (int t = 1; t <= T; t++) {
            //        System.out.println("Case #" + t + ": " + sol[t - 1]);
        }
    }
}
