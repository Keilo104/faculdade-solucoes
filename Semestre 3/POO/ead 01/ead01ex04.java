import java.util.Scanner;

public class ead01ex04 {
    public static void main(String[] args) {
        /* Dada duas Strings A e B, faça um programa que imprima “Sim” se A e B são anagramas e “Nao”,
        caso contrário. Um anagrama é a transposição de letras de palavra ou frase para formar outra palavra
        ou frase diferente. Por exemplo, as palavras “roma” e “amor” são anagramas. Considere como entrada
        apenas palavras com letras minúsculas. */

        Scanner leitor = new Scanner(System.in);
        char[] s1, s2;
        boolean flag = true;

        s1 = leitor.nextLine().toCharArray();
        long contS1 = 1;
        s2 = leitor.nextLine().toCharArray();
        long contS2 = 1;

        if(s1.length == s2.length) {
            for (int i = 0; i < s1.length; i++) {
                contS1 *= (int) s1[i];
                contS2 *= (int) s2[i];
            }

            if(contS1 != contS2) {
                flag = false;
            }
        } else {
            flag = false;
        }

        if(flag) {
            System.out.println("Sim");
        } else {
            System.out.println("Nao");
        }
    }
}
