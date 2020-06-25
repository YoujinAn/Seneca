/*
 * JAC444 Workshop 5
 * File: Student.java
 * Name: Youjin An (140413188)
 * Date: 25 June, 2020
 */

package student;

import java.util.ArrayList;
import java.util.List;

// Student class should be serializable.
public class Student implements java.io.Serializable {

	// Fields
	private int stdID;
	private String firstName;
	private String lastName;
	private List<String> courses;

	// Constructor
	public Student() {
		courses = new ArrayList<>();
	}

	public Student(int stdID, String firstName, String lastName, List<String> courses) {
		this.stdID = stdID;
		this.firstName = firstName;
		this.lastName = lastName;
		this.courses = courses;
	}

	// Student ID
	public int getStdID() {
		return stdID;
	}

	public void setStdID(int stdID) throws StudentException {
		if (stdID > 0) {
			this.stdID = stdID;
		} else {
			throw new StudentException("Invalid Student ID!");
		}
	}

	// Student Name
	public String getFullName() {
		return firstName + ' ' + lastName;
	}

	public String getFirstName() {
		return firstName;
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	// Course
	public List<String> getCourses() {
		return courses;
	}

	public void addCourse(String course) {
		this.courses.add(course);
	}

	public void setCourses(List<String> courses) throws StudentException {
		if (courses.size() != 0) {
			this.courses = courses;
		} else {
			throw new StudentException("Invalid Courses!");
		}
	}
}
