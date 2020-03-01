package lista1;

import java.util.Scanner;

public class ex02 {
    static int recursiveFactorial(int x) {
        if(x > 0) {
            int temp = recursiveFactorial(x - 1);
            x *= temp;
        } else {
            return 1;
        }
        return x;
    }

    static int iterativeFactorial(int x) {
        int temp = 1;

        for (int i = 1; i < x+1; i++) {
            temp *= i;
        }

        return temp;
    }

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        int input = leitor.nextInt();

        System.out.printf("recursivo: %d, iterativo: %d", recursiveFactorial(input), iterativeFactorial(input));
    }
}
