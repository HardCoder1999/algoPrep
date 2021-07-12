import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();
		while(t--){
			int n = nextInt();
			int[] vaccine = new int[n];
			int[] virus = new int[n];

			for(int i=0; i<n; i++)
				vaccine[i] = sc.nextInt();

			for(int i=0; i<n; i++)
				virus[i] = sc.nextInt();

			Arrays.sort(vaccine);
			Arrays.sort(virus);

			int flag = 1;

			for(int i=0; i<n; i++){
				if(vaccine[i] <= virus[i]){
					flag = 0;
					break;
				}
			}

			String result = (flag == 1)? "Yes" : "No";
			System.out.println(result);
		}
	}
}