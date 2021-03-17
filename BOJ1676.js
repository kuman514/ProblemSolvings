// Solving BOJ 1676

const readLine = require('readline')
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
})

// Get prime factorization amount of 2 and 5
let factorial2and5 = [[0, 0]]
for (let i = 1; i <= 500; i++) {
  factorial2and5.push([
    factorial2and5[i - 1][0] + getFactorAmount(2, i),
    factorial2and5[i - 1][1] + getFactorAmount(5, i)
  ])
}

rl.on('line', line => {
  const result = getResult(factorial2and5[parseInt(line)])
  console.log(result)
  rl.close()
}).on('close', () => {
  process.exit()
})

function getFactorAmount (prime, num) {
  let remain = num
  let result = 0
  
  while (remain > 1) {
    if (remain % prime === 0) {
      remain = Math.floor(remain / prime)
      result++
    } else {
      break
    }
  }
  
  return result
}

function getResult (amount) {
  return Math.min(amount[0], amount[1])
}
