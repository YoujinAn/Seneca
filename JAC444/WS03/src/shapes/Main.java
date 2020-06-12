/*
 * JAC444 Workshop 3
 * File: Main.java
 * Name: Youjin An (140413188)
 * Date: June 11, 2020
 */

package shapes;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) {
		
String fileName = "./src/shapes.txt";
		
		System.out.println("------->JAC 444 Assignment 1<-------");
		System.out.println("------->Task 1 ... <-------");
		
		// List<Shape> arrayOfShapes = new ArrayList<>();
		Shape[] shapes = new Shape[100];
		int index = 0;
		
		// read a file
		try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
			String s;
			
			while ((s = br.readLine()) != null) {
				
				// ["Triangle", "1.0", "2.0", "3.0"]
				String[] tokens = s.split(",");
				// Shape shape = null;
				
				try {
					switch(tokens[0]) {
					
					//compare contents and proper number of tokens
					case "Circle":
						if(tokens.length == 2) {
							// Convert string to double
							double radius = Double.parseDouble(tokens[1]);
						
							// Create object
							shapes[index] = new Circle(radius);
							index++;
						}	
						break;
						
					case "Triangle":
						if(tokens.length == 4) {
							double side1 = Double.parseDouble(tokens[1]);
							double side2 = Double.parseDouble(tokens[2]);
							double side3 = Double.parseDouble(tokens[3]);
																		
							shapes[index] = new Triangle(side1, side2, side3);
							index++;
						}	
						break;
						
					case "Parallelogram":
						if(tokens.length == 3) {
							double width = Double.parseDouble(tokens[1]);
							double height = Double.parseDouble(tokens[2]);
																		
							shapes[index] = new Parallelogram(width, height);
							index++;
						}
						break;
						
					case "Rectangle":
						if(tokens.length == 3) {
							double width = Double.parseDouble(tokens[1]);
							double length = Double.parseDouble(tokens[2]);
												
							shapes[index] = new Rectangle(width, length);
							index++;
						}
						break;
						
					case "Square":
						if(tokens.length == 2) {
							double side = Double.parseDouble(tokens[1]);
																			
							shapes[index] = new Square(side);
							index++;
						}
						else{
							continue; //ignore and continue read a file
						}
						break;
						
					default:
						
					}
				} catch (CircleException e) {
					System.out.println(e.getMessage());
				} catch (TriangleException e) {
					System.out.println(e.getMessage());
				} catch (ParallelogramException e) {
					System.out.println(e.getMessage());
				} catch (Exception e) {
					System.out.println(e.getMessage());
				}
			}		
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			System.out.println("\n" + index + " shapes were created:");
			
			for(int i = 0; i < index; i++) {
				System.out.println(shapes[i] + "\n");
			}
		}
		
		/*
		 * Delete the triangle with the minimum perimeter (there could be more than one minimum) and 
		 * the circle with the maximum perimeter (there could be more than one maximum) from the shapes.
		 */
		
		System.out.println("------->Task 2 ... <-------");
		
		double min = 0;
		double max = 0;
		
		// Check Min and Max
		for(int i = 0; i < index; i++) {
			// check if the perimeter of circle is larger than max
			if(shapes[i].getClass().getSimpleName().equals("Circle")) {
				if(max <= shapes[i].getPerimeter()) {
					max = shapes[i].getPerimeter();
				}
				min = max;
			} 
			// check if the perimeter of triangle is less than min
			else if(shapes[i].getClass().getSimpleName().equals("Triangle")) {
				if(min >= shapes[i].getPerimeter()) {
					min = shapes[i].getPerimeter();
				}
			}
		}
		
		// Delete
		for(int i = 0; i < index; i++) {
			if(shapes[i].getClass().getSimpleName().equals("Circle")) {
				if(shapes[i].getPerimeter() == max) {
					for(int j = i; j < index; j++) {
						shapes[j] = shapes[j+1];
					}
					index--;
				}
			}
			
			if(shapes[i].getClass().getSimpleName().equals("Triangle")) {
				if(shapes[i].getPerimeter() == min) {
					for(int j = i; j < index; j++) {
						shapes[j] = shapes[j+1];
					}
					index--;
				}
			}
		}
		
		// Print
		for(int i = 0; i < index; i++) {
			System.out.println(shapes[i] + "\n");
		}
		
		// Calculate and print the total perimeter of all parallelograms and the total perimeter of all	triangles.
		System.out.println("------->Task 3 ... <-------");
		
		double totalOfParallelogram = 0;
		double totalOfTriangle = 0;
		
		// Calculate the total perimeter of all parallelograms and the total perimeter of all triangles
		for(int i = 0; i < index; i++) {
			if(shapes[i].getClass().getSimpleName().equals("Parallelogram")) {
				totalOfParallelogram += shapes[i].getPerimeter();
			}
			else if (shapes[i].getClass().getSimpleName().equals("Triangle")) {
				totalOfTriangle += shapes[i].getPerimeter();
            }
		}
		
		// Print
		System.out.println("Total perimeter of Parallelogram is: " + totalOfParallelogram);
		System.out.println("Total perimeter of Triangle is: " + totalOfTriangle);
	}
}
