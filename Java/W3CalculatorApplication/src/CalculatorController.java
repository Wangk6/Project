import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

public class CalculatorController {
	float prevNum = -1;
	float currNum = -1;
	float answer = 0;
	int operation = 0;
    @FXML
    private Button btn1;

    @FXML
    private Button btn4;

    @FXML
    private Button btn7;

    @FXML
    private Button btn2;

    @FXML
    private Button btn5;

    @FXML
    private Button btn8;

    @FXML
    private Button btn3;

    @FXML
    private Button btn6;

    @FXML
    private Button btn9;

    @FXML
    private Button btn0;

    @FXML
    private Button btnPlus;

    @FXML
    private Button btnDiv;

    @FXML
    private Button btnEQ;

    @FXML
    private Button btnClr;

    @FXML
    private TextField display;

    @FXML
    void clearTextField(ActionEvent event) { //Clear Button
    	display.setText("");
    	operation = 0; //Reset operation
    }

    @FXML
    void numberPress(ActionEvent event) { //Number Buttons
    	if(event.getSource() == btn1) {
    		if(operation == 0) { //Check if the last action was an operation, if not, set text, else clear then set
    		display.setText(display.getText() + "1");
    		} else {
    			display.clear();
    			display.setText(display.getText() + "1");
    		}
    	}else if (event.getSource() == btn2) {
    		if(operation == 0) {
    		display.setText(display.getText() + "2");
    		} else {
    			display.clear();
    			display.setText(display.getText() + "2");
    		}
    	}else if (event.getSource() == btn3) {
    		if(operation == 0) {
    		display.setText(display.getText() + "3");
    		} else {
    			display.clear();
    			display.setText(display.getText() + "3");
    		}
    	}else if (event.getSource() == btn4) {
    		if(operation == 0) {
    		display.setText(display.getText() + "4");
    		} else {
    			display.clear();
    			display.setText(display.getText() + "4");
    		}
    	}else if (event.getSource() == btn5) {
    		if(operation == 0) {
    		display.setText(display.getText() + "5");
    		} else {
    			display.clear();
    			display.setText(display.getText() + "5");
    		}
    	}else if (event.getSource() == btn6) {
    		if(operation == 0) {
    		display.setText(display.getText() + "6");
    		} else {
    			display.clear();
    			display.setText(display.getText() + "6");
    		}
    	}else if (event.getSource() == btn7) {
    		if(operation == 0) {
    		display.setText(display.getText() + "7");
    		} else {
    			display.clear();
    			display.setText(display.getText() + "7");
    		}
    	}else if (event.getSource() == btn8) {
    		if(operation == 0) {
    		display.setText(display.getText() + "8");
    		} else {
    			display.clear();
    			display.setText(display.getText() + "8");
    		}
    	}else if (event.getSource() == btn9) {
    		if(operation == 0) {
    		display.setText(display.getText() + "9");
    		} else {
    			display.clear();
    			display.setText(display.getText() + "9");
    		}
    	}else if (event.getSource() == btn0) {
    		if(operation == 0) {
    		display.setText(display.getText() + "0");
    		} else {
    			display.clear();
    			display.setText(display.getText() + "0");
    		}
    	}
    }

    @FXML
    void operatorPress(ActionEvent event) { //Operator Button
    	if (event.getSource() == btnPlus) {
    		prevNum = Float.parseFloat(display.getText()); //Store the previous number, parse from string to float
    		display.setText("+");
    		operation = 1;
    	}else if (event.getSource() == btnDiv) {
    		prevNum = Float.parseFloat(display.getText()); //Store the previous number, parse from string to float
    		display.setText("/");
    		operation = 2;
    	}else if (event.getSource() == btnEQ) {
    		currNum = Float.parseFloat(display.getText());

    		switch(operation) {//Calculate
    		case 1: 
    			answer = prevNum + currNum;
    			if (answer % 1 != 0) { //If the answer is not a whole number, display a decimal point else display as int
    			display.setText(String.valueOf(answer));
    			} else {
    				int b = Math.round(answer);
    				display.setText(String.valueOf(b));
    			}
    			break;
    		case 2:
				answer = prevNum / currNum;
    			if(currNum == 0) { //Don't allow invalid division
    				display.setText("Cannot Divide By Zero");
    			} else if (answer % 1 != 0){
    				display.setText(String.valueOf(answer));
    			} else {
    				int b = Math.round(answer);
    				display.setText(String.valueOf(b));
    			}
    			break;
    		}
    	}
    }

}
