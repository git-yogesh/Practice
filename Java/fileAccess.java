import java.io.*;
import java.util.*;
//Run as java fileAccess input.txt 1
public class fileAccess {
  public static void main(String[] args) throws IOException {
    FileReader in = null;
    FileWriter out = null;
    int column = Integer.parseInt(args[1]);
    try {
      in = new FileReader(new File(args[0]));
      out = new FileWriter("output.txt");
      BufferedReader br = new BufferedReader(in);
      String line = null;
      while((line = br.readLine()) != null) {
        String[] str = line.split(",");
        out.write(str[column-1]);
        out.write("\n");
        System.out.println(str[column-1]);
      }
    } finally {
      if(in != null) in.close();
      if(out != null) out.close();
    }
  }
}
