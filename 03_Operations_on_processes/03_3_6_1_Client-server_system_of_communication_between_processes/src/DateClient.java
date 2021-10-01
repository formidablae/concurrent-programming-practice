/**
 * Client program requesting current date from server.
 *
 */ 

import java.net.*;
import java.io.*;

public class DateClient
{
	public static void main(String[] args)
	{
		try
		{
			// Changeable to an IP name or address other than the localhost
			Socket sock = new Socket("127.0.0.1",6013);
			InputStream in = sock.getInputStream();
			BufferedReader bin = new BufferedReader(new InputStreamReader(in));

			String line;
			while((line = bin.readLine()) != null)
			{
				System.out.println(line);
			}
			
			sock.close();
		}
		catch (IOException ioe)
		{
				System.err.println(ioe);
		}
	}
}
