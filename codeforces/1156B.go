package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"strings"
)

func CF1156B(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var t int		
	for Fscan(in, &t); t > 0; t-- {
		var s string
		Fscan(in, &s)
		
		h := make([]int, 26)
		for _, c := range s {
			d := int(c) - int('a')
			h[d]++
		}

		occur := make([]int, 0)
		for i := 0; i < 26; i++ {
			if h[i] > 0 {
				occur = append(occur, i)
			}
		}

		if len(occur) == 1 {
			Fprintln(out, s)
		} else {
			// occurrance of each charcter
			if len(occur) >= 4 {
				for i := 1; i < len(occur); i += 2 {
					Fprint(out, strings.Repeat(string(int('a') + occur[i]), h[occur[i]]) )
				}
				for i := 0; i < len(occur); i += 2 {
					Fprint(out, strings.Repeat(string(int('a') + occur[i]), h[occur[i]]) )
				}
				Fprintln(out)
			} else {
				// kinds = 2, 3
				if occur[len(occur) - 1] == occur[0] + len(occur) - 1 {
					Fprintln(out, "No answer")
				} else {
					// x, x+1, z
					if occur[1] == occur[0] + 1 {
						// x, z, x+1
						Fprint(out, strings.Repeat(string(int('a') + occur[0]), h[occur[0]]) )
						Fprint(out, strings.Repeat(string(int('a') + occur[2]), h[occur[2]]) )
						Fprint(out, strings.Repeat(string(int('a') + occur[1]), h[occur[1]]) )
					} else {
						// x, z-1, z
						// z-1,x, z
						Fprint(out, strings.Repeat(string(int('a') + occur[1]), h[occur[1]]) )
						Fprint(out, strings.Repeat(string(int('a') + occur[0]), h[occur[0]]) )
						if len(occur) > 2 {
							Fprint(out, strings.Repeat(string(int('a') + occur[2]), h[occur[2]]) )
						}
					}
					Fprintln(out)
				}
			}
		}
	}

}

func main() { CF1156B(os.Stdin, os.Stdout) }