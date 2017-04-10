package com.kaftanatiy.Lab3Java.threads;

import com.kaftanatiy.Lab3Java.Main;
import com.kaftanatiy.Lab3Java.primitives.MyMatrix;
import com.kaftanatiy.Lab3Java.primitives.MyVector;

public class Task3 implements Runnable {
    private int startIndex;
    private int endIndex;

    private DataControl dataMonitor;
    private TaskControl taskMonitor;

    private int alpha3;
    private int beta3;
    private MyVector S3;
    private MyMatrix MK3;

    public Task3(DataControl dm, TaskControl tm) {
        dataMonitor = dm;
        taskMonitor = tm;

        startIndex = Main.H * 2;
        endIndex = Main.H * 3;
    }

    @Override
    public void run() {
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
        alpha3 = dataMonitor.copyAlpha();
        beta3 = dataMonitor.copyBeta();
        S3 = dataMonitor.copyS();
        MK3 = dataMonitor.copyMK();

        //Calculate
        for (int i = startIndex; i < endIndex; i++) {
            //MO*MK
            MyVector temp = new MyVector(Main.N);
            for (int j = 0; j < Main.N; j++) {
                int element = 0;
                for(int k = 0; k < Main.N; k++) {
                    element += Main.MO.get(i, k) * MK3.get(k, j);
                }
                temp.set(j, element);
            }

            //S*(MO*MK)
            int sum = 0;
            for (int j = 0; j < Main.N; j++) {
                sum += S3.get(j) * temp.get(j);
            }

            //b*S*(MO*MK)
            sum *= beta3;

            //a*E+b*S*(MO*MK)
            sum = alpha3 * Main.E.get(i) + sum;

            Main.A.set(i, sum);
        }
        //End calculate

        taskMonitor.signalCalcDone();
    }
}
