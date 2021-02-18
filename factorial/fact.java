import java.util.Scanner;
public class fact {
	 static int trailingZeroes(int n) {
		return (n == 0 ? 0 : n / 5 + trailingZeroes(n / 5));}
	public static void main(String[] args) {
		
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		scan.close();
	   System.out.println(trailingZeroes(n));

		
	}

}
