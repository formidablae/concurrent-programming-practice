class Worker2 implements Runnable
{
	public void run()
	{
		System.out.println("Auxilliary thread: Hello world!");
	}
}

public class Second
{
	public static void main(String args[])
	{
		//Runnable runner = new Worker2();
		//Thread thrd = new Thread(runner);
		
		Thread thrd = new Thread(new Worker2());
		thrd.start();
		System.out.println("Main       thread: Hello world!");
	}
}
