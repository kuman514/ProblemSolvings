// Solving BOJ 25640

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let jinhoMbti = null;
let n = null;
let i = 0;
let result = 0;

rl.on('line', (line) => {
  if (jinhoMbti === null) {
    jinhoMbti = line;
  } else if (n === null) {
    n = parseInt(line);
  } else if (i < n) {
    if (jinhoMbti === line) {
      result++;
    }

    i++;
    if (i === n) {
      console.log(result);
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});
