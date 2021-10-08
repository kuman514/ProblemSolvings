// Solving BOJ 2845

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let density = null;
let size = null;
const article = [];

rl.on('line', (line) => {
  if (density === null && size === null) {
    [density, size] = line.split(' ').map((item) => parseInt(item));
  } else {
    article.push(...(line.split(' ').map((item) => parseInt(item))));

    const total = density * size;
    const diff = [];

    article.forEach((result) => {
      diff.push(result - total);
    });

    console.log(diff.join(' '));
    rl.close();
  }
}).on('close', () => {
  process.exit();
});
