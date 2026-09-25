Graph = {}

Graph["Start"] = {}
Graph["A"]     = {}
Graph["B"]     = {}
Graph["Fin"]   = {}

Graph["Start"]["A"] = 6
Graph["Start"]["B"] = 2
Graph["A"]["Fin"]   = 1
Graph["B"]["A"]     = 3
Graph["B"]["Fin"]  = 5
Graph["Fin"]        = {}

#---------------------------

infinity = float("inf")

Costs = {}

Costs["A"] = 6
Costs["B"] = 2
Costs["C"] = infinity

#---------------------------
Parents =  {}

Parents["A"] =  "Start"
Parents["B"] =  "Start"
Parents["Fin"] =  None

#---------------------------

Processed = []

#---------------------------

def Find_Lowest_Node(Costs):
 Lowest_Cost = infinity
 Lowest_Cost_Node = None

 for Node in Costs:
  Cost = Costs[Node]

  if Cost < Lowest_Cost and Node not in Processed:
   
   Lowest_Cost = Cost
   Lowest_Cost_Node = Node
   return Lowest_Cost_Node
 
#---------------------------

Node = Find_Lowest_Node(Costs)

while Node is not None:
 
 Cost = Costs[Node]
 Neighbors = Graph[Node]

 for n in Neighbors.keys():
  New_Cost = Cost + Neighbors[n]

  if Costs[n] > New_Cost:
   Costs[n] = Node
   Parents[n] = Node
  
  Processed.append(Node)
  Node = Find_Lowest_Node(Costs)

print(New_Cost)