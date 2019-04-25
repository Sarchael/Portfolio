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
public class SecondTopMenuController {
    
    private AllControllers allControllers = AllControllers.getInstance();
    
    private static final String LANDING_PAGEFXML = "LandingPage.fxml";
    private static final String PREVIOUS_PACKAGESFXML = "PreviousPackages.fxml";
    private static final String HOME_PAGEFXML = "HomePage.fxml";
    private static final String TOP_MENUFXML = "TopMenu.fxml";
    private static final String SEND_PACKAGEFXML = "SendPackage.fxml";
    private static final String TRACE_PACKAGEFXML = "TracePackage.fxml";
    
    @FXML
    private ToggleGroup secondTopMenuButtonsGroup;
    
    
    
    
    @FXML
    private void initialize(){
        allControllers.setSecondTopMenuController(this);
    }
    
    @FXML
    private void previousPackages(){
        BorderPaneController borderPaneController = allControllers.getBorderPaneController();
        if(secondTopMenuButtonsGroup.getSelectedToggle()!=null)
            borderPaneController.setCenter(PREVIOUS_PACKAGESFXML);
        else
            borderPaneController.setCenter(LANDING_PAGEFXML);
    }
        
    @FXML
    private void signOut(){
        BorderPaneController borderPaneController = allControllers.getBorderPaneController();
        borderPaneController.setTop(TOP_MENUFXML);
        borderPaneController.setCenter(HOME_PAGEFXML);
    }
       
    @FXML
    private void sendPackage(){
        BorderPaneController borderPaneController = allControllers.getBorderPaneController();
        if(secondTopMenuButtonsGroup.getSelectedToggle()!=null)
            borderPaneController.setCenter(SEND_PACKAGEFXML);
        else
            borderPaneController.setCenter(LANDING_PAGEFXML);
    }
    
    @FXML
    private void tracePackage(){
        BorderPaneController borderPaneController = allControllers.getBorderPaneController();
        if(secondTopMenuButtonsGroup.getSelectedToggle()!=null)
            borderPaneController.setCenter(TRACE_PACKAGEFXML);
        else
            borderPaneController.setCenter(LANDING_PAGEFXML);
    }   
}
