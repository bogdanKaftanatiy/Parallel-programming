package com.kaftanatiy.Lab3Java.threads;

/**
 * Monitor class to synchronize threads
 * @author Bogdan Kaftanatiy
 */
public class TaskControl {
    private int inputCount = 0;
    private int alphaCount = 0;
    private int betaCount = 0;
    private int calcCount = 0;

    public synchronized void signalInputDone() {
        inputCount++;
        if(inputCount == 3)
            notifyAll();
    }

    public synchronized void waitInput() {
        while (inputCount < 3) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }


    public synchronized void signalCalcAlphaDone() {
        alphaCount++;
        if(alphaCount == 4)
            notifyAll();
    }

    public synchronized void waitCalcAlpha() {
        while (alphaCount < 4){
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }


    public synchronized void signalCalcBetaDone() {
        betaCount++;
        if (betaCount == 4)
            notifyAll();
    }

    public synchronized void waitCalcBeta() {
        while (betaCount < 4) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }


    public synchronized void signalCalcDone() {
        calcCount++;
        if (calcCount == 3)
            notifyAll();
    }

    public synchronized void waitCalc() {
        while (calcCount < 3) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
