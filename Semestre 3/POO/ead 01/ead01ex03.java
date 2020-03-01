import java.util.Scanner;

public class ead01ex03 {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        String input = leitor.nextLine();
        boolean flag = true;

        for (int i = 0; i < input.length(); i++) {
            if(input.charAt(i) != input.charAt(input.length() - i - 1)) {
                flag = false;
                break;
            }
        }

        if(flag) {
            System.out.println("Sim");
        } else {
            System.out.println("Nao");
        }
    }
}
