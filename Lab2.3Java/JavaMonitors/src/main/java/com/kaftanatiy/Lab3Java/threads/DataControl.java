package com.kaftanatiy.Lab3Java.threads;

import com.kaftanatiy.Lab3Java.Main;
import com.kaftanatiy.Lab3Java.primitives.MyMatrix;
import com.kaftanatiy.Lab3Java.primitives.MyVector;

/**
 * Monitor class to synchronize access to data
 * @author Bogdan Kaftanatiy
 */
public class DataControl {
    private int alpha;
    private int beta;
    private MyVector S;
    private MyMatrix MK;

    public DataControl() {
        alpha = 0;
        beta = Integer.MAX_VALUE;
        S = new MyVector(Main.N);
        MK = new MyMatrix(Main.N);
    }

    public synchronized void calculateAlpha(int a) {
        alpha += a;
    }

    public int copyAlpha() {
        return alpha;
    }


    public synchronized void calculateBeta(int b) {
        if(b < beta)
            beta = b;
    }

    public int copyBeta() {
        return beta;
    }


    public synchronized void inputS() {
        S.fill();
    }

    public MyVector copyS() {
        return new MyVector(S);
    }


    public synchronized void inputMK() {
        MK.fill();
    }

    public MyMatrix copyMK() {
        return new MyMatrix(MK);
    }
}
