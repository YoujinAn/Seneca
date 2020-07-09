/*
 * JAC444 Workshop 6
 * File: Rectangle.java
 * Name: Youjin An (140413188)
 * Date: July 09, 2020
 */

package shapes;

public class Rectangle extends Parallelogram {
	
	/*
	 *  Lamda expresstion
	 */
	private ShapeArea shape = () -> getWidth() * getHeight();
	
	public double calculateArea() {	
		return shape.getArea();
	}
	
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

