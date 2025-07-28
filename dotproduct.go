
package main

import ("fmt")
import ("math/rand")
import ("time")
import ("runtime")
const LEN = 10000000

func main() {
  // memUsage()
  fmt.Printf(" go dotProduct array size :  %d \n", LEN )
  
  start0 := time.Now()
  arr := [LEN] float64 {}
  brr := [LEN] float64 {}
  for i := 0; i < LEN; i ++ {
    arr[i] = rand.Float64()
    brr[i] = rand.Float64()
  }
  fmt.Printf(" go 2 arrays init  takes  %d ms\n", time.Since(start0).Milliseconds() )
  // memUsage()

  start := time.Now()
  dotProduct (arr, brr)
  fmt.Printf(" go dotProduct takes  %d ms, total : %d ms\n", 
    time.Since(start).Milliseconds(), time.Since(start0).Milliseconds() )
  
  // memUsage()
}

func dotProduct (arr, brr [LEN] float64 ) float64 {
  result := 0.0
  for i := 0; i < LEN; i ++ {
    result += arr[i] * brr[i]
  }
  return result
}

func memUsage () {
  
  var m runtime.MemStats
  runtime.ReadMemStats(&m)

  fmt.Printf("Allocated memory: %v bytes\n", m.Alloc)
  fmt.Printf("Total allocated memory (cumulative): %v bytes\n", m.TotalAlloc)
  fmt.Printf("Memory obtained from system: %v bytes\n", m.Sys)
  fmt.Printf("Number of garbage collections: %v\n", m.NumGC)
}
