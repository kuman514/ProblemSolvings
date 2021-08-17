// Solving BOJ 14490

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
  const [a, b] = line.split(':').map((item) => Number(item));
  console.log(getGreatestDivision(a, b));
  rl.close();
}).on('close', () => {
  process.exit();
});
 
function getGreatestDivision(a, b) {
  const gcdNum = gcd(Math.min(a, b), Math.max(a, b));
  return `${a / gcdNum}:${b / gcdNum}`;
}

function gcd(minNum, maxNum) {
  if (maxNum % minNum === 0) {
    return minNum;
  } else {
    return gcd(maxNum % minNum, minNum);
  }
}
