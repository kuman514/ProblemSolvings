// Solving BOJ 1551

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n = null;
let k = null;
let array = null;

rl.on('line', line => {
  if (n === null && k === null) {
    [n, k] = line.split(' ').map(item => parseInt(item));
  } else {
    array = line.split(',').map(item => parseInt(item));
    for (let i = 0; i < k; i++) {
      const newArray = [];
      for (let j = 1; j < n - i; j++) {
        newArray.push(array[j] - array[j - 1]);
      }
      array = newArray;
    }
    console.log(array.join(','));
    rl.close();
  }
}).on('close', () => {
  process.exit();
});
