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
  
  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturec").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturef").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturec1").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturef1").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturec2").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturef1").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturec3").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturef3").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturec4").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturef4").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturec5").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturef5").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturec6").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturef6").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturec7").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturef7").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturec8").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturef8").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturec9").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturef9").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturec10").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturef10").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturec11").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperaturef11").innerHTML = this.responseText;
      }
    };
  }, 10000) ;

  var T1 = document.getElementById("temperaturec");
  var div1 = document.getElementById("temperature1");
  if(T1 === 127.00){
    div1.style.display = "none"
  } else {
    div1.style.display = "block"
  }

  var T2 = document.getElementById("temperaturec1");
  var div2 = document.getElementById("temperature2");
  if(T2 === 127.00){
    div2.style.display = "none"
  } else {
    div2.style.display = "block"
  }

  var T3 = document.getElementById("temperaturec2");
  var div3 = document.getElementById("temperature3");
  if(T3 === 127.00){
    div3.style.display = "none"
  } else {
    div3.style.display = "block"
  }

  var T4 = document.getElementById("temperaturec3");
  var div4 = document.getElementById("temperature4");
  if(T4 === 127.00){
    div4.style.display = "none"
  } else {
    div4.style.display = "block"
  }

  var T5 = document.getElementById("temperaturec4");
  var div5 = document.getElementById("temperature5");
  if(T4 === 127.00){
    div5.style.display = "none"
  } else {
    div5.style.display = "block"
  }

  var T6 = document.getElementById("temperaturec5");
    var div6 = document.getElementById("temperature6");
  if(T4 === 127.00){
    div6.style.display = "none"
  } else {
    div6.style.display = "block"
  }
  
  var T7 = document.getElementById("temperaturec6");
  var div7 = document.getElementById("temperature7");
  if(T4 === 127.00){
    div7.style.display = "none"
  } else {
    div7.style.display = "block"
  }
  
  var T8 = document.getElementById("temperaturec7");
  var div8 = document.getElementById("temperature8");
  if(T4 === 127.00){
    div8.style.display = "none"
  } else {
    div8.style.display = "block"
  }
  
  var T9 = document.getElementById("temperaturec8");
  var div9 = document.getElementById("temperature9");
  if(T4 === 127.00){
    div9.style.display = "none"
  } else {
    div9.style.display = "block"
  }
  
  var T10 = document.getElementById("temperaturec9");
  var div10 = document.getElementById("temperature10");
  if(T4 === 127.00){
    div10.style.display = "none"
  } else {
    div10.style.display = "block"
  }
  
  var T11 = document.getElementById("temperaturec10");
  var div11 = document.getElementById("temperature11");
  if(T4 === 127.00){
    div11.style.display = "none"
  } else {
    div11.style.display = "block"
  }
  
  var T12 = document.getElementById("temperaturec11");
  var div12 = document.getElementById("temperature12");
  if(T4 === 127.00){
    div12.style.display = "none"
  } else {
    div12.style.display = "block"
  }