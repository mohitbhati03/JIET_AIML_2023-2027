class A extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("From Thread A: i=" + i);
        }
        System.out.println("Exit from Thread A");
    }
}

class B extends Thread {
    public void run() {
        for (int j = 1; j <= 5; j++) {
            System.out.println("From Thread B: j=" + j);
        }
        System.out.println("Exit from Thread B");
    }
}

class ThreadTest {
    public static void main(String args[]) {
        System.out.println("main thread started");
        A a = new A();
        a.start();
        B b = new B();
        b.start();
        System.out.println("main thread ended");
    }
}