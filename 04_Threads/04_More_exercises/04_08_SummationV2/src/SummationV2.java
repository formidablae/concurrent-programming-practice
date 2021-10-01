/**
 * Sum example: A Java multithread program that runs a summation function 
 * between two user input integers.
 * Create a parallel thread to do the summation and return the result in a
 * (global) variable shared with the main thread.
 * The main thread than prints the result to video..
 *
 * Second solution: Sommator is declared as inner class of SummationV2 and
 * thus it has access (and shares) all that is declared inside SummationV2 class.
 */

public class SummationV2
{
	private int result;
	
	// Creation and spawn "on the fly" of the child thread to do the summation.
	// The result is directly put in the private variable result of the SummationV2.
	
	public void doSum(int a, int b)
	{
		// Passing of the integer values to be added.
		Thread summatorThrd = new Thread(new Summator(a, b));
		summatorThrd.start();
		
		try
		{
			summatorThrd.join(); 
		}
		catch (InterruptedException ex)
		{
			ex.printStackTrace();
		}
	}

	// Inner class:
	public class Summator implements Runnable
	{		
		int a, b;

		public Summator(int a, int b)
		{
			this.a = a;
			this.b = b;
		}

		public void run()
		{
			result = a + b;
		}
	}

	public static void main(String[] args)
	{
		int a = 3;
		int b = 5;
		
		// An object of type SummationV2 is created. It's doSum(a, b) method
		// is called in order to do the summation and to print the result to video.
		SummationV2 sumTester = new SummationV2();
		sumTester.doSum(a,b);
		System.out.println("Sum of " + a + " + " + b + " = " + sumTester.result);
	}
}
