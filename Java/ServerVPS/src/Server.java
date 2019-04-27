import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    private int port;
    private ServerSocket serverSocket;

    public Server(int p){
        port = p;
    }

    public void start() throws IOException {
        serverSocket = new ServerSocket(port);

        while(true){
            Socket socket = serverSocket.accept();
            Thread t = new Thread(new SimplePokeResponseService(socket));
            t.start();
        }
    }

    public void stop() throws IOException {
        serverSocket.close();
    }
}
