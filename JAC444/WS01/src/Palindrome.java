import java.util.Scanner;

public class Palindrome {
	
	public static void CheckPalidrome(String _input){
		String reverseString = reverseString(_input);
		
		if(reverseString.equals(_input)) {
			System.out.println( _input + " is a palindrome.");
		}
		else {
			System.out.println( _input + " is not a palindrome.");
		}
	}
	
	public static String reverseString (String _input) {
		Stack stack = new Stack(100);
		String temp = "";
		
		// push
		for(int i = 0; i < _input.length(); i++) {
			stack.puch(_input.charAt(i));
		}
		
		// reverse
		while(!stack.isEmpty()) {
			temp = temp + stack.pop();
		}		
		
		return temp;
	}

	public static void main(String[] args) {
		// Enter string or number
		System.out.println("Please enter: ");
		
		// User input
		Scanner scanner = new Scanner(System.in);
		String input = scanner.nextLine();
		CheckPalidrome(input);
	}
}
