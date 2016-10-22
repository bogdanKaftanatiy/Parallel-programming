package primitiveTypes;

import java.util.Random;

/**
 * Created by Bogdan Kaftanatiy on 26.09.2016.
 */
public class Matrix {
    private int dimension;
    private int[][] array;

    public Matrix(int dimension) {
        this.dimension = dimension;
        array = new int[dimension][dimension];
    }

    public Matrix(Matrix other) {
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

    public int getMaxElement() {
        int result = Integer.MIN_VALUE;
        for (int i = 0; i < dimension; i++){
            for (int j = 0; j < dimension; j++) {
                if (array[i][j] > result)
                    result = array[i][j];
            }
        }
        return result;
    }

    public int get(int i, int j) {
        return array[i][j];
    }

    public int getDimension() {
        return dimension;
    }

    public Matrix trasparentMatrixs() {
        Matrix result = new Matrix(this);

        for (int i = 0; i < dimension; i++) {
            for (int j = i; j < dimension; j++) {
                int temp = result.array[i][j];
                result.array[i][j] = result.array[j][i];
                result.array[j][i] = temp;
            }
        }

        return result;
    }

    public Matrix multipleMatrix(Matrix other) {
        if(this.dimension != other.dimension)
            throw new IllegalArgumentException();
        Matrix result = new Matrix(dimension);

        for (int i = 0; i < dimension; i++){
            for (int j = 0; j < dimension; j++){
                result.array[i][j] = 0;
                for (int k = 0; k < dimension; k++){
                    result.array[i][j] += this.array[i][k] * other.array[k][j];
                }
            }
        }

        return result;
    }

    public Matrix multipleNumber(int number) {
        Matrix result = new Matrix(this);
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++){
                result.array[i][j] *= number;
            }
        }
        return result;
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
