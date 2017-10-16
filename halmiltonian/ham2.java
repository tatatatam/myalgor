import java.util.Scanner;
public class ham2 {


   public static void main(String []args) {
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int[][] vect = new int[n][n];
      int[] x = new int[n];
      for(int i =1;i<=vect.length;i++){
        for(int j =1;j<=vect.length;j++){
          vect[i][j]=0;
          x[i]=0;
        }
      }
      int edge = sc.nextInt();
      int v1,v2;
      System.out.println(edge);
      // for(int i=1;i<= edge.length();i++){
      //   v1 = sc.nextInt();
      //   v2 = sc.nextInt();
      //   vect[v1][v2]=1;
      //   vect[v2][v1]=1;
      // }
      // cycle(G,n,2);
   }

}
