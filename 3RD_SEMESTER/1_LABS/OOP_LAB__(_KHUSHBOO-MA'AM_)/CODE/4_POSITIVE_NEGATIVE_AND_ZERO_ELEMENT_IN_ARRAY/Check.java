import java.util.Scanner;

public class Check {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements for array: ");
        int noe = sc.nextInt();
        int[] arr = new int[noe];

        System.out.println("Enter " + noe + " elements in array: ");
        for (int i = 0; i < noe; i++) {
            arr[i] = sc.nextInt();
        }

        int np = 0, nn = 0, nz = 0;
        for (int i = 0; i < noe; i++) {
            if (arr[i] > 0) {
                np++;
            } else if (arr[i] < 0) {
                nn++;
            } else {
                nz++;
            }
        }

        System.out.println("Number of positive elements = " + np);
        System.out.println("Number of negative elements = " + nn);
        System.out.println("Number of zero elements = " + nz);
    }
}