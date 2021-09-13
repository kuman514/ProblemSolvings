// Solving BOJ 2225

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
  const inputs = line.split(' ').map((item) => parseInt(item));
  console.log(disassembleSum(...inputs));
  rl.close();
}).on('close', () => {
  process.exit();
});

function disassembleSum(n, k) {
  const countTable = Array.from({length: n + 1}, () => Array.from({length: k + 1}, (_, index) => ((index === 1) ? 1 : 0)));

  for (let i = 2; i <= k; i++) {
    for (let j = 1; j <= n; j++) {
      if (j === 1) {
        countTable[j][i] = (countTable[j][i - 1] + 1) % 1000000000;
      } else {
        countTable[j][i] = (countTable[j][i - 1] + countTable[j - 1][i]) % 1000000000;
      }
    }
  }

  return countTable[n][k];
}
