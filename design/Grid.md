Grid
===

### Member variables:

- int X-Y size of a grid
- float 2D array of potential
- boolean 2D array of fixed flags

arrays are ordered y-x (rows, cols) and oriented

```
+--> x
|
\/
y
```

### Constructors:

- X-Y size only
- X-Y size + potential + fixed

### Methods:

- getSizeX()
- getSizeY()
- getPot(X, Y)
- setPot(X, Y, pot)
- isFixed(X, Y)
- setFixed(X, Y, fixed)
