public class Symbols
{
	/**
	 * @param args
	 */
	public static void main(String[] args)
	{
		Thread t1= new SymbolThread('*');
		Thread t2= new SymbolThread('#');

		t1.start();
		t2.start();
	}
}

class SymbolThread extends Thread
{
	char s;

	public SymbolThread(char s)
	{
		this.s = s;
	}

	public void run()
	{
		int i = 1; 
		/* Every thread holds a copy of the i variable;
		this way it is possible to have in the same line
		49 symbols of a thread + 40 (79 in total) of the other
		(at most and at least 1 only symbol). */
		
		while (true)
		{
			if (i == 40)
			{
				System.out.println(s);
				i=1;
			}
			else
			{
				System.out.print(s);
				i++;
			}
		}
	}
}
