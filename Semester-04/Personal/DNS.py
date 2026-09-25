import webbrowser

def FindIP(Input):
 Link = {
  "yahoo.com"    : "74.6.231.20"     ,
  "youtube.com"  : "142.251.35.174"  ,
  "google.com"   : "142.251.40.174"  ,
  "facebook.com" : "57.144.180.1"    ,
  "instagram.com": "157.240.19.174"  ,
  "x.com"        : "162.159.140.229"
      }
 if Input == "|?":
  print("to get IP : example.com")
  print("to stop: exit")
  return ""
 
 elif Input == "exit":
  print("program exited successfully.")
  return "exit"
 

  
def OpenLink(IP):
 if IP == "" or IP == "exit": return

 Ans = input("Open IP?(YES OR NO)").strip().lower()

 if Ans == "yes":
  URL = "http://" + IP
  webbrowser.open(URL)
 elif Ans == "no": return
 else:
  print("Wrong input ")
  OpenLink(IP)

In = ""
while In != "exit":
 In =  input("(|? for help)(Insert the link): ").strip().lower()
 FindIP(In)
 
#remove function
#Add function
#Change function