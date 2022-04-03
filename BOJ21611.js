// Solving BOJ 21611

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n = null;
let m = null;
const inputArray = [];
const commands = [];
const result = [0, 0, 0, 0];

rl.on('line', line => {
  if (n === null && n === null) {
    [n, m] = line.split(' ').map(item => parseInt(item));
  } else if (inputArray.length < n) {
    inputArray.push(line.split(' ').map(item => parseInt(item)));
  } else if (commands.length < m) {
    commands.push(line.split(' ').map(item => parseInt(item)));
    if (commands.length === m) {
      const rail = initRail();
      invokeGame(rail);
      console.log(1 * result[1] + 2 * result[2] + 3 * result[3]);
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});

function initRail() {
  const center = Math.floor(n / 2);
  const rail = [-1];
  let [row, col] = [center, center - 1];
  let offset = center;
  while (offset > 0) {
    // Down
    while (row <= n - 1 - offset) {
      //console.log(row, col);
      rail.push(inputArray[row][col]);
      row++;
    }
    // Right
    while (col <= n - 1 - offset) {
      //console.log(row, col);
      rail.push(inputArray[row][col]);
      col++;
    }
    // Up
    while (row >= offset) {
      //console.log(row, col);
      rail.push(inputArray[row][col]);
      row--;
    }
    // Left
    while (col >= offset - 1) {
      //console.log(row, col);
      rail.push(inputArray[row][col]);
      col--;
    }
    offset--;
  }
  //console.log(rail);
  return rail;
}

/*
80 79 78 77 76 75 74 73 72
49 48 47 46 45 44 43 42 71
50 25 24 23 22 21 20 41 70
51 26  9  8  7  6 19 40 69
52 27 10  1  .  5 18 39 68
53 28 11  2  3  4 17 38 67
54 29 12 13 14 15 16 37 66
55 30 31 32 33 34 35 36 65
56 57 58 59 60 61 62 63 64

Left
0: 1
1: 10 [+9]
2: 27 [+17]
3: 52 [+25]
n: (4 * n * (n + 1) + n + 1) [+(8n+1)]

Down
0: 3
1: 14 [+11]
2: 33 [+19]
3: 60 [+27]
n: (4 * n * (n + 1) + 3 * n + 3) [+(8n+3)]

Right
0: 5
1: 18 [+13]
2: 39 [+21]
3: 68 [+29]
n: (4 * n * (n + 1) + 5 * n + 5) [+(8n+5)]

Up
0: 7
1: 22 [+15]
2: 45 [+23]
3: 76 [+31]
n: (4 * n * (n + 1) + 7 * n + 7) [+(8n+7)]
*/

function invokeGame(rail) {
  let currentRail = Array.from(rail);
  const offset = [0, 7, 3, 1, 5];
  for (let i = 0; i < commands.length; i++) {
    const [direction, range] = commands[i];
    //console.log(i, direction, range);
    // Destroy
    for (let j = 0; j < range; j++) {
      const railIndex = (4 * j * (j + 1) + offset[direction] * j + offset[direction]);
      //console.log(railIndex);
      if (railIndex >= currentRail.length) {
        break;
      }
      currentRail[railIndex] = 0;
    }
    // Update Rail
    currentRail = currentRail.filter(item => (item !== 0));
    // Linked booms
    while (true) {
      let linkedBoom = false;
      let currentBall = 0;
      let currentSeries = 0;
      for (let j = 1; j < currentRail.length; j++) {
        if (currentBall !== currentRail[j]) {
          if (currentSeries >= 4) {
            // Start linked boom
            for (let k = j - currentSeries; k < j; k++) {
              //console.log(k, currentRail[k]);
              currentRail[k] = 0;
            }
            linkedBoom = true;
            result[currentBall] += currentSeries;
          }
          currentBall = currentRail[j];
          currentSeries = 1;
        } else {
          currentSeries++;
        }
      }
      // Final linked boom?
      if (currentSeries >= 4) {
        // Start linked boom
        for (let k = currentRail.length - currentSeries; k < currentRail.length; k++) {
          //console.log(k, currentRail[k]);
          currentRail[k] = 0;
        }
        linkedBoom = true;
        result[currentBall] += currentSeries;
      }
      if (!linkedBoom) {
        break;
      }
      // Update Rail
      currentRail = currentRail.filter(item => (item !== 0));
    }
    //console.log(currentRail);
    // Group transforming
    const groupedRail = [-1];
    let currentBall = 0;
    let currentSeries = 0;
    for (let j = 1; j < currentRail.length; j++) {
      if (currentBall !== currentRail[j]) {
        if (currentBall !== 0) {
          groupedRail.push(currentSeries);
          groupedRail.push(currentBall);
        }
        currentBall = currentRail[j];
        currentSeries = 1;
      } else {
        currentSeries++;
      }
    }
    // Final group
    groupedRail.push(currentSeries);
    groupedRail.push(currentBall);
    currentRail = groupedRail.filter((_, index) => (index < n * n));
    //console.log(currentRail);
  }
}
