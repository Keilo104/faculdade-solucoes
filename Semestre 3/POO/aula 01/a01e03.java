import java.util.Scanner;

class a01e03 {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        int ano = leitor.nextInt();

        if (ano % 400 == 0 || (ano % 100 != 0 && ano % 4 == 0)) {
            System.out.println("Ano bissexto");
        } else {
            System.out.println("Ano nao bissexto");
        }
    }
}
