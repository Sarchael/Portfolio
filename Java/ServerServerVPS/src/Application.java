import java.io.IOException;

public class Application {

    public static void main(String[] args){
        Server server = new Server(25942);
        try {
            server.start();
            server.stop();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
