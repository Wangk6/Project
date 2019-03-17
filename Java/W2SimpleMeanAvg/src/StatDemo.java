import java.io.*;
import java.text.DecimalFormat;
import java.util.Scanner;

public class StatDemo
{
	public static void main(String[] args) throws IOException
	{	
		double sum = 0; // The sum of the numbers
		int count = 0; // The number of numbers added
		double mean = 0; // The average of the numbers
		double stdDev = 0; // The standard deviation
		String line; // To hold a line from the file
		double difference; // The value and mean difference
		DecimalFormat df = new DecimalFormat("#.000"); //Three Decimal Format
		//Create an object of type Scanner
		Scanner keyboard = new Scanner (System.in);
		String filename; // The user input file name
		//Prompt the user and read in the file name
		System.out.println("This program calculates " +
				"statistics on a file " +
				"containing a series of numbers");
		System.out.print("Enter the file name: ");
		filename = keyboard.nextLine(); 
		keyboard.close();

		FileReader file = new FileReader(filename); //Read the filename to open
		BufferedReader buffread = new BufferedReader(file); //Pass the FileReader Object to BR Object
		line = buffread.readLine(); //Read the first line
		while(line != null)
		{
			sum = sum + Double.parseDouble(line);
			line = buffread.readLine(); //Prep for next loop
			//System.out.println(line); Test the numbers being read
			count++; //Keep count of the amount of numbers
		}
		file.close();
		buffread.close(); 		//Close the input file
		mean = sum/count;		//Calculate Mean

		FileWriter fw = new FileWriter("Results.txt", true); //FileWriter object
		PrintWriter outputFile = new PrintWriter(fw); 		//PrinterWriter object
		outputFile.println("The mean is: " + df.format(mean)); //Format the output file to three decimal places
		//Close the output file
		fw.close();
		outputFile.close();
	}
}
	
