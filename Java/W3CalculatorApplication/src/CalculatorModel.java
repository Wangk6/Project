import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class CalculatorModel extends Application{

	@Override
	public void start(Stage primaryStage) throws Exception {
		// TODO Auto-generated method stub
		Parent root=FXMLLoader.load(getClass().getResource("CalculatorFXML.fxml"));
		Scene sn = new Scene(root);
		primaryStage.setScene(sn);
		primaryStage.show();
	}
	public static void main (String [] args) {
		launch(args);
	}
	
}
