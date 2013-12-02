import java.util.Scanner;
import java.math.BigInteger;

public class Main{
     public static void main( String []args ){
          Scanner sc = new Scanner(System.in);
          BigInteger A,B;
          
          int n = sc.nextInt();
          while( n-- > 0 ){
               A = sc.nextBigInteger();
               B = sc.nextBigInteger();
               
               System.out.println( A.subtract( B ) );
          }
     } 
}
