/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package heap;

/**
 *
 * @author Aakash
 */
public class SortedHeap {

    public static final boolean LOW_HEAP = true;
    public static final boolean HIGH_HEAP = false;
    private boolean typeOfHeap = LOW_HEAP;
    private int noOfElements = 0;
    private Integer[] heap;

    public SortedHeap(int size, boolean typeOfHeap) {
        this.typeOfHeap = typeOfHeap;
        heap = new Integer[size];
    }

    public SortedHeap(int[] elements, boolean typeOfHeap) {
        this.typeOfHeap = typeOfHeap;
        this.heap = new Integer[elements.length];
        for (int i = 0; i < elements.length; i++) {
            this.insert(elements[i]);
        }
    }

    public void insert(int e) {
        this.noOfElements++;
        heap[noOfElements - 1] = e;
        if (noOfElements == 1) {
            return;
        }

        int childNodeIndex = noOfElements;
        int parentNodeIndex = this.parent(childNodeIndex);

        while ((childNodeIndex > 1) && (compareNodes(parentNodeIndex, childNodeIndex))) {
            int t = heap[parentNodeIndex - 1];
            heap[parentNodeIndex - 1] = heap[childNodeIndex - 1];
            heap[childNodeIndex - 1] = t;

            childNodeIndex = parentNodeIndex;
            parentNodeIndex = this.parent(parentNodeIndex);
        }
    }

    public int extract() {
        int element = heap[0];
        heap[0] = heap[noOfElements - 1];
        heap[noOfElements - 1] = null;
        this.noOfElements--;

        int parentNodeIndex = 1;
        int childNodeIndex = getChildNodeIndex(parentNodeIndex);
        
        while ((childNodeIndex <= noOfElements) && (compareNodes(parentNodeIndex, childNodeIndex))) {
            int t = heap[parentNodeIndex - 1];
            heap[parentNodeIndex - 1] = heap[childNodeIndex - 1];
            heap[childNodeIndex - 1] = t;

            parentNodeIndex = childNodeIndex;
            childNodeIndex = getChildNodeIndex(parentNodeIndex);
        }
        return element;
    }

    public static void main(String[] args) {
        int[] arr = {9, 2, 6, 5, 3, 7, 1, 4};
        SortedHeap lHeap = new SortedHeap(arr, SortedHeap.HIGH_HEAP);
        lHeap.printData();
        System.out.println("");

        for (int i = 0; i < arr.length; i++) {
            System.out.println("-----------");
            int element = lHeap.extract();
            System.out.println("extract = " + element);
            lHeap.printData();
        }
    }

    public static int parent(int i) {
        return (int) (i / 2);
    }

    public static int leftChild(int i) {
        return (2 * i);
    }

    public static int rightChild(int i) {
        return (2 * i + 1);
    }

    private boolean compareNodes(int parentNodeIndex, int childNodeIndex) {
        if (typeOfHeap == LOW_HEAP) {
            return (heap[parentNodeIndex - 1] > heap[childNodeIndex - 1]);
        } else {
            return (heap[parentNodeIndex - 1] < heap[childNodeIndex - 1]);
        }
    }

    private int getChildNodeIndex(int parentNodeIndex) {
        if (leftChild(parentNodeIndex) > noOfElements) {
            return noOfElements + 5;
        } else if (rightChild(parentNodeIndex) > noOfElements) {
            return leftChild(parentNodeIndex);
        } else {
            if (typeOfHeap == LOW_HEAP) {
                if ((heap[leftChild(parentNodeIndex) - 1] <= heap[rightChild(parentNodeIndex) - 1])) {
                    return leftChild(parentNodeIndex);
                } else {
                    return rightChild(parentNodeIndex);
                }
            } else {
                if ((heap[leftChild(parentNodeIndex) - 1] >= heap[rightChild(parentNodeIndex) - 1])) {
                    return leftChild(parentNodeIndex);
                } else {
                    return rightChild(parentNodeIndex);
                }
            }
        }
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
