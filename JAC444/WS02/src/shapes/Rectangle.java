/*
 * JAC444 Workshop 2
 * File: Rectangle.java
 * Name: Youjin An (140413188)
 * Date: June 8, 2020
 */

package shapes;

public class Rectangle extends Parallelogram {
	
	public Rectangle(double width, double height) throws ParallelogramException {
		super(width, height);
	}

	@Override
	public String toString() {
		return String.format("Rectangle {w=%.1f, h=%.1f} perimeter = %.4f", getWidth(), getHeight(), getPerimeter());
	}
}

