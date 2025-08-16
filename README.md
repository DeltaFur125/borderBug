This repo showcases how to reproduce a bug with GBDK's png2asset tool when trying to create a SBG border.

The `sgb_border` folder contains the GBDK example program of the same name, with the only change being the 'gb_border.png` image. The generated border shares a palette with the gameplay portion of the screen.

The `sgb_border_gbstudio` also contains the same GBDK example program, but the instead of using png2asset to generate the `border_data.c` file, GBStudio has been used instead. The process to do so was:
1. Create a default GBstudio project.
2. Enable SGB features, and use the same image as in `sgb_border` as the border.
3. Export the project's source code.
4. Take the relevant variables from the generated `src/data/border.c`, and use them on our own `border_data.c`.
5. Manually create `border_data.h`.

Following this process, the generated border is correct.

Here's a side by side comparision:

<img width="534" height="263" alt="image" src="https://github.com/user-attachments/assets/1bb69e84-ddc3-472d-958b-1f98c009c18e" />

# Aditional notes
Using [this SGB border injector](https://www.marcrobledo.com/super-game-boy-border-injector/) with its companion [border converter](https://www.marcrobledo.com/super-game-boy-border-converter/) also generates a correct border.

This has been tested on Ares, Mugen, BGB and mGBA, but not on real hardware (yet).
