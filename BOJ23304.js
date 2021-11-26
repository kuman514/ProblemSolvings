// Solving BOJ 23304

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
  console.log(isAkarakaPalin(line) ? 'AKARAKA' : 'IPSELENTI');
  rl.close();
}).on('close', () => {
  process.exit();
});

function isAkarakaPalin(str) {
  if (str.length === 1) {
    return true;
  }

  const limit = Math.floor(str.length / 2);
  const end = str.length - 1;

  for (let i = 0; i < limit; i++) {
    if (str[i] !== str[end - i]) {
      return false;
    }
  }

  if (str.length % 2 === 0) {
    return isAkarakaPalin(str.slice(0, limit)) && isAkarakaPalin(str.slice(limit));
  } else {
    return isAkarakaPalin(str.slice(0, limit)) && isAkarakaPalin(str.slice(limit + 1));
  }
}
