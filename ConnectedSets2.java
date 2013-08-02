/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package connectedSets;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Aakash
 */
public class Solution2 {

    public static int solve(char[][] arr) {
        int N = arr.length, count = 0;
        WeightedQuickUnionUF uf = new WeightedQuickUnionUF(N * N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == '1') {
                    if (j > 0 && arr[i][j - 1] == '1') {
                        uf.union(i * N + j, i * N + j - 1);
                    }
                    if (j < N - 1 && arr[i][j + 1] == '1') {
                        uf.union(i * N + j, i * N + (j + 1));
                    }
                    if (i < N - 1 && j > 0 && arr[i + 1][j - 1] == '1') {
                        uf.union(i * N + j, (i + 1) * N + (j - 1));
                    }
                    if (i < N - 1 && arr[i + 1][j] == '1') {
                        uf.union(i * N + j, (i + 1) * N + (j));
                    }
                    if (i < N - 1 && j < N - 1 && arr[i + 1][j + 1] == '1') {
                        uf.union(i * N + j, (i + 1) * N + (j + 1));
                    }
                } else {
                    count++;
                }

            }
        }
        return uf.count() - count;
    }

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int[] sol = new int[T];
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            char[][] arr = new char[N][];
            for (int i = 0; i < N; i++) {
                arr[i] = br.readLine().replaceAll(" ", "").toCharArray();
            }
            sol[t] = solve(arr);
        }
        for (int i = 0; i < sol.length; i++) {
            System.out.println(sol[i]);
        }
    }
}
