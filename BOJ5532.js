// Solving BOJ 5532

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let [l, a, b, c, d] = [null, null, null, null, null];

rl.on('line', (line) => {
  if (l === null) {
    l = parseInt(line);
  } else if (a === null) {
    a = parseInt(line);
  } else if (b === null) {
    b = parseInt(line);
  } else if (c === null) {
    c = parseInt(line);
  } else if (d === null) {
    d = parseInt(line);

    console.log(l - Math.max(Math.ceil(a / c), Math.ceil(b / d)));

    rl.close();
  }
}).on('close', () => {
  process.exit();
});
