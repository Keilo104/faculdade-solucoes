public class UserAccount {
    private String email;
    private String userName;

    private UserAccount[] followers;
    private int qtdFollowers;

    private Post[] timeline;
    private int posTimelineAtual;

    private Post[] posts;
    private int qtdPost;

    public UserAccount(String user, String email) {
        this.userName = user;
        this.email = email;

        this.followers = new UserAccount[1000];
        this.timeline = new Post[10];
        this.posts = new Post[1000];
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String userName() {
        return userName;
    }

    public void publish(String quote) {
        Post newPost = new Post(this, quote);

        this.posts[qtdPost++] = newPost;

        for (int i = 0; i < qtdFollowers; i++) {
            this.followers[i].updateTimeline(newPost);
        }
    }

    public void clapPost(int postIdx) {
        this.timeline[postIdx].clap();
    }

    public void booPost(int postIdx) {
        this.timeline[postIdx].boo();
    }

    public void updateTimeline(Post newPost) {
        this.timeline[posTimelineAtual++ % 10] = newPost;
    }

    public void acceptFollower(UserAccount newFollower) {
        this.followers[qtdFollowers++] = newFollower;
    }

    public String showTimeline() {
        String retorno = "";

        if(posTimelineAtual > 9) {
            for (int i = 0; i < 10; i++) {
                retorno += this.timeline[i].show() + "\n";
            }
        } else {
            for (int i = 0; i < posTimelineAtual; i++) {
                retorno += this.timeline[i].show() + "\n";
            }
        }

        return retorno;
    }

    public String showMyPosts() {
        String retorno = "";

        for (int i = 0; i < qtdPost; i++) {
            retorno += this.posts[i].show() + "\n";
        }

        return retorno;
    }

    public String showMyFollowers() {
        String retorno = "";

        for (int i = 0; i < qtdFollowers; i++) {
            retorno += this.followers[i].userName() + ", " + this.followers[i].getEmail() + "\n";
        }

        return retorno;
    }

    public boolean delete(int postIdx) {
        this.posts[postIdx] = null;

        return true;
    }
}
