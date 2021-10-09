### tasktree CLI tool

Make a todo list where each element is a child of something. When all children for a given node are marked as completed, that node gets popped! Simple as that.

This is the original C++ version, where it more-or-less served as a coding exercise.I have *designs* for a newer vesion with a better encoding scheme (and a whole host of other features). The plan is to make a simple frontend so users can run this in a browser and use it as a todo list. Then put it up on my [website](bokehbox.us).

Watch out for incremental progress, but be warned, my personal projects generally have to take a backseat...

### misc

However flawed this implementation is, I still really like this idea for some reason... if you want to collaborate please [let me know!](mailto:gkweston@tamu.edu)

### current output example
```
 Build				        ()
  ├╴UI design 			    (a)
  │  ├╴dynamic window 		(aa)
  │  └╴different pages 		(ab)
  ├╴Frontend Implementation	(b)
  │  ├╴HTML			        (ba)
  │  │  └╴task ex		    (baa)
  │  ├╴CSS			        (bb)
  │  └╴JS Animations		(bc)
  └╴Backend			        (c)
     ├╴database			    (ca)
     └╴lambdas			    (cb)
```