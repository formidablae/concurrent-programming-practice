public class Third
{
	public static void main(String[] args)
	{
		System.out.println("This is the " + Thread.currentThread().getName() + " thread");
		
		//Creation of 10 threads of anonymous class   
		for (int i = 0; i < 10; i++)
		{
			new Thread("thrd_" + i)
			{
				public void run()
				{
					System.out.println("Thread: " + getName() + " running");
				}
			}.start();
		}
	}
}