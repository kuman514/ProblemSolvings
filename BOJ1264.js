// Solving BOJ 1264

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  if (line === '#') {
      rl.close();
      return;
  }

  let count = 0;
  for (let i = 0; i < line.length; i++) {
    switch (line[i]) {
      case 'a': case 'e': case 'i': case 'o': case 'u':
      case 'A': case 'E': case 'I': case 'O': case 'U':
        count++;
        break;
    }
  }
  console.log(count);
}).on('close', () => {
  process.exit();
});
