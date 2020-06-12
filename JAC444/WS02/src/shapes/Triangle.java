/*
 * JAC444 Workshop 2
 * File: Triangle.java
 * Name: Youjin An (140413188)
 * Date: June 8, 2020
 */

package shapes;

public class Triangle implements Shape {
	private double side1;
	private double side2;
	private double side3;
	
	public Triangle(double side1, double side2, double side3) throws TriangleException {
		if (side1 > 0 && side2 > 0 && side3 > 0 && 
				(side1 + side2) > side3 && (side2 + side3) > side1 && (side1 + side3) > side2) {
			this.side1 = side1;
			this.side2 = side2;
			this.side3 = side3;
		}
		else {
			throw new TriangleException("Invalid side(s)!");
		}
	}
	
	public double getSide1() {
		return side1;
	}

	public void setSide1(double side1) throws TriangleException {
		if(side1 > 0 && 
				(side1 + side2) > side3 && (side2 + side3) > side1 && (side1 + side3) > side2) {
			this.side1 = side1;
		}
		else {
			throw new TriangleException("Invalid side!");
		}
	}

	public double getSide2() {
		return side2;
	}

	public void setSide2(double side2) throws TriangleException {
		if(side2 > 0 && 
				(side1 + side2) > side3 && (side2 + side3) > side1 && (side1 + side3) > side2) {
			this.side2 = side2;
		}
		else {
			throw new TriangleException("Invalid side!");
		}
	}

	public double getSide3() {
		return side3;
	}

	public void setSide3(double side3) throws TriangleException {
		if(side3 > 0 && 
				(side1 + side2) > side3 && (side2 + side3) > side1 && (side1 + side3) > side2) {
			this.side3 = side3;
		}
		else {
			throw new TriangleException("Invalid side!");
		}
	}

	@Override
	public double getPerimeter() {
		return getSide1() + getSide2() + getSide3();
	}
	
	@Override
	public String toString() {
		return String.format("%s {s1=%.1f, s2=%.1f, s3=%.1f} perimeter = %.4f", getClass().getSimpleName(), getSide1(), getSide2(), getSide3(), getPerimeter());
	}
}
