import java.util.Scanner;

public class ead01ex02 {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        String input = leitor.nextLine().trim();
        int k = leitor.nextInt();

        String s1 = "", s2 = "", temp;

        if(input.length() >= k) {
            s1 = input.substring(0, k);
            s2 = input.substring(0, k);

            for (int i = 0; i < input.length() - k + 1; i++) {
                temp = input.substring(i, i+k);

                if(temp.compareTo(s1) < 0) {
                    s1 = temp;
                }
                if(temp.compareTo(s2) > 0) {
                    s2 = temp;
                }
            }
            System.out.printf("%s %s", s1, s2);
        }
    }
}
