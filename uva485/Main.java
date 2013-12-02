import java.util.Scanner;
import java.math.*;

public class Main{

     public static void main(String []args){
     
          
          BigInteger v[][] = new BigInteger[2][];
                     v[0]  = new BigInteger[209];
                     v[1]  = new BigInteger[209];     
          int index=0;
          
          v[index][0]   = BigInteger.ONE;
          v[index][1]   = BigInteger.ONE;
          v[index+1][0] = BigInteger.ONE;
          v[index+1][1] = BigInteger.ONE;
          
          System.out.println("1");
          System.out.println("1 1");
          
          for(int i=2; i<205; i++){
               index++;
               int now = index%2;
               int bef = (index-1)%2;
               
               System.out.print("1");
               
               for(int j=0; j<i-1; j++){
                    
                    v[now][j+1] = v[bef][j].add( v[bef][j+1] );
                    System.out.print(" "+v[now][j+1]);           
               }
               
               System.out.println(" 1");
               
               v[now][i] = BigInteger.ONE;      
          }                    
     }
}
