/*
 * JAC444 Workshop 6
 * File: Circle.java
 * Name: Youjin An (140413188)
 * Date: July 09, 2020
 */

package shapes;

import static java.lang.Math.PI;
import java.lang.Math;

public class Circle implements Shape{
	private double radius;
	
	/*
	 *  Lamda expresstion
	 */
	private ShapeArea shape = () -> PI * getRadius() * getRadius();
	
	public double calculateArea() {
		return shape.getArea();
	}	
	
	public Circle(double radius) throws CircleException {
		if(radius > 0)	{
			this.radius = radius;
		}
		else {
			throw new CircleException("Invalid radius!");
		}
	}
	
	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) throws CircleException {
		if(radius > 0) {
			this.radius = radius;
		}
		else {
			throw new CircleException("Invalid radius!");	
		}
	}

	@Override
	public double getPerimeter() {
		return 2 * Math.PI * getRadius();
	}

	@Override
	public String toString() {
		if (getRadius() >= 2) {
			return String.format("%s {r=%.1f} perimeter = %.4f", getClass().getSimpleName(), getRadius(), getPerimeter(), shape);
		}
		else {
			return String.format("%s {r=%.1f} perimeter = %.5f", getClass().getSimpleName(), getRadius(), getPerimeter(), shape);
		}
	}
}
