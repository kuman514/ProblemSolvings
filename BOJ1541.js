// Solving BOJ 1541

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
  const parsed = parseExp(line);
  console.log(getMinimumExpResult(parsed.nums, parsed.opers));
  rl.close();
}).on('close', () => {
  process.exit();
});

function parseExp(exp) {
  const nums = [];
  const opers = [];
  
  let index = 0;
  while (index < exp.length) {
    switch (exp[index]) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        let tmpNum = '';
        while (index < exp.length && exp[index] !== '+' && exp[index] !== '-') {
          tmpNum += exp[index];
          index++;
        }
        nums.push(Number(tmpNum));
        break;
      case '+': case '-':
        opers.push(exp[index]);
        index++;
        break;
    }
  }

  return {
    nums: nums,
    opers: opers
  };
}

function getMinimumExpResult(nums, opers) {
  let first = nums[0];
  let opponents = 0;

  // Until first '-'
  let index = 0;
  while (index < opers.length && opers[index] !== '-') {
    // numIndex = index + 1
    first += nums[index + 1];
    index++;
  }

  while (index < opers.length) {
    opponents += nums[index + 1];
    index++;
  }

  return (first - opponents);
}
