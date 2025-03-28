/**
 * @file Aquarium.h
 * @brief Header for the Aquarium class.
 */

 #ifndef _AQUARIUM_H_
 #define _AQUARIUM_H_
 
 #include <iostream>
 #include <CImg.h>
 #include <chrono>
 
 using namespace std;
 using namespace cimg_library;
 
 class Milieu;
 
 /**
  * @class Aquarium
  * @brief Represents an aquarium display.
  *
  * The Aquarium class is derived from the CImgDisplay class and provides functionality
  * to display an aquarium simulation. It contains a Milieu object that represents the
  * environment of the aquarium.
  */
 class Aquarium : public CImgDisplay
 {
 
 private:
    Milieu *flotte; /**< Pointer to the Milieu object representing the aquarium environment. */
    int delay;      /**< Delay between each frame update in milliseconds. */
    bool paused;
 public:
    /**
     * @brief Constructs an Aquarium object with the specified width, height, and delay.
     * @param width The width of the aquarium display.
     * @param height The height of the aquarium display.
     * @param _delay The delay between each frame update in milliseconds.
     */
    Aquarium(int width, int height, int _delay);
 
    /**
     * @brief Destructor for the Aquarium object.
     */
    ~Aquarium(void);
 
    /**
     * @brief Retrieves the Milieu object representing the aquarium environment.
     * @return A reference to the Milieu object.
     */
    Milieu &getMilieu(void) { return *flotte; }
 
    /**
     * @brief Runs the aquarium simulation.
     */
    void run(void);

 };
 
 #endif