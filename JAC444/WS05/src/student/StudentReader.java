/*
 * JAC444 Workshop 5
 * File: StudentReader.java
 * Name: Youjin An (140413188)
 * Date: 25 June, 2020
 */

package student;

import java.io.*;
import javax.swing.*;
import java.awt.*;

// Read those student objects from the file, and then 
// show their info in the console
public class StudentReader {
	
	public static void readStudentInfo(JPanel panel){
		panel.removeAll();
		
        JTextArea textArea = new JTextArea();
        JButton back = new JButton("Back");

        try {
            FileInputStream fis = new FileInputStream("student.out");
            ObjectInputStream ois = new ObjectInputStream(fis);

            boolean readStudent = true;
            while(readStudent) {
                Student student = (Student) ois.readObject();

                if(student != null) {
                    textArea.append(
                            "Student ID: " + student.getStdID() + '\n'
                            + "Full Name: " + student.getFullName() + '\n'
                            + "Course(s): " + student.getCourses() + "\n\n"
                    );

                    textArea.setMinimumSize(new Dimension(400, 400));
                    textArea.setFont(textArea.getFont().deriveFont(20.0f));

                } else{
                    readStudent = false;
                }
            }

            fis.close();

        }catch(EOFException e){
            textArea.append("End of file reached!\n");
        } catch(Throwable e){
            System.err.println(e);
        }

        panel.add(textArea, BorderLayout.CENTER);
        panel.add(back, BorderLayout.SOUTH);

        back.addActionListener(e ->{
            displayMenu(panel);
        });

        panel.validate();
        panel.repaint();
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
