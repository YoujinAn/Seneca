/*
 * JAC444 Workshop 3
 * File: Rectangle.java
 * Name: Youjin An (140413188)
 * Date: June 11, 2020
 */

package shapes;

public class Rectangle extends Parallelogram {
	
	public Rectangle(double width, double height) throws ParallelogramException {
		super(width, height);
	}
	
	@Override
	public double getPerimeter() {
		return 2 * (getWidth() + getHeight());
	}

	@Override
	public String toString() {
		return String.format("%s {w=%.1f, h=%.1f} perimeter = %.4f", getClass().getSimpleName(), getWidth(), getHeight(), getPerimeter());
	}
}

