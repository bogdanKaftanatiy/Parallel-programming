package com.kaftanatiy.Lab3Java.threads;

import com.kaftanatiy.Lab3Java.Main;
import com.kaftanatiy.Lab3Java.primitives.MyMatrix;
import com.kaftanatiy.Lab3Java.primitives.MyVector;

public class Task1 implements Runnable {
    private int startIndex;
    private int endIndex;

    private DataControl dataMonitor;
    private TaskControl taskMonitor;

    private int alpha1;
    private int beta1;
    private MyVector S1;
    private MyMatrix MK1;

    public Task1(DataControl dm, TaskControl tm) {
        dataMonitor = dm;
        taskMonitor = tm;

        startIndex = 0;
        endIndex = Main.H;
    }

    @Override
    public void run() {
        //input
        dataMonitor.inputMK();
        Main.B.fill();

        taskMonitor.signalInputDone();
        taskMonitor.waitInput();

        //Calculate alpha
        int alpha_i = 0;
        for (int i = startIndex; i < endIndex; i++) {
            alpha_i += Main.B.get(i) * Main.C.get(i);
        }
        dataMonitor.calculateAlpha(alpha_i);
        taskMonitor.signalCalcAlphaDone();

        //Calculate beta
        int beta_i = Integer.MAX_VALUE;
        for(int i = startIndex; i < endIndex; i++) {
            if(Main.Z.get(i) < beta_i)
                beta_i = Main.Z.get(i);
        }
        dataMonitor.calculateBeta(beta_i);
        taskMonitor.signalCalcBetaDone();

        taskMonitor.waitCalcAlpha();
        taskMonitor.waitCalcBeta();

        //Copy data
        alpha1 = dataMonitor.copyAlpha();
        beta1 = dataMonitor.copyBeta();
        S1 = dataMonitor.copyS();
        MK1 = dataMonitor.copyMK();

        //Calculate
        for (int i = startIndex; i < endIndex; i++) {
            //MO*MK
            MyVector temp = new MyVector(Main.N);
            for (int j = 0; j < Main.N; j++) {
                int element = 0;
                for(int k = 0; k < Main.N; k++) {
                    element += Main.MO.get(i, k) * MK1.get(k, j);
                }
                temp.set(j, element);
            }

            //S*(MO*MK)
            int sum = 0;
            for (int j = 0; j < Main.N; j++) {
                sum += S1.get(j) * temp.get(j);
            }

            //b*S*(MO*MK)
            sum *= beta1;

            //a*E+b*S*(MO*MK)
            sum = alpha1 * Main.E.get(i) + sum;

            Main.A.set(i, sum);
        }
        //End calculate

        taskMonitor.waitCalc();

        System.out.println("Result:");
        if(Main.N > 10)
            System.out.println("  is too large..");
        else
            System.out.println("A: " + Main.A);

    }
}
