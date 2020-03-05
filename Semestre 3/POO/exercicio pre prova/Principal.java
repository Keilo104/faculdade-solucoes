public class Principal {
    public static void main(String[] args) {
        UserAccount pessoalegal = new UserAccount("luna", "luna@emailtop.com");
        UserAccount seguidor1 = new UserAccount("otário", "aaaaaaaaaa");

        pessoalegal.acceptFollower(seguidor1);

        pessoalegal.publish("a vida é difícil, porém");
        pessoalegal.publish("aaaaaaaaaaaaaaaaaaaaaaaaaa");
        pessoalegal.publish("minha vida está caindo aos pedaços.");

        pessoalegal.delete(2);

        seguidor1.clapPost(0);
        seguidor1.clapPost(0);
        seguidor1.booPost(0);
        seguidor1.booPost(0);
        seguidor1.clapPost(0);

        for (int i = 0; i < 20; i++) {
            pessoalegal.publish("publicação nro " + i);
        }

        System.out.println(seguidor1.showTimeline());
        System.out.println(pessoalegal.showMyPosts());
        System.out.println(pessoalegal.showMyFollowers());
    }
}
