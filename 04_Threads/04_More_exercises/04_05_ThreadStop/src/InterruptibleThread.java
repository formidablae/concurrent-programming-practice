/**
 * This class file illustrates deferred cancellation using the
 * isInterrupted() method.
 */

public class InterruptibleThread implements Runnable 
{
	/**
	 * This thread will continue to run as long
	 * as it is not interrupted.
	 */

	public void run()
	{
		while (true)
		{
			/**
			 * run for awhile
			 */

			if (Thread.currentThread().isInterrupted())
			{
				System.out.println("Child thread: I'm now interrupted!");
				break;
			}
		}
		// clean up and terminate
	}
}
