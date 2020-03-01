import java.util.Scanner;

class a01e01 {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        int x = leitor.nextInt();
        double caseA = (0.25 * x) + 7.5;
        double caseB = (0.50 * x) + 2.5;

        if (x < 1) {
            System.out.println("Erro");
        } else if (caseA < caseB) {
            System.out.println("Criterio A");
        } else if (caseB < caseA){
            System.out.println("Criterio B");
        } else {
            System.out.println("Indiferente");
        }
    }
}
