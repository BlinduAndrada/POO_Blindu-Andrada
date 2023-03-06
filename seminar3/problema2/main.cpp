#include "Canvas.h"

int main() {

	//Canvas canvas(30, 20);

	//canvas.DrawRect(5, 5, 15, 10, '*');
	//canvas.Print();
	//canvas.Clear();
	//canvas.Print();

    //Canvas canvas(40, 40);

    //canvas.DrawLine(0, 0, 40, 40, '*');
    //canvas.DrawLine(0, 40, 0, 40, '*');
    //canvas.DrawRect(5, 5, 15, 15, '+');
    //canvas.FillRect(5, 4, 15, 14, '-');
    //canvas.DrawCircle(20, 15, 5, '*');
    //canvas.FillCircle(20, 15, 3, '%');

    //canvas.Clear();

    //canvas.DrawRect(5, 5, 15, 10, '+');
    //canvas.FillRect(4, 4, 14, 9, '-');

    //canvas.Print();

    //canvas.Clear();

    //Pentru o fata zambitoare intr-un un canvas de 30x20
    
    /*Canvas canvas(30, 20);

    // un cerc pentru fata
    canvas.FillCircle(15, 10, 8, '.');

    // doua cercuri pentru ochi
    canvas.FillCircle(12, 8, 2, '*');
    canvas.FillCircle(18, 8, 2, '*');

    // un dreptunghi pentru fata
    canvas.DrawRect(12, 12, 18, 14, '-');

    // printez the canvas-ul
    canvas.Print();

    canvas.Clear();
    canvas.Print();
    */

    //Mikey Mouse face

    cout << "\n//Mikey Mouse face//\n\n";

    // Create a canvas object
    Canvas canvas(60, 30);

    // Draw the face circle
    canvas.FillCircle(30, 15, 10, '#');

    // Draw the nose circle
    canvas.FillCircle(30, 20, 3, '#');

    // Draw the eyes
    canvas.FillCircle(25, 12, 2, 'O');
    canvas.FillCircle(35, 12, 2, 'O');

    // Draw the pupils
    canvas.FillCircle(25, 12, 1, '*');
    canvas.FillCircle(35, 12, 1, '*');

    // Draw the eyebrows
    canvas.DrawLine(22, 9, 28, 9, '-');
    canvas.DrawLine(32, 9, 38, 9, '-');

    // Draw the ears
    canvas.FillCircle(20, 5, 7, '#');
    canvas.FillCircle(40, 5, 7, '#');

    // Draw the smile
    canvas.DrawRect(25, 17, 35, 19, '*');

    // Print the canvas
    canvas.Print();

	return 0;
}
