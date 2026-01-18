import java.util.Scanner;

class Deposit {
    String depName, depAccType;
    long depAccNo;
    float depAmt, avalBal = 0;

    void getDepDetails(String name, String accType, long accNo) {
        depName = name;
        depAccType = accType;
        depAccNo = accNo;
    }

    void getDeposit(float amount) {
        depAmt = amount;
        avalBal += depAmt;
    }

    void showRecpt() {
        System.out.println("\nAccount Holder: " + depName);
        System.out.println("Account Type: " + depAccType);
        System.out.println("Amount Deposited: Rs. " + depAmt);
        System.out.println("Available Balance: Rs. " + avalBal);
    }
}

class MainClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Deposit dep1 = new Deposit();
        String name, accType;
        long accNo;
        float amount;
        int recpt;

        System.out.print("Enter Account Holder's Name: ");
        name = sc.nextLine();
        System.out.print("Enter Account Type: ");
        accType = sc.nextLine();
        System.out.print("Enter Account Number: ");
        accNo = sc.nextLong();
        System.out.print("Enter Deposit Amount: ");
        amount = sc.nextFloat();

        dep1.getDepDetails(name, accType, accNo);
        dep1.getDeposit(amount);

        System.out.print("Do you want a receipt? Enter 1 for yes and 0 for no: ");
        recpt = sc.nextInt();
        if (recpt == 1) {
            dep1.showRecpt();
        } else {
            System.out.println("Amount deposited successfully.");
        }

        sc.close(); 
    }
}