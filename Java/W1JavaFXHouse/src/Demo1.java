/*
 * Author: Kevin Wang
 * Date: 2/12/2019
 * Purpose: Create a house using javaFX
 * 
 * 
 */

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Polyline;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;
public class Demo1 extends Application
{
	@Override
	public void start(Stage primaryStage) throws Exception{
		// TODO Auto-generated method stub
		
		//Background Color
			Rectangle backgroundBlue = new Rectangle(0,0,560,200);
			backgroundBlue.setFill(Color.rgb(200,230,255));
		Group background = new Group(backgroundBlue);
		//House Base
			//Roof
			Polyline roof = new Polyline();
			roof.getPoints().addAll(280.0, 0.0, //Top Left
									65.0, 110.0, //Lower left corner
									495.0, 110.0, //Lower Right Corner
									280.0, 0.0); //Top Right
			roof.setFill(Color.WHITE); //Fill it with white
			
			//NOTES - 30 Pixels less than the triangle roof +/-
			
			//Front Wall 
			Rectangle wall = new Rectangle(95, 110, 370, 340);
			wall.setFill(Color.BROWN);
			//NOTES - All Pillar + Doors = 7 Entities
			//		  HouseWall Width/7 = 55 (Round Down)
			//		  55 Pixels - 20 for spacing = 35 Pixel Width approx
			
			//White Roof Siding
			Rectangle roofTwo = new Rectangle(95, 110, 370, 20);
			roofTwo.setFill(Color.WHITE);
			roofTwo.setStroke(Color.BLACK);
			
			//Pillar
				//Column
				Rectangle [] pillar = new Rectangle [4];
				int startX = 105;
					for (int i = 0; i < 4; i++) {
						pillar[i] = new Rectangle (startX, 100, 35, 270);
						pillar[i].setFill(Color.WHITE);
						pillar[i].setStroke(Color.BLACK);
						startX = startX + 105;
				}
				//PillarBottomBase
				Rectangle [] pillarBottom = new Rectangle [4];
				startX = 100;
					for (int i = 0; i < 4; i++) {
						pillarBottom[i] = new Rectangle (startX, 370, 45, 15);
						pillarBottom[i].setFill(Color.WHITE);
						pillarBottom[i].setStroke(Color.BLACK);
						startX = startX + 105;
				}
				//PillarCircle
				Circle [] pillarCircle = new Circle [8];
				startX = 105;
				int startY = 140;
				for (int i = 0; i < 4; i++) {
					pillarCircle[i] = new Circle (startX, startY, 10);
					pillarCircle[i].setFill(Color.WHITE);
					pillarCircle[i].setStroke(Color.BLACK);
					startX = startX + 105;
			}
				//PillarCircle Second Set
				startX = 140;
				startY = 140;
				for (int i = 4; i < 8; i++) {
					pillarCircle[i] = new Circle (startX, startY, 10);
					pillarCircle[i].setFill(Color.WHITE);
					pillarCircle[i].setStroke(Color.BLACK);
					startX = startX + 105;
			}

			//Doors + Windows
				//Random Gray Rectangle in Center
					Rectangle greyRect = new Rectangle(255, 155, 50, 30);
					greyRect.setFill(Color.GREY);
					greyRect.setStroke(Color.BLACK);
				
				//WindowFrame
					Rectangle [] sideWindowFrame = new Rectangle [3];
					startX = 150;
						for (int i = 0; i < 3; i++) {
							if (i == 1) { //Make the Door taller
								sideWindowFrame[i] = new Rectangle (startX, 240, 50, 145);
								sideWindowFrame[i].setFill(Color.WHITE);
								sideWindowFrame[i].setStroke(Color.BLACK);
								startX = startX + 105;
								
							}else {
							sideWindowFrame[i] = new Rectangle (startX, 270, 50, 115);
							sideWindowFrame[i].setFill(Color.WHITE);
							sideWindowFrame[i].setStroke(Color.BLACK);
							startX = startX + 105;
							}
					}
				//Bigger Window Panel
						//NOTES - 2 Column, 5 Row
						// Door Size: Width(50 Pixel) Height (145 Pixel)
						// Estimate: Width(20 each) Height (24)
						Rectangle [] windowPanel = new Rectangle [30];
						startX = 160;
						startY = 290;
							for (int i = 0; i < 24; i++) {
								if ( (i % 2) == 0 && i!= 0 && (i%6 != 0)) { //After every 2, jump 65 pixels
									startX = startX + 65;
									windowPanel[i] = new Rectangle (startX, startY, 10, 15);
									windowPanel[i].setFill(Color.BLACK);
									windowPanel[i].setStroke(Color.BLACK);	
									startX = startX + 20;
								} else if ( (i % 6) == 0 && i!=0) {
									startX = 160; //Make it back to the position of the first window
									startY = startY + 25;
									windowPanel[i] = new Rectangle (startX, startY, 10, 15);
									windowPanel[i].setFill(Color.BLACK);
									windowPanel[i].setStroke(Color.BLACK);	
									startX = startX + 20;
								} else {
								windowPanel[i] = new Rectangle (startX, startY, 10, 15);
								windowPanel[i].setFill(Color.BLACK);
								windowPanel[i].setStroke(Color.BLACK);
								startX = startX + 20;
								}
							}
				//Smaller Window Panel
						startX = 160;
						startY = 275;
							for (int i = 24; i < 30; i++) {
								if ( (i % 2) == 0 && (i%6 != 0)) { //After every 2, jump 65 pixels
									startX = startX + 65;
									windowPanel[i] = new Rectangle (startX, startY, 10, 10);
									windowPanel[i].setFill(Color.BLACK);
									windowPanel[i].setStroke(Color.BLACK);	
									startX = startX + 20;
								} else {
								windowPanel[i] = new Rectangle (startX, startY, 10, 10);
								windowPanel[i].setFill(Color.BLACK);
								windowPanel[i].setStroke(Color.BLACK);
								startX = startX + 20;
								}
							}
			//Stairs
				//Platform
						Rectangle platform = new Rectangle(95, 385, 370, 5);
						platform.setFill(Color.GREY);
						platform.setStroke(Color.BLACK);
				//Stairs
						Rectangle [] stairs = new Rectangle [11];
						startX = 145;
						startY = 385;
						int startWid = 270;
						for (int i = 0; i < 11; i++) {
							stairs[i] = new Rectangle (startX, startY, startWid, 10);
							stairs[i].setFill(Color.GREY);
							stairs[i].setStroke(Color.BLACK);
							startX = startX - 10;
							startY = startY + 10;
							startWid = startWid + 20;
						}
			
		Group base = new Group(wall, greyRect);
		
		for(int i = 0; i < 4; i++) {
			base.getChildren().add(pillar[i]);
			base.getChildren().add(pillarBottom[i]);
		}
		
		for(int i = 0; i < 8; i++) {
			base.getChildren().add(pillarCircle[i]);
		}
		for(int i = 0; i < 3; i++) {
			base.getChildren().add(sideWindowFrame[i]);
		}
		for (int i = 0; i < 30; i++) {
			base.getChildren().add(windowPanel[i]);
		}
		base.getChildren().add(roofTwo);
		base.getChildren().add(roof);
		base.getChildren().add(platform);
		for (int i = 0; i < 11; i++) {
			base.getChildren().add(stairs[i]);
		}

		//Root
		Group root = new Group(background, base);
		//Scene
			Scene scene = new Scene(root, 560, 540, Color.rgb(100, 200, 0));
			
			primaryStage.setTitle("A House");
			primaryStage.setScene(scene);
			primaryStage.show();
	}
}