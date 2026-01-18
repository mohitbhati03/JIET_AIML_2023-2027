import java.util.Scanner;

class RandomCheck {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();

        System.out.print("Enter '1' to check for Palindrome & '2' to check for Armstrong: ");
        int option = sc.nextInt();

        int temp = num, digit, rev = 0, sum = 0;

        switch (option) {
            case 1:
                while (num > 0) {
                    digit = num % 10;
                    rev = rev * 10 + digit;
                    num /= 10;
                }
                if (rev == temp) {
                    System.out.println("Palindrome");
                } else {
                    System.out.println("Not Palindrome");
                }
                break;

            case 2:
                num = temp;
                while (num > 0) {
                    digit = num % 10;
                    sum = sum + (digit * digit * digit);
                    num /= 10;
                }
                if (sum == temp) {
                    System.out.println("Armstrong");
                } else {
                    System.out.println("Not Armstrong");
                }
                break;

            default:
                System.out.println("Check not applicable.");
        }
    }
}