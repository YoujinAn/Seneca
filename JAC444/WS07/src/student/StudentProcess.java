/*
 * JAC444 Workshop 7
 * File: StudentProcess.java
 * Name: Youjin An (140413188)
 * Date: July 16, 2020
 */

package student;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.function.Consumer;
import java.util.function.BiConsumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Stream;
import java.util.stream.Collectors;
import java.util.Optional;

public class StudentProcess {

	public static void main(String[] args) {
		
		// Typical input
		Student[] students = {
				new Student("Jack", "Smith", 50.0, "IT"),
				new Student("Aaron", "Johnson", 76.0, "IT"),
				new Student("Maaria", "White", 35.8, "Business"),
				new Student("John", "White", 47.0, "Media"),
				new Student("Laney", "White", 62.0, "IT"),
				new Student("Jack", "Jones", 32.9, "Business"),
				new Student("Wesley", "Jones", 42.89, "Media")
			};
		
		
		List <Student> studentList = Arrays.asList(students);
		
		System.out.println("Task 1:\n");
		System.out.println("Complete Student list:");
		studentList.forEach(System.out::println);
		
		System.out.print("\n\n");
		System.out.println("Task 2:\n");
		System.out.println("Student who got 50.0-100.0 sorted by grade:");
		studentList.stream()
			.filter(Student::isGradeBetween50And100)
			.sorted(Comparator.comparing(Student::getGrade))
			.forEach(System.out::println);
	
		
		System.out.print("\n\n");
		System.out.println("Task 3:\n");
		System.out.println("First Student who got 50.0-100.0:");
		studentList.stream()
			.filter(Student::isGradeBetween50And100)
			.findFirst()
			.ifPresent(System.out::println);
		
		System.out.print("\n\n");
		System.out.println("Task 4:\n");
		System.out.println("Students in ascending order by last name then first:");
		studentList.stream()
			.sorted(Comparator.comparing(Student::getLastName).thenComparing(Student::getFirstName))
			.forEach(System.out::println);
		System.out.println();
		System.out.println("Students in descending order by last name then first:");
		studentList.stream()
			.sorted(Comparator.comparing(Student::getLastName).thenComparing(Student::getFirstName).reversed())
			.forEach(System.out::println);
		
		System.out.print("\n\n");
		System.out.println("Task 5:\n");
		System.out.println("Unique Student last names:");
		studentList.stream()
			.map(Student::getLastName)
			.distinct()
			.sorted()
			.forEach(System.out::println);
	}
}
