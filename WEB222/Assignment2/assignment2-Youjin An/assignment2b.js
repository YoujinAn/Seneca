/*******************************************************************************
 *                     WEB222 – Assignment 2
 * I declare that this assignment is my own work in accordance with Seneca 
 * Academic Policy.  No part of this assignment has been copied manually or 
 * electronically from any other source (including web sites) or distributed to 
 * other students.
 * 
 * Name: Youjin An      Student ID: 140413188     Date: 30 Sep, 2019
 *
 ******************************************************************************/

// an array of course objects
var courses = [
    { code: 'APC100', name: 'Applied Professional Communications', hours: 3, url: 'http://www.senecacollege.ca/' },
    { code: 'IPC144', name: 'Introduction to Programming Using C', hours: 4, url: 'https://scs.senecac.on.ca/~ipc144/' },
    { code: 'ULI101', name: 'Introduction to Unix/Linux and the Internet', hours: 4, url: 'https://cs.senecac.on.ca/~fac/uli101/live/' },
    { code: 'IOS110', name: 'Introduction to Operating Systems Using Windows', hours: 4, url: 'https://cs.senecac.on.ca/~fac/ios110' },
    { code: 'EAC150', name: 'College English', hours: 3, url: null }
];

// prototype object for creating student objects
var student = { 
    name: "", 
    dob: new Date(),
    sid: "",
    program: "", 
    gpa: 4.0,
    toString: function () {
        return 'Student info for ' + this.name + ': born on ' + this.dob.toLocaleDateString() +
               ', student id ' + this.sid + ', progrem ' + this.program + ', current GPA ' + this.gpa; 
    }
};

/************************************************************
 * Start your Part B code here. Do not change the code above.
 ************************************************************/

/*****************************
 *          Task 1 
 *****************************/

var last = courses.pop();
console.log("Course " + last.code + " was deleted from the array (course)");
console.log("Adding new couse objects into the array (course)");

console.log("Course objects in the array (course): ");

var IBC233 = Object.create(courses);
IBC233.code = 'IBC233';
IBC233.name = 'iSERIES Business Computing';
IBC233.hours = 4;
IBC233.url = 'https://scs.senecac.on.ca/~ibc233/';


var OOP244 = Object.create(courses);
OOP244.code = 'OOP244';
OOP244.name = 'Introduction to Object Oriented Programming';
OOP244.hours = 4;
OOP244.url = 'https://scs.senecac.on.ca/~oop244/';


var WEB222 = Object.create(courses);
WEB222.code = 'WEB222';
WEB222.name = 'Internet I - Internet Fundamentals';
WEB222.hours = 4;
WEB222.url = 'https://scs.senecac.on.ca/~web222/';


var DBS201 = Object.create(courses);
DBS201.code ='DBS201';
DBS201.name = 'Introduction to Database Design and SQL';
DBS201.hours = 4;
DBS201.url = 'https://scs.senecac.on.ca/~dbs201/';

courses.push(IBC233, OOP244, WEB222, DBS201); // 8

for(var i =0;i<courses.length;i++){
   console.log('"'+courses[i].code+', '+courses[i].name+', '+courses[i].hours+' hours/week, website: '+courses[i].url+'"');
}

/*****************************
 *          Task 2
 *****************************/

console.log("Student objects in the array (students): ");

var student0 = Object.create(student); 
student0.name= "John Smith";
student0.dob= new Date(1999,8,10);
student0.sid= "010456101";
student0.program= "CPA"; 
student0.gpa= 4.0;

var student1 = Object.create(student); 
student1.name= "Jim Carrey";
student1dob= new Date(1992,1,17);
student1.sid="012345678";
student1.program= "CPD";
student1.gpa= 3.5;

var student2 = Object.create(student); 
student2.name= "Justin Bieber";
student2.dob= new Date(1994,2,1);
student2.sid= "0987654321";
student2.program= "CAN";
student2.gpa= 3.0;

var student3 = Object.create(student);
student3.name= "Justin Trudeau"; 
student3.dob= new Date(1992,1,12);
student3.sid= "123456789";
student3.program= "CAN"; 
student3.gpa= 4.0;

var students = [student0, student1, student2, student3];

var str = "";

for(x in students){
   str += x + ": " + students[x] + "\n";
}
console.log(str);


