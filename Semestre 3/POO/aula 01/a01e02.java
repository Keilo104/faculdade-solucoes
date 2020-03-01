import java.util.Scanner;

class a01e02 {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        int a = leitor.nextInt();
        int b = leitor.nextInt();
        int c = leitor.nextInt();

        if (a < 1 || b < 1 || c < 1) {
            System.out.println("Erro");
        } else if (a+b <= c || a+c <= b || b+c <= a) {
            System.out.println("Nao forma triangulo");
        } else if (a == b || b == c || a == c) {
            if(a == b && b == c) {
                System.out.println("Equilatero");
            } else {
                System.out.println("Isosceles");
            }

        } else {
            System.out.println("Escaleno");
        }
    }
}
