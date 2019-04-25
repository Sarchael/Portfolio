/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package firmakurierska;

import java.io.IOException;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.layout.BorderPane;

/**
 * FXML Controller class
 *
 * @author Michal
 */
public class BorderPaneController {
    
    private AllControllers allControllers = AllControllers.getInstance();

    private static final String HOME_PAGEFXML = "HomePage.fxml";
    private static final String TOP_MENUFXML = "TopMenu.fxml";
    
    @FXML
    private BorderPane borderPane;
    
    
    
    
    @FXML
    private void initialize() {
        setCenter(HOME_PAGEFXML);
        setTop(TOP_MENUFXML);
        allControllers.setBorderPaneController(this); 
    }
     
    public void setCenter (String fxmlPath){
        FXMLLoader loader = new FXMLLoader(this.getClass().getResource(fxmlPath));
        Parent parent = null;
        try {
            parent = loader.load();
        }
        catch (IOException ex) {
            ex.getStackTrace();
        }
        
        borderPane.setCenter(parent);
    }
    
    public void setTop(String fxmlPath){
        FXMLLoader loader = new FXMLLoader(this.getClass().getResource(fxmlPath));
        Parent parent = null;
        try {
            parent = loader.load();
        }
        catch (IOException ex) {
            ex.getStackTrace();
        }
        
        borderPane.setTop(parent);
    }
    
}
