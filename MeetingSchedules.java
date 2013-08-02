/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package meetingSchedules;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Aakash
 */
public class Solution {

    private static final int HOURS = 24;
    private static final int MINUTES = 60;

    private static void makeBusy(boolean[] time, int startTime, int endTime) {
        for (int min = startTime; min < endTime; min++) {
            time[min] = true;
        }
    }

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tok = br.readLine().trim().split(" ");
        int M = Integer.parseInt(tok[0]);
        int K = Integer.parseInt(tok[1]);
        boolean[] busy = new boolean[HOURS * MINUTES+1];
        for (int i = 0; i < M; i++) {
            tok = br.readLine().trim().split(" ");
            int startTime = Integer.parseInt(tok[0]) * MINUTES + Integer.parseInt(tok[1]);
            int endTime = Integer.parseInt(tok[2]) * MINUTES + Integer.parseInt(tok[3]);
            makeBusy(busy, startTime, endTime);
        }
        for (int min = 0; min < busy.length; min++) {
            int startMin = min;
            while (min < busy.length && !busy[min++]);
            if (--min - startMin >= K) {
                System.out.format("%02d %02d %02d %02d\n", (startMin / MINUTES) % HOURS, (startMin % MINUTES), (min / MINUTES) % HOURS, (min % MINUTES));
            }
        }
    }
}
