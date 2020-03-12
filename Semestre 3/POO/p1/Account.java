public class Account {
    private long number, agency;
    private double balance, availableCredit;
    private int password, accountTime;
    private Client client;
    private Bank bank;

    public Account(Client c, Bank b, int password) {
        this.client = c;
        this.bank = b;
        this.password = password;

        this.number = this.bank.addAccount(this);
        this.client.addAccount(this);

        this.availableCredit = 200;
    }

    public long getNumber() {
        return number;
    }

    public long getAgency() {
        return agency;
    }

    public void setAgency(long agency) {
        this.agency = agency;
    }

    public double balance(int password) {
        if(chkPass(password)) {
            return balance;
        } else {
            // não sei como retornar algo para erro
            return -10000000;
        }
    }

    public double getAvailableCredit() {
        return availableCredit;
    }

    public void setPassword(int oldPass, int newPassword) {
        if(chkPass(oldPass)) {
            this.password = newPassword;
        }
    }

    public int getAccountTime() {
        return accountTime;
    }

    /* apenas para debug
    public void setAccountTime(int accountTime) {
        this.accountTime = accountTime;
    }*/

    public Client getClient() {
        return client;
    }

    public Bank getBank() {
        return bank;
    }

    // num programa de verdade, isso seria mais complicado
    private boolean chkPass(int pass) {
        return pass == this.password;
    }

    public double increaseLimit(double amount, int password) {
        if(chkPass(password) && amount > this.availableCredit) {
            this.availableCredit = this.bank.approveLimit(amount, this.accountTime);
            return this.availableCredit;
        }

        return -1;
    }

    public boolean withdraw(double amount, int password) {
        if(chkPass(password) && amount > 0 && this.balance - amount >= -this.availableCredit) {
            this.balance -= amount;
            return true;
        } else {
            return false;
        }
    }

    public boolean deposit(double amount, int password) {
        if(chkPass(password) && amount > 0) {
            this.balance += amount;
            return true;
        } else {
            return false;
        }
    }

    public boolean deleteAccount() {
        return this.client.removeAccount(this) && this.bank.removeAccount(this);
    }
}
