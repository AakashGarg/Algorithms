/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package heap;

/**
 *
 * @author Aakash
 */
public class HighHeap {

    private int noOfElements = 0;
    private Integer[] heap;

    public HighHeap(int size) {
        heap = new Integer[size];
    }

    public HighHeap(int[] elements) {
        this.heap = new Integer[elements.length];
        for (int i = 0; i < elements.length; i++) {
            this.insert(elements[i]);
        }
    }

    public int parent(int i) {
        return (int) (i / 2);
    }

    public int leftChild(int i) {
        return (2 * i);
    }

    public int rightChild(int i) {
        return (2 * i + 1);
    }

    public void insert(int e) {
        this.noOfElements++;
        heap[noOfElements - 1] = e;
        if (noOfElements == 1) {
            return;
        }

        int childNodeIndex = noOfElements;
        int parentNodeIndex = this.parent(childNodeIndex);

        while ((childNodeIndex > 1) && (heap[parentNodeIndex - 1] < heap[childNodeIndex - 1])) {

            int t = heap[parentNodeIndex - 1];
            heap[parentNodeIndex - 1] = heap[childNodeIndex - 1];
            heap[childNodeIndex - 1] = t;

            childNodeIndex = parentNodeIndex;
            parentNodeIndex = this.parent(parentNodeIndex);
        }
    }

    public int extractMax() {
        int maxElement = heap[0];
        heap[0] = heap[noOfElements - 1];
        heap[noOfElements - 1] = null;

        int parentNodeIndex = 1;
        int childNodeIndex = Math.max(leftChild(parentNodeIndex), rightChild(parentNodeIndex));

        while ((childNodeIndex < noOfElements - 1) && (heap[parentNodeIndex - 1] < heap[childNodeIndex - 1])) {
            int t = heap[parentNodeIndex - 1];
            heap[parentNodeIndex - 1] = heap[childNodeIndex - 1];
            heap[childNodeIndex - 1] = t;

            parentNodeIndex = childNodeIndex;
            childNodeIndex = Math.max(leftChild(parentNodeIndex), rightChild(parentNodeIndex));
        }
        this.noOfElements--;
        return maxElement;
    }

    public static void main(String[] args) {
        int[] arr = {9, 2, 6, 5, 3, 7, 1, 4};
        HighHeap lHeap = new HighHeap(arr);
        lHeap.printData();
        System.out.println("");

        int maxElement = lHeap.extractMax();
        System.out.println("max element = " + maxElement);
        lHeap.printData();
    }

    private void printData() {
        int maxSpaces = 0;
        int n = noOfElements;
        while (n > 1) {
            n = n / 2;
            maxSpaces++;
        }
        maxSpaces++;
        int noOfElementsToPrint = 1;
        int index = 0;
        int count = 0;
        for (int j = 0; j < maxSpaces; j++) {
            for (int k = 0; k < maxSpaces - j; k++) {
                System.out.print(" ");
            }
            for (int i = 0; i < noOfElementsToPrint && count < noOfElements; i++) {
                System.out.print(this.heap[count++] + " ");
            }
            System.out.println("");
            noOfElementsToPrint *= 2;
        }
    }
}
