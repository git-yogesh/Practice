import java.io.*;
import java.util.*;
import java.util.regex.*;

public class RegexDir {
  public static void main(String[] args) throws IOException {
  File dir = null;
  FileReader in = null;
  String regex = "(.*)(Yog)(.*)";
  Pattern pattern = Pattern.compile(regex);
  Matcher matcher = null;
    dir = new File(args[0]);
    File[] files = dir.listFiles();
    if(files != null) {
      for(File file : files) {
        try {
          in = new FileReader(file);
          BufferedReader br = new BufferedReader(in);
          String line = null;
          while((line = br.readLine()) != null) {
            matcher = pattern.matcher(line);
            if(matcher.find()) {
              System.out.println(matcher.group(0));
            }
          }
        } finally {
          if(in != null) in.close();
        }
      }
    }
  }
}
