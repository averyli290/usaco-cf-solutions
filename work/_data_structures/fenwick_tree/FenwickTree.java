/*
Implementation of a Fenwick Tree in Java.
*/

import java.util.ArrayList;
import java.util.Collections;

public class FenwickTree {
    int size;
    int[] tree;

    public FenwickTree(int size) {
        this.size = size;
        this.tree = new int[size];
        for(int i = 0; i < size; i++) {
            this.tree[i] = 0;
        }
    }
    
    public FenwickTree(int[] arr) {
        this.size = arr.length;
        this.tree = new int[this.size];
        for(int i = 0; i < this.size; i++) {
            this.add(i, arr[i]);
        }
        for(int i = 0; i < this.size; i++) {
            System.out.println(this.tree[i]);
        }
    }

    public int sum(int r) {
        int res = 0;
        while (r >= 0) {
            res += this.tree[r];
            r = (r & (r + 1)) - 1;
        }
        return res;
    }

    public int sum(int l, int r) {
        return this.sum(r) - this.sum(l - 1);
    }

    public void add(int idx, int delta) {
        while (idx < this.size) {
            this.tree[idx] += delta;
            idx = idx | (idx + 1);
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[8];
        for (int i = 0; i < 8; i++) {
            arr[i] = i;
        }
        FenwickTree test = new FenwickTree(arr);
        System.out.println("Sum: ");
        System.out.println(test.sum(0, 2));
    }
}