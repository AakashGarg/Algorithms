/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package topcoder;

import java.util.*;

/**
 *
 * @author Aakash
 */
public class SquaredSubsets {

    private Integer[] asIntegerArr(int[] a) {
        Integer[] xList = new Integer[a.length];
        int i = 0;
        for (int e : a) {
            xList[i++] = Integer.valueOf(e);
        }
        return xList;
    }

    private Coordinate[] getPointsList(int[] x, int[] y) {
        Coordinate[] points = new Coordinate[x.length];
        for (int i = 0; i < points.length; i++) {
            points[i] = new Coordinate(x[i], y[i]);
        }
        return points;
    }

    public long countSubsets(int n, int[] X, int[] Y) {
        long count = 0;
        Coordinate[] points = getPointsList(X, Y);
        Coordinate[] pointsY = Arrays.copyOf(points, points.length);

        Arrays.sort(points, new XComparator());
        Arrays.sort(pointsY, new YComparator());
        for (int i = 0; i < X.length && ((points[i].x + n) <= points[points.length - 1].x); i++) {
            for (int j = 0; j < Y.length && ((pointsY[j].y + n) <= pointsY[points.length - 1].y); j++) {
                count += countSubSets(X, Y, points[j].x, points[j].y, n);
            }
        }
        return count;
    }

    private long countSubSets(int[] X, int[] Y, int x, int y, int n) {
        long noOfPoints = 0;
        for (int i = 0; i < X.length; i++) {
            if (X[i] == x || Y[i] == y || X[i] == x + n || Y[i] == y + n) {
                noOfPoints++;
            } else if (X[i] > x && X[i] < x + n && Y[i] > y && Y[i] < y + n) {
                noOfPoints++;
            }
        }
        return (long) Math.pow(2, noOfPoints);
    }

    private static class Coordinate {

        int x;
        int y;

        private Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static class XComparator implements Comparator<Coordinate> {

        @Override
        public int compare(Coordinate p1, Coordinate p2) {
            return p1.x - p2.x;
        }
    }

    private class YComparator implements Comparator<Coordinate> {

        @Override
        public int compare(Coordinate p1, Coordinate p2) {
            return p1.y - p2.y;
        }
    }
}
