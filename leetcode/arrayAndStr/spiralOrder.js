/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if (!matrix.length || !matrix[0].length) {
        return [];
    }

    const rows = matrix.length; 
    const colums = matrix[0].length;
    const visited = new Array(rows).fill(0).map(() => new Array(colums).fill(false));
    const total = rows * colums;
    const order = new Array(total).fill(0);

    const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    let directionIndex = 0;
    let row = 0;
    let col = 0;
    for (let i = 0; i < total; i++) {
        order[i] = matrix[row][col];
        visited[row][col] = true;
        const nextRow = row + directions[directionIndex][0];
        const nextCol = col + directions[directionIndex][1];
        if (!(nextRow >= 0 && nextCol >=0 && nextRow < rows && nextCol < colums && !visited[nextRow][nextCol])) {
            directionIndex = (directionIndex + 1) % 4;
        }
        row += directions[directionIndex][0];
        col += directions[directionIndex][1];
    }

    return order;
};

let input = [[1,2,3],[4,5,6],[7,8,9]];
let res = spiralOrder(input);
console.log(res);