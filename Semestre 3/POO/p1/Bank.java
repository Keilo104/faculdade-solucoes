public class Bank {
    private static int maxAcc = 1000;
    private int number, qtdAcc;
    private Account[] accounts = new Account[maxAcc];

    public Bank(int number) {
        this.number = number;
    }

    public int getNumber() {
        return number;
    }

    public int getQtdAcc() {
        return qtdAcc;
    }

    public int addAccount(Account newAcc) {
        if(newAcc != null) {
            this.accounts[qtdAcc] = newAcc;
            this.qtdAcc++;
        }

        // qtdAcc é o número da conta
        return qtdAcc;
    }

    public boolean removeAccount(Account removeAcc) {
        int idx = -1;

        for (int i = 0; i < qtdAcc; i++) {
            if(this.accounts[i] == removeAcc) {
                idx = i;
                break;
            }
        }

        if(this.accounts[idx] != null) {
            for (int i = idx+1; i < qtdAcc; i++) {
                this.accounts[i-1] = this.accounts[i];
            }
            qtdAcc--;
            return true;
        } else {
            return false;
        }
    }

    public double approveLimit(double amount, int accountTime) {
        double maxCredit = (300 * accountTime) + 200;

        return Math.min(amount, maxCredit);
    }

    public void listAccounts() {
        for (int i = 0; i < qtdAcc; i++) {
            if(this.accounts[i] != null) {
                System.out.println("Number: " + this.accounts[i].getNumber() + ", Agency: " + this.accounts[i].getAgency() + ", Owner: " + this.accounts[i].getClient().getNome() + ", CPF: " + this.accounts[i].getClient().getCpf());
            }
        }
    }

    public void listAccounts(long agency) {
        for (int i = 0; i < qtdAcc; i++) {
            if(this.accounts[i] != null && this.accounts[i].getAgency() == agency) {
                System.out.println("Number: " + this.accounts[i].getNumber() + ", Owner: " + this.accounts[i].getClient().getNome() + ", CPF: " + this.accounts[i].getClient().getCpf());
            }
        }
    }
}
