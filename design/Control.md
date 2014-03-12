Control
===

So far the console menu is cancelled. Command line parametric control used instead.

File Import:
-f FILENAME = in.dat

Grid initialisation:
-numA
-anaA
-numC
-s --size = 10
-X --sizeX = 10
-Y --sizeY = 10
-V = -5.0
+V = 5.0
-GND = 0.0
-r = 0.25
-d = 1.0

Simulation:
-o --output OUTPUT_FILENAME = out.dat
-p --precision = 0.001
-m --maxIteration = 1000
-v --verbose = false
-ns --nosim = false

Gnuplot Export flags:
-pot
-map
-fl --fieldlines
-epl --equipotlines
-diff FILENAME
-diffA
-diffo DIFF_OUTPUT_FILENAME = diff.dat

Example of comparing FILE1 with FILE2 without simulating FILE1: 
ESS -f FILE1 -diff FILE2 -m 0



User first has to Fill Grid with some initial boundary data. Therefore in the first menu `Fill Grid` there are 5 options:

- AnalyticProbA
- NumericProbA
- NumericProbC
- Custom Grid
- Import from file

In first 4 cases user defined size of a Grid is required to create a Grid. In the case of import the size of a grid will be determined based on the data file.

For the prepared ProbA and ProbC cases user will be asked for +V, -V and GND potential value if necessary then the grid will be filled with corresponding data.

Import will require a query for filename and optionally type of the imported file.

For the simulation user only has to specify a change threshold and/or maxIteration to stop the simulation iterating.

After the simulation is done program will ask for .dat filename to save the result of the simulation and give user options for saving/exporting results (coloured potential map, equi potential lines, electric field lines).  

@TODO Analytic vs. Numeric difference 
