public class Main {
    public static void main(String[] args) {
        Bank nu = new Bank(1);
        Client otario = new Client("pedro", "123123123");
        Account bbb = new Account(otario, nu, 12321);
        Account bbb2 = new Account(otario, nu, 12321);
        Account bbb3 = new Account(otario, nu, 12321);

        bbb2.setAgency(123);

        //bbb.deleteAccount();
        //bbb.setAccountTime(6);
        bbb.increaseLimit(99999999, 12321);
        bbb.withdraw(1100, 12321);
        bbb.deposit(500, 12321);
        bbb.withdraw(400, 12321);
        bbb.withdraw(99, 12321);
        System.out.println(bbb.getAvailableCredit());

        //bbb2.deleteAccount();

        otario.listAccounts();
        System.out.println();
        nu.listAccounts();
        System.out.println();
        nu.listAccounts(123);

    }
}
