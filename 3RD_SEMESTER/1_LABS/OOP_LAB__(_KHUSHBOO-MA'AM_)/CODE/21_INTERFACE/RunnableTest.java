class X implements Runnable {
    public void run() {
        for (int i = 0; i <= 5; i++) {
            System.out.println("The Thread X is: " + i);
        }
        System.out.println("End of the Thread X");
    }
}

class RunnableTest {
    public static void main(String args[]) {
        X r = new X();
        Thread threadX = new Thread(r);
        threadX.start();
        System.out.println("The end of the main thread");
    }
}