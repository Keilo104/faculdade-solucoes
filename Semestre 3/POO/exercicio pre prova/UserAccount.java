public class UserAccount {
    private String email, userName;
    private UserAccount[] followers;
    private Post[] timeline, posts;
    private int qtdFollowers, qtdTimeline, qtdPost;

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
            if(this.followers[i] != null) {
                this.followers[i].updateTimeline(newPost);
            }
        }
    }

    public void clapPost(int postIdx) {
        this.timeline[postIdx].clap();
    }

    public void booPost(int postIdx) {
        this.timeline[postIdx].boo();
    }

    public void updateTimeline(Post newPost) {
        this.timeline[qtdTimeline++ % 10] = newPost;
    }

    public void acceptFollower(UserAccount newFollower) {
        this.followers[qtdFollowers++] = newFollower;
    }

    public void blockFollower(UserAccount follower) {
        for (int i = 0; i < qtdFollowers; i++) {
            if(this.followers[i] == follower) {
                this.followers[i] = null;
            }
        }
    }

    public String showTimeline() {
        String retorno = "";

        for (int i = 0; i < 10; i++) {
            if(this.timeline[i] != null) {
                retorno += this.timeline[i].show() + "\n";
            }
        }

        return retorno;
    }

    public String showMyPosts() {
        String retorno = "";

        for (int i = 0; i < qtdPost; i++) {
            if(this.posts[i] != null) {
                retorno += this.posts[i].show() + "\n";
            }
        }

        return retorno;
    }

    public String showMyFollowers() {
        String retorno = "";

        for (int i = 0; i < qtdFollowers; i++) {
            if(this.followers[i] != null) {
                retorno += this.followers[i].userName() + ", " + this.followers[i].getEmail() + "\n";
            }
        }

        return retorno;
    }

    public boolean delete(int postIdx) {
        this.posts[postIdx] = null;

        return true;
    }


}
