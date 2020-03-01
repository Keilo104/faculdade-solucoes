package lista1;

import java.util.Random;

public class ex08 {
    public static void main(String[] args) {
        Random rand = new Random();
        int[] qtdd = new int[11];
        int temp;

        for (int i = 0; i < 100000; i++) {
            temp = rand.nextInt(6) + rand.nextInt(6);

            qtdd[temp]++;
        }

        for (int i = 0; i < 11; i++) {
            System.out.printf("Quantidade de somas igual a %d: %.2f%%\n", i+2, (float) qtdd[i] / 1000);
        }
    }
}
