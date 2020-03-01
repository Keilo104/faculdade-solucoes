import java.util.Scanner;

class a01e05 {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        int x1 = leitor.nextInt(); // robo pos x
        int y1 = leitor.nextInt(); // robo pos y
        int a = leitor.nextInt(); // ângulo
        int f = -(leitor.nextInt() - 90); // feixe
        int d = leitor.nextInt(); // distância

        int direction = (a + f) % 360;

        if(direction < 0) {
            direction += 360;
        }

        int x2 = (int) Math.round(d * Math.cos(Math.toRadians(direction)) + x1);
        int y2 = (int) Math.round(d * Math.sin(Math.toRadians(direction)) + y1);
        
        if(d < 0) {
            System.out.println("Erro");
        } else {
            System.out.println("(" + x2 + "," + y2 + ")");
        }
    }
}
