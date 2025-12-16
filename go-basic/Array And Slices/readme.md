# Array And Slice
---

---
# Slice Operations
- make()
- append()
- len(), cap()
- copy()
- Slicing [:]

---
# Notes
- Array has fixed size, Slice is just a piece of an array (we call it dynamic array).
- This `a1` is array of zero length and capacity.
```go
a1 := [...]int{}  // same as [0]int
a2 := [...]int{1, 2, 3} // same as [3]int{1, 2, 3}, Then why it is used ?
```
- 2D array
```go
var x [n][m]int
```
---

# Quiz
This quizs are from ChatGPT. I will try to add more real interview quizs.

```text
Q1. Array vs Slice
    - List three fundamental differences that affects performance or behaviour.
Q2. Memory Model
    - What does a slice header contain?
    - Where is the underlying array allocated?
Q3. Value vs Reference Semantics
    - When you pass a slice to a function, what is copied?
    - What happens if the function appends beyond capacity?
Q4. Why can append be O(1) sometimes and O(n) other times?
Q5. How does Go decide when to allocate a new underlying array during append?
Q6. How can you force append not to modify the original slice’s underlying array?
```

```text
Q. What is the output ?
    s := []int{1, 2, 3}
    t := s
    t[0] = 100
    fmt.Println(s)
```

```text
Q. What is the output and explain what is happening.
    s := make([]int, 0, 2)
    s = append(s, 1)
    s = append(s, 2)
    t := append(s, 3)

    fmt.Println(s, t)
```

```text
Q. What is the output ?
    s := []int{1, 2, 3, 4}
    a := s[1:3]
    a[0] = 100
    fmt.Println(s)
```

```text
Q. What is wrong here? How do you fix it without global variables?
    func modify(s []int) {
        s = append(s, 10)
    }

    func main() {
        s := []int{1, 2, 3}
        modify(s)
        fmt.Println(s)
    }
```

```text
Q. What is the output ?
```


```text
Q. What is the output ?
```

```text
Q. What is the output ?
```

```text
Q. What is the output ?
```

```text
Q. What is the output ?
```

```text
Q. What is the output ?
```

```text
Q. What is the output ?
```

```text
Q. What is the output ?
```

---