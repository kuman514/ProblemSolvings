// Solving BOJ 20291

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n = null;
let i = 0;
const extensions = new Map();

rl.on('line', (line) => {
    if (n === null) {
        n = parseInt(line);
        return;
    } else if (i < n) {
        const [_, extension] = line.split('.');
        
        if (extensions.has(extension)) {
            extensions.set(extension, extensions.get(extension) + 1);
        } else {
            extensions.set(extension, 1);
        }
        
        i++;
        if (i === n) {
            let finalValue = '';
            const keys = [...extensions.keys()];
            keys.sort();
            keys.forEach((key) => {
                finalValue += `${key} ${extensions.get(key)}\n`;
            });
            console.log(finalValue);
            rl.close();
            return;
        }
    }
}).on('close', () => {
  process.exit();
});
