/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Modele;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.sql.Connection;
import java.sql.DriverManager;

import java.sql.SQLException;
import java.sql.Statement;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author oem
 */
public class SendPackage {

    public void addPackageToDatabase(String sName, String sSurname, String sStreet, String sHouseNumber, String sLocalNumber, String sPhoneNumber, String sEmail,
            String rName, String rSurname, String rStreet, String rHouseNumber, String rLocalNumber, String rPhoneNumber, String rEmail,
            String length, String width, String height, String weight, int ID) {
        try {
            // loading the JDBC driver            
            Class.forName("org.apache.derby.jdbc.ClientDriver");

            Connection con = DriverManager.getConnection("jdbc:derby://localhost:1527/Kurierzy", "a", "a");

            Statement statement = con.createStatement();
            DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd");
            LocalDate localDate = LocalDate.now();
            //System.out.println(dtf.format(localDate)); //2016/11/16

            /*statement.executeUpdate("CREATE TABLE Paczki "
                    + "(nrPaczki INTEGER NOT NULL GENERATED ALWAYS AS IDENTITY (START WITH 1, INCREMENT BY 1)  "
                    + ", imieAdr VARCHAR(50), nazwiskoAdr VARCHAR(50), status VARCHAR(50), dataNadania VARCHAR(50) "
                    + ", dataDostarczenia VARCHAR(50),PRIMARY KEY(nrPaczki) )");*/
            
            statement.executeUpdate("INSERT INTO Paczki (imieAdr, nazwiskoAdr, status, dataNadania, ulicaAdr, nrDomAdr, nrLokalAdr, nrTelAdr, emailAdr, "
                    + "imieNad, nazwiskoNad, ulicaNad, nrDomNad, nrLokalNad, nrTelNad, emailNad, dlugosc, szerokosc, "
                    + "wysokosc, waga, idU) VALUES ('" + sName + "' , '" + sSurname + "' , 'Paczka u adresata' , '"
                    + dtf.format(localDate) + "' , '" + sStreet + "' , '" + sHouseNumber + "' , '" + sLocalNumber + "' , '" + sPhoneNumber + "' , '" 
                    + sEmail + "' , '" + rName + "' , '" + rSurname + "' , '" + rStreet + "' , '" + rHouseNumber + "' , '" + rLocalNumber + "' , '" 
                    + rPhoneNumber + "' , '" + rEmail + "' , '" + length + "' , '" + width + "' , '" + height + "' , '" + weight + "' , " + ID + ")");
            

            

        } catch (SQLException sqle) {
            System.err.println(sqle.getMessage());
        } catch (ClassNotFoundException cnfe) {
            System.err.println(cnfe.getMessage());
        }
    }
    
    public void generateCard(String sName, String sSurname, String sStreet, String sHouseNumber, String sLocalNumber, String sPhoneNumber, String sEmail,
            String rName, String rSurname, String rStreet, String rHouseNumber, String rLocalNumber, String rPhoneNumber, String rEmail,
            String length, String width, String height, String weight){
        
        PrintWriter writer;
            try {
                writer = new PrintWriter("Karta Wysyłkowa.txt", "UTF-8");
                writer.println("Dane Nadawcy:");
                writer.println("Imię: "+sName);
                writer.println("Nazwisko: "+sSurname);
                writer.println("Ulica: "+sStreet);
                writer.println("Numer Domu: "+sHouseNumber);
                writer.println("Numer Lokalu: "+sLocalNumber);
                writer.println("Numer Telefonu: "+sPhoneNumber);
                writer.println("Adres Emial: "+sEmail);
                writer.println("");
                writer.println("Dane Odbiorcy:");
                writer.println("Imię: "+rName);
                writer.println("Nazwisko: "+rSurname);
                writer.println("Ulica: "+rStreet);
                writer.println("Numer Domu: "+rHouseNumber);
                writer.println("Numer Lokalu: "+rLocalNumber);
                writer.println("Numer Telefonu: "+rPhoneNumber);
                writer.println("Adres Emial: "+rEmail);
                writer.println("");
                writer.println("Wymiary Paczki:");
                writer.println("Długość: "+length);
                writer.println("Szerokość: "+width);
                writer.println("Wysokość: "+height);
                writer.println("Waga: "+weight);
                writer.close();
            } catch (FileNotFoundException ex) {
                Logger.getLogger(SendPackage.class.getName()).log(Level.SEVERE, null, ex);
            } catch (UnsupportedEncodingException ex) {
                Logger.getLogger(SendPackage.class.getName()).log(Level.SEVERE, null, ex);
            }
        
    }

}
