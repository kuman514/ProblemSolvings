// Solving BOJ 2470

// Get readline module
const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n = null;
let values = null;

// Get input
rl.on('line', line => {
  if (n === null) {
    n = Number(line);
  } else {
    values = line.split(' ').map((item) => {return Number(item);});
    values.sort((a, b) => {
      if (a < b) {
        return -1;
      }
      if (a > b) {
        return 1;
      }
      if (a === b) {
        return 0;
      }
    });
    const result = getCloseTo0(values);
    console.log(`${result[0]} ${result[1]}`);
    rl.close();
  }
}).on('close', () => {
  process.exit();
});

// Two pointer solution
function getCloseTo0(arr) {
  let left = 0;
  let right = arr.length - 1;
  let closest = null;
  let mindiff = null;

  while (left < right) {
    const diff = Math.abs(arr[left] + arr[right]);

    // If first or new minimum difference
    if (closest === null || mindiff > diff) {
      mindiff = diff;
      closest = [arr[left], arr[right]];
    }

    if (arr[left] + arr[right] > 0) {
      right--;
    } else if (arr[left] + arr[right] < 0) {
      left++;
    } else {
      // If exactly 0, no more mix
      break;
    }
  }

  return closest;
}