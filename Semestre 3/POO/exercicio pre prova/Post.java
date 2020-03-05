import java.time.LocalDate;

public class Post {
    private String quote;
    private LocalDate date;
    private int claps;
    private int boos;
    private UserAccount user;

    public Post(UserAccount account, String quote) {
        this.quote = quote;
        this.user = account;

        this.date = LocalDate.now();
        this.claps = 0;
        this.boos = 0;
    }

    public String quote() {
        return quote;
    }

    public LocalDate date() {
        return date;
    }

    public int claps() {
        return claps;
    }

    public int boos() {
        return boos;
    }

    public UserAccount user() {
        return user;
    }

    public String show() {
        return String.format("[%s] %s says \"%s\" | Claps: %d | Boos: %d", this.date, this.user.userName(), this.quote, this.claps, this.boos);
    }

    public void clap() {
        this.claps++;
    }

    public void boo() {
        this.boos++;
    }
}