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

var people = [{"id":1,"first_name":"Iorgo","last_name":"Quinnell","gender":"Male","birthDate":"1992-12-21T15:11:03Z","email":"iquinnell0@zimbio.com","web":"http://plala.or.jp","creditScore":555,"rating":4.43},
{"id":2,"first_name":"Gaby","last_name":"Greene","gender":"Male","birthDate":"1992-12-01T19:48:14Z","email":"ggreene1@nasa.gov","web":"https://deviantart.com","creditScore":451,"rating":9.61},
{"id":3,"first_name":"Thebault","last_name":"Pozzo","gender":"Male","birthDate":"1993-08-22T19:50:43Z","email":"tpozzo2@slashdot.org","web":"http://nymag.com","creditScore":366,"rating":9.1},
{"id":4,"first_name":"Astrid","last_name":"Probart","gender":"Female","birthDate":"1993-04-12T16:57:47Z","email":"aprobart3@indiatimes.com","web":"https://joomla.org","creditScore":339,"rating":17.35},
{"id":5,"first_name":"Annalee","last_name":"MacFadzean","gender":"Female","birthDate":"1993-01-25T10:42:23Z","email":"amacfadzean4@cornell.edu","web":"http://guardian.co.uk","creditScore":453,"rating":19.95},
{"id":6,"first_name":"Florinda","last_name":"Stenton","gender":"Female","birthDate":"1992-12-03T14:17:16Z","email":"fstenton5@tripadvisor.com","web":"http://dagondesign.com","creditScore":523,"rating":12.91},
{"id":7,"first_name":"Becka","last_name":"McKomb","gender":"Female","birthDate":"1993-01-27T12:41:27Z","email":"bmckomb6@rediff.com","web":"https://macromedia.com","creditScore":311,"rating":7.47},
{"id":8,"first_name":"Kippar","last_name":"Kochlin","gender":"Male","birthDate":"1992-11-02T12:47:19Z","email":"kkochlin7@upenn.edu","web":"http://vimeo.com","creditScore":464,"rating":12.19},
{"id":9,"first_name":"Laurence","last_name":"Queenborough","gender":"Male","birthDate":"1992-10-09T19:29:25Z","email":"lqueenborough8@archive.org","web":"http://dailymail.co.uk","creditScore":529,"rating":3.36},
{"id":10,"first_name":"Olympie","last_name":"Jagiello","gender":"Female","birthDate":"1993-01-12T11:27:26Z","email":"ojagiello9@phoca.cz","web":"http://trellian.com","creditScore":360,"rating":19.14},
{"id":11,"first_name":"Tracey","last_name":"Pascall","gender":"Female","birthDate":"1993-08-22T08:06:01Z","email":"tpascalla@biblegateway.com","web":"http://tuttocitta.it","creditScore":560,"rating":17.0},
{"id":12,"first_name":"Temp","last_name":"Pothbury","gender":"Male","birthDate":"1993-05-04T09:23:27Z","email":"tpothburyb@wisc.edu","web":"http://sakura.ne.jp","creditScore":696,"rating":8.73},
{"id":13,"first_name":"Des","last_name":"Hughs","gender":"Male","birthDate":"1993-01-20T01:29:39Z","email":"dhughsc@wix.com","web":"https://marriott.com","creditScore":213,"rating":19.7},
{"id":14,"first_name":"Fletcher","last_name":"Whitman","gender":"Male","birthDate":"1993-05-03T07:43:16Z","email":"fwhitmand@msn.com","web":"http://cbsnews.com","creditScore":463,"rating":12.78},
{"id":15,"first_name":"Rufus","last_name":"Staveley","gender":"Male","birthDate":"1993-01-25T21:14:55Z","email":"rstaveleye@exblog.jp","web":"http://smh.com.au","creditScore":619,"rating":18.98},
{"id":16,"first_name":"Raven","last_name":"O' Reagan","gender":"Female","birthDate":"1993-07-20T19:56:17Z","email":"roreaganf@abc.net.au","web":"https://wired.com","creditScore":580,"rating":2.38},
{"id":17,"first_name":"Gweneth","last_name":"Hendrikse","gender":"Female","birthDate":"1993-01-25T04:23:35Z","email":"ghendrikseg@umn.edu","web":"https://squidoo.com","creditScore":552,"rating":13.3},
{"id":18,"first_name":"Jacobo","last_name":"Warstall","gender":"Male","birthDate":"1993-03-16T03:58:14Z","email":"jwarstallh@wix.com","web":"https://europa.eu","creditScore":266,"rating":15.3},
{"id":19,"first_name":"Mathew","last_name":"Wyon","gender":"Male","birthDate":"1992-11-16T07:01:10Z","email":"mwyoni@php.net","web":"https://livejournal.com","creditScore":354,"rating":16.47},
{"id":20,"first_name":"Patric","last_name":"Dagwell","gender":"Male","birthDate":"1993-08-14T06:03:18Z","email":"pdagwellj@economist.com","web":"https://hubpages.com","creditScore":720,"rating":12.65},
{"id":21,"first_name":"Kev","last_name":"Clee","gender":"Male","birthDate":"1993-04-26T01:23:29Z","email":"kcleek@narod.ru","web":"http://posterous.com","creditScore":673,"rating":4.15},
{"id":22,"first_name":"Zacharias","last_name":"Finci","gender":"Male","birthDate":"1992-11-05T07:31:05Z","email":"zfincil@fda.gov","web":"http://pinterest.com","creditScore":306,"rating":18.09},
{"id":23,"first_name":"Althea","last_name":"O'Kelly","gender":"Female","birthDate":"1993-02-12T16:43:30Z","email":"aokellym@hc360.com","web":"https://nydailynews.com","creditScore":600,"rating":13.89},
{"id":24,"first_name":"Juana","last_name":"Barnsdale","gender":"Female","birthDate":"1993-03-26T06:15:57Z","email":"jbarnsdalen@google.ca","web":"https://123-reg.co.uk","creditScore":714,"rating":17.11},
{"id":25,"first_name":"Elena","last_name":"Denziloe","gender":"Female","birthDate":"1992-09-22T12:24:53Z","email":"edenziloeo@chronoengine.com","web":"https://paginegialle.it","creditScore":708,"rating":7.15},
{"id":26,"first_name":"Wilt","last_name":"Leyban","gender":"Male","birthDate":"1992-08-27T05:49:13Z","email":"wleybanp@xinhuanet.com","web":"https://posterous.com","creditScore":436,"rating":13.56},
{"id":27,"first_name":"Lorenza","last_name":"Southers","gender":"Female","birthDate":"1992-10-15T16:22:56Z","email":"lsouthersq@slate.com","web":"http://accuweather.com","creditScore":628,"rating":2.11},
{"id":28,"first_name":"Mead","last_name":"Rosenbarg","gender":"Male","birthDate":"1992-09-13T04:52:10Z","email":"mrosenbargr@soundcloud.com","web":"http://adobe.com","creditScore":629,"rating":18.27},
{"id":29,"first_name":"Ole","last_name":"Yuryatin","gender":"Male","birthDate":"1992-09-29T12:46:04Z","email":"oyuryatins@imgur.com","web":"https://artisteer.com","creditScore":616,"rating":13.72},
{"id":30,"first_name":"Hermann","last_name":"Putley","gender":"Male","birthDate":"1992-09-14T03:03:37Z","email":"hputleyt@ifeng.com","web":"http://redcross.org","creditScore":350,"rating":13.06},
{"id":31,"first_name":"Isabelle","last_name":"Harbard","gender":"Female","birthDate":"1993-06-08T13:57:45Z","email":"iharbardu@shop-pro.jp","web":"https://ucla.edu","creditScore":538,"rating":4.66},
{"id":32,"first_name":"Freedman","last_name":"Mallock","gender":"Male","birthDate":"1993-01-11T11:19:07Z","email":"fmallockv@ustream.tv","web":"https://ted.com","creditScore":516,"rating":4.55},
{"id":33,"first_name":"Gillian","last_name":"Reimer","gender":"Female","birthDate":"1992-10-21T16:43:15Z","email":"greimerw@wufoo.com","web":"https://issuu.com","creditScore":549,"rating":18.92},
{"id":34,"first_name":"Fredrika","last_name":"Annandale","gender":"Female","birthDate":"1992-12-10T05:44:12Z","email":"fannandalex@newsvine.com","web":"https://mlb.com","creditScore":726,"rating":11.61},
{"id":35,"first_name":"Cordula","last_name":"Faussett","gender":"Female","birthDate":"1992-11-18T18:59:49Z","email":"cfaussetty@mac.com","web":"http://telegraph.co.uk","creditScore":431,"rating":13.16},
{"id":36,"first_name":"Homere","last_name":"Taunton","gender":"Male","birthDate":"1993-08-19T02:53:04Z","email":"htauntonz@sakura.ne.jp","web":"https://fotki.com","creditScore":799,"rating":4.17},
{"id":37,"first_name":"Fabiano","last_name":"Gullam","gender":"Male","birthDate":"1992-09-21T22:56:28Z","email":"fgullam10@latimes.com","web":"http://zdnet.com","creditScore":786,"rating":15.84},
{"id":38,"first_name":"Saw","last_name":"Grattage","gender":"Male","birthDate":"1993-06-05T18:00:15Z","email":"sgrattage11@pinterest.com","web":"http://networksolutions.com","creditScore":683,"rating":3.16},
{"id":39,"first_name":"Corly","last_name":"Whitcombe","gender":"Female","birthDate":"1993-06-28T14:13:50Z","email":"cwhitcombe12@rediff.com","web":"https://stumbleupon.com","creditScore":519,"rating":11.95},
{"id":40,"first_name":"Jock","last_name":"Burel","gender":"Male","birthDate":"1993-04-30T13:54:54Z","email":"jburel13@webeden.co.uk","web":"http://163.com","creditScore":494,"rating":4.69},
{"id":41,"first_name":"Berget","last_name":"Bome","gender":"Female","birthDate":"1992-11-19T15:58:37Z","email":"bbome14@archive.org","web":"https://mozilla.com","creditScore":472,"rating":16.58},
{"id":42,"first_name":"Dante","last_name":"Stickney","gender":"Male","birthDate":"1993-08-12T22:54:45Z","email":"dstickney15@vistaprint.com","web":"http://themeforest.net","creditScore":257,"rating":15.14},
{"id":43,"first_name":"Ugo","last_name":"Hainsworth","gender":"Male","birthDate":"1993-05-24T06:01:00Z","email":"uhainsworth16@mashable.com","web":"http://miibeian.gov.cn","creditScore":319,"rating":5.54},
{"id":44,"first_name":"Peder","last_name":"Pepper","gender":"Male","birthDate":"1993-07-28T01:52:04Z","email":"ppepper17@mysql.com","web":"http://businesswire.com","creditScore":239,"rating":5.02},
{"id":45,"first_name":"Dario","last_name":"Najera","gender":"Male","birthDate":"1993-05-24T01:37:23Z","email":"dnajera18@twitter.com","web":"https://163.com","creditScore":785,"rating":7.0},
{"id":46,"first_name":"Minor","last_name":"Strangman","gender":"Male","birthDate":"1993-08-17T09:39:38Z","email":"mstrangman19@samsung.com","web":"https://flavors.me","creditScore":630,"rating":17.72},
{"id":47,"first_name":"Sascha","last_name":"Valerius","gender":"Male","birthDate":"1992-12-17T22:13:38Z","email":"svalerius1a@oracle.com","web":"https://nasa.gov","creditScore":676,"rating":8.97},
{"id":48,"first_name":"Bride","last_name":"Beentjes","gender":"Female","birthDate":"1992-12-29T01:14:32Z","email":"bbeentjes1b@rakuten.co.jp","web":"http://google.com.br","creditScore":545,"rating":3.38},
{"id":49,"first_name":"Valentijn","last_name":"Gallandre","gender":"Male","birthDate":"1993-05-15T21:42:01Z","email":"vgallandre1c@purevolume.com","web":"https://delicious.com","creditScore":775,"rating":7.7},
{"id":50,"first_name":"Hallie","last_name":"Soule","gender":"Female","birthDate":"1993-05-29T09:07:56Z","email":"hsoule1d@sun.com","web":"https://wordpress.org","creditScore":223,"rating":19.32},
{"id":51,"first_name":"Thurstan","last_name":"Masseo","gender":"Male","birthDate":"1993-05-17T17:51:48Z","email":"tmasseo1e@dot.gov","web":"https://godaddy.com","creditScore":778,"rating":10.33},
{"id":52,"first_name":"Siffre","last_name":"Rupert","gender":"Male","birthDate":"1993-01-04T11:37:00Z","email":"srupert1f@weebly.com","web":"https://intel.com","creditScore":733,"rating":15.94},
{"id":53,"first_name":"Brucie","last_name":"Kolushev","gender":"Male","birthDate":"1993-05-07T05:48:19Z","email":"bkolushev1g@wix.com","web":"http://time.com","creditScore":760,"rating":13.11},
{"id":54,"first_name":"Neal","last_name":"Keasey","gender":"Male","birthDate":"1993-03-22T10:17:39Z","email":"nkeasey1h@devhub.com","web":"http://paginegialle.it","creditScore":775,"rating":14.58},
{"id":55,"first_name":"Holly-anne","last_name":"Falla","gender":"Female","birthDate":"1992-12-19T09:35:26Z","email":"hfalla1i@liveinternet.ru","web":"https://github.com","creditScore":426,"rating":19.96},
{"id":56,"first_name":"Melantha","last_name":"Southernwood","gender":"Female","birthDate":"1992-09-05T00:14:13Z","email":"msouthernwood1j@noaa.gov","web":"https://home.pl","creditScore":637,"rating":19.3},
{"id":57,"first_name":"Pansie","last_name":"Drissell","gender":"Female","birthDate":"1993-08-23T21:49:19Z","email":"pdrissell1k@meetup.com","web":"https://studiopress.com","creditScore":372,"rating":5.14},
{"id":58,"first_name":"Helyn","last_name":"Smoth","gender":"Female","birthDate":"1993-07-04T19:07:48Z","email":"hsmoth1l@soup.io","web":"http://discovery.com","creditScore":282,"rating":16.55},
{"id":59,"first_name":"Jenelle","last_name":"Gosson","gender":"Female","birthDate":"1993-08-17T17:50:48Z","email":"jgosson1m@instagram.com","web":"http://quantcast.com","creditScore":322,"rating":1.15},
{"id":60,"first_name":"Felice","last_name":"Matches","gender":"Female","birthDate":"1993-07-01T09:35:43Z","email":"fmatches1n@oakley.com","web":"https://europa.eu","creditScore":216,"rating":12.56},
{"id":61,"first_name":"Aurelea","last_name":"Pagen","gender":"Female","birthDate":"1993-08-24T17:38:53Z","email":"apagen1o@ehow.com","web":"https://ucla.edu","creditScore":626,"rating":7.66},
{"id":62,"first_name":"Claribel","last_name":"Leethem","gender":"Female","birthDate":"1993-07-11T19:11:59Z","email":"cleethem1p@ucoz.com","web":"http://usatoday.com","creditScore":513,"rating":15.2},
{"id":63,"first_name":"Dorisa","last_name":"Blumson","gender":"Female","birthDate":"1992-12-07T14:01:06Z","email":"dblumson1q@thetimes.co.uk","web":"http://fc2.com","creditScore":660,"rating":6.39},
{"id":64,"first_name":"Rockwell","last_name":"Placstone","gender":"Male","birthDate":"1993-06-05T08:28:19Z","email":"rplacstone1r@mac.com","web":"http://infoseek.co.jp","creditScore":785,"rating":18.22},
{"id":65,"first_name":"Erich","last_name":"Jarrel","gender":"Male","birthDate":"1992-10-29T06:29:43Z","email":"ejarrel1s@foxnews.com","web":"http://elpais.com","creditScore":709,"rating":13.99},
{"id":66,"first_name":"Rudy","last_name":"Balling","gender":"Male","birthDate":"1992-09-07T15:21:52Z","email":"rballing1t@ucsd.edu","web":"http://amazon.de","creditScore":520,"rating":4.39},
{"id":67,"first_name":"Dennie","last_name":"Khalid","gender":"Female","birthDate":"1992-09-24T18:09:30Z","email":"dkhalid1u@ucsd.edu","web":"http://vinaora.com","creditScore":229,"rating":11.17},
{"id":68,"first_name":"Emilio","last_name":"Crayke","gender":"Male","birthDate":"1993-08-04T17:50:10Z","email":"ecrayke1v@twitpic.com","web":"http://nbcnews.com","creditScore":609,"rating":7.65},
{"id":69,"first_name":"Reggy","last_name":"Caghy","gender":"Male","birthDate":"1992-11-26T03:56:50Z","email":"rcaghy1w@state.tx.us","web":"https://abc.net.au","creditScore":342,"rating":18.43},
{"id":70,"first_name":"Fonzie","last_name":"Le Marchant","gender":"Male","birthDate":"1993-06-21T16:05:16Z","email":"flemarchant1x@redcross.org","web":"https://arstechnica.com","creditScore":333,"rating":19.85},
{"id":71,"first_name":"Terrence","last_name":"Adiscot","gender":"Male","birthDate":"1993-06-16T16:26:15Z","email":"tadiscot1y@drupal.org","web":"https://cam.ac.uk","creditScore":282,"rating":10.65},
{"id":72,"first_name":"Kristy","last_name":"Lukesch","gender":"Female","birthDate":"1993-01-17T03:17:08Z","email":"klukesch1z@example.com","web":"https://slideshare.net","creditScore":394,"rating":18.87},
{"id":73,"first_name":"Roby","last_name":"Vaggers","gender":"Female","birthDate":"1993-01-12T05:54:18Z","email":"rvaggers20@google.es","web":"http://imdb.com","creditScore":489,"rating":9.91},
{"id":74,"first_name":"Philly","last_name":"Domelow","gender":"Female","birthDate":"1993-02-10T05:45:11Z","email":"pdomelow21@networksolutions.com","web":"https://dedecms.com","creditScore":606,"rating":15.07},
{"id":75,"first_name":"Paulo","last_name":"Jeffrey","gender":"Male","birthDate":"1993-01-31T18:51:21Z","email":"pjeffrey22@bravesites.com","web":"https://washingtonpost.com","creditScore":742,"rating":3.72},
{"id":76,"first_name":"Zolly","last_name":"Pountain","gender":"Male","birthDate":"1993-03-08T09:49:27Z","email":"zpountain23@drupal.org","web":"https://fotki.com","creditScore":254,"rating":15.7},
{"id":77,"first_name":"Sharona","last_name":"Slessor","gender":"Female","birthDate":"1993-02-11T22:04:30Z","email":"sslessor24@eventbrite.com","web":"http://blogger.com","creditScore":618,"rating":2.41},
{"id":78,"first_name":"Liva","last_name":"Philott","gender":"Female","birthDate":"1993-03-22T06:32:58Z","email":"lphilott25@nbcnews.com","web":"http://ucoz.com","creditScore":362,"rating":5.55},
{"id":79,"first_name":"Suki","last_name":"Van Salzberger","gender":"Female","birthDate":"1993-07-08T07:59:35Z","email":"svansalzberger26@jiathis.com","web":"http://shop-pro.jp","creditScore":316,"rating":11.29},
{"id":80,"first_name":"Silvester","last_name":"Searchwell","gender":"Male","birthDate":"1993-08-16T12:38:11Z","email":"ssearchwell27@china.com.cn","web":"http://flickr.com","creditScore":268,"rating":11.73},
{"id":81,"first_name":"Mellisa","last_name":"Iskowitz","gender":"Female","birthDate":"1993-01-23T05:09:36Z","email":"miskowitz28@theguardian.com","web":"https://examiner.com","creditScore":456,"rating":16.47},
{"id":82,"first_name":"Alica","last_name":"Marrian","gender":"Female","birthDate":"1992-12-26T13:03:04Z","email":"amarrian29@imgur.com","web":"https://elpais.com","creditScore":755,"rating":1.36},
{"id":83,"first_name":"Raul","last_name":"Reavell","gender":"Male","birthDate":"1993-03-21T22:57:10Z","email":"rreavell2a@hibu.com","web":"http://instagram.com","creditScore":242,"rating":3.2},
{"id":84,"first_name":"Marcella","last_name":"Edworthie","gender":"Female","birthDate":"1993-01-02T14:22:30Z","email":"medworthie2b@wikispaces.com","web":"https://dmoz.org","creditScore":683,"rating":5.57},
{"id":85,"first_name":"Fulton","last_name":"Ebbins","gender":"Male","birthDate":"1992-09-21T07:28:25Z","email":"febbins2c@fastcompany.com","web":"https://4shared.com","creditScore":271,"rating":4.71},
{"id":86,"first_name":"Allis","last_name":"Buddle","gender":"Female","birthDate":"1993-08-09T23:25:01Z","email":"abuddle2d@ning.com","web":"http://zdnet.com","creditScore":749,"rating":11.77},
{"id":87,"first_name":"Marchall","last_name":"Berr","gender":"Male","birthDate":"1992-12-01T09:31:23Z","email":"mberr2e@go.com","web":"http://imgur.com","creditScore":786,"rating":1.33},
{"id":88,"first_name":"Malchy","last_name":"Colpus","gender":"Male","birthDate":"1993-03-11T08:24:22Z","email":"mcolpus2f@dropbox.com","web":"https://twitpic.com","creditScore":440,"rating":13.14},
{"id":89,"first_name":"Ajay","last_name":"Etter","gender":"Female","birthDate":"1992-09-14T20:39:01Z","email":"aetter2g@friendfeed.com","web":"https://webeden.co.uk","creditScore":398,"rating":7.84},
{"id":90,"first_name":"Kial","last_name":"Sales","gender":"Female","birthDate":"1993-01-02T16:28:47Z","email":"ksales2h@foxnews.com","web":"http://cnet.com","creditScore":464,"rating":19.68},
{"id":91,"first_name":"Flora","last_name":"Mattiassi","gender":"Female","birthDate":"1993-07-15T19:02:17Z","email":"fmattiassi2i@hatena.ne.jp","web":"http://pagesperso-orange.fr","creditScore":761,"rating":3.89},
{"id":92,"first_name":"Tomi","last_name":"Benedettini","gender":"Female","birthDate":"1993-03-28T22:37:12Z","email":"tbenedettini2j@si.edu","web":"http://hexun.com","creditScore":657,"rating":7.64},
{"id":93,"first_name":"Marvin","last_name":"Lebbern","gender":"Male","birthDate":"1992-10-12T23:21:37Z","email":"mlebbern2k@list-manage.com","web":"http://wiley.com","creditScore":305,"rating":2.24},
{"id":94,"first_name":"Ignatius","last_name":"Mortimer","gender":"Male","birthDate":"1993-07-06T11:33:34Z","email":"imortimer2l@ibm.com","web":"https://hc360.com","creditScore":258,"rating":16.09},
{"id":95,"first_name":"Lark","last_name":"Kops","gender":"Female","birthDate":"1993-02-21T17:59:08Z","email":"lkops2m@microsoft.com","web":"http://youku.com","creditScore":562,"rating":16.92},
{"id":96,"first_name":"Kate","last_name":"Reeveley","gender":"Female","birthDate":"1993-03-17T19:44:09Z","email":"kreeveley2n@discuz.net","web":"http://wiley.com","creditScore":706,"rating":2.54},
{"id":97,"first_name":"Ania","last_name":"Codling","gender":"Female","birthDate":"1992-11-08T06:21:59Z","email":"acodling2o@webnode.com","web":"http://ning.com","creditScore":756,"rating":13.53},
{"id":98,"first_name":"Kirsteni","last_name":"Deverose","gender":"Female","birthDate":"1993-08-06T02:33:29Z","email":"kdeverose2p@gmpg.org","web":"https://independent.co.uk","creditScore":315,"rating":4.0},
{"id":99,"first_name":"Dorian","last_name":"Fairbeard","gender":"Female","birthDate":"1992-09-16T04:02:48Z","email":"dfairbeard2q@bing.com","web":"https://ask.com","creditScore":722,"rating":17.59},
{"id":100,"first_name":"Iver","last_name":"Anders","gender":"Male","birthDate":"1993-06-29T05:02:08Z","email":"ianders2r@nsw.gov.au","web":"http://sina.com.cn","creditScore":719,"rating":3.92},
{"id":101,"first_name":"Renaud","last_name":"Dohrmann","gender":"Male","birthDate":"1993-03-06T21:29:53Z","email":"rdohrmann2s@mtv.com","web":"https://mozilla.org","creditScore":257,"rating":12.02},
{"id":102,"first_name":"Courtney","last_name":"Ulster","gender":"Male","birthDate":"1992-12-23T15:16:20Z","email":"culster2t@clickbank.net","web":"http://github.com","creditScore":795,"rating":7.64},
{"id":103,"first_name":"Edythe","last_name":"McTague","gender":"Female","birthDate":"1992-12-23T06:14:19Z","email":"emctague2u@diigo.com","web":"https://ebay.co.uk","creditScore":485,"rating":6.0},
{"id":104,"first_name":"Rosaleen","last_name":"Wyldes","gender":"Female","birthDate":"1993-08-23T07:45:43Z","email":"rwyldes2v@theglobeandmail.com","web":"http://sciencedirect.com","creditScore":209,"rating":6.93},
{"id":105,"first_name":"Hewe","last_name":"Kingswell","gender":"Male","birthDate":"1993-04-29T20:48:53Z","email":"hkingswell2w@discovery.com","web":"http://xing.com","creditScore":759,"rating":3.82},
{"id":106,"first_name":"Rica","last_name":"Vowdon","gender":"Female","birthDate":"1992-11-18T06:11:58Z","email":"rvowdon2x@phpbb.com","web":"http://fc2.com","creditScore":725,"rating":12.18},
{"id":107,"first_name":"Gabrielle","last_name":"Lunt","gender":"Female","birthDate":"1993-07-05T09:48:39Z","email":"glunt2y@flickr.com","web":"http://smugmug.com","creditScore":323,"rating":12.01},
{"id":108,"first_name":"Orran","last_name":"Coggell","gender":"Male","birthDate":"1992-10-21T14:41:38Z","email":"ocoggell2z@independent.co.uk","web":"https://omniture.com","creditScore":526,"rating":6.1},
{"id":109,"first_name":"Barbette","last_name":"Mecozzi","gender":"Female","birthDate":"1993-05-30T04:53:52Z","email":"bmecozzi30@ocn.ne.jp","web":"http://umich.edu","creditScore":768,"rating":18.23},
{"id":110,"first_name":"Jacenta","last_name":"Skyner","gender":"Female","birthDate":"1993-06-02T01:03:13Z","email":"jskyner31@vk.com","web":"http://hexun.com","creditScore":689,"rating":15.64},
{"id":111,"first_name":"Fionna","last_name":"Oger","gender":"Female","birthDate":"1993-04-04T05:41:06Z","email":"foger32@comsenz.com","web":"https://narod.ru","creditScore":605,"rating":7.19},
{"id":112,"first_name":"De","last_name":"Kynvin","gender":"Female","birthDate":"1992-11-25T10:05:08Z","email":"dkynvin33@photobucket.com","web":"http://wordpress.com","creditScore":627,"rating":17.57},
{"id":113,"first_name":"Valina","last_name":"Hanrott","gender":"Female","birthDate":"1993-01-27T11:13:38Z","email":"vhanrott34@instagram.com","web":"https://deviantart.com","creditScore":677,"rating":7.45},
{"id":114,"first_name":"Kimble","last_name":"Ravenhill","gender":"Male","birthDate":"1992-11-21T06:00:03Z","email":"kravenhill35@skype.com","web":"https://unblog.fr","creditScore":596,"rating":19.17},
{"id":115,"first_name":"Orv","last_name":"Spykins","gender":"Male","birthDate":"1993-02-28T15:20:26Z","email":"ospykins36@mysql.com","web":"https://i2i.jp","creditScore":279,"rating":16.33},
{"id":116,"first_name":"Vidovik","last_name":"Carlow","gender":"Male","birthDate":"1992-11-02T16:04:56Z","email":"vcarlow37@usnews.com","web":"http://msn.com","creditScore":423,"rating":9.2},
{"id":117,"first_name":"Duff","last_name":"Esterbrook","gender":"Male","birthDate":"1992-10-26T10:52:22Z","email":"desterbrook38@etsy.com","web":"https://merriam-webster.com","creditScore":786,"rating":3.03},
{"id":118,"first_name":"Klaus","last_name":"McReynold","gender":"Male","birthDate":"1993-07-06T10:33:54Z","email":"kmcreynold39@spotify.com","web":"http://printfriendly.com","creditScore":700,"rating":18.88},
{"id":119,"first_name":"Serge","last_name":"Breheny","gender":"Male","birthDate":"1993-07-08T16:02:45Z","email":"sbreheny3a@devhub.com","web":"https://smh.com.au","creditScore":583,"rating":17.28},
{"id":120,"first_name":"Arny","last_name":"Grealish","gender":"Male","birthDate":"1993-05-04T08:36:51Z","email":"agrealish3b@cloudflare.com","web":"http://slate.com","creditScore":637,"rating":18.48},
{"id":121,"first_name":"Kelly","last_name":"Janjic","gender":"Female","birthDate":"1993-01-14T15:56:17Z","email":"kjanjic3c@dion.ne.jp","web":"https://exblog.jp","creditScore":558,"rating":11.22},
{"id":122,"first_name":"Adolf","last_name":"Casaletto","gender":"Male","birthDate":"1993-03-19T11:08:22Z","email":"acasaletto3d@com.com","web":"http://xing.com","creditScore":662,"rating":1.38},
{"id":123,"first_name":"Analise","last_name":"Skelhorne","gender":"Female","birthDate":"1992-12-14T14:55:01Z","email":"askelhorne3e@tuttocitta.it","web":"https://desdev.cn","creditScore":460,"rating":3.51},
{"id":124,"first_name":"Nelle","last_name":"Drohun","gender":"Female","birthDate":"1992-10-20T01:25:17Z","email":"ndrohun3f@house.gov","web":"http://hostgator.com","creditScore":789,"rating":5.56},
{"id":125,"first_name":"Valeda","last_name":"Risborough","gender":"Female","birthDate":"1993-03-07T18:57:57Z","email":"vrisborough3g@godaddy.com","web":"https://mail.ru","creditScore":355,"rating":10.68},
{"id":126,"first_name":"Jerrie","last_name":"Creus","gender":"Female","birthDate":"1993-01-05T12:45:49Z","email":"jcreus3h@shareasale.com","web":"http://aol.com","creditScore":241,"rating":1.08},
{"id":127,"first_name":"Kayne","last_name":"Steels","gender":"Male","birthDate":"1992-09-09T15:02:40Z","email":"ksteels3i@un.org","web":"https://mozilla.com","creditScore":604,"rating":5.19},
{"id":128,"first_name":"Rriocard","last_name":"Redington","gender":"Male","birthDate":"1992-08-28T12:32:34Z","email":"rredington3j@hatena.ne.jp","web":"http://hc360.com","creditScore":704,"rating":18.5},
{"id":129,"first_name":"Myranda","last_name":"Treweela","gender":"Female","birthDate":"1992-10-28T11:17:11Z","email":"mtreweela3k@wordpress.org","web":"http://tripod.com","creditScore":675,"rating":5.12},
{"id":130,"first_name":"Gilbertine","last_name":"Kidson","gender":"Female","birthDate":"1993-04-04T22:08:07Z","email":"gkidson3l@ycombinator.com","web":"https://last.fm","creditScore":443,"rating":5.38},
{"id":131,"first_name":"Case","last_name":"Farquhar","gender":"Male","birthDate":"1992-10-14T05:51:24Z","email":"cfarquhar3m@census.gov","web":"https://google.com.au","creditScore":326,"rating":4.18},
{"id":132,"first_name":"Marthe","last_name":"Fer","gender":"Female","birthDate":"1993-08-08T17:13:47Z","email":"mfer3n@ucla.edu","web":"http://marriott.com","creditScore":791,"rating":18.09},
{"id":133,"first_name":"Dale","last_name":"Goude","gender":"Male","birthDate":"1992-10-02T16:35:31Z","email":"dgoude3o@reuters.com","web":"https://arizona.edu","creditScore":669,"rating":15.1},
{"id":134,"first_name":"Abigael","last_name":"Habert","gender":"Female","birthDate":"1993-02-27T03:17:32Z","email":"ahabert3p@nps.gov","web":"http://sogou.com","creditScore":346,"rating":19.91},
{"id":135,"first_name":"Conroy","last_name":"Gask","gender":"Male","birthDate":"1992-10-21T14:09:01Z","email":"cgask3q@marriott.com","web":"http://bravesites.com","creditScore":499,"rating":1.61},
{"id":136,"first_name":"Joachim","last_name":"Goldson","gender":"Male","birthDate":"1993-03-07T08:13:36Z","email":"jgoldson3r@wired.com","web":"https://ed.gov","creditScore":436,"rating":2.74},
{"id":137,"first_name":"Gertruda","last_name":"Muggach","gender":"Female","birthDate":"1993-04-28T22:45:08Z","email":"gmuggach3s@msu.edu","web":"https://google.ca","creditScore":438,"rating":13.3},
{"id":138,"first_name":"Ardis","last_name":"Dresse","gender":"Female","birthDate":"1993-08-11T18:28:36Z","email":"adresse3t@homestead.com","web":"http://businessweek.com","creditScore":238,"rating":5.82},
{"id":139,"first_name":"Randi","last_name":"Pincott","gender":"Female","birthDate":"1993-01-06T01:55:31Z","email":"rpincott3u@mozilla.org","web":"https://skyrock.com","creditScore":372,"rating":4.21},
{"id":140,"first_name":"Parnell","last_name":"Rapinett","gender":"Male","birthDate":"1992-10-25T14:58:51Z","email":"prapinett3v@imdb.com","web":"http://weibo.com","creditScore":405,"rating":6.21},
{"id":141,"first_name":"Nessi","last_name":"Rose","gender":"Female","birthDate":"1993-08-11T04:16:21Z","email":"nrose3w@skyrock.com","web":"http://stanford.edu","creditScore":652,"rating":4.73},
{"id":142,"first_name":"Phylys","last_name":"Dunkerley","gender":"Female","birthDate":"1993-07-30T07:50:17Z","email":"pdunkerley3x@typepad.com","web":"http://sciencedaily.com","creditScore":563,"rating":19.1},
{"id":143,"first_name":"Alasdair","last_name":"Cadagan","gender":"Male","birthDate":"1993-05-01T18:55:26Z","email":"acadagan3y@boston.com","web":"http://youtu.be","creditScore":554,"rating":7.67},
{"id":144,"first_name":"Vale","last_name":"Bernardet","gender":"Female","birthDate":"1993-07-28T11:32:34Z","email":"vbernardet3z@webmd.com","web":"http://boston.com","creditScore":421,"rating":9.33},
{"id":145,"first_name":"Farand","last_name":"Ortiger","gender":"Female","birthDate":"1992-09-20T17:38:02Z","email":"fortiger40@nifty.com","web":"http://google.co.uk","creditScore":738,"rating":11.25},
{"id":146,"first_name":"Clarinda","last_name":"Kenan","gender":"Female","birthDate":"1993-05-11T13:11:46Z","email":"ckenan41@lulu.com","web":"http://uiuc.edu","creditScore":784,"rating":3.6},
{"id":147,"first_name":"Jeannine","last_name":"Lempenny","gender":"Female","birthDate":"1993-07-23T03:27:57Z","email":"jlempenny42@craigslist.org","web":"https://reddit.com","creditScore":384,"rating":9.78},
{"id":148,"first_name":"Tammi","last_name":"Snawden","gender":"Female","birthDate":"1993-01-21T05:52:24Z","email":"tsnawden43@flickr.com","web":"https://behance.net","creditScore":601,"rating":14.45},
{"id":149,"first_name":"Bibby","last_name":"Beckham","gender":"Female","birthDate":"1993-03-13T08:55:13Z","email":"bbeckham44@weather.com","web":"https://360.cn","creditScore":715,"rating":9.85},
{"id":150,"first_name":"Sander","last_name":"Reisenstein","gender":"Male","birthDate":"1993-02-07T18:37:02Z","email":"sreisenstein45@wired.com","web":"https://usa.gov","creditScore":574,"rating":8.02}];

/*****************************
 *          Task 1 
 *****************************/

function capNotFirstLetter (string_sentence) {
  
  //Change the first letter of the string to lower case and other letters to upper case.
  var updated_string = string_sentence.charAt(0).toLowerCase() + string_sentence.substr(1).toUpperCase();
  
  return updated_string;
}

console.log("/*****************************\nTask 1\n*****************************/");
console.log(capNotFirstLetter("Youjin"));

/*****************************
 *          Task 2
 *****************************/

console.log("/*****************************\nTask 2\n*****************************/");
var change_data = people.map(p => p.first_name);

for (var i = 0; i < change_data.length; i++){
  change_data[i] = capNotFirstLetter(change_data[i]);
}

console.log(change_data);

/*****************************
 *          Task 3
 *****************************/

console.log("/*****************************\nTask 3\n*****************************/");

var creditS = people.filter(function (p) {
    return p.creditScore > 400;}).map(function (p) {
    return p.creditScore;
});

console.log(creditS);

/*****************************
 *          Task 4
 *****************************/

var Birth = people.map(p => p.birthDate);
console.log(Birth.sort());







