import collections

def bfs(graph, root):

    v, queue = set(), collections.deque([root])
    v.add(root)

    while queue:

        vertex = queue.pop()
        print(str(vertex) + " ", end="")


        for branch in graph[vertex]:
            if branch not in v:
                v.add(branch)
                queue.append(branch)


if __name__ == '__main__':
    graph = {
        'A': ['B', 'C', "D"],
        'B': ['E', "F"],
        'C': ['G', "I"],
        'D': ['I'],
        'E': ['G','F'],
        "F": ['I','C'],
        'G': ['A','B'],
        "I": ['B','C']
    }
    print("Following is Breadth First Traversal: ")
    bfs(graph, 'D')
