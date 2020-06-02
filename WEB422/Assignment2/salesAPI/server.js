/*********************************************************************************
* WEB422 – Assignment 2 
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. 
* No part of this assignment has been copied manually or electronically from any other source 
* (including web sites) or distributed to other students. 
* * Name: Youjin An     Student ID: 140413188       Date: 02 June, 2020 
* Heroku Link: https://nameless-everglades-52094.herokuapp.com/ 
* ********************************************************************************/

const express = require("express");
const cors = require("cors");
const bodyParser = require("body-parser");
const dataService = require("./modules/data-service.js");
const myData = dataService("mongodb+srv://yan24:yan24@cluster0-m22bp.mongodb.net/sample_supplies?retryWrites=true&w=majority");

const app = express();
app.use(cors());
app.use(bodyParser.json());

const HTTP_PORT = process.env.PORT || 8080;

// ************* API Routes

// POST /api/sales (NOTE: This route must read the contents of the request body)

app.post('/api/sales', (req, res) => {
    myData.addNewSale(req.body).then(msg => res.json(msg))
        .catch(err => res.json(msg));
});

// GET /api/sales (NOTE: This route must accept the numeric query parameters "page" and "perPage", ie: /api/sales?page=1&perPage=5 )

app.get('/api/sales', (req, res) => {
    myData.getAllSales(req.query.page, req.query.perpage).then(allSales => res.json(allSales))
        .catch(err => res.json(msg));
});

// GET /api/sales (NOTE: This route must accept a numeric route parameter, ie: /api/sales/5bd761dcae323e45a93ccfe8)

app.get('/api/sales', (req, res) => {
    myData.getSaleById(req.params._id).then(singleSales => res.json(singleSales))
        .catch(err => res.json(msg));
});

// PUT /api/sales (NOTE: This route must accept a numeric route parameter, ie: /api/sales/5bd761dcae323e45a93ccfe8 as well as read the contents of the request body)

app.put('/api/sales', (req, res) => {
    myData.updateSaleById(req.params._id, req.body).then(msg => res.json(msg))
        .catch(err => res.json(msg));
});

// DELETE /api/sales (NOTE: This route must accept a numeric route parameter, ie: /api/sales/5bd761dcae323e45a93ccfe8)

app.delete('/api/sales', (req, res) => {
    myData.deleteSaleById(req.params._id).then(msg => res.json(msg))
        .catch(err => res.json(msg));
});

// ************* Initialize the Service & Start the Server

myData.initialize().then(() => {
    app.listen(HTTP_PORT, () => {
        console.log(`server listening on: ${HTTP_PORT}`);
    });
}).catch((err) => {
    console.log(err);
});

