/*
 * JAC444 Workshop 4
 * File: StudentWriter.java
 * Name: Youjin An (140413188)
 * Date: 18 June, 2020
 */

package student;

import java.io.*;
import java.util.Scanner;

// Enter some information for some student objects from the console and 
// save these student objects in a file.
public class StudentWriter {

	public static void addStudentInfo() {

		try {
			FileOutputStream fos = new FileOutputStream("student.out");
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			Scanner reader = new Scanner(System.in);

			boolean Enter_continue = true;

			// Enter student
			do {
				Student student = new Student();

				// Student ID
				System.out.print("Enter student ID: ");
				student.setStdID(reader.nextInt());
				reader.nextLine();

				// Student Name
				System.out.print("Enter student's first name: ");
				student.setFirstName(reader.nextLine());
				System.out.print("Enter student's last name: ");
				student.setLastName(reader.nextLine());

				// Course
				int NumOfcourses = 0;
				System.out.print("Number of student courses: ");
				NumOfcourses = reader.nextInt();
				String course = reader.nextLine();

				for (int i = 0; i < NumOfcourses; i++) {
					System.out.print("Enter student's course: ");
					course = reader.nextLine();
					student.addCourse(course);
				}

				oos.writeObject(student);
				oos.flush();

				// Another Student
				System.out.print("Do you want to enter another student? (y or n): ");
                String ask_continue = reader.nextLine();
                System.out.println("");
                
                while( ( !(ask_continue.equalsIgnoreCase("y")) || !(ask_continue.equalsIgnoreCase("Y")) ) && 
                		( !(ask_continue.equalsIgnoreCase("n")) || !(ask_continue.equalsIgnoreCase("N"))) ) {
                    System.out.println(ask_continue + " is an invalid answer. Please enter y or n: ");
                    ask_continue = reader.nextLine();
                }
                
                if(ask_continue.equalsIgnoreCase("n")){
                	Enter_continue = false;
                }

			} while (Enter_continue);

			oos.flush();
			fos.close();

		} catch (Throwable e) {
			System.err.println(e);
		}
	}
	
	public static void main(String[] args) {
		System.out.println("-------- Enter Student Data --------");
		StudentWriter.addStudentInfo();		
	}
}
