import java.io.*;
import java.util.*;

class Contacts
{
	public static void main(String args[])throws IOException
	{
		int col = Integer.parseInt(args[1]); // column number

		FileReader fileReader = new FileReader(new File(args[0]));
		
		BufferedReader br = new BufferedReader(fileReader);
		
		String line = null;
		while ((line = br.readLine()) != null) 
		{
			String[] str = line.split(",");
			System.out.println(str[col-1]);
		}
	}
}