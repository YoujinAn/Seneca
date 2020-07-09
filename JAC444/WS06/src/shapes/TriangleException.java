/*
 * JAC444 Workshop 6
 * File: TriangleException.java
 * Name: Youjin An (140413188)
 * Date: July 09, 2020
 */

package shapes;

//custom exception handler
@SuppressWarnings("serial")

public class TriangleException extends Exception {
	public TriangleException(String message) {
		super(message);
	}
}
