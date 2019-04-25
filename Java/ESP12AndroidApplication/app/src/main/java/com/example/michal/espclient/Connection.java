package com.example.michal.espclient;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Class that controll connection and communication with server
 *
 * @author Michał Pocheć
 * @version 3.1
 *
 */
public class Connection {

    /**
     * IP address represents by string
     */
    private String IPaddress="";

    /**
     * port number
     */
    private int port;

    /**
     * reference to the socket object
     */
    private Socket socket;


    /**
     * buffered input character stream
     */
    private BufferedReader input;

    /**
     * Formatted output character stream
     */
    private PrintWriter output;

    /**
     * Input stream for taking data from user
     */
    private Scanner userinput = new Scanner(System.in);









    /**
     * Constructor
     */
    public Connection(){

    }


    /**
     * Method responsible for initialization connection with server
     */
    public void initConnection(){

        try{
            //if(IPaddress.equals(""))
                //readProperties();
            IPaddress = "89.64.55.100";
            port = 2618;

            socket = new Socket(IPaddress, port);

            input = new BufferedReader(
                    new InputStreamReader(
                            socket.getInputStream()));
            output = new PrintWriter(
                    new BufferedWriter(
                            new OutputStreamWriter(
                                    socket.getOutputStream())), true);
        }
        catch(UnknownHostException e){ //when host doesnt response
            System.err.println("Wyjatek 1");
        }
        catch(IOException e){ //when there is any problem with streams or file was not found
            System.err.println(e.getMessage());
        }
        catch(NullPointerException e){ //when there is null reference when creating socket object
            System.err.println("Wyjatek 3");
        }
        catch(NumberFormatException e){ //when its impossible to convert port number to int
            System.err.println("Wyjatek 4");
        }
    }

    /**
     * Method that sensorbutton IP address and port number from properties file
     *
     * @exception FileNotFoundException when file doesnt exist
     * @exception NumberFormatException when its impossible to convert port number to int
     */
    /*public void readProperties() throws FileNotFoundException, NumberFormatException{
        File props = new File("PROPERTIES.PROP");
        Scanner sc = new Scanner(props);

        while(sc.hasNext()){
            String s = sc.next();
            if(s.equals("IP_ADDRESS")){ //looking for a variable with IP address
                if(sc.hasNext())
                    IPaddress = sc.next();
            }
            else if(s.equals("PORT")){ //looking for a variable with port address
                if(sc.hasNext())
                    port = Integer.parseInt(sc.next());
            }
        }
    }*/

    public String action(int what, String RGB) {
        initConnection();
        try{
            //String s = userinput.nextLine(); //taking command from user
            String s="";
            if (what == 1)
                s = "podaj parametry czasowo pogodowex";
            else if(what == 2)
                s = "steruj led" + RGB + "x";
            output.println(s); //sending them to server
            output.flush();
            s = input.readLine(); //taking answer from server
            if(s.length() < 5)
                return "Wrong response from ESP!";
            else{
                String cmd = s.substring(0,3); //Three-sign command from server
                switch(cmd){
                    case "COM":
                    {
                        //view.consoleOut(s.substring(4));
                        if(what == 1){
                            String ss = s.substring(4,33);
                            ss+=s.substring(36,51);
                            ss+=s.substring(54,67);
                            StringBuffer sb = new StringBuffer(ss);
                            sb.insert(29, "\n");
                            sb.insert(45, "\n");
                            return sb.toString();
                        }
                        else if(what==2){
                            //text.setText("Diodes: " + s.substring(4));
                            return ("Diode: " + s.substring(4));
                        }
                        break;

                    }
                    case "EXC":
                    {
                        System.err.println(s.substring(4));
                        break;
                    }
                    default:
                    {
                        System.err.println("Error! Unknown response! Please reconnect!");
                        break;
                    }
                }
            }
            //socket.close();
            Thread.sleep(50);
        } catch(IOException ex){
            System.err.println(ex.getMessage());
            //System.out.println("tu");
        } catch (InterruptedException ex) {
            Logger.getLogger(Connection.class.getName()).log(Level.SEVERE, null, ex);
        }
        catch (NullPointerException ex){
            System.err.println("Cos nie tak");
        }

        return "Cos nie przeszlo xd";
    }
}

