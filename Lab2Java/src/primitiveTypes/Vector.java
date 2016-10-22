package primitiveTypes;

import java.util.Random;

/**
 * Created by Bogdan Kaftanatiy on 26.09.2016.
 */
public class Vector {
    private int dimension;
    private int[] array;

    public Vector(int dimension) {
        this.dimension = dimension;
        array = new int[dimension];
    }

    public Vector(Vector other) {
        this.dimension = other.dimension;
        this.array = new int[this.dimension];
        for(int i = 0; i < dimension; i++) {
            this.array[i] = other.array[i];
        }
    }

    public void generate(int maxValue) {
        Random generator = new Random();

        for (int i = 0; i < dimension; i++) {
            array[i] = generator.nextInt(maxValue);
        }
    }

    public int multipleVectors(Vector other) {
        int result = 0;

        for (int i = 0; i < dimension; i++) {
            result += array[i] * other.array[i];
        }

        return result;
    }

    public Vector multipleMatrix(Matrix other) {
        Vector result = new Vector(other.getDimension());
        for (int k = 0; k < result.dimension; k++) {
            result.array[k] = 0;
            for (int i = 0; i < dimension; i++){
                result.array[k] += other.get(k, i) * this.array[i];
            }
        }
        return result;
    }

    public Vector sumVectors(Vector other) {
        Vector result = new Vector(dimension);

        for (int i = 0; i < dimension; i++) {
            result.array[i] = this.array[i] + other.array[i];
        }

        return result;
    }

    public Vector sortVector() {
        Vector result = new Vector(this);

        boolean flag = true;
        while (flag) {
            flag = false;
            for (int i = 1; i < dimension; i++) {
                if(result.array[i-1] > result.array[i]) {
                    int temp = result.array[i-1];
                    result.array[i-1] = result.array[i];
                    result.array[i] = temp;
                    flag = true;
                }
            }
        }

        return result;
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
