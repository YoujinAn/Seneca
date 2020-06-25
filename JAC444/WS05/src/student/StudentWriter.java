/*
 * JAC444 Workshop 5
 * File: StudentWriter.java
 * Name: Youjin An (140413188)
 * Date: 25 June, 2020
 */

package student;

import java.io.*;
import javax.swing.*;
import java.awt.*;
import static java.lang.Integer.parseInt;

import java.util.ArrayList;
import java.util.List;

// Enter some information for some student objects from the console and 
// save these student objects in a file.
public class StudentWriter {

	public static void addStudentInfo(JPanel panel) {
		panel.removeAll();
		
		List<Student> arrayOfStudents = new ArrayList<Student>();
		
		try {
			FileOutputStream fos = new FileOutputStream("student.out");
			ObjectOutputStream oos = new ObjectOutputStream(fos);

			List<JTextField> studentInput = new ArrayList<>();
			
			JLabel[] inputPrompt = {
                    new JLabel("Student ID : "),
                    new JLabel("First Name : "),
                    new JLabel("Last Name  : "),
                    new JLabel("Course Code: ")
            };
			
            for(int i = 0; i < 4; i++){
            	studentInput.add(new JTextField());
            }
          
            // JButton Components
            JButton addCourse = new JButton("Add Course");
            addCourse.setBounds(30, 170, 122, 30);
            JButton submit = new JButton("Submit");;
            JButton back = new JButton("Back");

            panel.removeAll();
            
            // Add JButton Components to Panel
            for (int i = 0; i < studentInput.size(); i++) {
            	studentInput.get(i).setColumns(20);
            	studentInput.get(i).setEditable(true);

                panel.add(inputPrompt[i]);
                panel.add(studentInput.get(i));
            }
            panel.add(addCourse);
            panel.add(submit);
            panel.add(back);

            // Action Listeners
            addCourse.addActionListener(event -> {
                        	
                JTextField field = new JTextField();
                field.setColumns(20);

                studentInput.add(field);
                panel.add(field);
                panel.add(addCourse);
                panel.add(submit);
                panel.add(back);

                panel.validate();
            });

            submit.addActionListener(event -> {
                try {
                	Student student = new Student();
                	
                    student.setStdID(parseInt(studentInput.get(0).getText()));
                    student.setFirstName(studentInput.get(1).getText());
                    student.setLastName(studentInput.get(2).getText());

                    for(int i = 3; i < studentInput.size(); i++) {
                        student.addCourse(studentInput.get(i).getText());
                    }

                    for (JTextField txtField : studentInput) {
                        txtField.setText("");
                    }
                    
                    arrayOfStudents.add(student);
                    
                    JOptionPane.showMessageDialog(submit, String.format("Student Record Added!", event.getActionCommand()));
                } catch (Throwable e) {
                    System.out.println(e);
                }
            });
           
            
            back.addActionListener(event -> {
                try {
                	for(int i = 0; i < arrayOfStudents.size(); i++) {
                		oos.writeObject(arrayOfStudents.get(i));
                    }              	
                    oos.flush();
                    fos.close();
                }catch (Throwable e){
                    System.out.println(e);
                }

                displayMenu(panel);
            });

            panel.validate();
            panel.repaint();
		} catch (Throwable e) {
			System.err.println(e);
		}
	}
	
	public static void displayMenu(JPanel panel){
		
        JButton[] menuButtons = {
                new JButton("Add Student"),
                new JButton("Display Student Records"),
                new JButton("Exit")
        };
        
        menuButtons[0].addActionListener(event -> {
        	StudentWriter.addStudentInfo(panel);
        });
        menuButtons[1].addActionListener(event -> {
        	StudentReader.readStudentInfo(panel);
        });
        menuButtons[2].addActionListener(event -> {
        	JOptionPane.showMessageDialog(menuButtons[2], String.format("Exiting Student Program", event.getActionCommand()));
        	System.exit(0);
        });
        
        panel.removeAll();

        for(JButton button : menuButtons){
            panel.add(button);
        }

        panel.validate();
        panel.repaint();
    }
	
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		JPanel panel = new JPanel(); 
		JLabel prog_title = new JLabel("Welcome to YoujinA(Rene)'s Student Program");
		JPanel Main_panel = new JPanel(); 
		
		panel.setLayout(new BorderLayout());
		panel.add(prog_title, BorderLayout.NORTH);
		panel.add(Main_panel, BorderLayout.CENTER);
		
		// JPanel
		frame.add(panel);
		
		frame.setResizable(false);
		frame.setVisible(true);	
		
        frame.setTitle("Student Manager");
        frame.setPreferredSize(new Dimension(600, 840/12*9));
        frame.setSize(600, 840/12*9);
        frame.setLocationRelativeTo(null);
        
        displayMenu(Main_panel);        
        
        // EXIT
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
