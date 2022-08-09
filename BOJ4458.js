// Solving BOJ 4458

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n = null;
let cur = 0;

rl.on('line', line => {
  if (n === null) {
    n = parseInt(line);
  } else {
    console.log(line[0].toUpperCase() + line.slice(1));
    cur++;
    if (cur === n) {
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});
