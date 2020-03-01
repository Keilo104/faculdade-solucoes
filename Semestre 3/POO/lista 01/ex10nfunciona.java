package lista1;

import java.util.Scanner;

public class ex10nfunciona {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        int qtd, maior, idx, temp, dinheiro;

        System.out.print("Digite a quantidade de dinheiro em centavos: ");
        dinheiro = leitor.nextInt();

        System.out.print("Digite a quantidade de moedas: ");
        qtd = leitor.nextInt();

        int[][] vetor = new int[qtd][2];

        for (int i = 0; i < qtd; i++) {
            System.out.printf("Digite o valor da %dª moeda: ", i+1);
            vetor[i][0] = leitor.nextInt();
        }

        // ordenando vetor
        for (int i = 0; i < qtd; i++) {
            maior = vetor[i][0];
            idx = i;

            for (int j = i+1; j < qtd; j++) {
                if(maior < vetor[j][0]) {
                    maior = vetor[j][0];
                    idx = j;
                }
            }

            temp = vetor[i][0];
            vetor[i][0] = vetor[idx][0];
            vetor[idx][0] = temp;
        }

        for (int i = 0; i < qtd; i++) {
            vetor[i][1] = dinheiro / vetor[i][0];
            dinheiro -= (vetor[i][1] * vetor[i][0]);
        }

        if(dinheiro == 0) {
            for (int i = 0; i < qtd; i++) {
                System.out.printf("Quantidade de moedas de %d centavos: %d\n", vetor[i][0], vetor[i][1]);
            }
        } else {
            System.out.println("Nenhuma combinação possível");
        }
    }
}
