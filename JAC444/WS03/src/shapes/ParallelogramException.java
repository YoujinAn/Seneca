/*
 * JAC444 Workshop 3
 * File: ParallelogramException.java
 * Name: Youjin An (140413188)
 * Date: June 11, 2020
 */

package shapes;

//custom exception handler
@SuppressWarnings("serial") 

public class ParallelogramException extends Exception {
	public ParallelogramException(String message) {
		super(message);
	}
}
