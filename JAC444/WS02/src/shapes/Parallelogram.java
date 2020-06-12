/*
 * JAC444 Workshop 2
 * File: Parallelogram.java
 * Name: Youjin An (140413188)
 * Date: June 8, 2020
 */

package shapes;

public class Parallelogram implements Shape {
	private double width;
	private double height;
	
	public Parallelogram(double width, double height) throws ParallelogramException {
		//check the values are not negative or zero
		if(width > 0 && height > 0) {
			this.width = width;
			this.height = height;
		}
		else {
			// throw exception
			throw new ParallelogramException("Invalid side!");
		}
	}
	
	// Width
	public double getWidth() {
		return width;
	}

	public void setWidth(double width) throws ParallelogramException {
		if(width > 0) {
			this.width = width;
		}
		else {
			throw new ParallelogramException("Invalid side!");
		}
	}
	
	// Height
	public double getHeight() {
		return height;
	}

	public void setHeight(double height) throws ParallelogramException {
		if(height > 0) {
			this.height = height;
		}
		else {
			throw new ParallelogramException("Invalid side!");
		}
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