public class Campeonato {
    private int ano;
    private String patrocinador;
    private int divisao;
    private double premiacao;
    private Time[] times;
    private Partida[][] rodadas;

    public Campeonato(int ano, String patrocinador, int divisao, double premiacao) {
        this.ano = ano;
        this.patrocinador = patrocinador;
        this.divisao = divisao;
        this.premiacao = premiacao;

        this.times = new Time[20];
        this.rodadas = new Partida[38][20];
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        if(ano > 0) {
            this.ano = ano;
        }
    }

    public String getPatrocinador() {
        return patrocinador;
    }

    public void setPatrocinador(String patrocinador) {
        if(!patrocinador.equals("")) {
            this.patrocinador = patrocinador;
        }
    }

    public int getDivisao() {
        return divisao;
    }

    public void setDivisao(int divisao) {
        if(divisao > 0 && divisao < 4) {
            this.divisao = divisao;
        }
    }

    public double getPremiacao() {
        return premiacao;
    }

    public void setPremiacao(double premiacao) {
        if(premiacao > 0) {
            this.premiacao = premiacao;
        }
    }
}
