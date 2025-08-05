
package main

import (
  "fmt"
  "strconv"
  "strings"
  "time"
  "math/rand"
  "os"
)

func to_int (val string) int {
  new_int, err := strconv.Atoi(val)
  if err != nil {
    panic(err)
  }
  return new_int
}

func roll (dice string) int {
  total := 0
  split := strings.Split(dice, "d")
  amount := split[0]
  die := split[1]

  idie := to_int(die)
  iamount := to_int(amount)
  rand.Seed(time.Now().UnixNano())
  for i := 0; i < iamount; i ++ {
    total += rand.Intn(idie) + 1
  }

  return total
}

func main () {
  if len(os.Args) != 2 {
    fmt.Println("you need to provide  your dice and amount")
    fmt.Println("For example: 2d4 or 1d20")
    os.Exit(0)
  }
  start0 := time.Now()
  res := roll(os.Args[1])
  fmt.Printf(" Go Lang : %d ms, res : %d \n ", time.Since(start0).Milliseconds() , res )
}

