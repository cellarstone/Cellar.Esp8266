#include "cellar_server.h"

string SettingsPage::setHeader()
{
  string result = "";
  result += "<head>";
  //result += "<meta http-equiv='refresh' content='10'/>";
  result += "<title>Cellarstone Senzor</title>";
  result += "<style> body { background-color: #fffff; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }</style>";
  result += "<style> .container { position: relative; margin-left: auto; margin-right: auto; margin-top:15px; margin-bottom:15px; } </style>";
  result += "<style> .text-center {text-align: center!important;} </style>";
  result += "<style> .btn { font-family: inherit; font-size: 100%; padding: .5em 1em; color: #444; color: rgba(0,0,0,.8); border: 1px solid #999; border: transparent; background-color: #E6E6E6; text-decoration: none; border-radius: 2px; } </style>";
  result += "<style> .btn:hover { background-image: linear-gradient(transparent,rgba(0,0,0,.05) 40%,rgba(0,0,0,.1)); } </style>";
  result += "<style> .btn-success { background-color: orange; } </style>";
  result += "<style> .form-control { display: block; width: 100%; padding: .375rem .75rem; font-size: 1rem; line-height: 1.5; color: #495057; background-color: #fff; background-image: none; background-clip: padding-box; border: 1px solid #ced4da; border-radius: .25rem; transition: border-color ease-in-out .15s,box-shadow ease-in-out .15s;}</style>";
  result += "<style> .form-group { margin-bottom: 1rem;} </style>";
  result += "<style> #logo { height: 100px; display: block; margin: auto; } </style>";
  result += "<style> #mycontainer { width: 50%; } </style>";
  result += "</head>";
  return result;
}

string SettingsPage::setBody()
{
  string result = "";
  result += "<body>";
  result += "<div class=\"container\">";
  result += "<img id=\"logo\" src=\"data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz4KPCEtLSBHZW5lcmF0b3I6IEFkb2JlIElsbHVzdHJhdG9yIDIxLjEuMCwgU1ZHIEV4cG9ydCBQbHVnLUluIC4gU1ZHIFZlcnNpb246IDYuMDAgQnVpbGQgMCkgIC0tPgo8c3ZnIHZlcnNpb249IjEuMSIgaWQ9IkxheWVyXzEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgeG1sbnM6eGxpbms9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkveGxpbmsiIHg9IjBweCIgeT0iMHB4IgoJIHZpZXdCb3g9IjAgMCAxMDAgMTAwIiBzdHlsZT0iZW5hYmxlLWJhY2tncm91bmQ6bmV3IDAgMCAxMDAgMTAwOyIgeG1sOnNwYWNlPSJwcmVzZXJ2ZSI+CjxzdHlsZSB0eXBlPSJ0ZXh0L2NzcyI+Cgkuc3Qwe2ZpbGw6I0JCQkRCRjt9Cgkuc3Qxe2ZpbGw6IzY4Njg2ODt9Cgkuc3Qye2ZpbGw6dXJsKCNTVkdJRF8xXyk7fQoJLnN0M3tmaWxsOnVybCgjU1ZHSURfMl8pO30KPC9zdHlsZT4KPGcgaWQ9IkxheWVyXzIiPgoJPHBhdGggY2xhc3M9InN0MCIgZD0iTTkzLjMsODQuOGMwLDYuNi0zLjksOC45LTguOSw4LjlIMTVjLTQuNywwLTguOS0zLjktOC45LTguOVYxNS41YzAtNSwzLjktOC45LDguOS04LjloNzAKCQljNi45LDAsOC4zLDIuMiw4LjMsOC45Vjg0Ljh6Ii8+Cgk8Zz4KCQk8cGF0aCBjbGFzcz0ic3QxIiBkPSJNODUuNiw2LjZjNC4yLDAsNy41LDMuMyw3LjUsNy41aDYuOVY4LjljMC01LTMuOS04LjktOC45LTguOWgtNS42VjYuNnoiLz4KCQk8cGF0aCBjbGFzcz0ic3QxIiBkPSJNOTMuMywyMS42djY0YzAsNC4yLTMuMyw3LjgtNy44LDcuOEgxNC40Yy00LjIsMC03LjgtMy4zLTcuOC03LjhWMTQuNGMwLTQuMiwzLjMtNy44LDcuOC03LjhoNjMuOVYwSDguOQoJCQlDNC4yLDAsMCwzLjksMCw4Ljl2ODIuM2MwLDUsMy45LDguOSw4LjksOC45aDgyLjJjNSwwLDguOS0zLjksOC45LTguOVYyMS42SDkzLjN6Ii8+Cgk8L2c+Cgk8Zz4KCQk8Zz4KCQkJCgkJCQk8bGluZWFyR3JhZGllbnQgaWQ9IlNWR0lEXzFfIiBncmFkaWVudFVuaXRzPSJ1c2VyU3BhY2VPblVzZSIgeDE9IjMzLjg4ODkiIHkxPSIxMC43MTU4IiB4Mj0iMzMuODg4OSIgeTI9IjkzLjI2NDMiIGdyYWRpZW50VHJhbnNmb3JtPSJtYXRyaXgoMSAwIDAgLTEgMCAxMDIpIj4KCQkJCTxzdG9wICBvZmZzZXQ9IjAiIHN0eWxlPSJzdG9wLWNvbG9yOiM0MjhDQ0IiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuMjk2OSIgc3R5bGU9InN0b3AtY29sb3I6IzQwOENDQSIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC40MDM5IiBzdHlsZT0ic3RvcC1jb2xvcjojMzk4QkM3Ii8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjQ4MDEiIHN0eWxlPSJzdG9wLWNvbG9yOiMyRThCQzIiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuNTQxOCIgc3R5bGU9InN0b3AtY29sb3I6IzFEOEFCQiIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC41OTM5IiBzdHlsZT0ic3RvcC1jb2xvcjojMDc4OEIxIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjYwNzQiIHN0eWxlPSJzdG9wLWNvbG9yOiMwMDg4QUUiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuNjIyNyIgc3R5bGU9InN0b3AtY29sb3I6IzBEOTNCQiIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC42NTU5IiBzdHlsZT0ic3RvcC1jb2xvcjojMjNBNkQwIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjY5NSIgc3R5bGU9InN0b3AtY29sb3I6IzM0QjVFMCIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC43NDM0IiBzdHlsZT0ic3RvcC1jb2xvcjojM0ZCRkVDIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjgxMTQiIHN0eWxlPSJzdG9wLWNvbG9yOiM0NkM1RjIiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjEiIHN0eWxlPSJzdG9wLWNvbG9yOiM0OEM3RjQiLz4KCQkJPC9saW5lYXJHcmFkaWVudD4KCQkJPHBhdGggY2xhc3M9InN0MiIgZD0iTTQ4LjksOTEuNEgxOC42Yy01LjYsMC04LjYtMi44LTguNi03LjVWMTYuM2MwLTUsMy4xLTcuNSw4LjYtNy41aDMwLjNjNS44LDAsOC45LDIuOCw4LjksNy41djE5LjRINDMuMwoJCQkJVjE5LjRIMjQuNHY2MS41aDE4LjlWNjMuNGgxNC40djIwLjVDNTcuOCw4OC42LDU0LjcsOTEuNCw0OC45LDkxLjR6Ii8+CgkJPC9nPgoJCTxnPgoJCQkKCQkJCTxsaW5lYXJHcmFkaWVudCBpZD0iU1ZHSURfMl8iIGdyYWRpZW50VW5pdHM9InVzZXJTcGFjZU9uVXNlIiB4MT0iNjYuODA1NSIgeTE9IjEwLjU4NzMiIHgyPSI2Ni44MDU1IiB5Mj0iOTMuMTM1NyIgZ3JhZGllbnRUcmFuc2Zvcm09Im1hdHJpeCgxIDAgMCAtMSAwIDEwMikiPgoJCQkJPHN0b3AgIG9mZnNldD0iMCIgc3R5bGU9InN0b3AtY29sb3I6IzQyOENDQiIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC4yOTY5IiBzdHlsZT0ic3RvcC1jb2xvcjojNDA4Q0NBIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjQwMzkiIHN0eWxlPSJzdG9wLWNvbG9yOiMzOThCQzciLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuNDgwMSIgc3R5bGU9InN0b3AtY29sb3I6IzJFOEJDMiIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC41NDE4IiBzdHlsZT0ic3RvcC1jb2xvcjojMUQ4QUJCIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjU5MzkiIHN0eWxlPSJzdG9wLWNvbG9yOiMwNzg4QjEiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuNjA3NCIgc3R5bGU9InN0b3AtY29sb3I6IzAwODhBRSIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMC42MjI3IiBzdHlsZT0ic3RvcC1jb2xvcjojMEQ5M0JCIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjY1NTkiIHN0eWxlPSJzdG9wLWNvbG9yOiMyM0E2RDAiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuNjk1IiBzdHlsZT0ic3RvcC1jb2xvcjojMzRCNUUwIi8+CgkJCQk8c3RvcCAgb2Zmc2V0PSIwLjc0MzQiIHN0eWxlPSJzdG9wLWNvbG9yOiMzRkJGRUMiLz4KCQkJCTxzdG9wICBvZmZzZXQ9IjAuODExNCIgc3R5bGU9InN0b3AtY29sb3I6IzQ2QzVGMiIvPgoJCQkJPHN0b3AgIG9mZnNldD0iMSIgc3R5bGU9InN0b3AtY29sb3I6IzQ4QzdGNCIvPgoJCQk8L2xpbmVhckdyYWRpZW50PgoJCQk8cGF0aCBjbGFzcz0ic3QzIiBkPSJNODEuNCw5MS40SDUyLjJjLTUuNiwwLTguOS0yLjgtOC45LTcuNVY2My40aDE0LjR2MTcuN2gxNy44VjY0LjhMNDYuNCw0MS4zYy0yLjUtMS45LTMuMS0zLjMtMy4xLTYuNlYxNi4zCgkJCQljMC01LDMuMS03LjUsOC45LTcuNWgyOS4yYzUuNiwwLDguOSwyLjgsOC45LDcuNXYxOC42SDc1LjhWMTkuMUg1OC4xdjE1bDI5LjIsMjMuM2MyLjUsMS45LDMuMSwzLjYsMy4xLDYuNnYxOS43CgkJCQlDOTAuMyw4OC42LDg2LjksOTEuNCw4MS40LDkxLjR6Ii8+CgkJPC9nPgoJPC9nPgo8L2c+Cjwvc3ZnPgo=\" alt=\"none\"/>";
  result += "</div>";

  result += "<h1 class=\"text-center\">{{firmware}} - Settings page</h1>";
  result += "<div id=\"mycontainer\"  class=\"container\">";

  result += "<form action='/submit' method='POST'>";

  result += "<div class=\"form-group\">";
  result += "<label for=\"senzorid\">SenzorID</label>";
  result += "<input type=\"text\" class=\"form-control\" id=\"senzorid\" name=\"senzorid\" placeholder=\"Enter Senzor ID\" value=\"{{senzorid}}\">";
  result += "</div>";

  result += "<div class=\"form-group\">";
  result += "<label for=\"wifissid\">Wifi SSID</label>";
  result += "<input type=\"text\" class=\"form-control\" id=\"wifissid\" name=\"wifissid\"  placeholder=\"Enter Wifi SSID\" value=\"{{wifissid}}\">";
  result += "</div>";

  result += "<div class=\"form-group\">";
  result += "<label for=\"wifipsswd\">Wifi Password</label>";
  result += "<input type=\"password\" class=\"form-control\" id=\"wifipsswd\" name=\"wifipsswd\"  placeholder=\"Enter Wifi password\" value=\"{{wifipsswd}}\">";
  result += "</div>";

  result += "<div class=\"form-group\">";
  result += "<label for=\"mqtturl\">MQTT Url</label>";
  result += "<input type=\"text\" class=\"form-control\" id=\"mqtturl\" name=\"mqtturl\"  placeholder=\"Enter MQTT Url\" value=\"{{mqtturl}}\">";
  result += "</div>";

  result += "<div class=\"form-group text-center\">";
  result += "<button type=\"submit\" class=\"btn btn-success\">Save</button>";
  result += "<a href=\"/\" class=\"btn\">Back</a>";
  result += "</div>";

  result += "</form>";

  result += "</div>";
  result += "</body>";

  return result;
}

string SettingsPage::getHTML()
{
  string page = "<html>";
  page += setHeader();
  page += setBody();
  page += "</html>";
  return page;
}
