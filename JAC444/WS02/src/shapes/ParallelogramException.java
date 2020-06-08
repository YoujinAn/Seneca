/*
 * JAC444 Workshop 2
 * File: ParallelogramException.java
 * Name: Youjin An (140413188)
 * Date: June 8, 2020
 */

package shapes;

//custom exception handler
@SuppressWarnings("serial") 

public class ParallelogramException extends Exception {
	public ParallelogramException(String message) {
		super(message);
	}
}
