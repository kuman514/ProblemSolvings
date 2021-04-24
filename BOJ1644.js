// Solving BOJ 1644

// Get readline module
const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Get input
rl.on('line', line => {
  const result = getCountOfPrimeSum(Number(line));
  console.log(result);
  rl.close();
}).on('close', () => {
  process.exit();
});

function getCountOfPrimeSum(num) {
  // Make a collection of primes
  let primes = [];
  for (let i = 2; i <= num; i++) {
    const range = Math.sqrt(i);
    let isPrime = true;

    for (let j = 2; j <= range; j++) {
      if (i % j === 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) {
      primes.push(i);
    }
  }

  // Two pointer solution
  let count = 0;
  let tmpsum = 0;
  let left = 0;
  let right = 0;

  while (right < primes.length || left < right) {
    if (tmpsum >= num) {
      if (tmpsum === num) {
        count++;
      }
      tmpsum -= primes[left];
      left++;
    } else {
      if (right >= primes.length) {
        tmpsum -= primes[left];
        left++;
      } else {
        right++;
        tmpsum += primes[right - 1];
      }
    }
  }

  return count;
}