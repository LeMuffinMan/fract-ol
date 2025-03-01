# My simple fractals explorer #
_"Fractal geometry is not just a chapter of mathematics, but one that helps Everyman to see the same world differently."_ 

Benoît Mandelbrot

![Julia_red](https://github.com/user-attachments/assets/71548daf-323c-4677-8967-30bf19df6a1b)

---
# Fractol - 42 School Project

Welcome to **Fractol**, a captivating journey into the mesmerizing world of fractals, where mathematics meets art through the power of computation. This project, developed as part of the 42 School curriculum, is a celebration of the beauty and complexity of fractal geometry, brought to life with code. Whether you're a math enthusiast, a programmer, or simply someone who appreciates visual artistry, Fractol invites you to explore the infinite intricacies of these mathematical wonders.

Fractals are more than just stunning visuals—they are a testament to the elegance of mathematics and its profound connection to the natural world. Through this project, I aimed to channel my passion for both mathematics and computer science into creating a tool that not only generates fractals but also inspires curiosity and creativity.

---

![Mandelbrot zoom out](https://github.com/user-attachments/assets/e45ee60f-1331-44e1-8960-cd3acb920396)
![Burning_ship zoom out](https://github.com/user-attachments/assets/44f2b044-910a-463c-a62a-b71352f861d9)

## Usage 

Requirements : 
  - MinilibX : https://github.com/42paris/minilibx-linux
  - X11

In the repo, just do :

```sh
make bonus
```

![image](https://github.com/user-attachments/assets/18f64e4c-d9d8-42fc-9341-61f26c1db69e)


## Main Notions Learned

- **Mathematical Foundations**: Deepened my understanding of complex numbers, iterative functions, and the mathematical principles behind fractals like the Mandelbrot and Julia sets.
- **Graphical Programming**: Gained hands-on experience with graphical libraries (e.g., MiniLibX) to render dynamic and interactive visualizations.
- **Algorithm Optimization**: Learned to optimize algorithms for real-time rendering, balancing performance and precision.
- **Creative Problem-Solving**: Explored the intersection of art and technology, using code to create visually stunning outputs.

---

## Main Difficulties

- **Performance Optimization**: Ensuring smooth rendering while maintaining the precision of fractal calculations was a significant challenge, especially for deeper zoom levels.
- **Mathematical Complexity**: Translating abstract mathematical concepts into efficient and accurate code required a deep dive into fractal theory.
- **User Interaction**: Designing an intuitive and responsive interface for exploring fractals added an extra layer of complexity.

---

## Going Further

Fractol is just the beginning! Here are some ideas to take this project to the next level:
- **Expand Fractal Variety**: Implement additional fractals like the Burning Ship, Newton's Fractal, or custom formulas.
- **Advanced Coloring Algorithms**: Experiment with new coloring techniques to enhance the visual appeal of fractals.
- **3D Fractals**: Explore the world of 3D fractals using OpenGL or other rendering libraries.
- **Interactive Features**: Add features like saving images, adjusting color palettes, or sharing fractal coordinates.

---
![Julia_green](https://github.com/user-attachments/assets/6dda8090-c931-4f79-bd20-739f2c4d884a)
![Julia_blue](https://github.com/user-attachments/assets/261a653a-99db-442a-a362-407c0a319605)

Fractol is more than a project—it's a testament to the beauty of mathematics and the endless possibilities of programming. Dive in, explore, and let your curiosity guide you through the infinite depths of fractal geometry. Contributions, feedback, and ideas are always welcome!

Happy exploring! 🚀

---

## Inputs

The **Fractol** project supports a variety of keyboard and mouse inputs to interact with the fractals. Below is a detailed list of available controls:

### Keyboard Controls

- **Fractal Selection**:
  - `1` to `7`: Switch between different fractals.
  - `8`: Switch to a special fractal (Multibrot) with increased power.
  - `P`: Toggle psychedelic mode.

- **Zoom and Movement**:
  - `Arrow Keys`: Move the fractal view.
  - `Shift + Up/Down`: Zoom in/out.
  - `+` (Numpad): Increase the number of iterations.
  - `-` (Numpad): Decrease the number of iterations.
  - `Backspace`: Switch between the current fractal and the last viewed fractal.

- **Multibrot Power Control**:
  - `+` (Main Keyboard): Increase the power of the Multibrot.
  - `-` (Main Keyboard): Decrease the power of the Multibrot.

- **Julia Set Controls**:
  - `A`: Set origin or arrival point for Julia set transformations.
  - `Shift + A`: Reset Julia set origin.

- **Animation and Speed**:
  - `Space`: Pause/resume animation.
  - `Ctrl + +`: Increase animation speed.
  - `Ctrl + -`: Decrease animation speed.

- **Color and Rendering**:
  - `C`: Cycle through color palettes.
  - `Shift + C`: Reset to the default color palette.

- **Combo Keys**:
  - `Shift`: Toggle shift combo mode.
  - `Ctrl`: Toggle control combo mode.
  - `Alt`: Toggle alt combo mode.

- **Miscellaneous**:
  - `ESC` or `Window Close (X)`: Exit the program.

### Mouse Controls

- **Zoom**:
  - `Mouse Wheel Up`: Zoom in.
  - `Mouse Wheel Down`: Zoom out.
  - `Mouse Wheel Click`: Reset zoom and position.

- **Julia Set Interaction**:
  - `Left Click`: Set Julia constant based on mouse position.
  - `Shift + Left Click`: Switch to Julia set and set constant.

- **Iteration Control**:
  - `Shift + Mouse Wheel Up`: Increase the number of iterations.
  - `Shift + Mouse Wheel Down`: Decrease the number of iterations.

- **Animation Speed**:
  - `Alt + Mouse Wheel Up`: Increase animation speed.
  - `Alt + Mouse Wheel Down`: Decrease animation speed.

- **Fractal Switching**:
  - `Ctrl + Mouse Wheel Up`: Increase fractal transformation speed.
  - `Ctrl + Mouse Wheel Down`: Decrease fractal transformation speed.

### Notes

- **Combination Keys**: Some controls require combination keys (e.g., `Shift`, `Ctrl`, `Alt`) to activate specific functionalities.
- **Dynamic Interaction**: The program allows for dynamic interaction with fractals, including zooming, panning, and adjusting rendering parameters in real-time.

For more details on how each input affects the fractal rendering, refer to the source code or experiment with the controls directly in the program.
