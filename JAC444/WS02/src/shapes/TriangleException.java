/*
 * JAC444 Workshop 2
 * File: TriangleException.java
 * Name: Youjin An (140413188)
 * Date: June 8, 2020
 */

package shapes;

//custom exception handler
@SuppressWarnings("serial")

public class TriangleException extends Exception {
	public TriangleException(String message) {
		super(message);
	}
}
