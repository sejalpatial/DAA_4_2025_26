# =========================
# 1. N-Queens Problem
# =========================

def solve_n_queens(n):
    solutions = []
    board = [["." for _ in range(n)] for _ in range(n)]
    
    left_row = [0] * n
    upper_diag = [0] * (2 * n - 1)
    lower_diag = [0] * (2 * n - 1)

    def solve(col):
        if col == n:
            solutions.append(["".join(row) for row in board])
            return

        for row in range(n):
            if left_row[row] == 0 and lower_diag[row + col] == 0 and upper_diag[n - 1 + col - row] == 0:
                board[row][col] = "Q"
                left_row[row] = 1
                lower_diag[row + col] = 1
                upper_diag[n - 1 + col - row] = 1

                solve(col + 1)

                board[row][col] = "."
                left_row[row] = 0
                lower_diag[row + col] = 0
                upper_diag[n - 1 + col - row] = 0

    solve(0)
    return solutions


def print_n_queens(n):
    solutions = solve_n_queens(n)
    
    print(f"Total Solutions: {len(solutions)}\n")
    
    for idx, sol in enumerate(solutions, 1):
        print(f"Solution {idx}:")
        for row in sol:
            print(row)
        print()


# Example run
print_n_queens(4)


# =========================
# 2. Hamiltonian Cycle
# =========================

def hamiltonian_cycle(graph):
    n = len(graph)
    path = [-1] * n

    path[0] = 0  # start from vertex 0

    def is_safe(v, pos):
        # Check if vertex is adjacent to previous
        if graph[path[pos - 1]][v] == 0:
            return False
        
        # Check if already included
        if v in path:
            return False
        
        return True

    def solve(pos):
        if pos == n:
            # Check if last vertex connects to first
            return graph[path[pos - 1]][path[0]] == 1

        for v in range(1, n):
            if is_safe(v, pos):
                path[pos] = v

                if solve(pos + 1):
                    return True

                path[pos] = -1

        return False

    if not solve(1):
        print("No Hamiltonian Cycle exists")
        return False

    print("Hamiltonian Cycle:")
    print(" -> ".join(map(str, path)) + f" -> {path[0]}")
    return True


# Example graph (Adjacency Matrix)
graph = [
    [0, 1, 1, 0, 1],
    [1, 0, 1, 1, 1],
    [1, 1, 0, 1, 0],
    [0, 1, 1, 0, 1],
    [1, 1, 0, 1, 0]
]

hamiltonian_cycle(graph)