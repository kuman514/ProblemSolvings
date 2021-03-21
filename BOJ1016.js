// Solving BOJ 1016

const readLine = require('readline')
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
})

rl.on('line', line => {
  const get = line.split(' ').map(item => parseInt(item))
  console.log(notSquareInteger(get[0], get[1]))
  rl.close()
}).on('close', () => {
  process.exit()
})

function notSquareInteger (min, max) {
  let result = 0
  let isNotSquare = Array.from({length: max - min + 1}, () => true)
  
  // false if the number is divided by square
  const range = Math.sqrt(max)
  for (let i = 2; i <= range; i++) {
    let isq = i * i
    let index = isq * Math.ceil(min / isq)
    while (index <= max) {
      isNotSquare[index - min] = false
      index += isq
    }
  }

  for (let i = 0; i < isNotSquare.length; i++) {
    if (isNotSquare[i]) {
      result++
    }
  }

  return result
}
