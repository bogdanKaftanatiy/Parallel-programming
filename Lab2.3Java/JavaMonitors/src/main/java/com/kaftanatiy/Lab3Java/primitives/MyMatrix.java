package com.kaftanatiy.Lab3Java.primitives;

import java.util.Random;

/**
 * Model of matrix with size N*N
 * @author Bogdan Kaftanatiy
 * */
public class MyMatrix {
    private int dimension;
    private int[][] array;

    public MyMatrix(int dimension) {
        this.dimension = dimension;
        array = new int[dimension][dimension];
    }

    public MyMatrix(MyMatrix other) {
        this.dimension = other.dimension;
        array = new int [this.dimension][this.dimension];
        for (int i = 0; i < this.dimension; i++) {
            for(int j = 0; j < this.dimension; j++) {
                this.array[i][j] = other.array[i][j];
            }
        }
    }

    public void generate(int maxValue) {
        Random generator = new Random();
        for (int i = 0; i < dimension; i++){
            for (int j = 0; j < dimension; j++){
                array[i][j] = generator.nextInt(maxValue);
            }
        }
    }

    public void fill() {
        for (int i = 0; i < dimension; i++){
            for (int j = 0; j < dimension; j++){
                array[i][j] = 1;
            }
        }
    }

    public int get(int i, int j) {
        return array[i][j];
    }

    public void set(int i, int j, int value) {
        array[i][j] = value;
    }

    public int getDimension() {
        return dimension;
    }

    @Override
    public String toString() {
        String result = "";
        for (int i = 0; i < dimension; i++){
            for (int j = 0; j < dimension; j++){
                result += array[i][j] +"\t";
            }
            result += "\n";
        }
        return result;
    }
}
