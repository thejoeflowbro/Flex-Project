function savenetwork() { 
  var wmode = 0;
  config.network.dhcp = 0;
  config.network.hide = 0;
  if (document.getElementById("inputtohide").style.display === "none") {
    var b = document.getElementById("ssid");
    config.network.ssid = b.options[b.selectedIndex].value;
  } else {
    config.network.ssid = document.getElementById("inputtohide").value;
  }
  if (document.getElementById("wmodeap").checked) {
    wmode = 1;
    config.network.bssid = "";
    if (!checkOctects("ipaddress")) {
      return;
    }
    if (!checkOctects("subnet")) {
      return;
    }
    config.network.apip = document.getElementById("ipaddress").value;
    config.network.apsubnet = document.getElementById("subnet").value;
    if (parseInt(document.querySelector("input[name=",hideapenable,"]:checked").value) === 1) { 
      config.network.hide = 1;
    } else {
      config.network.hide = 0;
    }
  } else {
    config.network.bssid = document.getElementById("wifibssid").value;
    if (parseInt(document.querySelector("input[name=",dhcpenabled,"]:checked").value) === 1) {
      config.network.dhcp = 1;
    } else {
      config.network.dhcp = 0;
      if (!checkOctects("ipaddress")) {
        return;
      }
      if (!checkOctects("subnet")) {
        return;
      }
      if (!checkOctects("dnsadd")) {
        return;
      }
      if (!checkOctects("gateway")) {
        return;
      }
      config.network.ip = document.getElementById("ipaddress").value;
      config.network.dns = document.getElementById("dnsadd").value;
      config.network.subnet = document.getElementById("subnet").value;
      config.network.gateway = document.getElementById("gateway").value;
    }
  }
  config.network.wmode = wmode;
  config.network.pswd = document.getElementById("wifipass").value;
  config.network.offtime = parseInt(document.getElementById("disable_wifi_after_seconds").value);
  uncommited();
} ;
 function commit() { 
   inProgress("commit"); 
 } 
 function handleAP() { 
   document.getElementById("ipaddress").value = config.network.apip; 
   document.getElementById("subnet").value = config.network.apsubnet; 
   document.getElementById("hideap").style.display = "block"; 
   document.getElementById("hideBSSID").style.display = "none"; 
   document.getElementById("scanb").style.display = "none"; 
   document.getElementById("ssid").style.display = "none"; 
   document.getElementById("dhcp").style.display = "none"; 
   $("#staticip1").slideDown(); 
   $("#staticip1").show(); 
   //document.getElementById("staticip1").style.display = "block"; 
   $("#staticip2").slideUp(); 
   //document.getElementById("staticip2").style.display = "none"; 
   document.getElementById("inputtohide").style.display = "block"; 
 } 
 function handleDHCP() { 
   if (document.querySelector("input[name=",dhcpenabled,"]:checked").value === "1") { 
     $("#staticip2").slideUp(); 
     $("#staticip1").slideUp(); 
   } else { 
     document.getElementById("ipaddress").value = config.network.ip; 
     document.getElementById("subnet").value = config.network.subnet; 
     $("#staticip1").slideDown(); 
     $("#staticip1").show(); 
     $("#staticip2").slideDown(); 
     $("#staticip2").show(); 
   } 
 } 
  function handleSTA() { 
    document.getElementById("hideap").style.display = "none"; 
    document.getElementById("hideBSSID").style.display = "block"; 
    document.getElementById("scanb").style.display = "block"; 
    document.getElementById("dhcp").style.display = "block"; 
    if (config.network.dhcp === 0) { 
      $("input[name=",dhcpenabled,"][value=",0,"]").prop("checked", true); 
      //$("input[name=dhcpenabled][value="0"]").attr("checked", "checked"); 
    } 
    handleDHCP();
  }

// Get current sensor readings when the page loads
window.addEventListener('load', getReadings);

// Function to get current readings on the webpage when it loads for the first time
function getReadings(){
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var myObj = JSON.parse(this.responseText);
      console.log(myObj);
      document.getElementById("temperaturec").innerHTML = myObj;
    }
  };
  xhr.open("GET", "/readings", true);
  xhr.send();
}

if (!!window.EventSource) {
  var source = new EventSource('/events');

  source.addEventListener('open', function(e) {
    console.log("Events Connected");
  }, false);

  source.addEventListener('error', function(e) {
    if (e.target.readyState != EventSource.OPEN) {
      console.log("Events Disconnected");
    }
  }, false);

  source.addEventListener('message', function(e) {
    console.log("message", e.data);
  }, false);

  source.addEventListener('new_readings', function(e) {
    console.log("new_readings", e.data);
    var myObj = JSON.parse(e.data);
    console.log(myObj);
    plotTemperature(myObj);
  }, false);
}