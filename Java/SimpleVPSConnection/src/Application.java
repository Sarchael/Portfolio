import java.io.IOException;

import static java.lang.Thread.sleep;

public class Application {

    public static void main(String[] args){

        Connection connection = new Connection("185.24.216.103", 25942);

        try {
            int i = 1;
            while (true) {
                String response = connection.pokeServer();
                System.out.println(i + ": " + response);
                i++;
                sleep(1000);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
