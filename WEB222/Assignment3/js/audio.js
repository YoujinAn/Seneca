// Data for the "HTML Audio" Page

var audio = {
    controls: true, 
    source: [
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.mp3", type: "audio/mpeg"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.ogg", type: "audio/ogg"}
    ]
};

// Loading the Page
window.onload = function() {

    var audio_arr = document.getElementById("audio_arr"); // Get ID

    /*-----------------------------------------------------
                            audio1
    -----------------------------------------------------*/

    var fg1 = document.createElement('figure'); // <figure> </figure>

    var audio1 = document.createElement("audio"); // <audio> </audio>
    audio1.setAttribute("controls", true);

    var source1 = document.createElement("source");
    source1.setAttribute('src', audio.source[0].src);
    source1.setAttribute('type', audio.source[0].type);

    audio1.appendChild(source1);
    fg1.appendChild(audio1);

    audio_arr.appendChild(fg1);

    /*-----------------------------------------------------
                            audio2
    -----------------------------------------------------*/

    var fg2 = document.createElement('figure'); // <figure> </figure>

    var audio2 = document.createElement("audio"); // <audio> </audio>
    audio2.setAttribute("controls", true);

    var source2 = document.createElement("source");
    source2.setAttribute("src", audio.source[1].src);
    source2.setAttribute("type", audio.source[1].type);

    audio2.appendChild(source2);
    fg2.appendChild(audio2);

    audio_arr.appendChild(fg2);

}