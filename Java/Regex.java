import java.io.*;
import java.util.regex.*;

public class Regex {
  public static void main(String[] args) {
      String line = "Yogesh Patil";
    String regex = "(Yog)(.*)";
    Pattern pattern = Pattern.compile(regex);
    Matcher matcher = pattern.matcher(line);
    if(matcher.find()) {
      System.out.println(matcher.group(0));
      System.out.println(matcher.group(1));
      System.out.println(matcher.group(2));
    } else {
      System.out.println("Not found");
    }
  }
}
