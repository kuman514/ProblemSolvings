// Solving BOJ 9934

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let depth = null;
let fullBinaryTree = null;
let infixOrder = null;
let infixIndex = 0;

rl.on('line', (line) => {
  if (depth === null) {
    depth = parseInt(line);
    fullBinaryTree = Array.from({length: 2 ** depth}, () => 0);
  } else {
    infixOrder = line.split(' ').map((item) => parseInt(item));
    visitBuildings(1);
    let result = '';
    let currentDepth = 1;
    let nextDepthStart = 2 ** currentDepth;
    for (let i = 1; i < fullBinaryTree.length; i++) {
      if (i === nextDepthStart) {
        result += '\n';
        currentDepth++;
        nextDepthStart *= 2;
      }

      if (i + 1 === nextDepthStart) {
        result += `${fullBinaryTree[i]}`;
      } else {
        result += `${fullBinaryTree[i]} `;
      }
    }
    console.log(result);
    rl.close();
  }
}).on('close', () => {
  process.exit();
});

function visitBuildings(currentIndex) {
  const isLeaf = (currentIndex * 2 >= fullBinaryTree.length);
  !isLeaf && visitBuildings(currentIndex * 2);
  fullBinaryTree[currentIndex] = infixOrder[infixIndex];
  infixIndex++;
  !isLeaf && visitBuildings(currentIndex * 2 + 1);
}
