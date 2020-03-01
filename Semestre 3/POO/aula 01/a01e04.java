import java.util.Scanner;

class a01e04 {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        int operador = leitor.nextInt();
        int a = leitor.nextInt();
        int b = leitor.nextInt();

        switch(operador) {
            case 0:
                System.out.println(a + b);
                break;
            case 1:
                System.out.println(a - b);
                break;
            case 2:
                System.out.println(a * b);
                break;
            case 3:
                if (b != 0 && a != 0) {
                    if (((float) a / b) % 1 == 0) {
                        System.out.println(a / b);
                    } else {
                        System.out.println((float) a / b);
                    }
                } else {
                    System.out.println("Erro");
                }
                break;
            case 4:
                System.out.println((int) Math.pow(a, b));
                break;
            case 5:
                if (b != 0 && a != 0) {
                    System.out.println(a % b);
                } else {
                    System.out.println("Erro");
                }
                break;
            default:
                System.out.println("Erro");
                break;
        }
    }
}
