graph = {

         '1':{'4':4,'2':3,'7':3},
         '2':{'6':7,'1':4, '7':1},
         '3':{'6':5,'4':8,'7':9},
         '4':{'1':4,'3':8},
         '5':{'6':1,'8':4,'7':10},
         '6':{'2':7,'3':5,'9':3,'5':1},
         '7':{'3':9,'2':1,'5':10},
         '8':{'9':2,'5':4},
         '9':{'8':2,'10':3,'6':3},
         '10':{'4':70,'9':3,}
        }




def  dijkstra(graph ,start, end ,k):

    unseennode= graph
    shortestdistance={}
    infini=99999
    predecessor = {}
    path = []

    for i in unseennode:
        shortestdistance[i]=infini
    shortestdistance[start]=0



    while unseennode:
        minnode= None

        for node in unseennode:
            if minnode is None:
                minnode=node
            elif shortestdistance[node] < shortestdistance[minnode]:
                minnode=node


        for  childnode,weight  in graph[minnode].items():
            x = weight + shortestdistance[minnode]

            #this comments code is used to suitable with hackerrank challenge 
            #https://www.hackerrank.com/contests/w38/challenges/a-time-saving-affair
            # if ((x // k) % 2) == 1:
            #      x  = (x // k + 1) * k;

            if x   < shortestdistance[childnode]:
                shortestdistance[childnode] = x
                predecessor[childnode]=minnode



        unseennode.pop(minnode)

    currentnode = end
    while currentnode != start :
        try :
            path.insert(0, currentnode)
            currentnode = predecessor[currentnode]
        except KeyError:
            print("not reachble ")
            break





    path.insert(0,start)
    if shortestdistance[end] != infini :
       print(shortestdistance[end])
       print(path)


dijkstra(graph ,'1', '10',4)




