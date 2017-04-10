package com.kaftanatiy.Lab3Java.threads;

import com.kaftanatiy.Lab3Java.Main;
import com.kaftanatiy.Lab3Java.primitives.MyMatrix;
import com.kaftanatiy.Lab3Java.primitives.MyVector;

public class Task2 implements Runnable {
    private int startIndex;
    private int endIndex;

    private DataControl dataMonitor;
    private TaskControl taskMonitor;

    private int alpha2;
    private int beta2;
    private MyVector S2;
    private MyMatrix MK2;

    public Task2(DataControl dm, TaskControl tm) {
        dataMonitor = dm;
        taskMonitor = tm;

        startIndex = Main.H;
        endIndex = Main.H * 2;
    }

    @Override
    public void run() {
        //input
        Main.MO.fill();
        Main.Z.fill();

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
        alpha2 = dataMonitor.copyAlpha();
        beta2 = dataMonitor.copyBeta();
        S2 = dataMonitor.copyS();
        MK2 = dataMonitor.copyMK();

        //Calculate
        for (int i = startIndex; i < endIndex; i++) {
            //MO*MK
            MyVector temp = new MyVector(Main.N);
            for (int j = 0; j < Main.N; j++) {
                int element = 0;
                for(int k = 0; k < Main.N; k++) {
                    element += Main.MO.get(i, k) * MK2.get(k, j);
                }
                temp.set(j, element);
            }

            //S*(MO*MK)
            int sum = 0;
            for (int j = 0; j < Main.N; j++) {
                sum += S2.get(j) * temp.get(j);
            }

            //b*S*(MO*MK)
            sum *= beta2;

            //a*E+b*S*(MO*MK)
            sum = alpha2 * Main.E.get(i) + sum;

            Main.A.set(i, sum);
        }
        //End calculate

        taskMonitor.signalCalcDone();
    }
}
