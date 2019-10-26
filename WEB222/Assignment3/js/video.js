// Data for the "HTML Video" Page

var video = {
    controls: true, 
    width: 320,
    height: 240,
    source: [
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.mp4", type: "video/mp4"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.ogg", type: "video/ogg"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.webm", type: "video/webm"}
    ]
};

// Loading the Page
window.onload = function() {

    var video_arr = document.getElementById("video_arr");

    /*-----------------------------------------------------
                            video1
    -----------------------------------------------------*/

    var fg1 = document.createElement('figure'); // <figure> </figure>

    var video1 = document.createElement("video"); // <video> </video>
    video1.setAttribute("width", video.width);
    video1.setAttribute("height", video.height);
    video1.setAttribute("controls", true);

    var source1 = document.createElement("source");
    source1.setAttribute("src", video.source[0].src);
    source1.setAttribute("type", video.source[0].type);

    video1.appendChild(source1);
    fg1.appendChild(video1);

    video_arr.appendChild(fg1);

    /*-----------------------------------------------------
                            video2
    -----------------------------------------------------*/

    var fg2 = document.createElement('figure'); // <figure> </figure>

    var video2 = document.createElement("video"); // <video> </video>
    video2.setAttribute("width", video.width);
    video2.setAttribute("height", video.height);
    video2.setAttribute("controls", true);

    var source2 = document.createElement("source");
    source2.setAttribute("src", video.source[1].src);
    source2.setAttribute("type", video.source[1].type);

    video2.appendChild(source2);
    fg2.appendChild(video2);

    video_arr.appendChild(fg2);

    /*-----------------------------------------------------
                            video3
    -----------------------------------------------------*/

    var fg3 = document.createElement('figure'); // <figure> </figure>

    var video3 = document.createElement("video"); // <video> </video>
    video3.setAttribute("width", video.width);
    video3.setAttribute("height", video.height);
    video3.setAttribute("controls", true);

    var source3 = document.createElement("source");
    source3.setAttribute("src", video.source[2].src);
    source3.setAttribute("type", video.source[2].type);

    video3.appendChild(source3);
    fg3.appendChild(video3);

    video_arr.appendChild(fg3);

}