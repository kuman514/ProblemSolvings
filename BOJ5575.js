// Solving BOJ 5575

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const totalTime = [];

rl.on('line', (line) => {
  if (totalTime.length < 3) {
    const [h1, m1, s1, h2, m2, s2] = line.split(' ').map((item) => parseInt(item));
    const [sec1, sec2] = [
      h1 * 3600 + m1 * 60 + s1,
      h2 * 3600 + m2 * 60 + s2
    ];
    const totalSeconds = sec2 - sec1;
    totalTime.push([
      Math.floor(totalSeconds / 3600),
      Math.floor((totalSeconds % 3600) / 60),
      totalSeconds % 60
    ]);

    if (totalTime.length === 3) {
      let result = '';
      for (let i = 0; i < totalTime.length; i++) {
        result += `${totalTime[i][0]} ${totalTime[i][1]} ${totalTime[i][2]}\n`;
      }
      console.log(result);
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});
