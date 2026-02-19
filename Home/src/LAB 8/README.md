Flood Fill Algorithm – Short Overview

Objective:
Fill enclosed shapes by coloring all connected pixels from a starting point.

Algorithm (4-Connected Flood Fill):

Start with a background color (e.g., black).

Pick a point inside the shape.

If the current pixel has the background color (old_col):

Color it with fill_col.

Recursively fill four directions:

flood(x+1, y, fill_col, old_col); // right
flood(x-1, y, fill_col, old_col); // left
flood(x, y+1, fill_col, old_col); // down
flood(x, y-1, fill_col, old_col); // up


Features:

Simple recursive filling

Works for closed boundaries

Demonstrates pixel connectivity

Conclusion:
Flood Fill efficiently fills enclosed areas using recursion and illustrates basic graphics concepts.