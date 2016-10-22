package threads;

import primitiveTypes.*;

/**
 * Created by Bogdan Kaftanatiy on 26.09.2016.
 */
public class FirstThread implements FunctionsThread {
    private int size = 10;
    private Matrix MA = new Matrix(size);
    private Matrix MB = new Matrix(size);
    private Vector A = new Vector(size);
    private Vector B = new Vector(size);

    @Override
    public void generateElements() {
        MA.generate(100);
        MB.generate(100);
        A.generate(100);
        B.generate(100);
        System.out.println("Function 1 arguments generate\nMA:\n" + MA + "\nMB:\n" + MB + "\nA\n" + A + "\nB\n" + B);
    }

    @Override
    public void calculateFunction() {
        int result;
        Matrix maxMatrix = MA.multipleMatrix(MB);
        result = maxMatrix.getMaxElement() * A.multipleVectors(B);
        System.out.println("Function 1 calculated\nFunction 1 result = " + result);
    }

    @Override
    public void run() {
        generateElements();
        calculateFunction();
    }
}
