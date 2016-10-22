package threads;

import primitiveTypes.Matrix;
import primitiveTypes.Vector;

/**
 * Created by Bogdan Kaftanatiy on 26.09.2016.
 */
public class ThirdThread implements FunctionsThread {
    private int size = 10;
    private Vector O = new Vector(size);
    private Vector P = new Vector(size);
    private Matrix MR = new Matrix(size);
    private Matrix MS = new Matrix(size);

    @Override
    public void generateElements() {
        O.generate(100);
        P.generate(100);
        MR.generate(100);
        MS.generate(100);
        System.out.println("Function 3 arguments generate\nO:\n" + O + "\nP:\n" + P + "\nMR:\n" + MR + "\nMS:\n" + MS);
    }

    @Override
    public void calculateFunction() {
        Vector result;
        Vector sortVector = (O.sumVectors(P)).sortVector();
        Matrix transMatrix = (MR.multipleMatrix(MS)).trasparentMatrixs();
        result = sortVector.multipleMatrix(transMatrix);
        System.out.println("Function 3 calculated\nFunction 3 result = \n" + result);
    }

    @Override
    public void run() {
        generateElements();
        calculateFunction();
    }
}
