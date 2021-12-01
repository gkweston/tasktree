### tasktree CLI tool

Make a todo list where each element is a child of something. When all children for a given node are marked as completed, that node gets popped! Simple as that.

This is the original C++ version, where it more-or-less served as a coding exercise. To see the react version which supports some functionallity (and has fun animations) checkout `react-fronted`.

### current output example
```
 Build				()
  ├╴UI design 			(a)
  │  ├╴dynamic window 		(aa)
  │  └╴different pages 		(ab)
  ├╴Frontend Implementation	(b)
  │  ├╴HTML			(ba)
  │  │  └╴task ex		(baa)
  │  ├╴CSS			(bb)
  │  └╴JS Animations		(bc)
  └╴Backend			(c)
     ├╴database			(ca)
     └╴lambdas			(cb)
```