from collections import deque



graph = {}
graph["you"] = ["Alice","Bob","Claire"]
graph["Alice"] = ["Peggy"]
graph["Bob"] = ["Anuj","Peggy"]
graph["Claire"] = ["Thom","Johny"]
graph["Peggy"] = []
graph["Anuj"] = []
graph["Thom"] = []
graph["Johny"] = []

Sellerlist = ["Johny" , "Anuj"]
def Seller(name):
    return name in Sellerlist
       
def Search(name):

 search_queue = deque()
 search_queue += graph[name]
 Searched = []
 
 if Seller(name):
        print(name + " is a mango seller!")
        return True
 else:
        while search_queue:
  
         Person = search_queue.popleft()
         if not Person in Searched:
    
          if Seller(Person):
           print (Person + " is a mango seller")
           return True
    
          else:
            search_queue += graph[Person]
            Searched.append(Person)
        print("No mango seller found.")
        return False



print(Search(input("Name:: ")))
