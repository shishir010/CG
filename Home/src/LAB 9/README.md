Line Clipping – Cohen–Sutherland Algorithm

Objective:
Clip lines to display only the visible portion inside a rectangular window.

Algorithm Steps:

Input: Line endpoints P1(x1, y1), P2(x2, y2) and clipping window (wx1, wy1) top-left, (wx2, wy2) bottom-right.

Assign Region Codes: 4-bit code for each endpoint:

Left, Right, Bottom, Top based on position relative to window.

Check Visibility:

Both codes = 0000 → completely visible → draw.

Logical AND ≠ 0000 → invisible → discard.

Otherwise → partially visible → clip.

Find Intersections: Replace outside points with intersections on window boundaries.

Draw Line: Draw the clipped portion.

Features:

Fast visibility testing using binary codes

Reduces unnecessary drawing

Improves rendering efficiency

Conclusion:
Cohen–Sutherland efficiently clips lines, determining visibility using region codes and clipping only when necessary.