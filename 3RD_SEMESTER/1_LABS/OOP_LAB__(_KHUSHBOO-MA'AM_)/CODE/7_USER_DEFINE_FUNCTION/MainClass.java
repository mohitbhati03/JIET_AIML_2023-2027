class FunctionDemo {
    int num1, num2, res;

    void printValue() {
        System.out.println("Numbers are: " + num1 + " " + num2);
    }

    void setValues(int n1, int n2) {
        num1 = n1;
        num2 = n2;
    }

    int add() {
        res = num1 + num2; // Add the missing semicolon here
        return res;
    }

    int sub() {
        return (num1 - num2);
    }
}

class MainClass {
    public static void main(String args[]) {
        FunctionDemo fd1 = new FunctionDemo();
        
        // Initialize values before printing
        fd1.setValues(0, 0); // Set initial values to avoid displaying defaults
        fd1.printValue();
        
        // Set new values and perform addition
        fd1.setValues(1, 2);
        int sum = fd1.add();
        System.out.println("Sum of numbers = " + sum);
        
        fd1.printValue();
        System.out.println("Difference of the numbers = " + fd1.sub());
    }
}