/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package firmakurierska;

import Modele.SignUp;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.paint.Color;

/**
 * FXML Controller class
 *
 * @author Michal
 */
public class SignUpController { 
    
    private AllControllers allControllers = AllControllers.getInstance();
    
    @FXML
    private TextField loginField;
    
    @FXML
    private PasswordField passwordField;
    
    @FXML
    private PasswordField secondPasswordField;
    
    @FXML
    private Label errorMessage;
    
    private SignUp signUp;
    
    
    @FXML
    private void initialize(){
        allControllers.setSignUpController(this);
        signUp = new SignUp();
    }
    
    @FXML
    private void register(){
        if(!passwordField.getText().equals(secondPasswordField.getText())){ 
            errorMessage.setTextFill(Color.RED);
            errorMessage.setText("Hasła różnią się!");
        }
        else if(signUp.checkLogin(loginField.getText())){
            errorMessage.setTextFill(Color.RED);
            errorMessage.setText("Konto o podanym loginie już istnieje!");
        }
        else if(passwordField.getText().length() < 5 || loginField.getText().length() < 5){
            errorMessage.setTextFill(Color.RED);
            errorMessage.setText("Login i haslo powinny byc dluzsze niz 5 znakow!");
        }
        else{
            signUp.register(loginField.getText(), passwordField.getText());
            errorMessage.setTextFill(Color.GREEN);
            errorMessage.setText("Rejestracja przebiegła pomyślnie! Możesz się zalogować!");
        }
             
        loginField.setText("");
        passwordField.setText("");
        secondPasswordField.setText("");
    }
}
