#include "cellar_server.h"

string HomePage::setHeader()
{
  string header = "<head>";
  //header += "<meta http-equiv='refresh' content='10'/>";
  header += "<title>Cellarstone Senzor</title>";
  header += "<style> body { background-color: #fffff; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; } </style>";
  header += "<style> table { text-align: center; width: 100%} </style>";
  header += "<style> .container { position: relative; margin-left: auto; margin-right: auto; margin-top:15px; margin-bottom:15px;} </style>";
  header += "<style> .text-center {text-align: center!important;} </style>";
  header += "<style> .btn { font-family: inherit; font-size: 100%; padding: .5em 1em; color: #444; color: rgba(0,0,0,.8); border: 1px solid #999; border: transparent; background-color: #E6E6E6; text-decoration: none; border-radius: 2px; } </style>";
  header += "<style> .btn:hover { background-image: linear-gradient(transparent,rgba(0,0,0,.05) 40%,rgba(0,0,0,.1)); } </style>";
  header += "<style> .btn-success { background-color: green; } </style>";
  header += "<style> .btn-danger { background-color: red; } </style>";
  header += "<style> .btn-warning { background-color: orange; } </style>";
  header += "<style> #logo { height: 100px; display: block; margin: auto; } </style>";
  header += "<style> #mycontainer { width: 50%; } </style>";
  header += "<style> .myvalue { color: blue; } </style>";
  header += "</head>";

  //Serial.println(header.c_str());

  return header;
}

string HomePage::setBody()
{
  string body = "<body>";

  body += "<div class=\"container\">";
  body += "<img id=\"logo\" src=\"data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz4KPCEtLSBHZW5lcmF0b3I6IEFkb2JlIElsbHVzdHJhdG9yIDIxLjEuMCwgU1ZHIEV4cG9ydCBQbHVnLUluIC4gU1ZHIFZlcnNpb246IDYuMDAgQnVpbGQgMCkgIC0tPgo8c3ZnIHZlcnNpb249IjEuMSIgaWQ9IkxheWVyXzEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgeG1sbnM6eGxpbms9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkveGxpbmsiIHg9IjBweCIgeT0iMHB4IgoJIHZpZXdCb3g9IjAgMCAxMDAgMTAwIiBzdHlsZT0iZW5hYmxlLWJhY2tncm91bmQ6bmV3IDAgMCAxMDAgMTAwOyIgeG1sOnNwYWNlPSJwcmVzZXJ2ZSI+CjxzdHlsZSB0eXBlPSJ0ZXh0L2NzcyI+Cgkuc3Qwe2ZpbGw6I0JCQkRCRjt9Cgkuc3Qxe2ZpbGw6IzY4Njg2ODt9Cgkuc3Qye2ZpbGw6dXJsKCNTVkdJRF8xXyk7fQoJLnN0M3tmaWxsOnVybCgjU1ZHSURfMl8pO30KPC9zdHlsZT4KPGcgaWQ9IkxheWVyXzIiPgoJPHBhdGggY2xhc3M9InN0MCIgZD0iTTkzLjMsODQuOGMwLDYuNi0zLjksOC45LTguOSw4LjlIMTVjLTQuNywwLTguOS0zLjktOC45LTguOVYxNS41YzAtNSwzLjktOC45LDguOS04LjloNzAKCQljNi45LDAsOC4zLDIuMiw4LjMsOC45Vjg0Ljh6Ii8+Cgk8Zz4KCQk8cGF0aCBjbGFzcz0ic3QxIiBkPSJNODUuNiw2LjZjNC4yLDAsNy41LDMuMyw3LjUsNy41aDYuOVY4LjljMC01LTMuOS04LjktOC45LTguOWgtNS42VjYuNnoiLz4KCQk8cGF0aCBjbGFzcz0ic3QxIiBkPSJNOTMuMywyMS42djY0YzAsNC4yLTMuMyw3LjgtNy44LDcuOEgxNC40Yy00LjIsMC03LjgtMy4zLTcuOC03LjhWMTQuNGMwLTQuMiwzLjMtNy44LDcuOC03LjhoNjMuOVYwSDguOQoJCQlDNC4yLDAsMCwzLjksMCw4Ljl2ODIuM2MwLDUsMy45LDguOSw4LjksOC45aDgyLjJjNSwwLDguOS0zLjksOC45LTguOVYyMS42SDkzLjN6Ii8+Cgk8L2c+Cgk8Zz4KCQk8Zz4KCQkJCgkJCQk8bGluZWFyR3JhZGllbnQgaWQ9IlNWR0lEXzFfIiBncmFkaWVudFVuaXRzPSJ1c2VyU3BhY2VPblVzZSIgeDE9IjMzLjg4ODkiIHkxPSIxMC43MTU4IiB4Mj0iMzMuODg4OSIgeTI9IjkzLjI2NDMiIGdyYWRpZW50VHJhbnNmb3JtPSJtYXRyaXgoMSAwIDAgLTEgMCAxMDIpIj4KCQkJCTxzdG9wICBvZmZzZXQ9IjAiIHN0eWxlPSJzdG9wLWNvbG9yOiM0MjhDQ0IiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuMjk2OSIgc3R5bGU9InN0b3AtY29sb3I6IzQwOENDQSIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC40MDM5IiBzdHlsZT0ic3RvcC1jb2xvcjojMzk4QkM3Ii8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjQ4MDEiIHN0eWxlPSJzdG9wLWNvbG9yOiMyRThCQzIiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuNTQxOCIgc3R5bGU9InN0b3AtY29sb3I6IzFEOEFCQiIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC41OTM5IiBzdHlsZT0ic3RvcC1jb2xvcjojMDc4OEIxIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjYwNzQiIHN0eWxlPSJzdG9wLWNvbG9yOiMwMDg4QUUiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuNjIyNyIgc3R5bGU9InN0b3AtY29sb3I6IzBEOTNCQiIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC42NTU5IiBzdHlsZT0ic3RvcC1jb2xvcjojMjNBNkQwIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjY5NSIgc3R5bGU9InN0b3AtY29sb3I6IzM0QjVFMCIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC43NDM0IiBzdHlsZT0ic3RvcC1jb2xvcjojM0ZCRkVDIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjgxMTQiIHN0eWxlPSJzdG9wLWNvbG9yOiM0NkM1RjIiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjEiIHN0eWxlPSJzdG9wLWNvbG9yOiM0OEM3RjQiLz4KCQkJPC9saW5lYXJHcmFkaWVudD4KCQkJPHBhdGggY2xhc3M9InN0MiIgZD0iTTQ4LjksOTEuNEgxOC42Yy01LjYsMC04LjYtMi44LTguNi03LjVWMTYuM2MwLTUsMy4xLTcuNSw4LjYtNy41aDMwLjNjNS44LDAsOC45LDIuOCw4LjksNy41djE5LjRINDMuMwoJCQkJVjE5LjRIMjQuNHY2MS41aDE4LjlWNjMuNGgxNC40djIwLjVDNTcuOCw4OC42LDU0LjcsOTEuNCw0OC45LDkxLjR6Ii8+CgkJPC9nPgoJCTxnPgoJCQkKCQkJCTxsaW5lYXJHcmFkaWVudCBpZD0iU1ZHSURfMl8iIGdyYWRpZW50VW5pdHM9InVzZXJTcGFjZU9uVXNlIiB4MT0iNjYuODA1NSIgeTE9IjEwLjU4NzMiIHgyPSI2Ni44MDU1IiB5Mj0iOTMuMTM1NyIgZ3JhZGllbnRUcmFuc2Zvcm09Im1hdHJpeCgxIDAgMCAtMSAwIDEwMikiPgoJCQkJPHN0b3AgIG9mZnNldD0iMCIgc3R5bGU9InN0b3AtY29sb3I6IzQyOENDQiIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC4yOTY5IiBzdHlsZT0ic3RvcC1jb2xvcjojNDA4Q0NBIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjQwMzkiIHN0eWxlPSJzdG9wLWNvbG9yOiMzOThCQzciLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuNDgwMSIgc3R5bGU9InN0b3AtY29sb3I6IzJFOEJDMiIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC41NDE4IiBzdHlsZT0ic3RvcC1jb2xvcjojMUQ4QUJCIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjU5MzkiIHN0eWxlPSJzdG9wLWNvbG9yOiMwNzg4QjEiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuNjA3NCIgc3R5bGU9InN0b3AtY29sb3I6IzAwODhBRSIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC42MjI3IiBzdHlsZT0ic3RvcC1jb2xvcjojMEQ5M0JCIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjY1NTkiIHN0eWxlPSJzdG9wLWNvbG9yOiMyM0E2RDAiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuNjk1IiBzdHlsZT0ic3RvcC1jb2xvcjojMzRCNUUwIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjc0MzQiIHN0eWxlPSJzdG9wLWNvbG9yOiMzRkJGRUMiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuODExNCIgc3R5bGU9InN0b3AtY29sb3I6IzQ2QzVGMiIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMSIgc3R5bGU9InN0b3AtY29sb3I6IzQ4QzdGNCIvPgoJCQk8L2xpbmVhckdyYWRpZW50PgoJCQk8cGF0aCBjbGFzcz0ic3QzIiBkPSJNODEuNCw5MS40SDUyLjJjLTUuNiwwLTguOS0yLjgtOC45LTcuNVY2My40aDE0LjR2MTcuN2gxNy44VjY0LjhMNDYuNCw0MS4zYy0yLjUtMS45LTMuMS0zLjMtMy4xLTYuNlYxNi4zCgkJCQljMC01LDMuMS03LjUsOC45LTcuNWgyOS4yYzUuNiwwLDguOSwyLjgsOC45LDcuNXYxOC42SDc1LjhWMTkuMUg1OC4xdjE1bDI5LjIsMjMuM2MyLjUsMS45LDMuMSwzLjYsMy4xLDYuNnYxOS43CgkJCQlDOTAuMyw4OC42LDg2LjksOTEuNCw4MS40LDkxLjR6Ii8+CgkJPC9nPgoJPC9nPgo8L2c+Cjwvc3ZnPgo=\" alt=\"none\"/>";
  body += "</div>";

  body += "<h1 class=\"text-center\">PIR Senzor</h1>";
  body += "<div id=\"mycontainer\" class=\"container\">";

  body += "<table class=\"table\">";
  body += "<thead>";
  body += "<tr>";
  body += "<th>Parameter</th>";
  body += "<th>Value</th>";
  body += "</tr>";
  body += " </thead>";
  body += "<tbody>";

  body += "<tr>";
  body += "<td>SenzorID</td>";
  body += "<td class=\"myvalue\">{{senzorid}}</td>";
  body += "</tr>";

  body += "<tr>";
  body += "<td>Wifi SSID</td>";
  body += "<td class=\"myvalue\">{{wifissid}}</td>";
  body += "</tr>";

  body += "<tr>";
  body += "<td>Wifi Psswd</td>";
  body += "<td class=\"myvalue\">{{wifipsswd}}</td>";
  body += "</tr>";

  body += "<tr>";
  body += "<td>MQTT Url</td>";
  body += "<td class=\"myvalue\">{{mqtturl}}</td>";
  body += "</tr>";

  body += "</tbody>";
  body += "</table>";

  body += "</div>";

  body += "<div class=\"container text-center\">";
  body += "<a href=\"/clear\" class=\"btn btn-danger\" role=\"button\">Clear EEPROM</a>";
  body += "<a href=\"/restart\" class=\"btn btn-warning\" role=\"button\">Restart</a>";
  body += "<a href=\"/settings\" class=\"btn btn-success\" role=\"button\">Change settings</a>";
  body += "</div>";

  body += "</body>";


  //Serial.println(body.c_str());


  return body;
}

string HomePage::getHTML()
{
  string homepage = "<html>";

  //Serial.println(page.c_str());

  homepage += setHeader();

  // Serial.println(page.c_str());

  homepage += setBody();

  //Serial.println(page.c_str());

  homepage += "</html>";

  //Serial.println(homepage.c_str());

  return homepage;
}
