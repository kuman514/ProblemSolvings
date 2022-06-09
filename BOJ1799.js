// Solving BOJ 1799

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n = null;
const wall = [];
const deployed = [];
let currentBishops = 0;
let maximumBishops = 0;
let total = 0;

rl.on('line', (line) => {
  if (n === null) {
    n = parseInt(line);
  } else {
    wall.push(line.split(' ').map((item) => (item !== '1')));
    if (wall.length === n) {
      deployed.push(Array.from({length: 2 * n - 1}, () => false));
      deployed.push(Array.from({length: 2 * n - 1}, () => false));

      // Scan black tiles
      currentBishops = 0;
      maximumBishops = 0;
      countMaximumBishops(0, n * n);
      total += maximumBishops;

      // Scan white tiles
      currentBishops = 0;
      maximumBishops = 0;
      countMaximumBishops(1, n * n);
      total += maximumBishops;
      
      console.log(total);
      rl.close();
    }
  }
  
}).on('close', () => {
  process.exit();
});

function countMaximumBishops(startIndex, totalLength) {
  let i = startIndex;
  while (i < totalLength) {
    const row = Math.floor(i / n);
    const col = i % n;

    let next = i + 2;
    if (n % 2 === 0) {
      if (i % n === n - 1) {
        next = i + 1;
      } else if (i % n === n - 2) {
        next = i + 3;
      }
    }

    // Scan wall
    if (wall[row][col]) {
      i = next;
      continue;
    }

    // Scan deployed diagonally
    const deployDiag = [(n - 1) + (col - row), row + col];

    // [0] => (n - 1) + (col - row)
    // [1] => (row + col)
    if (deployed[0][deployDiag[0]] || deployed[1][deployDiag[1]]) {
      i = next;
      continue;
    }

    // Deploy a bishop
    currentBishops++;
    if (maximumBishops < currentBishops) {
      maximumBishops = currentBishops;
    }
    deployed[0][deployDiag[0]] = true;
    deployed[1][deployDiag[1]] = true;

    // Go for the next
    countMaximumBishops(next, totalLength);

    // Restore
    currentBishops--;
    deployed[0][deployDiag[0]] = false;
    deployed[1][deployDiag[1]] = false;

    i = next;
  }
}
