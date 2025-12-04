import heapq

def astar(maze, start, goal):
    def h(pos):
        # Manhattan-Distanz als Heuristik
        return abs(pos[0] - goal[0]) + abs(pos[1] - goal[1])

    open_list = []
    heapq.heappush(open_list, (0 + h(start), 0, start))  # (f, g, position)
    
    came_from = {}
    g_score = {start: 0}

    while open_list:
        f, g, current = heapq.heappop(open_list)

        if current == goal:
            # Ziel erreicht → Pfad rekonstruieren
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            return path[::-1]

        x, y = current
        neighbors = [(x+1,y), (x-1,y), (x,y+1), (x,y-1)]
        # V, A, >, <

        for neighbor in neighbors:
            
            nx, ny = neighbor
            print(f"Testing: ({nx}, {ny})")
            if 0 <= nx < len(maze) and 0 <= ny < len(maze[0]) and maze[nx][ny] != 1:
                tentative_g = g + 1
                
                if neighbor not in g_score or tentative_g < g_score[neighbor]:
                    came_from[neighbor] = current
                    g_score[neighbor] = tentative_g
                    print(f"   ╚> Good neighbor")
                    heapq.heappush(open_list, (tentative_g + h(neighbor), tentative_g, neighbor))
                
    
    return None  # Kein Pfad gefunden

# Beispiel-Labyrinth: 0 = frei, 1 = Wand
# x ist vertikal, y ist horizontal
maze = [
    [0, 0, 0, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 1, 0],
    [1, 1, 1, 1, 0],
    [0, 0, 0, 0, 0]
]

start = (0, 0)
goal = (4, 0)

path = astar(maze, start, goal)

if path:
    print("\nGefundener Pfad:")
    for p in path:
        print(p)
else:
    print("Kein Pfad gefunden.")
