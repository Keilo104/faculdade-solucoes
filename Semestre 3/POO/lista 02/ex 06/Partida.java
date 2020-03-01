import java.util.Date;

public class Partida {
    private int id;
    private Time time1, time2;
    private Date data;
    private Estadio estadio;

    public Partida(int id, Time time1, Time time2, Date data, Estadio estadio) {
        this.id = id;
        this.time1 = time1;
        this.time2 = time2;
        this.data = data;
        this.estadio = estadio;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Time getTime1() {
        return time1;
    }

    public void setTime1(Time time1) {
        this.time1 = time1;
    }

    public Time getTime2() {
        return time2;
    }

    public void setTime2(Time time2) {
        this.time2 = time2;
    }

    public Date getData() {
        return data;
    }

    public void setData(Date data) {
        this.data = data;
    }

    public Estadio getEstadio() {
        return estadio;
    }

    public void setEstadio(Estadio estadio) {
        this.estadio = estadio;
    }
}
