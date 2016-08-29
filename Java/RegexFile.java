import java.io.*;
import java.util.*;
import java.util.regex.*;

public class RegexFile {
  public static void main(String[] args) throws IOException {
    FileReader in = null;
    String regex1 = "(Yog)(.*)";
    String regex = "(^Yog)(.*)";
    Pattern pattern = Pattern.compile(regex);
    Matcher matcher = null;
    try {
      in = new FileReader(new File(args[0]));
      BufferedReader br = new BufferedReader(in);
      String line = null;
      while((line = br.readLine()) != null) {
        matcher = pattern.matcher(line);
        if(matcher.find()) {
          System.out.println(matcher.group(0));
        }
      }
    }
    finally {
        if(in != null) {
          in.close();
        }
    }
  }
}
