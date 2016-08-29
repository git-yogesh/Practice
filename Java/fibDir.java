import java.io.*;
import java.util.*;

public class fibDir {

  int fibonacci(int n) {
    if(n == 0 || n == 1) return n;
    return (fibonacci(n-1) + fibonacci(n-2));
  }
  public static void main(String[] args) throws IOException, SecurityException{
    int[] arr = new int[1000];
    fibDir obj = new fibDir();
    int n = Integer.parseInt(args[0]);
    int i = 0;
    String dir_name = null;
    String file_name = null;
    File file = null;
    File dir = null;
    FileWriter out = null;
    BufferedWriter bw = null;
    while(i<n) {
      arr[i] = obj.fibonacci(i);
      i++;
    }
    for(i=0; i<n; i++) {
      //System.out.println(arr[i] + " ");
      if(arr[i] % 2 == 0) {
        file_name = "file"+arr[i]+".txt";
        file = new File(file_name);
        file.createNewFile();
        out = new FileWriter(file);
        bw = new BufferedWriter(out);
        bw.write(arr[i]);
        bw.close();
        out.close();
        System.out.println(arr[i]);
      }
      else {
        dir_name = "dir"+arr[i];
        dir = new File(dir_name);
        dir.mkdir();
      }
    }
  }
}
