import java.util.Scanner;

class MainClass {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int num1, num2, res;
        System.out.println("Enter two numbers: ");
        num1 = sc.nextInt();
        num2 = sc.nextInt();
        
        if (num2 != 0) {
            res = num1 / num2;
            System.out.println("Result = " + res);
        } else {
            System.out.println("Error: Division by zero is not allowed.");
        }
        
        sc.close();
    }
}