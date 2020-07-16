/*
 * JAC444 Workshop 7
 * File: Student.java
 * Name: Youjin An (140413188)
 * Date: July 16, 2020
 */

package student;

public class Student {

	// Fields
	private String firstName;
	private String lastName;
	private double grade;
	private String department;

	// Constructor
	public Student(String firstName, String lastName, double grade, String department) {
		this.setFirstName(firstName);
		this.setLastName(lastName);
		this.setGrade(grade);
		this.setDepartment(department);
	}

	// Full Name
	public String getName() {
		return getFirstName() + " " + getLastName();
	}

	// fistName
	public void setFirstName(String _firstName) {
		this.firstName = _firstName;
	}

	public String getFirstName() {
		return firstName;
	}

	// lastName
	public void setLastName(String _lastName) {
		this.lastName = _lastName;
	}

	public String getLastName() {
		return lastName;
	}

	// grade
	public void setGrade(double _grade) {
		this.grade = _grade;
	}

	public double getGrade() {
		return grade;
	}

	// department
	public void setDepartment(String _department) {
		this.department = _department;
	}

	public String getDepartment() {
		return department;
	}
	
	// ToString
	@Override
	public String toString() {
		return String.format("%-9s%-9s%8.2f   %s", getFirstName(), getLastName(), getGrade(), getDepartment());
	}
	
	// Equal
	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null) {
			return false;
		}
		if (getClass() != obj.getClass()) {
			return false;
		}
		
		Student other = (Student) obj;
		
		if (department == null) {
			if (other.department != null) {
				return false;
			}
		} else if (!department.equals(other.department)) {
			return false;
		}
		
		if (firstName == null) {
			if (other.firstName != null) {
				return false;
			}
		} else if (!firstName.equals(other.firstName)) {
			return false;
		}
		
		if (Double.doubleToLongBits(grade) != Double.doubleToLongBits(other.grade)) {
			return false;
		}
		
		if (lastName == null) {
			if (other.lastName != null) {
				return false;
			}
		} else if (!lastName.equals(other.lastName)) {
			return false;
		}
		
		return true;
	}
	
	// Between 50 - 100
	public boolean isGradeBetween50And100() {
		if (getGrade() >= 50.0 && getGrade() <= 100.0) {
			return true;
		} else {
			return false;
		}
	}	
}
