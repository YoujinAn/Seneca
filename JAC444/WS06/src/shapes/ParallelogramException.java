/*
 * JAC444 Workshop 6
 * File: ParallelogramException.java
 * Name: Youjin An (140413188)
 * Date: July 09, 2020
 */

package shapes;

//custom exception handler
@SuppressWarnings("serial") 

public class ParallelogramException extends Exception {
	public ParallelogramException(String message) {
		super(message);
	}
}
