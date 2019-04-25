import java.io.*;
import java.net.Socket;

public class Connection {

    private String IPaddress;
    private int port;
    private Socket socket;
    private BufferedReader input;
    private PrintWriter output;

    public Connection(String IP, int p){
        IPaddress = IP;
        port = p;
    }

    private void initConnection() throws IOException {
        socket = new Socket(IPaddress, port);
        input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
    }

    public String pokeServer() throws IOException {
        initConnection();
        String response = input.readLine();
        socket.close();
        input.close();
        output.close();
        return response;
    }
}
