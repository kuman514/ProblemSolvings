// Solving BOJ 11660

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let size = null;
let queries = null;

let lines = 0;
let tasks = 0;

let result = '';

const board = [];

rl.on('line', (line) => {
  if (size === null && queries === null) {
    [size, queries] = line.split(' ').map((item) => Number(item));
  } else if (lines < size) {
    board.push(line.split(' ').map((item) => Number(item)));
    lines++;
    if (lines === size) {
      preCalculate();
    }
  } else if (tasks < queries) {
    const coords = line.split(' ').map((item) => Number(item));
    tasks++;
    if (tasks === queries) {
      result += `${getAreaSum([coords[0], coords[1]], [coords[2], coords[3]])}`;
      console.log(result);
      rl.close();
    } else {
      result += `${getAreaSum([coords[0], coords[1]], [coords[2], coords[3]])}\n`;
    }
  }
}).on('close', () => {
  process.exit();
});

function preCalculate() {
  // Row 0
  for (let j = 1; j < board[0].length; j++) {
    board[0][j] += board[0][j - 1];
  }

  // Row 1~
  for (let i = 1; i < board.length; i++) {
    let lineSum = 0;
    for (let j = 0; j < board[i].length; j++) {
      lineSum += board[i][j];
      board[i][j] = (board[i - 1][j] + lineSum);
    }
  }
}

function getAreaSum(rc1, rc2) {
  const [r1, c1, r2, c2] = [rc1[0] - 1, rc1[1] - 1, rc2[0] - 1, rc2[1] - 1];
  let result = board[r2][c2];
  if (r1 > 0) {
    result -= board[r1 - 1][c2];
  }
  if (c1 > 0) {
    result -= board[r2][c1 - 1];
  }
  if (r1 > 0 && c1 > 0) {
    result += board[r1 - 1][c1 - 1];
  }
  return result;
}
