package lista1;

import java.util.Scanner;

public class ex03 {
    static void recursiveWTF(int x) {
        if(x > 1) {
            if(x % 2 == 0) {
                x = x /2;
            } else {
                x = (3 * x) + 1;
            }
            System.out.printf("%d, ", x);
            recursiveWTF(x);
        }
    }

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        int input = leitor.nextInt();

        recursiveWTF(input);
    }
}
