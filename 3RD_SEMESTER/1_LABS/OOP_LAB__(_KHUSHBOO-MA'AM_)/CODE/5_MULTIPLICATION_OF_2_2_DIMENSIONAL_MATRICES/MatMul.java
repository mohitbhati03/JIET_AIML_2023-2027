import java.util.Scanner;

public class MatMul {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r1, c1, r2, c2;

        System.out.print("Enter the number of rows for matrix 1: ");
        r1 = sc.nextInt();
        System.out.print("Enter the number of columns for matrix 1: ");
        c1 = sc.nextInt();

        System.out.print("Enter the number of rows for matrix 2: ");
        r2 = sc.nextInt();
        System.out.print("Enter the number of columns for matrix 2: ");
        c2 = sc.nextInt();

        if (c1 != r2) {
            System.out.println("Matrix Multiplication not possible.");
            return;
        }

        int[][] mat1 = new int[r1][c1];
        int[][] mat2 = new int[r2][c2];
        int[][] resmat = new int[r1][c2];

        System.out.print("Enter " + (r1 * c1) + " elements in matrix 1: ");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                mat1[i][j] = sc.nextInt();
            }
        }

        System.out.print("Enter " + (r2 * c2) + " elements in matrix 2: ");
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                mat2[i][j] = sc.nextInt();
            }
        }

        System.out.println("You have entered the following matrices:");
        displayMatrix("Matrix 1", mat1);
        displayMatrix("Matrix 2", mat2);

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                int sum = 0;
                for (int k = 0; k < c1; k++) { 
                    sum += mat1[i][k] * mat2[k][j];
                }
                resmat[i][j] = sum;
            }
        }

        System.out.println("Resultant Matrix:");
        displayMatrix("Resultant Matrix", resmat);
    }
    
    private static void displayMatrix(String title, int[][] matrix) {
        System.out.println(title + ":");
        for (int[] row : matrix) {
            for (int value : row) {
                System.out.print(value + "\t");
            }
            System.out.println();
        }
    }
}