import java.util.Scanner;

public class a02e03 {
    public static void main(String[] args) {
        int[] nros = new int[10];
        Scanner leitor = new Scanner(System.in);
        int cont = 0, temp, idx = 0;
        boolean flagSame = true, flagFim = false, flagAdc;

        for (int i = 0; i < 5 && flagSame; i++) {
            temp = leitor.nextInt();
            cont++;

            for (int j = 0; j < cont; j++) {
                if(nros[j] == temp) {
                    System.out.println("Erro");
                    flagSame = false;
                }
            }

            nros[i] = temp;
        }

        if(flagSame) {
            for (int i = 0; i < cont; i++) {
                System.out.printf("%d ", nros[i]);
            }

            System.out.println();

            while(!flagFim) {
                temp = leitor.nextInt();
                flagAdc = true;

                for(int i = 0; i < cont; i++) {
                    if(nros[i] == temp) {
                        flagAdc = false;
                        idx = i;
                        break;
                    }
                }

                if(flagAdc) {
                    nros[cont] = temp;
                    cont++;
                } else {
                    for (int i = idx; i < cont; i++) {
                        nros[i] = nros[i+1];
                    }
                    cont--;
                }

                for (int i = 0; i < cont; i++) {
                    System.out.printf("%d ", nros[i]);
                }

                if(cont == 0 || cont == 10) {
                    flagFim = true;
                } else {
                    System.out.println();
                }
            }
        }
    }
}
