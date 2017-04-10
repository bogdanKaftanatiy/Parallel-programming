package com.kaftanatiy.Lab3Java.primitives;

import java.util.Random;

/**
 * Model of Vector with size N
 * @author Bogdan Kaftanatiy
 */
public class MyVector {
    private int dimension;
    private int[] array;

    public MyVector(int dimension) {
        this.dimension = dimension;
        array = new int[dimension];
    }

    public MyVector(int[] array) {
        this.array = array;
        this.dimension = array.length;
    }

    public MyVector(MyVector vector) {
        this.dimension = vector.dimension;
        this.array = new int[dimension];
        for (int i = 0; i < dimension; i++) {
            array[i] = vector.array[i];
        }
    }

    public void generate(int maxValue) {
        Random generator = new Random();

        for (int i = 0; i < dimension; i++) {
            array[i] = generator.nextInt(maxValue);
        }
    }

    public void fill() {
        for (int i = 0; i < dimension; i++) {
            array[i] = 1;
        }
    }

    public int getDimension() {
        return dimension;
    }

    public void set(int i, int value) {
        if(i < 0 || i > dimension - 1)
            throw  new IllegalStateException();
        array[i] = value;
    }

    public int get(int i) {
        if(i < 0 || i > dimension - 1)
            throw  new IllegalStateException();
        return array[i];
    }

    @Override
    public String toString() {
        String result = "";

        for (int i = 0; i < dimension; i++) {
            result += array[i] + "\t";
        }

        return result;
    }
}
