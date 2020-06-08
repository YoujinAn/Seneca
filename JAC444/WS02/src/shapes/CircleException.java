/*
 * JAC444 Workshop 2
 * File: CircleException.java
 * Name: Youjin An (140413188)
 * Date: June 8, 2020
 */

package shapes;

//Custom exception handler
@SuppressWarnings("serial")

public class CircleException extends Exception {
	public CircleException(String message) {
		super(message);
	}
}
