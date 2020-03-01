package lista1;

import java.util.Scanner;

public class ex09 {
    static int calcDoces(int x, int m, int r) {
        if(x + r >= m) {
            x += calcDoces((x + r) / m, m, (x + r) % m);
        }
        return x;
    }

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        float dinheiro, preco;
        int promo;

        System.out.print("Digite a quantidade de dinheiro de Xozé: ");
        dinheiro = leitor.nextFloat();

        System.out.print("Digite o preço dos chocolates: ");
        preco = leitor.nextFloat();

        System.out.print("Digite a quantidade de papéis para a promoção: ");
        promo = leitor.nextInt();

        System.out.printf("Quantidade de chocolates comidos: %d", calcDoces((int) (dinheiro / preco), promo, 0));
    }
}
