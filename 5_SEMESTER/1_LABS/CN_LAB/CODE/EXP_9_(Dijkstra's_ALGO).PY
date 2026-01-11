import heapq

V = 5

def dijkstra(graph, src):
    dist = [float('inf')] * V
    dist[src] = 0
    pq = [(0, src)] 

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v in range(V):
            if graph[u][v] > 0 and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]
                heapq.heappush(pq, (dist[v], v))

    print("Vertex\tDistance from Source")
    for i in range(V):
        print(f"{i}\t\t{dist[i]}")

graph = [
    [0, 10, 0, 0, 5],
    [0, 0, 1, 0, 2],
    [0, 0, 0, 4, 0],
    [7, 0, 6, 0, 0],
    [0, 3, 9, 2, 0]
]

dijkstra(graph, 0)  
