import threads.*;

/**
 * Created by Bogdan Kaftanatiy on 26.09.2016.
 */
public class Main {
    public static void main(String[] args) {
        Thread t1 = new Thread(new FirstThread());
        Thread t2 = new Thread(new SecondThread());
        Thread t3 = new Thread(new ThirdThread());
        t1.start();
        t2.start();
        t3.start();

        try {
            t1.join();
            t2.join();
            t3.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
