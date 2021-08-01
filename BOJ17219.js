// Solving BOJ 17219

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let sites = null;
let searches = null;

let curSiteLines = 0;
let curSearchLines = 0;

let memos = new Map();
let result = '';

rl.on('line', (line) => {
  if (sites === null && searches === null) {
    [sites, searches] = line.split(' ').map((item) => Number(item));
  } else if (curSiteLines < sites) {
    const [url, password] = line.split(' ');
    memos.set(url, password);
    curSiteLines++;
  } else {
    result += `${memos.get(line)}\n`;
    curSearchLines++;
    if (curSearchLines === searches) {
      console.log(result);
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});
