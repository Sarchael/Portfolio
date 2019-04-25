/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package firmakurierska;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import Modele.Status;

/**
 * FXML Controller class
 *
 * @author Michal
 */
public class TracePackageController {

    private AllControllers allControllers = AllControllers.getInstance();

    @FXML
    private TextField packageNumber;

    @FXML
    private Label timeID;
    @FXML
    private Label timeField;
    @FXML
    private Label statusID;
    @FXML
    private Label statusField;
    @FXML
    private Label errorMessage;

    @FXML
    private void initialize() {
        allControllers.setTracePackageController(this);
    }

    @FXML
    private void traceYourPackage() {
        
        Status status = new Status(); 
        String[] packageData = status.checkStatus(packageNumber.getText());

        if (!packageData[0].equals("")) {
            timeID.setVisible(true);
            statusID.setVisible(true);
            timeField.setText(packageData[1]);
            statusField.setText(packageData[0]);
            errorMessage.setText("");
        } else {
            timeID.setVisible(false);
            statusID.setVisible(false);
            timeField.setText("");
            statusField.setText("");
            errorMessage.setText("Nie znaleziono paczki o podanym numerze!");
            packageNumber.setText("");
        }
    }
}
