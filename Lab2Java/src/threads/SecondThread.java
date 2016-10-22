package threads;

import primitiveTypes.*;

/**
 * Created by Bogdan Kaftanatiy on 26.09.2016.
 */
public class SecondThread implements FunctionsThread {
    private int size = 10;
    private Matrix MG = new Matrix(size);
    private Matrix MH = new Matrix(size);
    private Matrix MK = new Matrix(size);

    @Override
    public void generateElements() {
        MG.generate(100);
        MH.generate(100);
        MK.generate(100);
        System.out.println("Function 2 arguments generate\n MG:\n" + MG + "\nMH:\n" + MH + "\nMK:\n" + MK);
    }

    @Override
    public void calculateFunction() {
        Matrix result;
        Matrix multipleMatrix = MH.multipleMatrix(MK);
        result = multipleMatrix.multipleNumber(MG.getMaxElement());
        System.out.println("Function 2 calculated\nFunction 2 result = \n" + result);
    }

    @Override
    public void run() {
        generateElements();
        calculateFunction();
    }
}
