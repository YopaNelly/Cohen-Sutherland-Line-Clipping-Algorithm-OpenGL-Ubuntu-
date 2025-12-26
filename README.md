# Cohen-Sutherland-Line-Clipping-Algorithm-OpenGL-Ubuntu-




# 📌 Cohen–Sutherland Line Clipping Algorithm (OpenGL – Ubuntu)

## 📖 Definition of the Cohen–Sutherland Algorithm

The **Cohen–Sutherland algorithm** is a **line clipping algorithm** used in computer graphics to determine which portion of a line lies inside a **rectangular clipping window**.
It assigns a **4-bit region code** to each endpoint of the line, indicating its position relative to the window. Using these codes, the algorithm efficiently decides whether to **accept, reject, or clip** the line.



## 🎯 Purpose of This Program

This program demonstrates the **Cohen–Sutherland line clipping algorithm** using **OpenGL in C** on Ubuntu.
It **automatically executes step by step**, showing:

1. The clipping window
2. Original lines (in red)
3. Intersection points (in yellow)
4. Clipped lines (in green)

The program uses `sleep()` to pause between steps, allowing the user to **see each stage of the algorithm visually**.



## 🧠 Features of the Program

* Draws the **clipping window**
* Draws **original lines** before clipping
* Computes **region codes** internally
* Shows **intersection points**
* Draws **final clipped line**
* **Automatic execution** with delays (no keyboard input needed)



## 🪟 Clipping Window

The rectangular window is defined by:

* Bottom-left: (50, 10)
* Bottom-right: (80, 10)
* Top-right: (80, 40)
* Top-left: (50, 40)



## 📐 Lines Clipped

1. Line 1: P1(40, 15) → P2(75, 45)
2. Line 2: P3(70, 20) → P4(100, 10)



## 🎨 Color Legend

| Color  | Meaning             |
| ------ | ------------------- |
| White  | Clipping window     |
| Red    | Original line       |
| Yellow | Intersection points |
| Green  | Clipped line        |



## 🛠️ Requirements

### Operating System

* Ubuntu Linux

### Libraries

* OpenGL
* GLUT (FreeGLUT)



## 📥 Install Required Libraries

Open a terminal and run:

```bash
sudo apt update
sudo apt install freeglut3 freeglut3-dev
```



## 📄 Files

* `clip_auto.c` → Main C source file with automatic Cohen–Sutherland clipping

---

## ▶️ Steps to Compile and Run

### Step 1: Open Terminal

Navigate to the directory containing `clip_auto.c`.

```bash
cd path/to/your/file
```



### Step 2: Compile the Program

```bash
gcc clip_auto.c -o clip_auto -lGL -lGLU -lglut
```



### Step 3: Run the Program

```bash
./clip_auto
```

A window will open showing the **clipping process automatically**.



## 🧪 Program Execution

1. The **clipping window** is drawn first (white rectangle).
2. The **first line** is drawn in **red**.
3. **Intersection points** appear in **yellow**.
4. The **clipped line** is drawn in **green**.
5. After a short pause, the **second line** is drawn, following the same steps.

All steps are controlled using `sleep()` to provide **visual pauses** between stages.



## 🏁 Conclusion

The **Cohen–Sutherland algorithm** efficiently clips lines using **region codes and logical operations**.
This program enhances understanding by providing **automatic, visual, step-by-step execution**, making it ideal for learning and demonstration.
