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
import javafx.collections.ObservableList;

/**
 *
 * @author Piotr
 */
public class PreviousPackagesViewer {
    
    
    public void selectFromDatabase(ObservableList listOfItems, int userID) {
        
        try {
                // Load the JDBC Driver
                Class.forName("org.apache.derby.jdbc.ClientDriver");
            } catch (ClassNotFoundException cnfe) {
                System.err.println(cnfe.getMessage());
                return;
            }

            // Make a connection to DB
        try (Connection con = DriverManager.getConnection("jdbc:derby://localhost:1527/Kurierzy", "a", "a")) {
            
            String query = "SELECT * FROM PACZKI WHERE IDU=" + userID;
            Statement statement = con.createStatement();
            ResultSet rs = statement.executeQuery(query);
            
            //List list = new ArrayList();
            while (rs.next()) {
                listOfItems.add(new PackagesHistory(rs.getString("nrPaczki"), rs.getString("imieAdr") 
                        + " " + rs.getString("nazwiskoAdr"), rs.getString("status"), rs.getString("dataNadania"), rs.getString("dataDostarczenia")));
            }
            rs.close();
            
            //listOfItems = FXCollections.observableList(list);
            

        } catch (SQLException sqle) {
            System.err.println(sqle.getMessage());
        }      
        
  
    }
    
}
