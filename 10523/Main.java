import java.util.Scanner;
import java.math.BigInteger;

public class Main{
     public static void main(String []args){
          BigInteger sum,A,I;
          Scanner sc = new Scanner(System.in);
          while( sc.hasNextInt() ){
               sum = new BigInteger("0");
               int n = sc.nextInt();
               int a = sc.nextInt();
               A = new BigInteger(""+a);
               
               for(int i=1; i<=n; i++){
                    I = new BigInteger(""+i);
                    sum = sum.add( I.multiply(A.pow(i)) );
               }
               System.out.println(sum);
          }
     }
}
