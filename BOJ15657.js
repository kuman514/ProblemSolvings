// Solving BOJ 15657

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const nm = {
  n: null,
  m: null,
  result: ''
};
const numbers = [];
const curContain = [];

rl.on('line', (line) => {
  if (nm.n === null && nm.m === null) {
    [nm.n, nm.m] = line.split(' ').map((item) => parseInt(item));
  } else {
    numbers.push(...(line.split(' ').map((item) => parseInt(item))));
    numbers.sort((a, b) => (a - b));
    pickPermutation(0, 0);
    console.log(nm.result);
    rl.close();
  }
}).on('close', () => {
  process.exit();
});

function pickPermutation(depth, curIndex) {
  for (let i = curIndex; i < numbers.length; i++) {
    curContain.push(numbers[i]);
    if (depth === nm.m - 1) {
      let curResult = '';
      for (let j = 0; j < curContain.length; j++) {
        if (j === curContain.length - 1) {
          curResult += `${curContain[j]}\n`;
        } else {
          curResult += `${curContain[j]} `;
        }
      }
      nm.result += curResult;
    } else {
      pickPermutation(depth + 1, i);
    }
    curContain.pop();
  }
}
