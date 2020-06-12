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
	
	}
}
