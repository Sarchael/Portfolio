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
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Krisu
 */
public class SignUp {
    public boolean checkLogin(String login) {
        try (Connection con = DriverManager.getConnection("jdbc:derby://localhost:1527/Kurierzy", "a", "a")) {

            // loading the JDBC driver
            Class.forName("org.apache.derby.jdbc.ClientDriver");

            String query = "SELECT id FROM Uzytkownicy WHERE login = '" + login + "'";
            Statement statement = con.createStatement();
            ResultSet rs = statement.executeQuery(query);

            if (rs.next()) {
                return true;
            }

        } catch (SQLException | ClassNotFoundException sqle) {
            System.err.println(sqle.getMessage());
        }

        return false;
    }
    
    public void register(String login, String password){
        try {
            // loading the JDBC driver
            Class.forName("org.apache.derby.jdbc.ClientDriver");
            Connection con = DriverManager.getConnection("jdbc:derby://localhost:1527/Kurierzy", "a", "a");
            Statement statement = con.createStatement();
            
            statement.executeUpdate("INSERT INTO Uzytkownicy "
                    + "(login, haslo) "
                    + "VALUES ("
                    + "'" + login + "' ," + "'" + password + "')");

        } catch (ClassNotFoundException | SQLException ex) {
            Logger.getLogger(SignUp.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
