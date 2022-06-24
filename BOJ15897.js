// Solving BOJ 15897

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  console.log(harmonicLemmaValue(parseInt(line)));
  rl.close();
}).on('close', () => {
  process.exit();
});

function harmonicLemmaValue(n) {
  /*
    The number of numbers that equlas to FLOOR(n / x) * f(x)
    = j - i + 1 (where i <= x <= j)

    The maximum j that meets FLOOR(n / i) = FLOOR(n / j)
    = FLOOR(n / FLOOR(n / i))

    In BOJ 15897, f(x) = 1 + FLOOR((n - 1) / x), in range of 1 <= x <= (n - 1)
    (Because j start at 1 not 0)
    That means we will get (1 + FLOOR((n - 1) / x)) * (j - i + 1)
  */
  let result = 0;
  let i = 1;
  let maximumJ = 0;
  while (i < n) {
    maximumJ = Math.floor((n - 1) / Math.floor((n - 1) / i));
    result += ((1 + Math.floor((n - 1) / i)) * (maximumJ - i + 1));
    i = maximumJ + 1;
  }
  result++;
  return result;
}
