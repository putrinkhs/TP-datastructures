# Implementasi Algoritma Kruskal dengan Penanganan Jalur yang Tidak Ada

class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)

        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

# Daftar edge dan jaraknya
edges = [
    (5, 'Kantor1', 'Pemukiman1'),
    (10, 'Data Center', 'Pemukiman1'),
    (13, 'Kantor2', 'Pemukiman1'),
    (20, 'Data Center', 'Kantor2'),
    (25, 'Kantor1', 'Pemukiman2'),
    (30, 'Data Center', 'Kantor1'),
    (40, 'Kantor2', 'Pemukiman2')
]

# Daftar titik
nodes = ['Data Center', 'Kantor1', 'Kantor2', 'Pemukiman1', 'Pemukiman2']
node_index = {node: idx for idx, node in enumerate(nodes)}

# Inisialisasi Disjoint Set
ds = DisjointSet(len(nodes))

# Urutkan edges berdasarkan jarak
edges.sort()

# Algoritma Kruskal
mst = []
total_distance = 0

for distance, u, v in edges:
    u_index = node_index[u]
    v_index = node_index[v]
    
    if ds.find(u_index) != ds.find(v_index):
        ds.union(u_index, v_index)
        mst.append((u, v, distance))
        total_distance += distance

# Output hasil MST
print("Minimum Spanning Tree:")
for u, v, distance in mst:
    print(f"{u} - {v}: {distance} km")
print(f"Total distance: {total_distance} km")

# Identifikasi komponen terpisah
components = {}
for node in nodes:
    root = ds.find(node_index[node])
    if root not in components:
        components[root] = []
    components[root].append(node)

print("\nKomponen Terpisah:")
for comp in components.values():
    print(" - ".join(comp))

