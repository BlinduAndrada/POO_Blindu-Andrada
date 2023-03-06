#include "Canvas.h"

Canvas::Canvas(int width, int height) : width(width), height(height) {

	// Initializare canvas

	matrix = new char* [height];

	for (int i = 0; i < height; i++) {

		matrix[i] = new char[width];

		for (int j = 0; j < width; j++)
			matrix[i][j] = ' ';

	}

}

Canvas::~Canvas() {

	for (int i = 0; i < height; i++)
		delete[] matrix[i];

	delete[] matrix;

}

void Canvas::SetPoint(int x, int y, char ch) {
	if (x < 0 || x >= width || y < 0 || y >= height)
		return;
	this->matrix[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	//Brehenham's Line Algorithm
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;  //in loc de if
	int sy = (y1 < y2) ? 1 : -1;  //in loc de if
	int err = dx - dy;
	while (true) {
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2)
			break;
		int e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x1 += sx;

		}
		if (e2 < dx) {
			err += dx;
			y1 += sy;
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	int xc = 0;
	int yc = ray;
	int p = 1 - ray;
	while (xc <= yc) {

		SetPoint(x + xc, y + yc, ch);
		SetPoint(x - xc, y + yc, ch);
		SetPoint(x + xc, y - yc, ch);
		SetPoint(x - xc, y - yc, ch);
		SetPoint(x + yc, y + xc, ch);
		SetPoint(x - yc, y + xc, ch);
		SetPoint(x + yc, y - xc, ch);
		SetPoint(x - yc, y - xc, ch);
		xc++;
		if (p < 0)
			p += 2 * xc + 1;
		else {
			yc--;
			p += 2 * (xc - yc) + 1;
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = x - ray; i <= x + ray; i++)
		for (int j = y - ray; j <= y + ray; j++)
			if (pow(i - x, 2) + pow(j - y, 2) <= pow(ray, 2))
				SetPoint(i, j, ch);

		
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	DrawLine(left,top,right,top,ch);   //top line
	DrawLine(left,top,left,bottom,ch);  //left line
	DrawLine(right,top,right,bottom,ch); //right line
	DrawLine(left,bottom,right,bottom,ch); //bottom line 
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	//verificam left<=right si top<=botton
	if (left > right)
		swap(left, right);
	if (top, bottom)
		swap(top, bottom);
	//umplem fiecare rand de la top la bottom
	for (int y = top; y <= bottom; y++)
		for (int x = left; x <= right; x++)
			SetPoint(x, y, ch);

}

void Canvas::Print() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			cout << matrix[i][j];
		cout << '\n';
	}
}

void Canvas::Clear() {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			matrix[i][j] = ' ';

}