// Solving BOJ 9588

// Make a collection of primes
let primes = new Set()
for (let i = 2; i < 1000000; i++) {
  let notPrime = false
  let limit = Math.sqrt(i)

  for (let j = 2; j <= limit; j++) {
    if (i % j === 0) {
      notPrime = true
      break
    }
  }

  if (!notPrime) {
    primes.add(i)
  }
}

// Get readline module
const readLine = require('readline')
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
})

rl.on('line', line => {
  // Get input
  let input = parseInt(line)
  if (input === 0) {
    rl.close()
  } else {
    console.log(goldbach(input))
  }
}).on('close', () => {
  process.exit()
})

function goldbach (target) {
  for (let current of primes.values()) {
    if (target < current) {
      break
    } else {
      if (primes.has(target - current)) {
        return `${target} = ${current} + ${target - current}`
      }
    }
  }
  return 'Goldbach\'s conjecture is wrong.'
}
