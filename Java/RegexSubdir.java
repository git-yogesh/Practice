import java.io.*;
import java.util.*;
import java.util.regex.*;

public class RegexSubdir {
  public static void main(String[] args) throws IOException {
    FileReader in = null;
    File parentDir = new File(args[0]);

    FileFilter fileFilter = new FileFilter() {
      public boolean accept(File file) {
        return file.isDirectory();
      }
    };

    File[] subDir = parentDir.listFiles(fileFilter);
    BufferedReader br = null;
    String REGEX = "(^Yog)(.*)";
    Pattern pattern = Pattern.compile(REGEX);
    Matcher matcher = null;
    for(File dir : subDir) {
      System.out.println("Inside " + dir.getName());
      File[] files = dir.listFiles();
      for(File file : files) {
        System.out.println("Inside " + file.getName());
        try {
          in = new FileReader(file);
          br = new BufferedReader(in);
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
