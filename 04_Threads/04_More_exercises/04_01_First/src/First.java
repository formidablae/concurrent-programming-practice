class Worker extends Thread
{
	public void run()
	{
		System.out.println("Auxilliary thread: Hello world!");
	}
}

public class First
{
	public static void main(String args[])
	{
	   Thread runner = new Worker();
	   runner.start();
	   System.out.println("Main       thread: Hello world!");
	}
}