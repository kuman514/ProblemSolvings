// Solving BOJ 15663

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const nm = {
  n: null,
  m: null
};
const numbers = [];
const curContain = [];
const remain = Array.from({length: 10001}, () => 0);
const result = new Set();
let finalResult = '';

rl.on('line', (line) => {
  if (nm.n === null && nm.m === null) {
    [nm.n, nm.m] = line.split(' ').map((item) => parseInt(item));
  } else {
    numbers.push(...(line.split(' ').map((item) => parseInt(item))));
    numbers.sort((a, b) => (a - b));
    for (let i = 0; i < numbers.length; i++) {
      remain[numbers[i]]++;
    }
    pickPermutation(0, 0);
    console.log(finalResult);
    rl.close();
  }
}).on('close', () => {
  process.exit();
});

function pickPermutation(depth, curIndex) {
  for (let i = curIndex; i < numbers.length; i++) {
    if (remain[numbers[i]] > 0) {
      remain[numbers[i]]--;
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
        if (!result.has(curResult)) {
          result.add(curResult);
          finalResult += curResult;
        }
      } else {
        pickPermutation(depth + 1, 0);
      }
      curContain.pop();
      remain[numbers[i]]++;
    }
  }
}
