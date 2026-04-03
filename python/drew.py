import heapq
import itertools
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from IPython.display import HTML, display
def h1(state, goal):
    return sum(1 for i in range(9) if state[i] != 0 and state[i] != goal[i])
def get_neighbors(state):
    neighbors = []
    zero_idx = state.index(0)
    r, c = divmod(zero_idx, 3)
    moves = [(-1,0),(1,0),(0,-1),(0,1)]
    for dr, dc in moves:
        nr, nc = r + dr, c + dc
        if 0<=nr<3 and 0<=nc<3:
            new_idx = nr * 3 + nc
            s = list(state)
            s[zero_idx], s[new_idx] = s[new_idx], s[zero_idx]
            neighbors.append(tuple(s))
    return neighbors
def a_star_8_puzzle(start, goal):
    counter=itertools.count()
    pq=[(h1(start, goal), 0, next(counter), start, [start])]
    explored = set()
    while pq:
        f, g, _, state, path=heapq.heappop(pq)
        if state==goal:
            return path
        if state in explored:
            continue
        explored.add(state)
        for neighbor in get_neighbors(state):
            if neighbor not in explored:
                new_g=g + 1
                new_f=new_g + h1(neighbor, goal)
                heapq.heappush(
                    pq,
                    (new_f, new_g, next(counter), neighbor, path + [neighbor])
                )
    return None
fig, ax=plt.subplots(figsize=(4,4))
plt.close(fig)
def draw(state):
    ax.clear()
    ax.set_xticks([])
    ax.set_yticks([])
    ax.set_xlim(0, 3)
    ax.set_ylim(0, 3)
    ax.set_aspect('equal')
    for i in range(3):
        for j in range(3):
            val=state[i*3 + j]
            rect=plt.Rectangle((j,2 - i), 1, 1,
                                 facecolor='#FF6B6B' if val!=0 else '#f0f0f0',
                                 edgecolor='black')
            ax.add_patch(rect)
            if val!=0:
                ax.text(j + 0.5, 2 - i + 0.5, str(val),
                        ha='center', va='center',
                        fontsize=20, fontweight='bold')
def update(frame):
    draw(path[frame])
    ax.set_title(f"Step {frame}")
start=(7,2,4,
       5,0,6,
       8,3,1)
goal=(1,2,3,
      4,5,6,
      7,8,0)
path=a_star_8_puzzle(start,goal)
if path:
    print("Steps:",len(path)-1)
    ani=animation.FuncAnimation(fig,update,frames=len(path),interval=800,repeat=False)
    display(HTML(ani.to_jshtml()))
else:
    print("No solution")