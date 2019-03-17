import java.io.*;
import java.text.DecimalFormat;
import java.util.Scanner;

public class StatsDemo
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
		

		FileReader file = new FileReader(filename); //Read the filename to open
		Scanner inputFile = new Scanner(file); //Create scanner object to print the file
		while(inputFile.hasNext())
		{
			line = inputFile.nextLine();
			//System.out.println(line); Test the numbers being read
			sum = sum + Double.parseDouble(line);
			count++; //Keep count of the amount of numbers
		}
		file.close();
		inputFile.close(); 		//Close the input file
		mean = sum/count;		//Calculate Mean
		//FileWriter object
		FileWriter fw = new FileWriter("Results.txt", true);
		//PrinterWriter object
		PrintWriter outputFile = new PrintWriter(fw);
		outputFile.println("The mean is: " + df.format(mean));
		//Close the output file
		fw.close();
		outputFile.close();
	}
}
	
