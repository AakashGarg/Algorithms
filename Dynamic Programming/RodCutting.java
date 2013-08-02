import java.io.*;

class RodCutting {

    static Integer[] dp;
    static Integer[] s;

    static int bottomUpCut(int[] p, int n) {
        dp[0] = 0;
        s[0] = 0;
        for (int length = 1; length < p.length; length++) {
            int profit = Integer.MIN_VALUE;
            for (int cut = 1; cut <= length; cut++) {
                if (profit < (p[cut] + dp[length - cut])) {
                    profit = p[cut] + dp[length - cut];
                    s[length] = cut;
                }
            }
            dp[length] = profit;
        }
        return dp[n];
    }

    static void printCutRodSolution(int[] p, int n) {
        int profit = bottomUpCut(p, n);
        System.out.println("profit = "+profit);
        while (n > 0) {
            System.out.print(s[n] + "+");
            n = n - s[n];
        }
    }

    public static void main(String... s1) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(br.readLine());
        String[] line = br.readLine().trim().split(" ");
        int n = line.length;
        int[] p = new int[n + 1];
        p[0] = 0;
        s = new Integer[n + 1];
        dp = new Integer[n + 1];
        for (int i = 1; i <= n; i++) {
            p[i] = Integer.parseInt(line[i - 1]);
        }
        printCutRodSolution(p, q);
    }
}