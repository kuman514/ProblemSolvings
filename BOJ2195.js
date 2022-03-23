// Solving BOJ 2195

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const get = [];

rl.on('line', (line) => {
  get.push(line);
  if (get.length === 2) {
    const [s, p] = get;
    const words = new Set();

    for (let i = 0; i < s.length; i++) {
      for (let j = i + 1; j <= s.length; j++) {
        words.add(s.slice(i, j));
      }
    }

    let i = 0;
    let result = 0;
    while (i < p.length) {
      const start = i;
      while (i < p.length && words.has(p.slice(start, i + 1))) {
        i++;
      }
      result++;
    }

    console.log(result);

    rl.close();
  }
}).on('close', () => {
  process.exit();
});
