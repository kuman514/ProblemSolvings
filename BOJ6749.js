// Solving BOJ 6749

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let youngest = null;
let middle = null;

rl.on('line', (line) => {
  if (youngest === null) {
    youngest = parseInt(line);
  } else if (middle === null) {
    middle = parseInt(line);

    const oldest = middle + (middle - youngest);
    console.log(oldest);

    rl.close();
  }
}).on('close', () => {
  process.exit();
});
