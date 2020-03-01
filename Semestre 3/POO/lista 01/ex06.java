package lista1;

import java.util.Scanner;

public class ex06 {
    public static void main(String[] args) {
        int[] A = new int[5];
        int[] B = new int[5];
        int[] C = new int[5];
        Scanner leitor = new Scanner(System.in);
        boolean flag = false;

        for(int i = 0; i < 5; i++) {
            A[i] = leitor.nextInt();
        }

        for(int i = 0; i < 5; i++) {
            B[i] = leitor.nextInt();
        }

        for(int i = 0; i < 5; i++) {
            try {
                C[i] = Math.addExact(A[i], B[i]);
            } catch (ArithmeticException e){
                flag = true;
            }
        }

        if(flag) {
            System.out.println("Erro");
        } else {
            System.out.printf("%d, %d, %d, %d, %d", C[0], C[1], C[2], C[3], C[4]);
        }
    }
}
