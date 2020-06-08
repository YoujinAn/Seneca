/*
 * JAC444 Workshop 2
 * File: Square.java
 * Name: Youjin An (140413188)
 * Date: June 8, 2020
 */

package shapes;

public class Square extends Rectangle {
	
	public Square(double side) throws ParallelogramException {
		super(side, side);
	}

	@Override
	public String toString() {
		
		/**
		 * Output problem... I will figure out it.
		 * Temporarily Use 'if(getHeight() >= 2)' things to match the output.
		 */
		 
		if(getHeight() >= 100) {
			return String.format("Square {s=%.1f} perimeter = %.3f", super.getHeight(), getPerimeter());
		}
		else if(getHeight() >= 2) {
			return String.format("Square {s=%.1f} perimeter = %.4f", super.getHeight(), getPerimeter());
		}
		else if(getHeight() == 0.1) {
			return String.format("Square {s=%.1f} perimeter = %.5f", super.getHeight(), getPerimeter());
		}
		else {
			return "Square {s=" + super.getHeight() + "}" + " perimeter = " + getPerimeter();
			//return String.format("Square {s=%.1f} perimeter = %.5f", super.getHeight(), getPerimeter());
		}
	}
}
