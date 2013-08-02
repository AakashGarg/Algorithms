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
public class Solution {

    private int[] id;    // id[i] = parent of i
    private int[] sz;    // sz[i] = number of objects in subtree rooted at i
    private int count;   // number of components

    // Create an empty union find data structure with N isolated sets.
    public Solution(int N) {
        count = N;
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }

    // Return the number of disjoint sets.
    public int count() {
        return count;
    }

    // Return component identifier for component containing p
    public int find(int p) {
        while (p != id[p]) {
            p = id[p];
        }
        return p;
    }

    // Are objects p and q in the same set?
    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    // Replace sets containing p and q with their union.
    public void union(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) {
            return;
        }

        // make smaller root point to larger one
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        count--;
        //      System.out.println("connecting: " + p + "," + q);
    }

    public static int solve(char[][] arr) {
        int N = arr.length, count = 0;
        Solution uf = new Solution(N * N);
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
