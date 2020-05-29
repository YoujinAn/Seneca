public class Stack {
	
	private char[] arrayOfchar;
	private int sizeOfchar;

	// Size definition of array
	public Stack (int _sizeOfchar) {
		arrayOfchar = new char[_sizeOfchar];
		sizeOfchar = -1;
	}
	
	// Check the size status of the array
	public boolean isEmpty() {
		return sizeOfchar == -1;
	}
	
	public boolean isFull() {
		return sizeOfchar == arrayOfchar.length - 1;
	}
	
	// Stack
	public void puch (char character) {
		if(isFull()) {
			System.out.println("Stack is full!");
			throw new IllegalStateException("Stack is full");
		}
		else {
			arrayOfchar[++sizeOfchar] = character;
		}		
	}
	
	public char pop() {
		if(isEmpty()) {
			System.out.println("Stack is empty!");
			throw new IllegalStateException("Stack is empty");
		}
		else {
			return arrayOfchar[sizeOfchar--];
		}
	}
}
