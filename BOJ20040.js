// Solving BOJ 20040

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const parent = Array.from({length: 500000}, (_, index) => index);

let n = null;
let m = null;

let turn = 0;
let result = 0;

rl.on('line', (line) => {
  if (n === null && m === null) {
    [n, m] = line.split(' ').map((item) => parseInt(item));
  } else {
    turn++;
    const [org, dst] = line.split(' ').map((item) => parseInt(item));

    if (isCycle(org, dst)) {
      result = turn;
      rl.close();
    } else {
      addUnion(org, dst);
      if (turn >= m) {
        rl.close();
      }
    }
  }
}).on('close', () => {
  console.log(result);
  process.exit();
});

// Using union find

function findParent(cur) {
  if (cur === parent[cur]) {
    return cur;
  } else {
    // Update it's parent if not updated yet
    parent[cur] = findParent(parent[cur]);
    return parent[cur];
  }
}

function addUnion(org, dst) {
  const [start, end] = (org <= dst) ? [org, dst] : [dst, org];
  const [spr, sub] = [findParent(start), findParent(end)];
  parent[sub] = spr;
}

function isCycle(org, dst) {
  const [start, end] = (org <= dst) ? [org, dst] : [dst, org];
  const [startParent, endParent] = [findParent(start), findParent(end)];

  // If START and END already have the same parent, this is a cycle.
  return (startParent === endParent);
}
