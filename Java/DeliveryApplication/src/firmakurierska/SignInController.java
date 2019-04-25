/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package firmakurierska;

import Modele.Login;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;

/**
 * FXML Controller class
 *
 * @author Michal
 */
public class SignInController {  
    
    private AllControllers allControllers = AllControllers.getInstance();
    
    private static final String LANDING_PAGEFXML = "LandingPage.fxml";
    private static final String SECOND_TOP_MENUFXML = "SecondTopMenu.fxml";
    
    private int userID;
    
    @FXML
    private TextField loginField;
    
    @FXML
    private PasswordField passwordField;
    
    @FXML
    private Label incorrectPasses;
    
    
    
    
    @FXML
    private void initialize(){
        allControllers.setSignInController(this);
        userID = 0;
    }
    
    @FXML
    private void logging(){
        Login login = new Login();
        userID = login.CheckLogin(loginField.getText() , passwordField.getText());
        if(userID != 0)
        {
            loginField.setText("");
            passwordField.setText("");
            incorrectPasses.setText("");
            
            BorderPaneController borderPaneController = allControllers.getBorderPaneController();
            borderPaneController.setTop(SECOND_TOP_MENUFXML);
            borderPaneController.setCenter(LANDING_PAGEFXML);
        }
        else{
            incorrectPasses.setText("Niepoprawny login lub hasło!");
            loginField.setText("");
            passwordField.setText("");
        }
    }
    
    public int getUserID(){
        return userID;
    }
}
