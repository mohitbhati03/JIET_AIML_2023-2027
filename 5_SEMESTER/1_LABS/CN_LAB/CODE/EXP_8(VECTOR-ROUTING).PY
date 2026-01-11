import numpy as np

INF = 9999

nodes = int(input("Enter number of nodes: "))
print(f"Enter the {nodes}x{nodes} distance matrix (use {INF} for infinity):")
dist = np.array([list(map(int, input().split())) for _ in range(nodes)])

np.fill_diagonal(dist, 0)

via = np.arange(nodes).reshape(1, -1).repeat(nodes, axis=0)

for k in range(nodes):
    new_dist = dist[:, k, None] + dist[k]
    better = new_dist < dist
    dist[better] = new_dist[better]
    via[better] = k

for i in range(nodes):
    print(f"\nRouting table for node {i}:")
    print("Destination\tDistance\tNext Hop")
    for j in range(nodes):
        print(f"{j}\t\t{dist[i, j]}\t\t{via[i, j]}")
