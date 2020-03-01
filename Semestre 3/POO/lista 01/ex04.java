package lista1;

import java.util.Scanner;

public class ex04 {
    static int recursiveFibonacci(int x) {
        if(x > 2) {
            x = recursiveFibonacci(x - 1) + recursiveFibonacci(x - 2);

            return x;
        } else {
            return 1;
        }
    }

    static void iterativeFibonacci(int x) {
        int a = 1, b = 1, c;

        for (int i = 0; i < x; i++) {
            System.out.printf("%d, ", a);
            c = b;
            b = a + b;
            a = c;
        }
    }

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        int input = leitor.nextInt();

        iterativeFibonacci(input);
        System.out.printf("\n%d",recursiveFibonacci(input));
    }
}
