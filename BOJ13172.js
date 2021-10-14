// Solving BOJ 13172

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const moduloValue = 1000000007n;
const moduloXMinus2 = moduloValue - 2n;
const moduloBitVal = [];

(function () {
  let curVal = BigInt(moduloXMinus2);
  while (curVal > 0n) {
    moduloBitVal.push(curVal % 2n === 1n);
    curVal /= 2n;
  }
})();

let n = null;
let cnt = 0;
let result = 0n;

rl.on('line', (line) => {
  if (n === null) {
    n = parseInt(line);
  } else {
    const [rawB, rawA] = line.split(' ').map((item) => BigInt(item));
    const rawGcd = gcd(rawB, rawA);
    result += getExpectedModValue(rawA / rawGcd, rawB / rawGcd);
    result %= moduloValue;

    cnt++;
    if (cnt === n) {
      console.log(`${result}`);
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});

function getExpectedModValue(a, b) {
  const sqValues = [b];
  for (let i = 1; i < moduloBitVal.length; i++) {
    sqValues.push((sqValues[i - 1] * sqValues[i - 1]) % moduloValue);
  }

  // Get B**1000000005 since B**1000000005 ≡ B**(-1)
  let result = 1n;
  for (let i = 0; i < moduloBitVal.length; i++) {
    if (moduloBitVal[i]) {
      result *= sqValues[i];
      result %= moduloValue;
    }
  }

  // Return (A * B**1000000005) % 1000000007
  const finalResult = (a * result) % moduloValue;

  return finalResult;
}

function gcd(minNum, maxNum) {
  if (maxNum % minNum === 0n) {
    return minNum;
  } else {
    return gcd(maxNum % minNum, minNum);
  }
}
