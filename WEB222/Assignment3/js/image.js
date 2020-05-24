// Data for the "HTML Images" Page

var images = [
    {caption: "Red Slate Mountain", alt: "Mountain", url: "https://upload.wikimedia.org/wikipedia/commons/thumb/2/20/Red_Slate_Mountain_1.jpg/320px-Red_Slate_Mountain_1.jpg"},
    {caption: "St. Petersburg River", alt: "River", url: "https://upload.wikimedia.org/wikipedia/commons/thumb/8/83/Saint-petersburg-river-march-24-2016.jpg/320px-Saint-petersburg-river-march-24-2016.jpg"},
    {caption: "Lybian Desert", alt: "Desert", url: "https://upload.wikimedia.org/wikipedia/commons/thumb/9/99/Libyan_Desert_-_2006.jpg/320px-Libyan_Desert_-_2006.jpg"},
    {caption: "Azerbaijan Forest", alt: "Forest", url: "https://upload.wikimedia.org/wikipedia/commons/thumb/6/6d/Azerbaijan_forest_3.JPG/320px-Azerbaijan_forest_3.JPG"},
    {caption: "Indonesian Jungle", alt: "Jungle", url: "https://upload.wikimedia.org/wikipedia/commons/thumb/f/f5/Indonesian_jungle3%2C_Zoo_Prague.jpg/320px-Indonesian_jungle3%2C_Zoo_Prague.jpg"}
];

// Loading the Page
window.onload = function() {

    var images_arr = document.getElementById("images_arr");

    /*-----------------------------------------------------
                            img 1
    -----------------------------------------------------*/
    var fg1 = document.createElement('figure'); // <figure> </figure>
    var fgcap1 = document.createElement('figcaption'); // <figcaption> </figcaption>
    var img = document.createElement('img'); // <img> </img>

    // img1 setting
    img.setAttribute("src",images[0].url);
    img.setAttribute("alt",images[0].alt)
    img.setAttribute("title",images[0].caption);

    // Input Info
    fg1.appendChild(img);
    fgcap1.appendChild(document.createTextNode(images[0].caption));
    fg1.appendChild(fgcap1);

    // Output result
    images_arr.appendChild(fg1);

    /*-----------------------------------------------------
                            img 2
    -----------------------------------------------------*/
    var fg2=document.createElement('figure'); // <figure> </figure>
    var fgcap2=document.createElement('figcaption');
    var img2=document.createElement('img');

    // img2 setting
    img2.setAttribute("src", images[4].url);
    img2.setAttribute("alt", images[4].alt)
    img2.setAttribute("title", images[4].caption); 

    // Input Info
    fg2.appendChild(img2);
    fgcap2.appendChild(document.createTextNode(images[4].caption));
    fg2.appendChild(fgcap2);

    // Output result
    images_arr.appendChild(fg2);

}