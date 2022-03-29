// Solving BOJ 23746

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n = null;
const compressInfo = new Map();
let decompressed = null;

rl.on('line', (line) => {
  if (n === null) {
    n = parseInt(line);
  } else if (compressInfo.size < n) {
    const [val, key] = line.split(' ');
    compressInfo.set(key, val);
  } else if (decompressed === null) {
    decompressed = decompress(line);
  } else {
    const [start, end] = line.split(' ').map((item) => (parseInt(item) - 1));
    console.log(decompressed.slice(start, end + 1));
    rl.close();
  }
}).on('close', () => {
  process.exit();
});

function decompress(compressed) {
  let result = '';
  for (let i = 0; i < compressed.length; i++) {
    result += compressInfo.get(compressed[i]);
  }
  return result;
}
