package main

import "fmt"

func main() {
	s := []int{}
	for i := 0; i < 5; i++ {
		s = append(s, i)
		fmt.Println(len(s), cap(s))
	}
}
