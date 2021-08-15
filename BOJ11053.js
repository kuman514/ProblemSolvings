// Solving BOJ 11053

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n = null;

rl.on('line', (line) => {
  if (n === null) {
    n = parseInt(line);
  } else {
    console.log(getLongestIncreasing(line.split(' ').map((item) => parseInt(item))));
    rl.close();
  }
}).on('close', () => {
  process.exit();
});

function getLongestIncreasing(arr) {
  const longestCount = [];
  let largest = 0;

  for (let i = 0; i < arr.length; i++) {
    let curLong = 0;
    for (let j = longestCount.length - 1; j >= 0; j--) {
      if (arr[i] > arr[j] && curLong < longestCount[j]) {
        curLong = longestCount[j];
      }
    }

    if (largest < curLong + 1) {
      largest = curLong + 1;
    }

    longestCount.push(curLong + 1);
  }

  return largest;
}
