/*
 * JAC444 Workshop 2
 * File: Main.java
 * Name: Youjin An (140413188)
 * Date: June 8, 2020
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
		
		List<Shape> arrayOfShapes = new ArrayList<>();
		
		// read a file
		try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
			String s;
			
			while ((s = br.readLine()) != null) {
				
				// ["Triangle", "1.0", "2.0", "3.0"]
				String[] tokens = s.split(",");
				Shape shape = null;
				
				try {
					switch(tokens[0]) {
					
					//compare contents and proper number of tokens
					case "Circle":
						if(tokens.length == 2) {
							// Convert string to double
							double radius = Double.parseDouble(tokens[1]);
						
							// Create object
							shape = new Circle(radius);
						}	
						break;
						
					case "Triangle":
						if(tokens.length == 4) {
							double side1 = Double.parseDouble(tokens[1]);
							double side2 = Double.parseDouble(tokens[2]);
							double side3 = Double.parseDouble(tokens[3]);
																		
							shape = new Triangle(side1, side2, side3);
						}	
						break;
						
					case "Parallelogram":
						if(tokens.length == 3) {
							double width = Double.parseDouble(tokens[1]);
							double height = Double.parseDouble(tokens[2]);
																		
							shape = new Parallelogram(width, height);
						}
						break;
						
					case "Rectangle":
						if(tokens.length == 3) {
							double width = Double.parseDouble(tokens[1]);
							double length = Double.parseDouble(tokens[2]);
												
							shape = new Rectangle(width, length);
						}
						break;
						
					case "Square":
						if(tokens.length == 2) {
							double side = Double.parseDouble(tokens[1]);
																			
							shape = new Square(side);
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
				
				if (shape != null) {
					// store only the valid line
					arrayOfShapes.add(shape);
				}
			}		
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			int size = arrayOfShapes.size();
			System.out.println("\n" + size + " shapes were created:");
			
			for(int i = 0; i < size; i++) {
				System.out.println(arrayOfShapes.get(i) + "\n");
			}
		}
	}
}
