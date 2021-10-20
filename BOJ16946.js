// Solving BOJ 16946

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n = null;
let m = null;
const walls = [];

rl.on('line', (line) => {
  if (n === null) {
    [n, m] = line.split(' ').map((item) => parseInt(item));
  } else {
    const input = Array.from(line).map((item) => (item === '1'));
    walls.push(input);

    if (walls.length === n) {
      console.log(countSpaceAfterBreach());
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});

function countSpaceAfterBreach() {
  const direction = [[1, 0], [0, 1], [-1, 0], [0, -1]];
  const visited = Array.from({length: n}, () => Array.from({length: m}, () => false));
  const indexPainted = Array.from({length: n}, () => Array.from({length: m}, () => -1));
  const countIndex = [];

  // Count and paint spaces available
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (!walls[i][j] && !visited[i][j]) {
        // Using BFS Search
        const getIndex = countIndex.length;
        countIndex.push(0);

        const next = [[i, j]];
        while (next.length > 0) {
          const [curR, curC] = next.shift();

          if (walls[curR][curC] || visited[curR][curC]) {
            continue;
          }

          visited[curR][curC] = true;
          indexPainted[curR][curC] = getIndex;
          countIndex[getIndex]++;

          for (let k = 0; k < 4; k++) {
            const [nextR, nextC] = [curR + direction[k][0], curC + direction[k][1]];

            if (nextR < 0 || nextR >= n) {
              continue;
            }

            if (nextC < 0 || nextC >= m) {
              continue;
            }

            if (walls[nextR][nextC]) {
              continue;
            }

            if (visited[nextR][nextC]) {
              continue;
            }

            next.push([nextR, nextC]);
          }
        }
      }
    }
  }

  // Calculate spaces available
  const results = Array.from({length: n}, () => Array.from({length: m}, () => 0));
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (walls[i][j]) {
        const alreadyIndexed = new Set();
        let curResult = 1;

        for (let k = 0; k < 4; k++) {
          const [nextR, nextC] = [i + direction[k][0], j + direction[k][1]];

          if (nextR < 0 || nextR >= n) {
            continue;
          }

          if (nextC < 0 || nextC >= m) {
            continue;
          }

          if (walls[nextR][nextC]) {
            continue;
          }

          const curCntIndex = indexPainted[nextR][nextC];
          if (alreadyIndexed.has(curCntIndex)) {
            continue;
          }

          alreadyIndexed.add(curCntIndex);
          curResult += countIndex[curCntIndex];
        }

        results[i][j] = curResult;
      }
    }
  }

  let finalResult = '';
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      finalResult += (results[i][j] % 10);
    }
    finalResult += '\n';
  }

  return finalResult;
}
