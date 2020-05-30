public class Palindrome {
	
	public static void main(String[] args) {
		System.out.println("Entered string is "  + (CheckPalidrome(args[0]) ? "palindrome" : "not palindrome"));
	}
	
	public static boolean CheckPalidrome(String _input){
		String reverseString = reverseString(_input);
		
		return reverseString.equals(_input);
	}
	
	public static String reverseString (String _input) {
		Stack stack = new Stack(_input.length());
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
}
