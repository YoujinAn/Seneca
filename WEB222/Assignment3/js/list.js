// Data for the "HTML Lists" Page

var fruits = [ "Apples","Oranges","Pears","Grapes","Pineapples","Mangos" ];

var directory = [
    {type: "file", name: "file1.txt"},
    {type: "file", name: "file2.txt"},
    {type: "directory", name: "HTML Files", files: [{type: "file", name: "file1.html"},{type: "file", name: "file2.html"}]},
    {type: "file", name: "file3.txt"},
    {type: "directory", name: "JavaScript Files", files: [{type: "file", name: "file1.js"},{type: "file", name: "file2.js"},{type: "file", name: "file3.js"}]}
];


// Loading the Page
window.onload = function() {

    /*****************************************
     *                List 1
     *****************************************/
    
    // The getElementById() method returns the element that has the ID attribute with the specified value.
    var list1 = document.getElementById('list1');
    var ol = document.createElement('ol');
    // document.createElement() is used with an HTML tag to create the element.

    for (var i = 0; i < fruits.length; i++) {
        var t = document.createTextNode(`${fruits[i]}`);
        var li = document.createElement('LI');
        li.appendChild(t)
        ol.appendChild(li);
    }

    list1.appendChild(ol);

    /*****************************************
     *                List 2
     *****************************************/

    var list2 = document.getElementById('list2');
    var ul = document.createElement('UL');

    // Separate files and directory
    for (var i = 0; i < directory.length; i++) {
        // just make them an li
        var t = document.createTextNode(`${directory[i].name}`);
        var li = document.createElement('LI');
        li.appendChild(t);
        ul.appendChild(li);
        // The appendChild() method appends a node as the last child of a node.

        // Create an inner UL
        if (directory[i].files) {
            var ul_ = document.createElement('UL');
            
            for (var x = 0; x < directory[i].files.length; x++) {
                var li_ = document.createElement('LI');
                var t = document.createTextNode(`${directory[i].files[x].name}`);
                li_.appendChild(t);
                ul_.appendChild(li_);
            }
            
            li.appendChild(ul_);
        }
        list2.appendChild(ul);
    }
}

