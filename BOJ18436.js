// Testing my segment tree using BOJ 18436

class SegmentTree {
  constructor(arr, initVal, processFunc) {
    this.arr = Array.from(arr);
    this.tree = Array.from(
      { length: 2 ** Math.ceil(Math.log2(this.arr.length) + 1) },
      () => initVal
    );

    this.initTree = (nodeNum, start, end) => {
      if (start == end) {
        this.tree[nodeNum] = this.arr[start];
      } else {
        this.tree[nodeNum] = processFunc(
          this.initTree(2 * nodeNum, start, Math.floor((start + end) / 2)),
          this.initTree(2 * nodeNum + 1, Math.floor((start + end) / 2) + 1, end)
        );
      }
      
      return this.tree[nodeNum];
    };

    this.getAreaVal = (nodeNum, start, end, areaLeft, areaRight) => {
      if (areaLeft > end || areaRight < start) {
        return initVal;
      } else if (areaLeft <= start && end <= areaRight) {
        return this.tree[nodeNum];
      } else {
        return processFunc(
          this.getAreaVal(2 * nodeNum, start, Math.floor((start + end) / 2), areaLeft, areaRight),
          this.getAreaVal(2 * nodeNum + 1, Math.floor((start + end) / 2) + 1, end, areaLeft, areaRight)
        );
      }
    };
    
    this.updateTree = (nodeNum, start, end, index, diff) => {
      if (index < start || index > end) {
        return;
      }

      this.tree[nodeNum] += diff;
      if (start !== end) {
        this.updateTree(2 * nodeNum, start, Math.floor((start + end) / 2), index, diff);
        this.updateTree(2 * nodeNum + 1, Math.floor((start + end) / 2) + 1, end, index, diff);
      }
    };

    this.areaVal = (start, end) => {
      return this.getAreaVal(1, 0, this.arr.length - 1, start - 1, end - 1);
    };

    this.update = (index, val) => {
      const diff = val - this.arr[index - 1];
      this.updateTree(1, 0, this.arr.length - 1, index - 1, diff);
      this.arr[index - 1] = val;
    };

    this.initTree(1, 0, this.arr.length - 1);
  }
}

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n = null;
let m = null;
let commands = 0;

let oddTree = null;
let evenTree = null;

let result = '';

rl.on('line', (line) => {
  if (n === null) {
    n = parseInt(line);
  } else if (oddTree === null && evenTree === null) {
    oddTree = new SegmentTree(line.split(' ').map((item) => (parseInt(item) % 2 === 1 ? 1 : 0)), 0, (left, right) => {
      return left + right;
    });
    evenTree = new SegmentTree(line.split(' ').map((item) => (parseInt(item) % 2 === 0 ? 1 : 0)), 0, (left, right) => {
      return left + right;
    });
  } else if (m === null) {
    m = parseInt(line);
  } else {
    const [a, b, c] = line.split(' ').map((item) => parseInt(item));
    switch (a) {
      case 1:
        oddTree.update(b, (c % 2 === 1 ? 1 : 0));
        evenTree.update(b, (c % 2 === 0 ? 1 : 0));
        break;
      case 2:
        result += `${evenTree.areaVal(b, c)}\n`;
        break;
      case 3:
        result += `${oddTree.areaVal(b, c)}\n`;
        break;
    }
    commands++;
    if (commands === m) {
      console.log(result);
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});
