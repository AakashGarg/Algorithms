/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package heap;

/**
 *
 * @author Aakash
 */
public class LowHeap {

    private int noOfElements = 0;
    private Integer[] heap;

    public LowHeap(int size) {
        heap = new Integer[size];
    }

    public LowHeap(int[] elements) {
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

        while ((childNodeIndex > 1) && (heap[parentNodeIndex - 1] > heap[childNodeIndex - 1])) {

            int t = heap[parentNodeIndex - 1];
            heap[parentNodeIndex - 1] = heap[childNodeIndex - 1];
            heap[childNodeIndex - 1] = t;

            childNodeIndex = parentNodeIndex;
            parentNodeIndex = this.parent(parentNodeIndex);
        }
    }

    private int getChildNodeIndex(int parentNodeIndex) {
        int leftChildIndex = leftChild(parentNodeIndex);
        int rightChildIndex = rightChild(parentNodeIndex);
        if (leftChildIndex > noOfElements) {                                       //doesn't have a child
            return noOfElements + 5;
        } else if (rightChildIndex > noOfElements) {                                 //doesn't have a right child
            return leftChild(parentNodeIndex);
        } else {                                                                            //have both childs
            if ((heap[leftChild(parentNodeIndex) - 1] <= heap[rightChild(parentNodeIndex) - 1])) {
                //       System.out.println("comparing "+heap[leftChild(parentNodeIndex)]+" with "+heap[rightChild(parentNodeIndex)]);
                return leftChild(parentNodeIndex);
            } else {
                return rightChild(parentNodeIndex);
            }
        }
    }

    public int extractMin() {
        int minElement = heap[0];
        heap[0] = heap[noOfElements - 1];
        heap[noOfElements - 1] = null;
        noOfElements--;

        int parentNodeIndex = 1;
        int childNodeIndex = getChildNodeIndex(parentNodeIndex);
       // System.out.println("*****" + childNodeIndex);

        while ((childNodeIndex <= noOfElements) && (heap[parentNodeIndex - 1] > heap[childNodeIndex - 1])) {
            int t = heap[parentNodeIndex - 1];
            heap[parentNodeIndex - 1] = heap[childNodeIndex - 1];
            heap[childNodeIndex - 1] = t;

            parentNodeIndex = childNodeIndex;
            childNodeIndex = getChildNodeIndex(parentNodeIndex);
        }
        //   this.noOfElements--;
        return minElement;
    }

    public static void main(String[] args) {
        int[] arr = {9, 2, 6, 5, 3, 7, 1, 4};
        LowHeap lHeap = new LowHeap(arr);
        lHeap.printData();
        System.out.println("");

        for (int i = 0; i < arr.length; i++) {
            int minElement = lHeap.extractMin();
            System.out.println("min element = " + minElement);
            lHeap.printData();
            System.out.println("-----------");
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
