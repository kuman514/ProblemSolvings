// Solving BOJ 1068

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const childNodes = [];
const data = {
  root: null,
  nodesInput: false,
  leaves: 0
};

rl.on('line', (line) => {
  if (childNodes.length === 0) {
    const n = parseInt(line);
    for (let i = 0; i < n; i++) {
      childNodes.push(new Set());
    }
  } else if (!data.nodesInput) {
    const inputs = line.split(' ').map((item) => parseInt(item));
    inputs.forEach((parent, current) => {
      if (parent === -1) {
        data.root = current;
      } else {
        childNodes[parent].add(current);
      }
    });
    data.nodesInput = true;
  } else {
    const erased = parseInt(line);
    childNodes[erased] = null;
    countLeaves(data.root);
    console.log(data.leaves);
    rl.close();
  }
}).on('close', () => {
  process.exit();
});

function countLeaves(node) {
  if (childNodes[node] === null) {
    return;
  }

  let isLeaf = true;
  for (const child of childNodes[node]) {
    if (childNodes[child] !== null) {
      isLeaf = false;
      countLeaves(child);
    }
  }

  if (isLeaf) {
    data.leaves++;
  }
}
