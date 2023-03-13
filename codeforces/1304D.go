package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func CF1304D(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var t int		
	for Fscan(in, &t); t > 0; t-- {
		var n int
		var s string
		Fscan(in, &n, &s)

		ans := make([]int, n)
		up := n		
		// put max elements from the front inside >>>
		for i := range s {
			if s[i] == '>' {
				ans[i] = up
				up--
			}
		}

		// put smallest elements from the end to front <<<
		down := 1
		for i := n - 1; i >= 0; i-- {
			if ans[i] > 0 {
				continue
			}
			end := i
			for ; i >= 0 && ans[i] == 0; i-- {}
			i++ // find the first place not used

			for j := i; j <= end; j++ {
				ans[j] = down
				down++
			}
		}
		
		for _, v := range ans {
			Fprint(out, v, " ")
		}
		Fprintln(out)

		ans = make([]int, n)
		up = n
		// place big numbers closer place to the end
		for i := len(s) - 1; i >= 0; i-- {
			if s[i] == '<' {
				ans[i + 1] = up
				up--
			}
		}

		down = 1
		// put smaller number from front to end, > places
		for i := 0; i < n; i++ {
			if ans[i] > 0 {
				continue
			}
			end := i
			for ; i < n && ans[i] == 0; i++ { }
			i--
			for j := i; j >= end; j-- {
				ans[j] = down
				down++
			}
		}

		for _, v := range ans {
			Fprint(out, v, " ")
		}
		Fprintln(out)
	}

}

func main() { CF1304D(os.Stdin, os.Stdout) }
