import java.io.*;
import java.net.Socket;

public class SimplePokeResponseService implements Runnable {

    private Socket socket;
    private BufferedReader input;
    private PrintWriter output;

    public SimplePokeResponseService(Socket s) {
        socket = s;
    }

    private void initStreams() throws IOException {
        output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
        input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
    }


    @Override
    public void run() {
        try {
            initStreams();
            String IP = socket.getRemoteSocketAddress().toString();
            output.println("You are connected to the server! Your IP is: " + IP.substring(1, IP.length()-5));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
