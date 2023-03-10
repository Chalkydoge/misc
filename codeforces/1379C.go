package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"sort"
)

func CF1379C(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	type pair struct { a, b int }
	var t int	
	
	for Fscan(in, &t); t > 0; t-- {
		var n, m int
		Fscan(in, &n, &m)

		f := make([]pair, m) 
		a := make([]int, m)

		for i := range f {
			Fscan(in, &f[i].a, &f[i].b)
			a[i] = f[i].a
		}

		sort.Slice(f, func(i, j int) bool {
			x, y := f[i], f[j]
			if x.b == y.b {
				return x.a > y.a
			} else {
				return x.b > y.b
			}
		})
		sort.Ints(a)

		ans := int64(0)
		i, sa := m - 1, int64(0)

		// sort f in order of 'b', reversed
		for _, p := range f {
			// a[i] > b[i], these a will only pick once
			for ; n > 0 && i >= 0 && a[i] >= p.b; i-- {
				sa += int64(a[i])
				n--
			}

			nn, s := n, sa
			if nn > 0 {
				if p.a < p.b {
					s += int64(p.a)
					nn--
				}
				s += int64(nn) * int64(p.b)
			}
			
			if s > ans {
				ans = s
			}
		}

		Fprintln(out, ans)
	}
}

func main() { CF1379C(os.Stdin, os.Stdout) }