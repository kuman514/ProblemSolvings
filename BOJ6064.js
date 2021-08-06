// Solving BOJ 6064

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let cases = null;
let currentCases = 0;
let result = '';

rl.on('line', (line) => {
  if (cases === null) {
    cases = Number(line);
  } else {
    currentCases++;
    const [m, n, x, y] = line.split(' ').map((item) => Number(item));
    result += `${getCainDate(m, n, x, y)}\n`;
    if (currentCases === cases) {
      console.log(result);
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});

function getCainDate(m, n, x, y) {
  let result = y;
  const range = lcm(Math.min(m, n), Math.max(m, n));

  let curX = y % m;
  if (curX === 0) {
    curX = m;
  }

  while (result <= range) {
    if (curX === x) {
      break;
    }

    result += n;
    curX += n;
    curX %= m;
    if (curX === 0) {
      curX = m;
    }
  }

  if (curX === x) {
    return result;
  } else {
    return -1;
  }
}

function gcd(minNum, maxNum){
  return (minNum % maxNum) === 0 ? maxNum : gcd(maxNum, minNum % maxNum);
}

function lcm(minNum, maxNum){
  return minNum * maxNum / gcd(minNum, maxNum);
}
