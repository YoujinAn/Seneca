/*********************************************************************************
* WEB222 – Assignment 1
* I declare that this assignment is my own work in accordance with Seneca Academic Policy.
* No part of this assignment has been copied manually or electronically from any other source
* (including web sites) or distributed to other students.
* Name: Youjin An   Student ID: 140413188       Date: 19 Sep, 2019
********************************************************************************/

/********************************************************************************
/* TASK 1: STUDENT INFO (USE YOUR INFORMATION)
********************************************************************************/

// ▶ a) Store the following information in variables:
var name = "Youjin An";
var course = 5;
var program = "Computer programming and analysis (CPA)";
var youjin_job = false;

// ▶ b) Output your student info to the browser console as:
console.log("My name is " + name + " and I'm in " + program + " program. I'm taking " + course + " in this semester.");

// ▶ c) Store the string “have” or “don’t have” into a variable based on 
//      the value of the variable storing whether or not you have a part‐time job (true/false).
if (youjin_job == true) {
  var job_yes = "have";
}
else if (youjin_job == false){
  var job_no = "don't have";
}

// ▶ d) Output your updated student info to the console as:
if (youjin_job == true) {
  console.log("My name is " + name + " and I'm in " + program + " program. I'm taking " + course + " in this semester and I " + job_yes + " a part-time job now.");
}
else if (youjin_job == false){
  console.log("My name is " + name + " and I'm in " + program + " program. I'm taking " + course + " in this semester and I " + job_no + " a part-time job now.");
}

/********************************************************************************
/* TASK 2: BIRTH AND GRAUATE YEAR
********************************************************************************/

// ▶ a) Store the current year in a variable. 
var current_year = 2019;

// ▶ b) Prompt to user “Please enter your age:” and store the input value in a variable. 
var youjin_age = prompt("Please enter your age: ");

// ▶ c) Output the birth year to the console as: "You were born in the year of ???."
var youjin_birth_year = current_year - youjin_age;
console.log("You were born in the year of " + youjin_birth_year);

// ▶ d) Prompt to user “Enter the number of years you expect to study in the college:” and store the input value in a variable. 
var in_college = prompt("Enter the number of years you expect to study in the college: ");

// ▶ e) Output the graduate year to
var graduate_year = current_year + Number(in_college);
console.log("You will graduate from Seneca college in the year of " + graduate_year);


/********************************************************************************
/* TASK 3: CELSIUS AND FAHRENHEIT TEMPERATURES
********************************************************************************/

// ▶ a) Store a Celsius temperature in a variable. 
var celsius_temp = 18;

// ▶ b) Convert it to Fahrenheit and output: "???°C is ???°F". 
var fahrenheit_temp = celsius_temp * 9/5 + 32;
console.log(celsius_temp + " °C is " + fahrenheit_temp + " °F");

// ▶ c) Store a Fahrenheit temperature into a variable. 
var fahrenheit_temp2 = 70;

// ▶ d) Convert it to Celsius and output: "???°F is ???°C."  
var celsius_temp2 = (fahrenheit_temp2 - 32) * 5/9;
console.log(fahrenheit_temp2 + " °F is " + celsius_temp2.toFixed(2) + " °C");


/********************************************************************************
/* TASK 4: EVEN AND ODD NUMBERS
********************************************************************************/

// ▶ a) Write a for loop that will iterate from 0 to 10. For each iteration, 
//      your code should check if the current number is even or odd, 
//      and output that information to the browser console (e.g. "5 is odd").
for (var num = 0; num <= 10; num++){
  if (num % 2 == 0){
    console.log(num + " is even");
  }
  else if (num % 2 == 1){
    console.log(num + " is odd");
  }
}

/********************************************************************************
/* TASK 5: LARGER OR LARGEST NUMBER
********************************************************************************/

// ▶ a) Write a function named largerNum using the declaration approach, 
//      the function: takes 2 arguments, both numbers, returns the larger (greater) 
//      one of the 2 numbers. 
function largerNum (num1, num2){
  if (num1 > num2){
    return num1;
  }
  else
    return num2;
}

// ▶ b) Call this function twice with different number parameters, 
//      and log the output to the web console with descriptive outputs each time 
//      (e.g. "The larger number of 5 and 12 is 12.").
function largerNum (num1, num2){
  if (num1 > num2){
    console.log("The larger number of " + num1 + " and " + num2 + " is " + num1);
  }
  else
    console.log("The larger number of " + num1 + " and " + num2 + " is " + num2);
}

console.log( largerNum (10, 5) );
console.log( largerNum (2, 5) );

/********************************************************************************
/* TASK 6: EVALUATOR
********************************************************************************/

// ▶ a) Write a function named evaluator using the declaration approach, the function: 
//      takes unknown number of arguments which are all number scores,
//      returns true if the average of these number scores is greater than or equal to 50. 
//      Otherwise return false.
function evaluator(){
  
  var sum = 0;
  for ( var i = 0; i < arguments.length; i++){
    sum += arguments[i];
  }
  var average = sum / arguments.length;
  
  if (50 <= average){
    return true;
  }
  else
    return false;
  
}

console.log( evaluator (10, 20, 30) ); // The result is false.

// ▶ b) Call this function 3 times with different number parameters, 
//      and log the output to the web console with descriptive outputs each time 
//      (e.g. “Average grater than or equal to 50: false”);
function evaluator(){
  
  var sum = 0;
  for ( var i = 0; i < arguments.length; i++){
    sum += arguments[i];
  }
  var average = sum / arguments.length;
  
  if (50 <= average){
    console.log("Average grater than or equal to 50: true");
  }
  else
    console.log("Average grater than or equal to 50: false");

}

console.log( evaluator (10, 20, 30) );
console.log( evaluator (30, 40, 50, 60) );
console.log( evaluator (50, 60, 70, 80) );

/********************************************************************************
/* TASK 7: GRADER
********************************************************************************/

// ▶ a) Write a function named Grader using the expression approach, the function: 
//      takes a single argument which is a number mark,
//      returns a grade for the mark ‐ "A", "B", "C", "D", or "F".
var Grader = function (mark) {
  
  if ( 80 <= mark && mark <= 100) {
    return 'A';
  }
  else if (70 <= mark && mark < 80) {
    return 'B';
  }
  else if ((60 <= mark && mark < 70)) {
    return 'C';
  }
  else
    return 'F';
  
};

console.log ( Grader(80) ); // The result is A

// ▶ b) Call this function 3 times with different number marks, 
//      and log the output to the web console with descriptive outputs each time 
//      (e.g., “mark 89, grade is A”)

var Grader = function (mark) {
  var grade = null;
  
  if ( 80 <= mark && mark <= 100) {
    grade = "A";
  }
  else if (70 <= mark && mark < 80) {
     grade = "B";
  }
  else if ((60 <= mark && mark < 70)) {
    grade = "C";
  }
  else
    grade = "F";
  
  console.log("mark " + mark + ", grade is " + grade);
  
};

console.log ( Grader (70) ); // The result is B
console.log ( Grader (90) ); // The result is A
console.log ( Grader (100) ); // The result is A

/********************************************************************************
/* TASK 8: SHOWMULTIPLES
********************************************************************************/

// ▶ a) Write a function called showMultiples using the declaration approach, 
//      the function: Takes 2 numeric arguments (num, numMultiples) – 
//      assume the user is entering valid (positive) whole numbers
var num = prompt("Enter number");
var numMultiples = prompt("Enter numMultiples");

function showMultiples (num, numMultiples) {
  
  for (var i = 1; i <= numMultiples; i++){
    var total = Number(num) * Number(i);
    console.log(num + " X " + i + " = " + total);
  }

}

// ▶ b) Call this function 3 times with different number parameters, 
//      and log the output to the web console with descriptive outputs
function showMultiples (num, numMultiples) {
  
  for (var i = 1; i <= numMultiples; i++){
    var total = Number(num) * Number(i);
    console.log("num: " + num + ", numMultiples: " + numMultiples);
    console.log(num + " X " + i + " = " + total);
  }

}


var num = prompt("Enter number", 3);
var numMultiples = prompt("Enter numMultiples", 4);
showMultiples(num, numMultiples);

var num1 = prompt("Enter number", 4);
var numMultiples1 = prompt("Enter numMultiples", 5);
showMultiples(num1, numMultiples1);

var num2 = prompt("Enter number", 6);
var numMultiples2 = prompt("Enter numMultiples", 2);
showMultiples(num2, numMultiples2);

