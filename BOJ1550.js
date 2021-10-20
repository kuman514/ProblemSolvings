// Solving BOJ 1550

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const values = new Map([
  ['0', 0],
  ['1', 1],
  ['2', 2],
  ['3', 3],
  ['4', 4],
  ['5', 5],
  ['6', 6],
  ['7', 7],
  ['8', 8],
  ['9', 9],
  ['A', 10],
  ['B', 11],
  ['C', 12],
  ['D', 13],
  ['E', 14],
  ['F', 15],
]);

rl.on('line', (line) => {
  let result = 0;
  let pow = 0;
  for (let i = line.length - 1; i >= 0; i--) {
    result += (values.get(line[i]) * (16 ** pow));
    pow++;
  }
  console.log(result);
  rl.close();
}).on('close', () => {
  process.exit();
});
