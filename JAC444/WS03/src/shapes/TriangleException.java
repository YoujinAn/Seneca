/*
 * JAC444 Workshop 3
 * File: TriangleException.java
 * Name: Youjin An (140413188)
 * Date: June 11, 2020
 */

package shapes;

//custom exception handler
@SuppressWarnings("serial")

public class TriangleException extends Exception {
	public TriangleException(String message) {
		super(message);
	}
}
