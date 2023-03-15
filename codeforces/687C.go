package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func CF687C(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, k int
	Fscan(in, &n, &k)

	c := make([]int, n)
	for i := 0; i < n; i++ {
		Fscan(in, &c[i])
	}

	/*
		f[i][j1][j2]: previous i numbers, ok to get |S1| = j1, |S2| = j2
	*/
	f := make([][]bool, k + 1)
	for i := 0; i <= k; i++ { f[i] = make([]bool, k + 1) }
	f[0][0] = true

	for i := 0; i < n; i++ {
		for j1 := k; j1 >= 0; j1-- {
			// trans from [j1]
			// fix j1, trans from j2
			for j2 := k; j2 >= 0; j2-- {
				f[j1][j2] = f[j1][j2] || (j1 >= c[i] && f[j1 - c[i]][j2]) || (j2 >= c[i] && f[j1][j2 - c[i]])
			}
		}
	}

	ans := []int{}
	tot := 0
	for x := 0; x <= k; x++ {
		if f[x][k - x] {
			ans = append(ans, x)
			tot++
		}
	}

	Fprintln(out, tot)
	for _, v := range ans {
		Fprint(out, v, " ")
	}
	Fprintln(out)
}

func main() { CF687C(os.Stdin, os.Stdout) }