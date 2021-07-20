// Solving BOJ 11659

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let queries = null;
let numbers = null;
let curQ = 0;
let result = '';

rl.on('line', (line) => {
  if (queries === null) {
    queries = Number(line.split(' ')[1]);
  } else if (numbers === null) {
    numbers = line.split(' ').map((item) => Number(item));
    for (let i = 1; i < numbers.length; i++) {
      numbers[i] += numbers[i - 1];
    }
  } else if (curQ < queries) {
    const [i, j] = line.split(' ').map((item) => (Number(item) - 1));
    const numI = (i === 0) ? 0 : numbers[i - 1];
    const numJ = numbers[j];
    curQ++;
    if (curQ === queries) {
      result += `${numJ - numI}`;
      console.log(result);
      rl.close();
    } else {
      result += `${numJ - numI}\n`;
    }
  }
}).on('close', () => {
  process.exit();
});
