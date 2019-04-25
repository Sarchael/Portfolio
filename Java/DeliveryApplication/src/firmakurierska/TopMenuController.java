/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package firmakurierska;

import javafx.fxml.FXML;
import javafx.scene.control.ToggleGroup;

/**
 * FXML Controller class
 *
 * @author Michal
 */
public class TopMenuController {   
    
    private AllControllers allControllers = AllControllers.getInstance();
    
    private static final String HOME_PAGEFXML = "HomePage.fxml";
    private static final String SIGN_INFXML = "SignIn.fxml";
    private static final String SIGN_UPFXML = "SignUp.fxml";
    private static final String TRACE_PACKAGEFXML = "TracePackage.fxml";
     
    @FXML
    private ToggleGroup topMenuButtonsGroup;
    
    
    
    
    @FXML
    private void initialize(){
        allControllers.setTopMenuController(this);
    }
    
    @FXML
    private void showHomePage(){
        BorderPaneController borderPaneController = allControllers.getBorderPaneController();
        if(topMenuButtonsGroup.getSelectedToggle()!=null)
            topMenuButtonsGroup.getSelectedToggle().setSelected(false);
        
        borderPaneController.setCenter(HOME_PAGEFXML);
    }    
    
    @FXML
    private void signIn(){
        BorderPaneController borderPaneController = allControllers.getBorderPaneController();
        if(topMenuButtonsGroup.getSelectedToggle()!=null)
            borderPaneController.setCenter(SIGN_INFXML);
        else
            borderPaneController.setCenter(HOME_PAGEFXML);
    }  
    
    @FXML
    private void signUp(){
        BorderPaneController borderPaneController = allControllers.getBorderPaneController();
        if(topMenuButtonsGroup.getSelectedToggle()!=null)
            borderPaneController.setCenter(SIGN_UPFXML);
        else
            borderPaneController.setCenter(HOME_PAGEFXML);
    }    
    
    @FXML
    private void tracePackage(){
        BorderPaneController borderPaneController = allControllers.getBorderPaneController();
        if(topMenuButtonsGroup.getSelectedToggle()!=null)
            borderPaneController.setCenter(TRACE_PACKAGEFXML);
        else
            borderPaneController.setCenter(HOME_PAGEFXML);
    }   
}
