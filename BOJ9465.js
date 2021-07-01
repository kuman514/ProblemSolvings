// Solving BOJ 9465

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let testcase = null;
let curts = 0;
let lines = 0;
let values = [];
let result = '';

rl.on('line', (line) => {
  if (testcase === null) {
    testcase = Number(line);
  } else if (curts < testcase) {
    if (lines === 1 || lines === 2) {
      values.push(line.split(' ').map((item) => Number(item)));
    }
    lines++;

    if (lines === 3) {
      result += getMaximumValue();
      values = [];
      lines = 0;
      curts++;
      if (curts === testcase) {
        console.log(result);
        rl.close();
      } else {
        result += '\n';
      }
    }
  }
}).on('close', () => {
  process.exit();
});

function getMaximumValue() {
  const value = [0, 0, 0];
  // 0: first, 1: second, 2: none
  for (let i = 0; i < values[0].length; i++) {
    const initVal = Array.from(value);

    // If tears first
    value[0] = Math.max(initVal[1], initVal[2]) + values[0][i];

    // If tears second
    value[1] = Math.max(initVal[0], initVal[2]) + values[1][i];

    // If not tear anything
    value[2] = Math.max(initVal[0], initVal[1]);
  }

  return Math.max(value[0], value[1], value[2]);
}
