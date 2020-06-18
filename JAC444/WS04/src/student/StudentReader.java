/*
 * JAC444 Workshop 4
 * File: StudentReader.java
 * Name: Youjin An (140413188)
 * Date: 18 June, 2020
 */

package student;

import java.io.*;

// Read those student objects from the file, and then 
// show their info in the console
public class StudentReader {
	
	public static void readStudentInfo () {
		try {
            FileInputStream fis = new FileInputStream("student.out");
            ObjectInputStream ois = new ObjectInputStream(fis);

            boolean readStudent = true;
            while(readStudent) {
            	Student student = (Student) ois.readObject();
            	
            	if(student != null) {
                    System.out.println("Student ID: " + student.getStdID());
                    System.out.println("Student Name: " + student.getFullName());
                    System.out.println("Student Course(s): " + student.getCourses());
                    System.out.println();
                } else{
                	readStudent = false;
                }
            }

            fis.close();

        }catch(EOFException e){
        	System.out.println("End of file reached!");
        } catch(Throwable e){
            System.err.println(e);
        }
	}
	
	public static void main(String[] args) {
		System.out.println("-------- Show Student Data --------");
		StudentReader.readStudentInfo();
	}
}
