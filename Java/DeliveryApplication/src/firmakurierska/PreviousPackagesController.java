/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package firmakurierska;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import Modele.PreviousPackagesViewer;

/**
 * FXML Controller class
 *
 * @author Michal
 */
public class PreviousPackagesController {

    private AllControllers allControllers = AllControllers.getInstance();

    @FXML
    private TableColumn packagesNumbers;
    @FXML
    private TableColumn receivers;
    @FXML
    private TableColumn status;
    @FXML
    private TableColumn postingDates;
    @FXML
    private TableColumn deliveryDates;
    @FXML
    private TableView table;

    private ObservableList historyListItems;
    
    private PreviousPackagesViewer viewer;

    @FXML
    private void initialize() {
        allControllers.setPreviousPackagesController(this);
        viewer = new PreviousPackagesViewer();
        historyListItems = FXCollections.observableArrayList();
        viewHistory();
    }
    
    private void viewHistory() {        
        
        packagesNumbers.setCellValueFactory(new PropertyValueFactory<>("packageNumber"));
        receivers.setCellValueFactory(new PropertyValueFactory<>("receiver"));
        status.setCellValueFactory(new PropertyValueFactory<>("status"));
        postingDates.setCellValueFactory(new PropertyValueFactory<>("postingDate"));
        deliveryDates.setCellValueFactory(new PropertyValueFactory<>("deliveryDate"));
        
        int currentUserID = allControllers.getSignInController().getUserID();
        
        // Select data from database
        viewer.selectFromDatabase(historyListItems, currentUserID);

        // Set selected data into the table view
        table.setItems(historyListItems);
    }
}
