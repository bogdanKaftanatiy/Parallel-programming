package com.kaftanatiy.Lab3Java;

import com.kaftanatiy.Lab3Java.primitives.*;
import com.kaftanatiy.Lab3Java.threads.*;

/**
 * Lab 3. Java
 * A = (B * C) * E + min(Z) * S * (MO * MK)
 * @author Bogdan Kaftanatiy IP-42
 */
public class Main {

    public static int N = 4;
    public static final int P = 4;
    public static int H = N / P;

    public static MyVector A = new MyVector(N);
    public static MyVector B = new MyVector(N);
    public static MyVector C = new MyVector(N);
    public static MyVector E = new MyVector(N);
    public static MyVector Z = new MyVector(N);
    public static MyMatrix MO = new MyMatrix(N);

    public static void main(String[] args) {
        Thread[] tasks = new Thread[P];
        DataControl dm = new DataControl();
        TaskControl tm = new TaskControl();

        tasks[0] = new Thread(new Task1(dm, tm));
        tasks[1] = new Thread(new Task2(dm, tm));
        tasks[2] = new Thread(new Task3(dm, tm));
        tasks[3] = new Thread(new Task4(dm, tm));

        for (int i = 0; i < P; i++) {
            tasks[i].start();
        }
    }
}
