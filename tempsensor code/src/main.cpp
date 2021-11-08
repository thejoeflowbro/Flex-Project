#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <WiFiManager.h>   // https://github.com/tzapu/WiFiManager
#include <ESPmDNS.h>
#include <SPIFFS.h>


// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

//Code in this void is executed once at the start
void setup() {
  Serial.begin(115200);

  // start up the wifi manager
  if (! MDNS.begin("FlexGreen")) {
 Serial.println(F("Error setting up MDNS responder"));
  }

  // WiFiManager
  // Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;

  //SSID and password for the accesspoint
  //First one is the SSID the second one is the password
  wifiManager.autoConnect("FlexGreen-TEMP", "FlexGreen");

  // or use this for auto generated name ESP + ChipID
  //wifiManager.autoConnect();

  // if you get here you have connected to the WiFi
  Serial.println("Connected.");
  
  //start the HTTP server
  server.begin();
}

//Code in this void is executed repeatedly
void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                    // If a new client connects,
 Serial.println("New Client.");    // print a message out in the serial port
 String currentLine = "";          // make a String to hold incoming data from the client
 while (client.connected()) {      // loop while the client's connected
   if (client.available()) {       // if there's bytes to read from the client,
  char c = client.read();          // read a byte, then
  Serial.write(c);                 // print it out the serial monitor
  header += c;
  if (c == '\n') {                 // if the byte is a newline character
   
    // if the current line is blank, you got two newline characters in a row.
    // that's the end of the client HTTP request, so send a response:
    if (currentLine.length() == 0) {
  
   // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
   // and a content-type so the client knows what's coming, then a blank line:
   client.println("HTTP/1.1 200 OK");
   client.println("Content-type:text/html");
   client.println("Connection: close");
   client.println();

   //HTML, CSS and JavaScript code for the webpage
   client.println(" <!DOCTYPE HTML><html> ");
   client.println(" <head> ");
   client.println("    <meta charset=\"utf-8\"> ");
   client.println("    <title>Flex Green</title> ");
   client.println("  <title>ESP Web Server</title> ");
   client.println(" <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"> ");
   client.println(" <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\" title=\"main\"/> ");
   client.println(" <link href=\"https://gitcdn.github.io/bootstrap-toggle/2.2.2/css/bootstrap-toggle.min.css\" rel=\"stylesheet\"/> ");
   client.println(" <link href=\"https://cdnjs.cloudflare.com/ajax/libs/bootstrap-slider/9.7.0/css/bootstrap-slider.min.css\" rel=\"stylesheet\"/> ");
   client.println(" <link href=\"https://cdnjs.cloudflare.com/ajax/libs/selectize.js/0.12.6/css/selectize.bootstrap3.min.css\" rel=\"stylesheet\"/> ");
   client.println(" <link href=\"https://cdnjs.cloudflare.com/ajax/libs/bootstrap-select/1.12.4/css/bootstrap-select.min.css\" rel=\"stylesheet\"/> ");
   //------------------------------------------------------------------------------------------CSS code------------------------------------------------------------------------------------------//
   client.println("  <style> html {  font-family: Arial, Helvetica, sans-serif;  display: inline-block;  position: relative;    overflow-x: hidden; overflow-y: hidden;  min-height: 100% } h1 {  font-size: 1.8rem;  color: white;} p {  font-size: 1.1em;  font-weight: 300;  line-height: 1.7em;  color: #999; } body {  background: #e7e9ec;  margin-bottom: 60px; } a, a:focus, a:hover {  color: inherit;  text-decoration: none;  transition: all .3s; } .overlay {  position: fixed;  width: 100vw;  height: 100vh;  background: rgba(0, 0, 0, .7);  z-index: 998;  display: none; } ul.CTAs {  padding: 20px; } [aria-expanded=true] {  color: #fff;} a[data-toggle=collapse] {  position: relative; }a[aria-expanded=false]::before, a[aria-expanded=true]::before {  content: '\e259';  display: block;  position: absolute;  right: 20px;  font-family: 'Glyphicons Halflings';  font-size: .6em; } a[aria-expanded=true] ::before {  content: '\e260'; } ul.CTAs a {  text-align: center;  display: block;  border-radius: 5px;  margin-bottom: 5px; } a.download {  background: #fff;  color: #198119; } content {  width: 100%;  min-height: 100vh;  transition: all .3s;  position: absolute;  top: 0;  right: 0; } i {  margin-right: 1em; } .header-row {  border-bottom: 1px solid #ccc; } label {   display: block; } .radio-option {   padding: 0 5px;   cursor: pointer; } .form-entry {   margin: 0 0 20px 0; } .form-entry .form-control {   width: 20em; } .form-entry label {   display: inline-block; } label:not(.error) .error-info {   display: none; } .error-info {   color: #f00;   font-size: 0.7em; } .error-info:before {   content: '('; } .error-info:after {   content: ')'; } .inline {   display: inline-block; } body {  margin-bottom: 200px;  background-color: white;} .modal-body .section-title {  border-bottom: 1px solid #eee;  padding-bottom: 0.2em;}ul.action-buttons {  list-style: none;  padding: 0;} .action-buttons li {  display: inline-block;} keyframes spin {  from { transform: scale(1) rotate(0deg); }  to { transform: scale(1) rotate(360deg); }}@-webkit-keyframes spin2 {  from { -webkit-transform: rotate(0deg); }  to { -webkit-transform: rotate(360deg); }} .selectize-delete { float: right; } .c-selectize-item { margin: 0 1em; } .sidenav {  height: 100%;  width: 200px;  position: fixed;  z-index: 1;  top: 0;  left: 0;  overflow-x: hidden;  padding-top: 20px;}  div{  border-style: none;} .units { font-size: 1.2rem; } .ds-labels{  font-size: 1.5rem;  vertical-align:middle;  padding-bottom: 15px;  color: white;  text-align: center;} .topnav {  padding: 10px 0px 10px 50px;  width: 100%;  height: 100%;  overflow: hidden;  background-color: #198119;  color: white;  font-size: 1.7rem;  text-align: center;} .topnavcontent{  text-align: center;  color:white;} .card {   background-color: rgb(224, 8, 8);   align-content: center;} .cards {   max-width: 700px;   margin: 0 auto;   display: grid;   grid-gap: 2rem;   grid-template-columns: repeat(auto-fit, minmax(300px, 1fr)); } .reading {   font-size: 2.8re; } .card.temperature {   color: #0e7c7b;   margin: 10px 0px 0px 0px;  border-radius: 22%;} .pcon {  color: white;  font-size: 24px;  text-align: center;} .logofg{  width: 200px; height: 100px;}#dropdown{  background-color: #198119;}body {  --Tcolor: #ffffff;  --nav-count: 10;  font-family: Montserrat, sans-serif;  font-size: 16px; overflow: hidden;} .btn {  color: var(--Tcolor);  font-weight: bold;  display: flex;  user-select: none;  text-shadow: 0 -1px rgba(0, 0, 0, 0.5);  cursor: pointer;  transition: all 150ms ease-out; width: 10vw;} .btn-open {  background-color: #fd9d08;  border-radius: 8px;} .nav-opener {  display: none;} .nav-opener:checked + .nav { transform: scale(1);  width: 84vw;   bottom: 0px; right: 0px;  height: 88vh;   border-radius: 50px 0px 0px 0px; } .nav-header {  display: flex;  justify-content: space-between;} .nav-title {  color: #fd9d08;  font-weight: bold;  height: var(--Nheight);  margin-left: 20px;  display: flex;  align-items: center;} .btn-nav svg {  margin-right: 5px;  display: block;} .btn-nav svg path {  fill: #414141;} .nav-link-opener {  display: none;} .nav { margin: 12vh 0px 0px 16vw; bottom: 0px; right: 0px; padding: 0px 0px 0px 40px; background-color: #2e2629 ; color:white ; display: grid; grid-template-rows: var(--Nheight) 30% auto; grid-template-columns: 100%; position: absolute; top: 0; left: 0; transform: scale(0); transition: transform 300ms ease; border-radius: 50px 0px 0px 0px;  border: 1px solid rgb(197, 197, 197);} .background_white{ height: 88vh; width: 84vw; background-color: rgb(255, 255, 255); bottom: 0px; right: 0px; position: absolute; border-radius: 50px 0px 0px 0px;  border: 1px solid rgb(197, 197, 197); </style> ");
   //----------------------------------------------------------------------------------------end CSS code----------------------------------------------------------------------------------------//
   client.println(" </head> ");
   client.println(" <body style=\"background-color: #E0E0E0;\"> ");
   client.println("    <img src=\"1394.png\" class=\"logofg\"> ");
   client.println("      <div class=\"dropdown\"> ");
   client.println("        <label class=\"btn btn-open\" for=\"netwerk\">NETWERK SETTINGS</label> ");
   client.println("      </div> ");
   client.println("      <br> ");
   client.println("      <hr class=\"line\"> ");
   client.println("      <div class=\"dropdown\"> ");
   client.println("        <label class=\"btn btn-open\" for=\"server\">SERVER SETTINGS</label> ");
   client.println("       </div> ");
   client.println("       <br> ");
   client.println("       <hr class=\"line\"> ");
   client.println("      </div> ");
   client.println("  <div class=\"overlay\"></div> ");
   client.println("  <div class=\"background_white\"> ");
   client.println("   <div class=\"cards\"> ");
   client.println("    <div class=\"card temperature\">   ");
   client.println("     <p class=\"pcon\"> ");
   client.println("     <i class=\"fas fa-thermometer-half\" style=\"color:#059e8a;\"></i>  ");
   client.println("     <span id=\"temperaturec\">%TEMPERATUREC%</span> ");
   client.println("     <sup class=\"units\">&deg;C</sup> ");
   client.println("     </p> ");
   client.println("      </div> ");
   client.println("      <div class=\"card temperature\">   ");
   client.println("     <p class=\"pcon\"> ");
   client.println("     <i class=\"fas fa-thermometer-half\" style=\"color:#059e8a;\"></i>  ");
   client.println("     <span id=\"temperaturef\" ></span>%TEMPERATUREF%</span> ");
   client.println("     <sup class=\"units\">&deg;F</sup> ");
   client.println("     </p> ");
   client.println("    </div> ");
   client.println("   </div> ");
   client.println("    </div> ");
   client.println("  </div> ");
   client.println(" </div> ");
   client.println("  <input type=\"checkbox\" id=\"netwerk\" class=\"nav-opener\" /> ");
   client.println("  <div class=\"nav\"> ");
   client.println("   <div id=\"networkcontent\" > ");
   client.println("   <br> ");
   client.println("   <br> ");
   client.println("   <legend style=\"color: white;\">Wi-Fi Settings</legend> ");
   client.println("   <h6 class=\"text-muted\" style=\"color: white;\">Type your Wi-Fi Networks SSID or Scan for nearby Wireless Networks to join.</h6> ");
   client.println("   <br> ");
   client.println("   <div class=\"row form-group\"> ");
   client.println("    <label class=\"col-xs-3\">Wi-Fi Mode<i style=\"margin-left: 10px;\"  aria-hidden=\"true\" data-toggle=\"popover\" data-trigger=\"hover\" data-placement=\"right\" data-content=\"You can run your ESP in AP Mode or Client Mode. In client mode you will need to connect to an existing Wi-Fi network, in AP Mode ESP creates a Wi-Fi network itself.\"></i></label> ");
   client.println("    <div class=\"col-xs-9\"> ");
   client.println("     <form> ");
   client.println("      <label class=\"radio-inline\"> ");
   client.println("       <input type=\"radio\" value=\"1\" name=\"wmode\" id=\"wmodeap\" onclick=\"handleAP();\" checked>Access Point </label> ");
   client.println("      <label class=\"radio-inline\"> ");
   client.println("       <input type=\"radio\" value=\"0\" name=\"wmode\" id=\"wmodesta\" onclick=\"handleSTA();\">Client</label> ");
   client.println("     </form> ");
   client.println("    </div> ");
   client.println("   </div> ");
   client.println("   <div class=\"row form-group\"> ");
   client.println("    <label class=\"col-xs-3\">SSID<i style=\"margin-left: 10px;\"  aria-hidden=\"true\" data-toggle=\"popover\" data-trigger=\"hover\" data-placement=\"right\" data-content=\"Wi-Fi Network's Name\"></i></label> ");
   client.println("    <span class=\"col-xs-7 col-md-5\"> ");
   client.println("      <input class=\"form-control input-sm\" id=\"inputtohide\" type=\"text\" name=\"ap_ssid\"> ");
   client.println("      <select class=\"form-control input-sm\" style=\"display:none;\" id=\"ssid\" onchange=\"listBSSID();\"></select> ");
   client.println("       </span> ");
   client.println("    <span class=\"col-xs-2\"> ");
   client.println("      <button id=\"scanb\" type=\"button\" class=\"btn btn-primary btn-xs\" style=\"display:none;\" onclick=\"scanWifi()\">Scan</button> ");
   client.println("       </span> ");
   client.println("   </div> ");
   client.println("   <div class=\"row form-group\" style=\"display:none\" id=\"hideBSSID\"> ");
   client.println("    <label class=\"col-xs-3\">BSSID<i style=\"margin-left: 10px;\"  aria-hidden=\"true\" data-toggle=\"popover\" data-trigger=\"hover\" data-placement=\"right\" data-content=\"If you have two Wi-Fi networks with the same SSID you may want to choose the specific one by BSSID\"></i></label> ");
   client.println("    <span class=\"col-xs-9 col-md-5\"> ");
   client.println("       <input id=\"wifibssid\" class=\"form-control input-sm\" type=\"text\" name=\"ap_bssid\"> ");
   client.println("       </span> ");
   client.println("   </div> ");
   client.println("   <div class=\"row form-group\"> ");
   client.println("    <label class=\"col-xs-3\">Password<i style=\"margin-left: 10px;\"  aria-hidden=\"true\" data-toggle=\"popover\" data-trigger=\"hover\" data-placement=\"right\" data-content=\"Wi-Fi Password\"></i></label> ");
   client.println("    <span class=\"col-xs-9 col-md-5\"> ");
   client.println("       <input id=\"wifipass\" class=\"form-control input-sm\" name=\"ap_passwd\" type=\"password\"> ");
   client.println("       </span> ");
   client.println("   </div> ");
   client.println("   <br> ");
   client.println("   <div class=\"row form-group\" id=\"hideap\"> ");
   client.println("    <label class=\"col-xs-3\">Hide Network Name<i style=\"margin-left: 10px;\"  aria-hidden=\"true\" data-toggle=\"popover\" data-trigger=\"hover\" data-placement=\"right\" data-content=\"You can choose to hide Wireless Network name, so your ESP does not broadcast SSID, keep in mind that people can still find your network if they are insist.\"></i></label> ");
   client.println("    <div class=\"col-xs-9\"> ");
   client.println("     <form> ");
   client.println("      <label class=\"radio-inline\"> ");
   client.println("       <input type=\"radio\" value=\"1\" name=\"hideapenable\">Yes</label> ");
   client.println("      <label class=\"radio-inline\"> ");
   client.println("       <input type=\"radio\" value=\"0\" name=\"hideapenable\" checked>No</label> ");
   client.println("     </form> ");
   client.println("    </div> ");
   client.println("   </div> ");
   client.println("   <br> ");
   client.println("   <div class=\"row form-group\" id=\"dhcp\"> ");
   client.println("    <label class=\"col-xs-3\">Use DHCP<i style=\"margin-left: 10px;\"  aria-hidden=\"true\" data-toggle=\"popover\" data-trigger=\"hover\" data-placement=\"right\" data-content=\"Choose if you want to get an IP address from DHCP server or not.\"></i></label> ");
   client.println("    <div class=\"col-xs-9\"> ");
   client.println("     <form> ");
   client.println("      <label class=\"radio-inline\"> ");
   client.println("       <input type=\"radio\" value=\"1\" name=\",dhcpenabled,\" onclick=\"handleDHCP();\" checked>Yes</label> ");
   client.println("      <label class=\"radio-inline\"> ");
   client.println("       <input type=\"radio\" value=\"0\" name=\",dhcpenabled,\" onclick=\"handleDHCP();\">No</label> ");
   client.println("     </form> ");
   client.println("    </div> ");
   client.println("   </div> ");
   client.println("   <div id=\"staticip1\"> ");
   client.println("    <div class=\"row form-group\"> ");
   client.println("     <label class=\"col-xs-3\">IP Address<i style=\"margin-left: 10px;\" aria-hidden=\"true\" data-html=\"true\" data-toggle=\"popover\" data-trigger=\"hover\" data-placement=\"right\" data-content=\"Enter IP Address<BR>(for example 192.168.4.1)\"></i></label> ");
   client.println("     <span class=\"col-xs-9 col-md-5\"> ");
   client.println("       <input id=\"ipaddress\" class=\"form-control input-sm\"> ");
   client.println("       </span> ");
   client.println("    </div> ");
   client.println("    <div class=\"row form-group\"> ");
   client.println("     <label class=\"col-xs-3\">Subnet Mask<i style=\"margin-left: 10px;\"  aria-hidden=\"true\" data-html=\"true\" data-toggle=\"popover\" data-trigger=\"hover\" data-placement=\"right\" data-content=\"Enter Subnet Mask<BR>(for example 255.255.255.0)\"></i></label> ");
   client.println("     <span class=\"col-xs-9 col-md-5\"> ");
   client.println("       <input id=\"subnet\" class=\"form-control input-sm\"> ");
   client.println("       </span> ");
   client.println("    </div> ");
   client.println("   </div> ");
   client.println("   <div id=\"staticip2\" style=\"display:none\"> ");
   client.println("    <div class=\"row form-group\"> ");
   client.println("     <label class=\"col-xs-3\">DNS Server</label> ");
   client.println("     <span class=\"col-xs-9 col-md-5\"> ");
   client.println("       <input id=\"dnsadd\" class=\"form-control input-sm\"> ");
   client.println("       </span> ");
   client.println("    </div> ");
   client.println("    <div class=\"row form-group\"> ");
   client.println("     <label class=\"col-xs-3\">Gateway</label> ");
   client.println("     <span class=\"col-xs-9 col-md-5\"> ");
   client.println("       <input id=\"gateway\" class=\"form-control input-sm\"> ");
   client.println("       </span> ");
   client.println("    </div> ");
   client.println("   </div> ");
   client.println("   <br> ");
   client.println("   <div class=\"row form-group\"> ");
   client.println("    <label class=\"col-xs-3\">Auto Disable Wifi<i style=\"margin-left: 10px;\"  aria-hidden=\"true\" data-toggle=\"popover\" data-trigger=\"hover\" data-placement=\"right\" data-content=\"Disable WiFi after a time interval, to conserve power in battery powered units. WiFi is re-enabled when an admin card is scanned, or device is rebooted. Remember that you need to have enough time to upload your configuration, so don't set it too low.\"></i></label> ");
   client.println("    <span class=\"col-xs-9 col-md-5\"> ");
   client.println("      <select class=\"form-control input-sm\" id=\"disable_wifi_after_seconds\" name=\"auto_restart_interval_seconds\"> ");
   client.println("        <option value='0'>Always on</option> ");
   client.println("        <option value='180'>3 min</option> ");
   client.println("        <option value='240'>4 min</option> ");
   client.println("        <option value='300'>5 min</option> ");
   client.println("        <option value='600'>10 min</option> ");
   client.println("        <option value='900'>15 min</option> ");
   client.println("        <option value='1800'>30 min</option> ");
   client.println("      </select> ");
   client.println("       </span> ");
   client.println("    <br> ");
   client.println("    <br> ");
   client.println("    <div class=\"col-xs-9 col-md-8\"> ");
   client.println("     <button onclick=\"savenetwork()\" class=\"btn btn-primary btn-sm pull-right\">Save</button> ");
   client.println("    </div> ");
   client.println("   </div> ");
   client.println("   <br> ");
   client.println("   <br> ");
   client.println("  </div> ");
   client.println("   </div> ");
   client.println("   <input type=\"checkbox\" id=\"server\" class=\"nav-opener\" /> ");
   client.println("  <div class=\"nav\"> ");
   client.println("  <h1>welkom</h1> ");
   client.println("  <h1>welkom</h1> ");
   client.println("  <h1>welkom</h1> ");
   client.println("  <h1>welkom</h1> ");
   client.println("  <h1>welkom</h1> ");
   client.println("  <h1>welkom</h1> ");
   client.println("  <h1>welkom</h1> ");
   client.println("  <h1>welkom</h1> ");
   client.println("  <h1>welkom</h1> ");
   client.println("  <h1>welkom</h1> ");
   client.println("  <h1>welkom</h1> ");
   client.println("  <h1>welkom</h1> ");
   client.println("  <h1>welkom</h1> ");
   client.println(" </div> ");
   client.println("  </div> ");
   //---------------------------------------------JavaScript code---------------------------------------------//
   client.println(" <script> function savenetwork() { ");
   client.println("  var wmode = 0;");
   client.println("  config.network.dhcp = 0;");
   client.println("  config.network.hide = 0;");
   client.println("  if (document.getElementById(\"inputtohide\").style.display === \"none\") {");
   client.println("    var b = document.getElementById(\"ssid\");");
   client.println("    config.network.ssid = b.options[b.selectedIndex].value;");
   client.println("  } else {");
   client.println("    config.network.ssid = document.getElementById(\"inputtohide\").value;");
   client.println("  }");
   client.println("  if (document.getElementById(\"wmodeap\").checked) {");
   client.println("    wmode = 1;");
   client.println("    config.network.bssid = \"\";");
   client.println("    if (!checkOctects(\"ipaddress\")) {");
   client.println("      return;");
   client.println("    }");
   client.println("    if (!checkOctects(\"subnet\")) {");
   client.println("      return;");
   client.println("    }");
   client.println("    config.network.apip = document.getElementById(\"ipaddress\").value;");
   client.println("    config.network.apsubnet = document.getElementById(\"subnet\").value;");
   client.println("    if (parseInt(document.querySelector(\"input[name=\"hideapenable\"]:checked\").value) === 1) { ");
   client.println("      config.network.hide = 1;");
   client.println("    } else {");
   client.println("      config.network.hide = 0;");
   client.println("    }");
   client.println("  } else {");
   client.println("    config.network.bssid = document.getElementById(\"wifibssid\").value;");
   client.println("    if (parseInt(document.querySelector(\"input[name=\",dhcpenabled,\"]:checked\").value) === 1) {");
   client.println("      config.network.dhcp = 1;");
   client.println("    } else {");
   client.println("      config.network.dhcp = 0;");
   client.println("      if (!checkOctects(\"ipaddress\")) {");
   client.println("        return;");
   client.println("      }");
   client.println("      if (!checkOctects(\"subnet\")) {");
   client.println("        return;");
   client.println("      }");
   client.println("      if (!checkOctects(\"dnsadd\")) {");
   client.println("        return;");
   client.println("      }");
   client.println("      if (!checkOctects(\"gateway\")) {");
   client.println("        return;");
   client.println("      }");
   client.println("      config.network.ip = document.getElementById(\"ipaddress\").value;");
   client.println("      config.network.dns = document.getElementById(\"dnsadd\").value;");
   client.println("      config.network.subnet = document.getElementById(\"subnet\").value;");
   client.println("      config.network.gateway = document.getElementById(\"gateway\").value;");
   client.println("    }");
   client.println("  }");
   client.println("  config.network.wmode = wmode;");
   client.println("  config.network.pswd = document.getElementById(\"wifipass\").value;");
   client.println("  config.network.offtime = parseInt(document.getElementById(\"disable_wifi_after_seconds\").value);");
   client.println("  uncommited();");
   client.println("} ;");
   client.println(" function commit() { ");
   client.println("   inProgress(\"commit\"); ");
   client.println(" } ");
   client.println(" function handleAP() { ");
   client.println("   document.getElementById(\"ipaddress\").value = config.network.apip; ");
   client.println("   document.getElementById(\"subnet\").value = config.network.apsubnet; ");
   client.println("   document.getElementById(\"hideap\").style.display = \"block\"; ");
   client.println("   document.getElementById(\"hideBSSID\").style.display = \"none\"; ");
   client.println("   document.getElementById(\"scanb\").style.display = \"none\"; ");
   client.println("   document.getElementById(\"ssid\").style.display = \"none\"; ");
   client.println("   document.getElementById(\"dhcp\").style.display = \"none\"; ");
   client.println("   $(\"#staticip1\").slideDown(); ");
   client.println("   $(\"#staticip1\").show(); ");
   client.println("   //document.getElementById(\"staticip1\").style.display = \"block\"; ");
   client.println("   $(\"#staticip2\").slideUp(); ");
   client.println("   //document.getElementById(\"staticip2\").style.display = \"none\"; ");
   client.println("   document.getElementById(\"inputtohide\").style.display = \"block\"; ");
   client.println(" } ");
   client.println(" function handleDHCP() { ");
   client.println("   if (document.querySelector(\"input[name=\"dhcpenabled\"]:checked\").value === \"1\") { ");
   client.println("     $(\"#staticip2\").slideUp(); ");
   client.println("     $(\"#staticip1\").slideUp(); ");
   client.println("   } else { ");
   client.println("     document.getElementById(\"ipaddress\").value = config.network.ip; ");
   client.println("     document.getElementById(\"subnet\").value = config.network.subnet; ");
   client.println("     $(\"#staticip1\").slideDown(); ");
   client.println("     $(\"#staticip1\").show(); ");
   client.println("     $(\"#staticip2\").slideDown(); ");
   client.println("     $(\"#staticip2\").show(); ");
   client.println("   } ");
   client.println(" } ");
   client.println("  function handleSTA() { ");
   client.println("    document.getElementById(\"hideap\").style.display = \"none\"; ");
   client.println("    document.getElementById(\"hideBSSID\").style.display = \"block\"; ");
   client.println("    document.getElementById(\"scanb\").style.display = \"block\"; ");
   client.println("    document.getElementById(\"dhcp\").style.display = \"block\"; ");
   client.println("    if (config.network.dhcp === 0) { ");
   client.println("      $(\"input[name=\"dhcpenabled\"][value=\"0\"]\").prop(\"checked\", true); ");
   client.println("      //$(\"input[name=dhcpenabled][value=\"0\"]\").attr(\"checked\", \"checked\"); ");
   client.println("    } ");
   client.println("    handleDHCP(); ");
   client.println("  }) ");
   client.println(" </script>");
   //---------------------------------------------End of JavaScript---------------------------------------------//
   client.println(" </body> ");
   client.println(" </html> ");
   //--------------------------------------------End HTML code code--------------------------------------------//

   // The HTTP response ends with another blank line
   client.println();
   // Break out of the while loop
   break;
    } else { // if you got a newline, then clear currentLine
   currentLine = "";
    }
  } else if (c != '\r') {  // if you got anything else but a carriage return character,
    currentLine += c;   // add it to the end of the currentLine
  }
   }
 }
 // Clear the header variable
 header = "";
 // Close the connection
 client.stop();
 Serial.println("Client disconnected.");
 Serial.println("");
  }
}
