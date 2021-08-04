// Solving BOJ 2579

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n = null;
const stairs = [];

rl.on('line', (line) => {
  if (n === null) {
    n = Number(line);
  } else {
    stairs.push(Number(line));
    if (stairs.length === n) {
      console.log(getMaximumStepValue());
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});

function getMaximumStepValue() {
  if (stairs.length === 1) {
    return stairs[0];
  } else if (stairs.length === 2) {
    return (stairs[0] + stairs[1]);
  }

  const points = [];

  /*
    Certain
    Stair 0 = stairs[0]
    Stair 1 = stairs[0] + stairs[1]
    Stair 2 = Max(stairs[0] + stairs[2], stairs[1] + stairs[2])
  */

  points.push(stairs[0]);
  points.push(stairs[0] + stairs[1]);
  points.push(Math.max(stairs[0] + stairs[2], stairs[1] + stairs[2]));

  /*
    Select bigger of each iteration
    Type 1: Step 2 stairs from Stair (i - 2)
            -> Best point from Stair (i - 2)
    Type 2: Step 1 stair from Stair (i - 1)
            -> (Best point from Stair (i - 2)) + value of Stair (i - 1)
    
    Concluded value of Stair i = (value of Stair i) + Max(Type 1, Type 2)
  */

  for (let i = 3; i < stairs.length; i++) {
    points.push(stairs[i] + Math.max(points[i - 2], points[i - 3] + stairs[i - 1]));
  }

  return points.pop();
}
