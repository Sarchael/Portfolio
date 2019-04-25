/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Modele;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author Patryk
 */
public class Status {


    public String[] checkStatus (String nrPaczki)
    {
        String[] status = new String[2];
        status[0] = "";
         try (Connection con = DriverManager.getConnection("jdbc:derby://localhost:1527/Kurierzy", "a", "a")) {

            // loading the JDBC driver
            Class.forName("org.apache.derby.jdbc.ClientDriver");

            String query = "SELECT nrPaczki,status,dataNadania,datadostarczenia"
                    + " FROM Paczki "
                    + "WHERE nrPaczki=" + nrPaczki;

            Statement statement = con.createStatement();
            ResultSet rs = statement.executeQuery(query);

            if (rs.next()) {
                status[0] = rs.getString("status");
                status[1] = rs.getString("datanadania");
            }

        } catch (SQLException sqle) {
            System.err.println(sqle.getMessage());
        } catch (ClassNotFoundException cnfe) {
            System.err.println(cnfe.getMessage());
        }
         return status;
    }
}
