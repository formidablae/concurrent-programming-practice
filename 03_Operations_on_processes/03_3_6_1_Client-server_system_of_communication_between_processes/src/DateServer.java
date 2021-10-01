/**
 * Time-of-day server listening to port 6013.
 *
 */
 
import java.net.*;
import java.io.*;

public class DateServer
{
	public static void main(String[] args)
	{
		try
		{
			ServerSocket sock = new ServerSocket(6013);

			// Listen for connections
			while (true)
			{
				Socket client = sock.accept();
				// Make a connection
				
				PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
				// Write the Date to the socket
				pout.println(new java.util.Date().toString());

				// Close the socket and resume listening for more connections
				client.close();
			}
		}
		catch (IOException ioe)
		{
				System.err.println(ioe);
		}
	}
}
