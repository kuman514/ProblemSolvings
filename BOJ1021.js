// Solving BOJ 1021

const readLine = require('readline')
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
})

let n = 0
let queue = []
let count = 0

rl.on('line', line => {
  if (n === 0) {
    const get = line.split(' ').map(item => parseInt(item))
    n = get[0]
    for (let i = 1; i <= n; i++) {
      queue.push(i)
    }
  } else {
    const get = line.split(' ').map(item => parseInt(item))
    extractQueue(get)
    console.log(count)
    rl.close()
  }
}).on('close', () => {
  process.exit()
})

function extractQueue (targets) {
  for (let item of targets) {
    for (let i in queue) {
      if (queue[i] === item) {
        if (i <= queue.length / 2) {
          for (let j = 0; j < i; j++) {
            const tmp = queue.shift()
            queue.push(tmp)
            count++
          }
          queue.shift()
        } else {
          const range = queue.length - i
          for (let j = 0; j < range; j++) {
            const tmp = queue.pop()
            queue.splice(0, 0, tmp)
            count++
          }
          queue.shift()
        }
        break
      }
    }
  }
}
