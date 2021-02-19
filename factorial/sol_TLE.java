import java.math.BigInteger; 
import java.util.Scanner; 
  
public class sol_TLE 
{ 
    // Returns Factorial of N 
    static BigInteger factorial(int N) 
    { 
        // Initialize result 
        BigInteger f = new BigInteger("1"); // Or BigInteger.ONE 
  
        // Multiply f with 2, 3, ...N 
        for (int i = 2; i <= N; i++) 
            f = f.multiply(BigInteger.valueOf(i)); 
  
        return f; 
    } 
  
    // Driver method 
    public static void main(String args[]) throws Exception 
    { 
        int N;
        Scanner in=new Scanner(System.in);
        N=in.nextInt();
        
        int c=0;
        BigInteger x=factorial(N);
        while(true)
        {
            if((x.mod(BigInteger.TEN)).compareTo(BigInteger.ZERO)!=0)
            {
                break;
            }
            
            else {
               x= x.divide(BigInteger.TEN);
                c++;
            }
        }
        System.out.println(c);
    } 
} 
