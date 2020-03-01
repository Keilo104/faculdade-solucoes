import java.util.Scanner;

public class a02e01 {
    public static void main(String[] args) {
        int[] dias;
        dias = new int[7];
        Scanner leitor = new Scanner(System.in);
        int total = 0;
        int cont = 0;

        for(int i = 0; i < 7; i++) {
            dias[i] = leitor.nextInt();
            total += dias[i];
        }

        for(int i:dias) {
            if(i > total/7) {
                cont += 1;
            }
        }

        System.out.println(cont);

    }
}
