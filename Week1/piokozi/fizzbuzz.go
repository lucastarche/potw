package main

import (
	"fmt"
)

type rule struct {
	divisor   int
	newstring string
}

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	rules := make([]rule, m) // make a slice of type rule and length m
	for i := range rules {
		var div int
		var str string
		fmt.Scanf("%d %s", &div, &str)
		rules[i].divisor = div
		rules[i].newstring = str
	}
	for i := 1; i <= n; i++ {
		var output string
		for _, v := range rules {
			if i%v.divisor == 0 {
				output += v.newstring
			}
		}
		if len(output) == 0 {
			fmt.Println(i)
		} else {
			fmt.Println(output)
		}
	} 
