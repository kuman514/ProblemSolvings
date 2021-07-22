// Solving BOJ 16928

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const boardDst = Array.from({length: 101}, () => null);
let lines = null;
let curLine = 0;

rl.on('line', (line) => {
  if (lines === null) {
    const [a, b] = line.split(' ').map((item) => Number(item));
    lines = a + b;
  } else if (curLine < lines) {
    const [org, dst] = line.split(' ').map((item) => Number(item));
    boardDst[org] = dst;
    curLine++;

    if (curLine === lines) {
      console.log(rollDice());
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});

function rollDice() {
  // [rolls, currentPlace]
  const next = [[0, 1]];
  const visited = Array.from({length: 101}, () => false);
  let result = 0;

  while (next.length > 0) {
    const cur = next.shift();

    // If already visited, pass
    if (visited[cur[1]]) {
      continue;
    }

    // Paint here visited
    visited[cur[1]] = true;

    // If here is the goal
    if (cur[1] === 100) {
      result = cur[0];
      break;
    }

    // Seek next
    for (let i = 1; i <= 6; i++) {
      const nextR = cur[0] + 1;
      let nextPos = cur[1] + i;

      // Out of range
      if (nextPos > 100) {
        break;
      }

      // Warp
      if (boardDst[nextPos] !== null) {
        nextPos = boardDst[nextPos];
      }

      // Already visited
      if (visited[nextPos]) {
        continue;
      }

      // Enqueue
      next.push([nextR, nextPos]);
    }
  }

  return result;
}
