# Compilation and execution istructions
For compilation and execution use the following commands:

## On Linux-like operating systems
Java JDK needs to be installed before trying to compile.

Using a terminal shell, navigate to the directory where you have saved the files of this repository:

```sh
cd ~/Path/To/Repo/03_3_6_1_Client-server_system_of_communication_between_processes/
```

To compile run:

```sh
javac src/DateClient.java -d bin/
javac src/DateServer.java -d bin/
```

# Definitions

`accept()`: puts the server in listening mode waiting for a request from the client.

`getInputStream()`: returns a ServletOutputStream for writing binary data in the response.

`getOutputStream()`: returns a ServletOutputStream for writing binary data in the response.

`PrinterWriter`: object that can send character text to the client.

`BufferedReader`: reads text from a character-input stream, buffering characters so as to provide for the efficient reading of characters, arrays, and lines.

`InputStream`: abstract class, superclass of all classes representing an input stream of bytes.

`InputStreamReader()`: creates an InputStreamReader (a bridge from byte streams to character streams). It reads bytes and decodes them into characters using a specified charset. 

`close()`: closes the socket/client.
