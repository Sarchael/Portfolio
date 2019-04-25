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
public class LandingPageController{

    private AllControllers allControllers = AllControllers.getInstance();
    
    private GaussianBlur gb;
    
    @FXML
    private Label labelOne;
    @FXML
    private Label labelTwo;
    @FXML
    private Label labelThree;
    
    @FXML
    private ImageView imageOne;
    @FXML
    private ImageView imageTwo;
    @FXML
    private ImageView imageThree;
    
    
    
    
    @FXML
    private void initialize() {
        allControllers.setLandingPageController(this);
        gb = new GaussianBlur();
        gb.setRadius(5);
    }    
    
    @FXML
    private void messageOne(){
        labelOne.setVisible(true);
        imageOne.setEffect(gb);
    }
    
    @FXML
    private void messageTwo(){
        labelTwo.setVisible(true);
        imageTwo.setEffect(gb);
    }
    
    @FXML
    private void messageThree(){
        labelThree.setVisible(true);
        imageThree.setEffect(gb);
    }
    
    @FXML
    private void clearMessages(){
        labelOne.setVisible(false);
        labelTwo.setVisible(false);
        labelThree.setVisible(false);
        imageOne.setEffect(null);
        imageTwo.setEffect(null);
        imageThree.setEffect(null);
    }
}
