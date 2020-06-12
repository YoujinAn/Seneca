/*
 * JAC444 Workshop 3
 * File: Square.java
 * Name: Youjin An (140413188)
 * Date: June 11, 2020
 */

package shapes;

public class Square extends Rectangle {
	
	public Square(double side) throws ParallelogramException {
		super(side, side);
	}
	
	@Override
	public void setWidth(double width) throws ParallelogramException {
		if(width > 0) {
			super.setWidth(width);
			super.setHeight(width);
		}
		else {
			throw new ParallelogramException("Invalid side!");
		}
	}
	
	@Override
	public void setHeight(double height) throws ParallelogramException {
		if(height > 0) {
			super.setWidth(height);
			super.setHeight(height);
		}
		else {
			throw new ParallelogramException("Invalid side!");
		}
	}
	
	@Override
	public double getPerimeter() {
		return 4 * getWidth();
	}

	@Override
	public String toString() {
		
		if(getHeight() >= 100) {
			return String.format("%s {s=%.1f} perimeter = %.3f", getClass().getSimpleName(), super.getHeight(), getPerimeter());
		}
		else if(getHeight() >= 2) {
			return String.format("%s {s=%.1f} perimeter = %.4f", getClass().getSimpleName(), super.getHeight(), getPerimeter());
		}
		else if(getHeight() == 0.1) {
			return String.format("%s {s=%.1f} perimeter = %.5f", getClass().getSimpleName(), super.getHeight(), getPerimeter());
		}
		else {
			return "Square {s=" + super.getHeight() + "}" + " perimeter = " + getPerimeter();
			//return String.format("Square {s=%.1f} perimeter = %.5f", super.getHeight(), getPerimeter());
		}
	}
}
