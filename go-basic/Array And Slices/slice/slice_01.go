package main

import "fmt"

func main() {
	arr := [5]int{1, 2, 3, 4, 5}
	s1 := arr[1:3]
	s2 := arr[2:5]

	s1[1] = 99
	fmt.Println("s1:", s1)
	fmt.Println("s2:", s2)
	fmt.Println("arr:", arr)
}
