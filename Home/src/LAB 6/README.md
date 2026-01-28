Title:  Triangle Reflection Program in C (Turbo C Graphics)

This C program demonstrates **drawing a triangle** using the graphics library and performing a **reflection** of the triangle across the vertical axis of the screen. It is implemented using **Turbo C/C++** graphics functions.

## Features

- Draws a triangle on a 2D coordinate system.
- Displays the X and Y axes for reference.
- Performs **horizontal reflection** of the triangle.
- Updates the graphics window to show the reflected triangle.

## How It Works

1. The program defines the initial coordinates of a triangle in a 2D array (`PolygonPoints`).
2. The `PolyLine()` function draws the triangle and the axes on the graphics window.
3. The `Reflect()` function performs a **horizontal reflection** by flipping the X-coordinates of the triangle points relative to the screen width (640 pixels).
4. The main function adjusts the triangle coordinates to fit the graphics window, displays the original triangle, waits for a key press, reflects the triangle, and then redraws it.

## Libraries Used

- `<graphics.h>`: For drawing shapes and lines.
- `<conio.h>`: For console input/output functions like `getch()`.
- `<stdio.h>`: Standard input/output functions.
- `<math.h>`: Mathematical operations (not heavily used in this program).

## Usage

1. Open the program in **Turbo C/C++**.
2. Compile and run the code.
3. The initial triangle will appear along with X and Y axes.
4. Press any key to see the triangle reflected across the vertical axis.

## Notes

- The program is specifically designed for **Turbo C/C++** environments using the old BGI graphics system.
- Make sure the path to the BGI driver is correct: `"C:\\Turboc3\\BGI"`.

---
