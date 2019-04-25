/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Modele;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author Patryk
 */
public class BazaDanych {

    public void createTables() {
        try {
            // loading the JDBC driver            
            Class.forName("org.apache.derby.jdbc.ClientDriver");

            Connection con = DriverManager.getConnection("jdbc:derby://localhost:1527/Kurierzy;create=true", "a", "a");

            Statement statement = con.createStatement();

            statement.executeUpdate("CREATE TABLE Uzytkownicy "
                    + "(id INTEGER NOT NULL GENERATED ALWAYS AS IDENTITY (START WITH 1, INCREMENT BY 1)  "
                    + ", login VARCHAR(50), haslo VARCHAR(50), PRIMARY KEY (id) )");
            statement.executeUpdate("CREATE TABLE Paczki "
                    + "(nrPaczki INTEGER NOT NULL GENERATED ALWAYS AS IDENTITY (START WITH 1, INCREMENT BY 1)  "
                    + ", imieAdr VARCHAR(50), nazwiskoAdr VARCHAR(50), status VARCHAR(50), dataNadania VARCHAR(50), "
                    + " ulicaAdr VARCHAR(50), nrDomAdr VARCHAR(50), nrLokalAdr VARCHAR(50), nrTelAdr VARCHAR(50), emailAdr VARCHAR(50), "
                    + "imieNad VARCHAR(50), nazwiskoNad VARCHAR(50), ulicaNad VARCHAR(50), nrDomNad VARCHAR(50), nrLokalNad VARCHAR(50), "
                    + "nrTelNad VARCHAR(50), emailNad VARCHAR(50), dlugosc VARCHAR(50), szerokosc VARCHAR(50), "
                    + "wysokosc VARCHAR(50), waga VARCHAR(50), dataDostarczenia VARCHAR(50), idU INTEGER, PRIMARY KEY(nrPaczki) )");
            statement.executeUpdate("INSERT INTO Uzytkownicy (login, haslo) VALUES ('admin' , 'admin1')");

        } catch (SQLException sqle) {
            System.err.println(sqle.getMessage());
        } catch (ClassNotFoundException cnfe) {
            System.err.println(cnfe.getMessage());
        }
    }
}
