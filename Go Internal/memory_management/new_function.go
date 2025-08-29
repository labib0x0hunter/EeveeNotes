package main

import "fmt"

func EscapeToHeap() {
	n := new(int)
	fmt.Println(n)
}

func NoEscapeToHeap() {
	m := new(int)
	_ = m
}

func main() {

	EscapeToHeap()
	NoEscapeToHeap()
}
