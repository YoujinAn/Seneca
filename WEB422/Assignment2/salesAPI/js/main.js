/*********************************************************************************
* WEB422 – Assignment 2 
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. 
* No part of this assignment has been copied manually or electronically from any other source 
* (including web sites) or distributed to other students. 
* * Name: Youjin An     Student ID: 140413188       Date: 02 June, 2020 

* ********************************************************************************/

let saleDatap = [];
let page = 1;           // keep track of the current page that the user is viewing
const perPage = 10;     // how many sale items we wish to view on each page of our application.

const saleTableTemplate = _.template(
    `<% _.forEach (sales, function (sale)){ %>
        <tr data-id= <%- sale._id %>>
            <td><%- sale.customer.email %></td>
            <td><%- sale.storeLacation %></td>
            <% var itemNum = 0; 
               sale.items.forEach(function(item) { itemNum ++; })%>
            <td><%- itemNum %></td>
            <td><%- moment.utc(sale.saleDate).local().format('LLLL')%></td>
        </tr>

        <% itemNum = 0 %>
    <% }) %>`
);

const saleModelBodyTemplate = _.template(
    `<h4>Customer</h4>
    <strong>email:</strong> <%- sale.customer.email %><br>
    <strong>age:</strong> <%- sale.customer.age %><br>
    <strong>satisfaction:</strong>  <%- sale.customer.satisfaction %> / 5
    <br><br>

    <% var itemTotalprice = 0; 
           sale.items.forEach(function(item) { 
               itemTotalprice += (item.price * item.quantity); })%>
    <h4> Items: $ <%- itemTotalprice.toFixed(2) %></h4>

    <table class="table">
        <thead>
            <tr>
                <th>Product Name</th>
                <th>Quantity</th>
                <th>Price</th>
            </tr>
        </thead>
        <tbody>
            <% _.forEach(sale.items, function(item){ %>
                <tr>
                    <td><%- item.name %></td>
                    <td><%- item.quantity %></td>
                    <td>$<%- item.price %></td>
                </tr>
            <% }) %>
        </tbody>
    </table>

    <% total = 0 %>
    `
);

function loadSaleData() {
    fetch("https://nameless-everglades-52094.herokuapp.com/api/sales?page=${page}&perPage=${perPage}")
        .then(res => res.json())
        .then((data) => {
            saleData = data.message;
            let newHtml = saleTableTemplate({ sales: saleData });

            $("#sale-table tbody").html(newHtml);
        });

    $("#current-page").html(page);
}

$(function () {
    loadSaleData();

    $("#sale-table tbody").on("click", "tr", function () {

        let clickedId = $(this).attr("data-id");
        let clickedSale = _.find(saleData, { '_id': clickedId });
        let temp = saleModelBodyTemplate({ 'sale': clickedSale });

        $("#sale-modal .modal-title").html(`Sale: ${$(this).attr("data-id")}`);
        $("#sale-modal .modal-body").html(temp);

        $("#sale-table").modal({
            backdrop: 'static', // disable clicking on the backdrop to close
            keyboard: false // disable using the keyboard to close
        });
    });

    $("previous-page").on("click", function (e) {
        if (page > 1) {
            page--;
            loadSaleData();
        }
    });

    $("next-page").on("click", function (e) {
        page++;
        loadSaleData();
    });
});