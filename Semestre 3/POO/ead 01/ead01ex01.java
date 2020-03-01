package ead;

import java.util.Scanner;

public class ead01ex01 {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        String input = leitor.nextLine();

        if(input.length() > 1){
            for(int i = 1; i < input.length(); i++) {

                for (int j = 0; j < i; j++) {
                    System.out.print(input.charAt(j));
                }

                System.out.print("*");
            }

            for(int i = input.length() - 1; i > 0; i--) {

                for (int j = 0; j < i; j++) {
                    System.out.print(input.charAt(j));
                }

                if(i != 1) {
                    System.out.print("*");
                }
            }
        } else {
            System.out.println("Invalido");
        }

    }
}
