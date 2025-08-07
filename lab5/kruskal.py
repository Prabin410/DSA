def find_leader(parent_list, node):
    if parent_list[node] < 0:
        return node
    else:
        parent_list[node] = find_leader(parent_list, parent_list[node])
        return parent_list[node]

def merge_sets(parent_list, node_a, node_b, mst_edges):
    leader_a = find_leader(parent_list, node_a)
    leader_b = find_leader(parent_list, node_b)
    
    if leader_a != leader_b:                        # Check if roots are different
        if parent_list[leader_a] < parent_list[leader_b]:   # leader_a set is larger
            parent_list[leader_a] += parent_list[leader_b]
            parent_list[leader_b] = leader_a
        else:
            parent_list[leader_b] += parent_list[leader_a]
            parent_list[leader_a] = leader_b
        mst_edges.append((node_a, node_b))


edges_list = [[1,2,1],[1,4,4],[2,3,3],[2,5,3],[3,5,1],[3,6,2],[4,5,1],[5,6,4]]
num_nodes = 6
minimum_spanning_tree = []
sorted_edges = sorted(edges_list, key=lambda x: x[2])

print("Edges sorted by weight:\n")
for edge in sorted_edges: 
    print(edge)

parent_array = []

for i in range(num_nodes + 1):
    parent_array.append(-1)       

for src_node, dest_node, weight in sorted_edges:
    merge_sets(parent_array, src_node, dest_node, minimum_spanning_tree)

print("\nEdges included in the Minimum Spanning Tree:")
for edge in minimum_spanning_tree:
    print(edge)
