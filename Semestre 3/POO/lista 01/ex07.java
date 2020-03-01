package lista1;

import java.util.Scanner;

public class ex07 {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        int[] vetor = new int[5];
        int pares = 0, imp = 0;

        for (int i = 0; i < 5; i++) {
            vetor[i] = leitor.nextInt();
            if(vetor[i] % 2 == 0) {
                pares += vetor[i];
            } else {
                imp += vetor[i];
            }
        }

        System.out.printf("Soma dos pares: %d\n", pares);
        System.out.printf("Soma dos ímpares: %d\n", imp);
    }
}
