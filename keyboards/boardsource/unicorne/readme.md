# Unicorne

![image](https://i.imgur.com/akJJFUmh.jpeg)

* Keyboard Maintainer: [waffle87](https://github.com/waffle87)
* Hardware Supported: Unicorne PCBs w/ integrated RP2040 microcontroller
* Hardware Availability: [boardsource.xyz](https://boardsource.xyz)

Make example for this keyboard (after setting up your build environment):

    make boardsource/unicorne:default

Flashing example for this keyboard:

    make boardsource/unicorne:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (the top left key) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

## SECURE macro with local build
During local builds, you simply set the environment variable before running your build commands. Here's how you can do it on mac and windows:

---

### **For macOS or Linux**

1. Open a terminal.
2. Export the `PASSWORD_SECRET` environment variable:
   ```bash
   export PASSWORD_SECRET="your_secure_password_here"
   ```
   - Replace `"your_secure_password_here"` with your actual password.

3. Run the QMK build command:
   ```bash
   make keyboard:keymap
   ```
   - Replace `keyboard` and `keymap` with your keyboard and keymap names.

   Example:
   ```bash
   make dz60:my_keymap
   ```

4. After the build is complete, if you want to clear the environment variable for added security, unset it:
   ```bash
   unset PASSWORD_SECRET
   ```

---

### **For Windows (Command Prompt)**

1. Open a Command Prompt (**cmd.exe**).
2. Set the `PASSWORD_SECRET` environment variable temporarily for the session:
   ```cmd
   set PASSWORD_SECRET=your_secure_password_here
   ```
   - Replace `your_secure_password_here` with your actual password.

3. Run the QMK build command:
   ```cmd
   make keyboard:keymap
   ```

   Example:
   ```cmd
   make dz60:my_keymap
   ```

4. The environment variable will only persist for the session. Once you close the Command Prompt, the variable will be cleared automatically. If you want to remove it within the session:
   ```cmd
   set PASSWORD_SECRET=
   ```

---

### **For Windows (PowerShell)**

1. Open a **PowerShell** window.
2. Set the `PASSWORD_SECRET` variable:
   ```powershell
   $env:PASSWORD_SECRET = "your_secure_password_here"
   ```
   - Replace `"your_secure_password_here"` with your actual password.

3. Run the QMK build command:
   ```powershell
   make keyboard:keymap
   ```

   Example:
   ```powershell
   make dz60:my_keymap
   ```

4. To clear the environment variable within your session:
   ```powershell
   Remove-Item Env:PASSWORD_SECRET
   ```

---

### **Debugging Environment Variables**
If you're unsure whether the environment variable is being correctly set:

- On **macOS/Linux**, you can check its value with:
  ```bash
  echo $PASSWORD_SECRET
  ```

- On **Windows Command Prompt**, use:
  ```cmd
  echo %PASSWORD_SECRET%
  ```

- On **Windows PowerShell**, use:
  ```powershell
  echo $env:PASSWORD_SECRET
  ```

---

### **Testing Locally**

1. Set the variable and build normally by using the instructions above.
2. Check the generated `password.h` file in your QMK keymap folder after running `generate_header.sh` to ensure it has the correct value:
   ```c
   #define PASSWORD_MACRO "your_secure_password_here"
   ```

3. If the file contains the correct password, the process is working as expected.

---

### **Automating Local Builds**
For convenience during local development, you can also use shell scripts or batch files to set the environment variable and run the build in one step:

- **Example for macOS/Linux Build Script (`build_with_secret.sh`):**
  ```bash
  #!/bin/bash
  export PASSWORD_SECRET="your_secure_password_here"
  make keyboard:keymap
  unset PASSWORD_SECRET
  ```

- **Example for Windows Batch File (`build_with_secret.bat`):**
  ```cmd
  @echo off
  set PASSWORD_SECRET=your_secure_password_here
  make keyboard:keymap
  set PASSWORD_SECRET=
  ```

Running this script automates the process and clears the password afterward.
