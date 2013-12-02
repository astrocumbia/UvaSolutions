import java.util.Scanner;
import java.math.BigInteger;

public class Main{
     public static void main( String []args ){
          Scanner sc = new Scanner( System.in );
          BigInteger MOD = new BigInteger("17");
          BigInteger N;
          
          while( sc.hasNextBigInteger( ) ){
               N = sc.nextBigInteger();
               if( N.compareTo(BigInteger.ZERO)==0 )break;
               
               if( N.mod( MOD ).compareTo(BigInteger.ZERO)==0 )
                    System.out.println("1");
               else 
                    System.out.println("0");
          }
   
     }
}
