import java.util.Scanner;

class MainClass {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int num1, num2, res;
        System.out.println("Enter two numbers: ");
        num1 = sc.nextInt();
        num2 = sc.nextInt();
        
        try {
            if (num2 == 0) {
                throw new ArithmeticException();
            }
            res = num1 / num2;
            System.out.println("Result = " + res);
        } catch (ArithmeticException exp) {
            System.out.println("Cannot divide by 0.");
            System.out.println(exp);
        } finally {
            sc.close(); // Close the scanner
        }
    }
}