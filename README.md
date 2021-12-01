### So you want a cool todo list?

Make a todo list where each element is a child of something. When all children for a given node are marked as completed, that node gets popped! Simple as that.

This contains the original C++ version, where it more-or-less served as a coding exercise. I've also added the react version which served as an inclass project for a UI/UX class which was quite *quickly* hacked together to meet an in-class demo deadline.

The React version began as implementing a frontend for my tasktree idea, but ended up serving to explore if users respond better to a *gamification* approach to completing everyday tasks (*i.e.*, are animations/score systetms fun or simply distracting).

We may still add support for some features, but these are the two working versions as they stand today.

### react build/run commands
```
git clone <this_repo>
cd tasktree/react_version
yarns
yarn start
```

See `/react_version/README.md` for more.

### cpp output example
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

See `/cpp_version/README.md` for more on the original version.

