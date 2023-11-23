const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta
      name="viewport"
      content="width=device-width, initial-scale=1, shrink-to-fit=no"
    />
    <meta name="mobile-web-app-capable" content="yes" />
    <meta
      name="apple-mobile-web-app-status-bar-style"
      content="black-translucent"
    />
    <meta name="theme-color" content="#0275d8" />
    <link rel="icon" type="image/x-icon" href="img/favicon.png" />
    <title>LAB 7</title>

    <script src="https://code.jquery.com/jquery-2.1.4.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/tether/1.4.0/js/tether.min.js"></script>
    <link
      rel="stylesheet"
      href="https://cdnjs.cloudflare.com/ajax/libs/tether/1.4.0/css/tether.min.css"
    />

    <link
      rel="stylesheet"
      href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/css/bootstrap.min.css"
      integrity="sha384-rwoIResjU2yc3z8GV/NPeZWAv56rSmLldC3R/AZzGRnGxQQKnKkoFVhFQhNUwEyJ"
      crossorigin="anonymous"
    />
    <script
      src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/js/bootstrap.min.js"
      integrity="sha384-vBWWzlZJ8ea9aCX4pEW3rVHjgjt7zpkNpZk+02D9phzyeVkE+jo0ieGizqPLForn"
      crossorigin="anonymous"
    ></script>
    <link rel="stylesheet" href="css/style.css" />
    <link
      href="https://fonts.googleapis.com/css?family=Montserrat|Raleway"
      rel="stylesheet"
    />
    <script
      src="https://kit.fontawesome.com/a552ae84ad.js"
      crossorigin="anonymous"
    ></script>
    <style>
      * {
        font-family: "Raleway", sans-serif;
      }
      pre {
        tab-size: 8;
      }
      body {
        background-color: #f9f9f9;
      }

      .container-fluid {
        padding: 20px;
      }

      .navbar-brand {
        font-family: "Montserrat", sans-serif;
      }
      .card {
        margin-bottom: 20px;
        text-align: center;
      }
      .card,
      .card-text {
        width: 100vw;
        color: #333;
      }

      @media (min-width: 768px) {
        .card,
        .card-text {
          width: 40vw;
        }
      }

      .card-text {
        width: 100%;
        word-wrap: break-word;
      }
      .navbar-inverse .navbar-toggler {
        border-color: rgba(255, 255, 255, 0.5);
      }
      .fa-bars {
        color: rgba(255, 255, 255, 0.5);
      }
      .card-title {
        font-size: 60px;
      }
      .card-title img {
        height: 60px;
      }
      .fa-positivo {
        color: limegreen;
      }
      .fa-negativo {
        color: red;
      }
      .fa-invalido {
        color: #ffda44;
      }
      .fa-bomba {
        color: dodgerblue;
      }
      .logo {
        width: 75px;
        height: 75px;
        display: block;
        margin: 5px auto;
        padding: 10px;
      }
      .slidecontainer {
        width: 100%;
      }

      .slider {
        width: 100%;
        height: 10px;
        border-radius: 5px;
        background: #d3d3d3;
        outline: none;
        opacity: 0.8;
        -webkit-transition: 0.2s;
        transition: opacity 0.2s;
      }

      .slider:hover {
        opacity: 1;
      }

      .slider::-webkit-slider-thumb {
        -webkit-appearance: none;
        appearance: none;
        width: 25px;
        height: 25px;
        border-radius: 50%;
        background: rgb(30, 85, 187);
        cursor: pointer;
      }

      .slider::-moz-range-thumb {
        width: 25px;
        height: 25px;
        border-radius: 50%;
        background: rgb(30, 85, 187);
        cursor: pointer;
      }

      .center {
        display: block;
        margin: 10px auto;
        max-width: 70%;
      }
      .onoffswitch {
        position: relative;
        width: 110px;
        user-select: none;
      }
      .onoffswitch-checkbox {
        position: absolute;
        opacity: 0;
        pointer-events: none;
      }
      .onoffswitch-label {
        display: block;
        overflow: hidden;
        cursor: pointer;
        border: 2px solid #798a99;
        border-radius: 20px;
      }
      .onoffswitch-inner {
        display: block;
        width: 200%;
        margin-left: -100%;
        transition: margin 0.3s ease-in 0s;
      }
      .onoffswitch-inner:before,
      .onoffswitch-inner:after {
        display: block;
        float: left;
        width: 50%;
        height: 23px;
        padding: 0;
        line-height: 23px;
        font-size: 14px;
        color: white;
        font-family: Trebuchet, Arial, sans-serif;
        font-weight: bold;
        box-sizing: border-box;
      }
      .onoffswitch-inner:before {
        content: "Ligado";
        padding-left: 10px;
        background-color: #0275d8;
        color: #ffffff;
      }
      .onoffswitch-inner:after {
        content: "Desligado";
        padding-right: 10px;
        background-color: #eeeeee;
        color: #999999;
        text-align: right;
      }
      .onoffswitch-switch {
        display: block;
        width: 17px;
        margin: 5px;
        background: #f7f7f7;
        position: absolute;
        top: 0;
        bottom: 0;
        right: 83px;
        border: 2px solid #798a99;
        border-radius: 20px;
        transition: all 0.3s ease-in 0s;
      }
      .onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-inner {
        margin-left: 0;
      }
      .onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-switch {
        right: 0px;
      }
    </style>
  </head>
  <body>
    <nav class="navbar navbar-toggleable-md navbar-inverse bg-primary">
      <button
        class="navbar-toggler navbar-toggler-right"
        type="button"
        data-toggle="collapse"
        data-target="#navbarSupportedContent"
        aria-controls="navbarSupportedContent"
        aria-expanded="false"
        aria-label="Toggle Navigation"
      >
        <i class="fa fa-bars" aria-hidden="true"></i>
      </button>
      <h1 class="navbar-brand mb-0 text-center">LAB 7</h1>
      <div class="collapse navbar-collapse" id="navbarSupportedContent">
        <ul class="navbar-nav mr-auto">
          <li class="nav-item active">
            <a class="nav-link" href="index.html">Home</a>
            <span class="sr-only">(current)</span>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="sobre.html">Sobre</a>
          </li>
        </ul>
      </div>
    </nav>
    <!-- DEFAULT ATÉ AQUI -->
    <div class="container-fluid">
      <div class="row">
        <div class="col-sm">
          <div class="card center">
            <div class="card-block center">
              <!--<span class="card-title"><i class="fa fa-lightbulb" aria-hidden="true" style="color:#dddddd;"></i></span>-->
              <span class="card-title"
                ><i
                  class="fa fa-lightbulb"
                  aria-hidden="true"
                  style="color: rgb(255, 238, 0)"
                ></i
              ></span>
              <br /><b>Luzes:</b>
              <div class="onoffswitch center">
                <input
                  type="checkbox"
                  name="onoffswitch"
                  class="onoffswitch-checkbox"
                  id="light"
                  tabindex="0"
                  checked
                />
                <label class="onoffswitch-label" for="light">
                  <span class="onoffswitch-inner"></span>
                  <span class="onoffswitch-switch"></span>
                </label>
              </div>
            </div>
          </div>
        </div>
        <div class="col-sm">
          <div class="card center">
            <div class="card-block center">
              <!--<span class="card-title"><i class="fa fa-plug" aria-hidden="true" style="color:#dddddd;"></i></span>-->
              <span class="card-title"
                ><i
                  class="fa fa-plug"
                  aria-hidden="true"
                  style="color: rgb(206, 3, 3)"
                ></i
              ></span>
              <br /><b>Tomadas</b>
              <br />
              <div class="onoffswitch center">
                <input
                  type="checkbox"
                  name="onoffswitch"
                  class="onoffswitch-checkbox"
                  id="outlet"
                  tabindex="0"
                  checked
                />
                <label class="onoffswitch-label" for="outlet">
                  <span class="onoffswitch-inner"></span>
                  <span class="onoffswitch-switch"></span>
                </label>
              </div>
            </div>
          </div>
        </div>
        <div class="col-sm">
          <div class="card center">
            <div class="card-block">
              <!--<span class="card-title"><i class="fas fa-door-closed" aria-hidden="true" style="color:#dddddd;"></i></span>-->
              <span class="card-title"
                ><i
                  class="fas fa-door-open"
                  aria-hidden="true"
                  style="color: #59c031"
                ></i
              ></span>
              <br /><b>Porta</b>
              <div class="onoffswitch center">
                <input
                  type="checkbox"
                  name="onoffswitch"
                  class="onoffswitch-checkbox"
                  id="door"
                  tabindex="0"
                  checked
                />
                <label class="onoffswitch-label" for="door">
                  <span class="onoffswitch-inner"></span>
                  <span class="onoffswitch-switch"></span>
                </label>
              </div>
            </div>
          </div>
        </div>
        <div class="col-sm">
          <div class="card center">
            <div class="card-block center">
              <!--<span class="card-title"><i class="fas fa-wind" aria-hidden="true" style="color:#dddddd;"></i></span>-->
              <span class="card-title"
                ><i
                  class="fas fa-wind"
                  aria-hidden="true"
                  style="color: rgb(99, 163, 247)"
                ></i
              ></span>
              <br /><b>Ar Condicionado</b>
              <br />
              <div class="d-flex justify-content-center my-4 slidecontainer">
                <form class="range-field">
                  <input
                    id="slider11"
                    class="border-0 slider"
                    type="range"
                    min="16"
                    max="28"
                  />
                </form>
                <span
                  class="font-weight-bold text-primary ml-2 mt-1 valueSpan"
                ></span>
                <span class="font-weight-bold text-primary ml-2 mt-1">ºC</span>
              </div>
              <div class="onoffswitch center">
                <input
                  type="checkbox"
                  name="onoffswitch"
                  class="onoffswitch-checkbox"
                  id="split"
                  tabindex="0"
                  checked
                />
                <label class="onoffswitch-label" for="split">
                  <span class="onoffswitch-inner"></span>
                  <span class="onoffswitch-switch"></span>
                </label>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <script>
      $(document).ready(function () {
        var sideslider = $("[data-toggle=collapse-side]");
        var sel = sideslider.attr("data-target");
        var sel2 = sideslider.attr("data-target-2");
        sideslider.click(function (event) {
          $(sel).toggleClass("in");
          $(sel2).toggleClass("out");
        });
      });

      $(document).ready(function () {
        const $valueSpan = $(".valueSpan");
        const $value = $("#slider11");
        $valueSpan.html($value.val());
        $value.on("input change", () => {
          $valueSpan.html($value.val());
        });
      });

      document.getElementById("light").onclick = function () {
        var status;
        if (this.checked) {
          status = "true";
        } else {
          status = "false";
        }
        const xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
            console.log("Successfully received");
          }
        };
        xhttp.open("GET", "/update?device=light&status=" + status, true);
        xhttp.send();
      };

      document.getElementById("outlet").onclick = function () {
        var status;
        if (this.checked) {
          status = "true";
        } else {
          status = "false";
        }
        const xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
            console.log("Successfully received");
          }
        };
        xhttp.open("GET", "/update?device=outlet&status=" + status, true);
        xhttp.send();
      };

      document.getElementById("door").onclick = function () {
        var status;
        if (this.checked) {
          status = "true";
        } else {
          status = "false";
        }
        const xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
            console.log("Successfully received");
          }
        };
        xhttp.open("GET", "/update?device=door&status=" + status, true);
        xhttp.send();
      };

      document.getElementById("split").onclick = function () {
        var status;
        if (this.checked) {
          status = "true";
        } else {
          status = "false";
        }
        const xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
            console.log("Successfully received");
          }
        };
        xhttp.open("GET", "/update?device=split&status=" + status, true);
        xhttp.send();
      };
    </script>
  </body>
</html>

)=====";