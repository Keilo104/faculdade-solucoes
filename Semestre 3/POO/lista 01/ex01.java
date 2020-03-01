package lista1;

import java.util.Scanner;

public class ex01 {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        int maior, menor, temp;

        maior = leitor.nextInt();
        menor = maior;

        for (int i = 0; i < 4; i++) {
            temp = leitor.nextInt();

            if(temp > maior) {
                maior = temp;
            } else if (temp < menor) {
                menor = temp;
            }
        }

        System.out.printf("%d, %d", maior, menor);

    }
}
