#*************************************************************************
#* 
#*         Author: Justin Hudoka
#*          Major: Computer Science
#*  Creation Date: 11/29/21
#*       Due Date: 12/15/21
#*         Course: CSC447
#* Professor Name: Dr. Schwesinger
#*       Filename: final.py
#*        Purpose: Demonstrates a* search with dead points in 3 dimensions
#*       Language: Python
#*
#*       	
#*       python final.py <testfile>  	
#*       
#*
#**************************************************************************

import sys
import time
from queue import PriorityQueue

#**************************************************************
# *
# * Function name: read_state
# * Description: parses in data from a file
# * Parameters: f - the file you are reading in from
#
# * Return Value: start - the starting coordinate
#                 goal - where we are tring to get to
#                 blocked - points we cannot go to
# *
# **************************************************************
def read_state(f):
    blocked = []
    data = f.readline()
    x,y,z = data.split()
    start = (int(x), int(y), int(z))
    data = f.readline()
    x,y,z = data.split()
    goal = (int(x), int(y), int(z))
    while True:
        data = f.readline()
        if data == '':
            break
        else:
            x,y,z = data.split()
            blocked.append((int(x), int(y), int(z)))
    return start, goal, blocked

#*********************************************************************
#*  Function: reconstruct
#*  Description: shows the path taken to get to the solution
#*  Parameters: n - the node we are currently at
#*              came_from - the node we came from prior to this node
#*
#*  return: path - the completed path taken to get here
#*********************************************************************
def reconstruct(n, came_from):
    path = []
    while n in came_from.keys():
        n = came_from[n]
        path.append(n)
    return list(reversed(path))

#*********************************************************************
#*  Function: successors
#*  Description: creates a list set of successors
#*  Parameters: state - the node we are currently at
#*              blocked - a list of nodes that cannot be accessed
#*
#*  return: result - a list of successors without the blocked nodes
#*********************************************************************
def successors(state, blocked):
    result = set()
    result.add((state[0]-1, state[1], state[2]))
    result.add((state[0], state[1]-1, state[2]))
    result.add((state[0], state[1], state[2]-1))
    result.add((state[0]+1, state[1], state[2]))
    result.add((state[0], state[1]+1, state[2]))
    result.add((state[0], state[1], state[2]+1))
    result = result - set(blocked)
    return list(result)

#*********************************************************************
#*  Function: heurisitic
#*  Description: calculates the heurisitic value of a node
#*  Parameters: n - the node for the heuristic we are trying to ascertain
#*              goal - the goal node that we are comparing it to
#*
#*  return: (dx + dy + dz) a number created from distances
#*********************************************************************
def heuristic(n, goal):
    dx = abs(n[0] - goal[0])
    dy = abs(n[1] - goal[1])
    dz = abs(n[2] - goal[2])
    return (dx + dy + dz)

#*********************************************************************
#*  Function: astar
#*  Description: uses astar search to find and optimal path to our goal
#*  Parameters: start - the node we are starting at
#*              goal - the goal node that we are trying to get to
#*              blocked - unaccessable nodes
#*  return: current - essentially the goal node
#*          came_from - a list of nodes which got us to the goal
#*********************************************************************
def astar(start, goal, blocked): # adapted from the project 1 and wikipedia on a*search

    frontier = PriorityQueue()
    frontier.put((1, start))

    reached = set()
    reached.add(start)

    came_from = {}
    g_score = {}
    g_score[start] = 0
    f_score = {}
    f_score[start] = heuristic(start, goal)

    while not frontier.empty():
        _, current = frontier.get()
        if current == goal:
            return current, came_from

        for neighbor in successors(current, blocked):
            tentative_gScore = g_score[current] + 1

            if neighbor not in g_score:
                g_score[neighbor] = float("inf")
            if tentative_gScore < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_gScore
                f_score[neighbor] = g_score[neighbor] + heuristic(neighbor, goal)

                if neighbor not in reached:
                    reached.add(neighbor)
                    frontier.put((f_score[neighbor], neighbor))

    raise Exception("No Solution")

if __name__ == "__main__":
    start_time = time.time()
    if len(sys.argv) != 2:
        print("Usage: <problem file>")
        sys.exit(0)

    
    with open(sys.argv[1]) as f:
        start, goal, blocked = read_state(f)

    if goal in blocked:
        raise Exception("No Solution")

    bad = successors(goal, blocked)
    if len(bad) == 0:
        raise Exception("No Solution")

    n, c= astar(start, goal, blocked)
    end_time = time.time()
    p = reconstruct(n, c)
    print(p)
    print('')
    print("Solution length: ", len(p))
    print("A* Search time: ", end_time - start_time)