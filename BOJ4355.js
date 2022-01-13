// Solving BOJ 4355
// Without using hardcoding

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const result = [];

rl.on('line', (line) => {
  const n = parseInt(line);
  if (n === 0) {
    let finalResult = '';
    for (let i = 0; i < result.length; i++) {
      if (i === result.length - 1) {
        finalResult += `${result[i]}`;
      } else {
        finalResult += `${result[i]}\n`;
      }
    }
    console.log(finalResult);
    rl.close();
  } else {
    result.push(getEulerPhiValue(n));
  }
}).on('close', () => {
  process.exit();
});

function getEulerPhiValue(n) {
  // If n is prime, phi(n) = n - 1
  // phi(m * n) = phi(m) * phi(n) (m and n are coprime)
  // phi(n ** k) = {n ** (k - 1)} * (n - 1)
  // phi((n ** k) * r) = {n ** (k - 1)} * (n - 1) * phi(r) (r and n are coprime)

  // Is n === 1?
  if (n === 1) {
    return 1;
  }

  // Is n prime?
  if (isPrime(n)) {
    return (n - 1);
  }

  // Get phi values
  const range = Math.sqrt(n);
  for (let i = 2; i <= range; i++) {
    if (n % i === 0) {
      let result = i - 1;
      let tmp = Math.floor(n / i);
      while (tmp % i === 0) {
        result *= i;
        tmp = Math.floor(tmp / i);
      }
      return result * getEulerPhiValue(tmp);
    }
  }
}

function isPrime(n) {
  const range = Math.sqrt(n);
  for (let i = 2; i <= range; i++) {
    if (n % i === 0) {
      return false;
    }
  }
  return true;
}
