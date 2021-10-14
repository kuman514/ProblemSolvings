// Solving BOJ 17070

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n = null;
const block = [];

rl.on('line', (line) => {
  if (n === null) {
    n = parseInt(line);
  } else {
    block.push(line.split(' ').map((item) => (parseInt(item) === 1)));
    if (block.length === n) {
      console.log(countMovingWays());
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});

function countMovingWays() {
  /*
    block = n*n matrix with values of [0, 1]

    layer = 3 layers of n*n matrix
      (To count the ways to reach [i][j])
      <0: horizontal, 1: diagonal, 2: vertical>

    layer[0][0][1] = 1
    for j => [2, n):
      if block[0][j]:
        break;
      layer[0][0][j] = layer[0][0][j - 1]

    for i => [1, n):
      for j => [2, n):
        if block[i][j]:
          continue;
        layer[0][i][j] = layer[0][i][j - 1] + layer[1][i][j - 1]
        if not block[i - 1][j] and not block[i][j - 1]:
          layer[1][i][j] = sum <f => [0, 2]> of <layer[f][i - 1][j - 1]>
        layer[2][i][j] = layer[1][i - 1][j] + layer[2][i - 1][j]

    return sum <f => [0, 2]> of <layer[f][n - 1][n - 1]>
  */

  const layer = Array.from({
    length: 3
  }, () => Array.from({
    length: n
  }, () => Array.from({
    length: n
  }, () => 0)));

  layer[0][0][1] = 1;
  for (let j = 2; j < n; j++) {
    if (block[0][j]) {
      break;
    }
    layer[0][0][j] = layer[0][0][j - 1];
  }

  for (let i = 1; i < n; i++) {
    for (let j = 2; j < n; j++) {
      if (block[i][j]) {
        continue;
      }

      layer[0][i][j] = layer[0][i][j - 1] + layer[1][i][j - 1];
      if (!block[i - 1][j] && !block[i][j - 1]) {
        for (let k = 0; k < 3; k++) {
          layer[1][i][j] += layer[k][i - 1][j - 1];
        }
      }
      layer[2][i][j] = layer[1][i - 1][j] + layer[2][i - 1][j];
    }
  }

  return (layer[0][n - 1][n - 1] + layer[1][n - 1][n - 1] + layer[2][n - 1][n - 1]);
}
