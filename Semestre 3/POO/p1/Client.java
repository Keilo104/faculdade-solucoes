public class Client {
    private static int maxAcc = 1000;
    private String nome, cpf;
    private Account[] accounts = new Account[maxAcc];
    private int qtdAcc;

    public Client(String nome, String cpf) {
        this.nome = nome;
        this.cpf = cpf;
    }

    public void addAccount(Account newAcc) {
        if(newAcc != null) {
            this.accounts[qtdAcc] = newAcc;
            this.qtdAcc++;
        }
    }

    public boolean removeAccount(Account removeAcc) {
        int idx = -1;

        for (int i = 0; i < qtdAcc; i++) {
            if(this.accounts[i] == removeAcc) {
                idx = i;
                break;
            }
        }

        if(idx != -1 && this.accounts[idx] != null) {
            for (int i = idx+1; i < qtdAcc; i++) {
                this.accounts[i-1] = this.accounts[i];
            }
            qtdAcc--;
            return true;
        } else {
            return false;
        }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        if(nome != null && !nome.equals("")) {
            this.nome = nome;
        }
    }

    public String getCpf() {
        return cpf;
    }

    public int getQtdAcc() {
        return qtdAcc;
    }

    public void listAccounts() {
        for (int i = 0; i < qtdAcc; i++) {
            if(this.accounts[i] != null) {
                System.out.println("Number: " + this.accounts[i].getNumber() + ", Agency: " + this.accounts[i].getAgency() + ", Bank: " + this.accounts[i].getBank().getNumber());
            }
        }
    }
}
