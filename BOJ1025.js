// Solving BOJ 1025

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let rows = null;
let cols = null;
const tiles = [];
let rCount = 0;

rl.on('line', (line) => {
  if (rows === null && cols === null) {
    [rows, cols] = line.split(' ').map((item) => parseInt(item));
  } else {
    tiles.push(Array.from(line));
    rCount++;
    if (rCount === rows) {
      console.log(getLargestSquare());
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});

function getLargestSquare() {
  let result = -1;

  // Start point
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      // Increase
      for (let rInc = -rows; rInc <= rows; rInc++) {
        for (let cInc = -cols; cInc <= cols; cInc++) {
          // Init
          let rPoint = i;
          let cPoint = j;
          let numberStr = '';

          // If rInc === 0 and cInc === 0
          if (rInc === 0 && cInc === 0) {
            const number = parseInt(tiles[rPoint][cPoint]);
            const sqrtNum = Math.sqrt(number);
            if (sqrtNum === Math.floor(sqrtNum)) {
              if (result < number) {
                result = number;
              }
            }
            continue;
          }

          // Process
          while ((0 <= rPoint && rPoint < rows) && (0 <= cPoint && cPoint < cols)) {
            numberStr += `${tiles[rPoint][cPoint]}`;
            const number = parseInt(numberStr);
            const sqrtNum = Math.sqrt(number);
            if (sqrtNum === Math.floor(sqrtNum)) {
              if (result < number) {
                result = number;
              }
            }

            rPoint += rInc;
            cPoint += cInc;
          }
        }
      }
    }
  }

  return result;
}
