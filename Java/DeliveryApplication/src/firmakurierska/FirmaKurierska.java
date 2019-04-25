/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package firmakurierska;

import java.io.IOException;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;
import Modele.BazaDanych;
/**
 *
 * @author Michal
 */
public class FirmaKurierska extends Application {
    
    private static final String BORDER_PANEFXML = "BorderPane.fxml";  
    
    @Override
    public void start(Stage primaryStage) throws IOException {
        
        FXMLLoader loader = new FXMLLoader(this.getClass().getResource(BORDER_PANEFXML));
        BorderPane borderPane = loader.load();
        Scene scene = new Scene(borderPane);
        
        primaryStage.setScene(scene);
        primaryStage.setTitle("Firma Kurierska");
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //testowe narazie
        BazaDanych bd = new BazaDanych();
        bd.createTables();
        
        launch(args);
    }
    
}
