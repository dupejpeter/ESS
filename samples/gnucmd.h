// File to take the iterated array plot through gnuplot and output a png file.
//
//

int gnucmd(int c_MatrixSize)
{

  // Outputting a command txt file for gnuplot.

  ofstream gnucmd("gnucmd.txt");
 
  gnucmd << "set size ratio 1
unset key
unset xtics
unset ytics
set xrange [0:" << c_MatrixSize-1 << "]
set yrange [0:" << c_MatrixSize-1 << "]
set samples 200; set isosamples 200
set surface
set palette rgb 33,13,10
set pm3d
set pm3d hidden3d 100
set hidden3d
set terminal pngcairo size 2000,2000
set output 'out.png'
set multiplot layout 2,2
set contour both
set cntrparam levels 10
set view 60,15,1,1
splot \"FDM_data.dat\" matrix w pm3d
set view 60,30
splot \"FDM_data.dat\" matrix w pm3d
set view 60,45
splot \"FDM_data.dat\" matrix w pm3d
set ticslevel 0
unset contour
set view 90,0
splot \"FDM_data.dat\" matrix w pm3d
unset multiplot
unset output
exit gnuplot" << endl;


  // Commanding Gnuplot
  
  system( "gnuplot.exe gnucmd.txt" );

  return 0;
}
  
    
