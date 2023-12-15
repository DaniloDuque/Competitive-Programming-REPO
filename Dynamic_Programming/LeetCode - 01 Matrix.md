```py
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        
        n = len(mat)
        m = len(mat[0])

        max_value = n * m
        queue = []

        for i in range(n):
            row = []
            for j in range(m):
                
                if mat[i][j]:
                    mat[i][j] = max_value
                else:
                    queue.append([i, j])

        moves = [[1, 0], [-1, 0], [0, -1], [0, 1]]

        def is_valid(i, j): return i >= 0 and i < n and j >= 0 and j < m

        def update_matrix(queue, mat):
            
            while queue:
                
                a, b = queue.pop()
                for x, y in moves:
                    
                    if is_valid(a + x, b + y) and mat[a + x][b + y] > mat[a][b]:
                        
                        mat[a + x][b + y] = 1 + mat[a][b]
                        queue.insert(0, [a + x, b + y])
                        
            return mat
            
        return update_matrix(queue, mat)
