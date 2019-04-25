/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package firmakurierska;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.effect.GaussianBlur;
import javafx.scene.image.ImageView;

/**
 * FXML Controller class
 *
 * @author Michal
 */
public class HomePageController { 
    
    private AllControllers allControllers = AllControllers.getInstance();
    
    private GaussianBlur gb;
            
    @FXML
    private Label textField;
    
    @FXML
    private ImageView first;
    @FXML
    private ImageView second;
    @FXML
    private ImageView third;
    @FXML
    private ImageView fourth;
    @FXML
    private ImageView fifth;
    @FXML
    private ImageView sixth;
    
    
    
    
    @FXML
    private void initialize(){
        allControllers.setHomePageController(this);
        gb = new GaussianBlur();
        gb.setRadius(5);
    }
    
    @FXML
    private void messageOne(){
        textField.setText("Udaj się do najbliższego sklepu i zakup paczkę o odpowiednich dla Ciebie wymiarach.");
        first.setEffect(gb);
    }
    
    @FXML
    private void messageTwo(){
        textField.setText("Zapakuj swoją przesyłkę do zakupionej wcześniej paczki. Pamiętaj, żeby odpowiednio zabezpieczyć zawartość!");
        second.setEffect(gb);
    }
    
    @FXML
    private void messageThree(){
        textField.setText("Zaloguj się do Naszej aplikacji i wypełnij formularz nadania paczki. Nie masz jeszcze konta? Zarejestruj się w dowolnej chwili!");
        third.setEffect(gb);
    }
    
    @FXML
    private void messageFour(){
        textField.setText("Wydrukuj i naklej na paczkę Kartę Wysyłkową. Bez niej paczka nie trafi do odbiorcy! Za jakiś czas po Twoją paczkę przyjedzie nasz kurier.");
        fourth.setEffect(gb);
    }
    
    @FXML
    private void messageFive(){
        textField.setText("Daj nam trochę czasu. W godzinach szczytu podróże w korkach dotykają niestety również nas :(");
        fifth.setEffect(gb);
    }
    
    @FXML
    private void messageSix(){
        textField.setText("Paczka zostanie przez Nas dostarczona nawet w 45 minut od momentu nadania!");
        sixth.setEffect(gb);
    }
    
    @FXML
    private void clearMessage(){
        textField.setText("Witamy w aplikacji Naszej firmy kurierskiej! Najedź na powyższe obrazki aby dowiedzieć się jak nadać swoją paczkę.");
        first.setEffect(null);
        second.setEffect(null);
        third.setEffect(null);
        fourth.setEffect(null);
        fifth.setEffect(null);
        sixth.setEffect(null);
    }
}
