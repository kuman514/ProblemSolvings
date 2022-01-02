// Solving BOJ 1990
// Without using hardcoding

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const palinPrimeArray = [];
for (let n = 5; n < 10000000; n++) {
  // Check palindrome
  let isPalin = true;
  const strNum = String(n);
  for (let i = 0; i < strNum.length / 2 && isPalin; i++) {
    if (strNum[i] !== strNum[strNum.length - 1 - i]) {
      isPalin = false;
    }
  }
  if (!isPalin) {
    continue;
  }

  // Check prime
  const range = Math.sqrt(n);
  let isPrime = true;
  for (let i = 2; i <= range && isPrime; i++) {
    if (n % i === 0) {
      isPrime = false;
    }
  }
  if (!isPrime) {
    continue;
  }

  // Add this palindrome prime number
  palinPrimeArray.push(n);
}

rl.on('line', (line) => {
  const [a, b] = line.split(' ').map((item) => {
    return parseInt(item);
  });
  console.log(paintPalinPrimes(a, b));
  rl.close();
}).on('close', () => {
  process.exit();
});

function paintPalinPrimes(a, b) {
  const rangedResult = palinPrimeArray.filter((item) => {
    return (a <= item && item <= b);
  });

  let result = '';
  for (let i = 0; i < rangedResult.length; i++) {
    result += `${rangedResult[i]}\n`;
  }

  result += '-1';

  return result;
}
