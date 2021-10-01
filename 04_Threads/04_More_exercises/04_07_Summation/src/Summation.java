// import java.io.*;

/**
 * Sum example: A Java multithread program that runs a summation function 
 * between two user input integers.
 * Create a parallel thread to do the summation and return the result in a
 * (global) variable shared with the main thread.
 * The main thread than prints the result to video..
 *
 * First solution: Summation and Summator are two distinct separate classes.
 */

public class Summation
{
	public static void main(String[] args)
	{
		// Definition of the shared object that will hold un integer.
		// See below the definiton of the wrapper class HoldInteger.
		HoldInteger result = new HoldInteger(); 
		
		// int a = Integer.parseInt(args[0]);
		// int b = Integer.parseInt(args[1]);
		int a = 3;
		int b = 5; 
		
		// Creation and spawn of the summator thread.
		// The int values to sum and the pointer to the shared object
		// where the result will be stored are passed as parameters
		// to the constructor of the Summator thread.
		Thread doSum = new Thread(new Summator(result, a, b));
		doSum.start();
		try
		{
			// The main thread is synchronized at the termination of the Summator thread
			doSum.join();
		}
		catch (InterruptedException e)
		{
			e.printStackTrace();
		}
		
		System.out.println("Sum of "+ a + " + " + b + " = " + result.getVal());
	}
}

class Summator implements Runnable
{
	private HoldInteger result; // private copy of the pointer to the shared object
	int a, b;
	
	public Summator(HoldInteger result, int a, int b)
	{
		this.result = result;
		this.a = a;
		this.b = b;
	}
	
	public void run()
	{
		result.setVal(a+b);
	}
}

/**
 * Definition of the wrapper class with getter and setter methods
 * for sharing of an integer without synchronization.
 */
class HoldInteger
{
	int value;
	
	public void setVal(int newVal)
	{
		value = newVal;
	}
	
	public int getVal()
	{
		return value;
	}
}
