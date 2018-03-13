#pragma once

class Rotatable { //Фигуры, пригодные к повороту
public:
  virtual void rotateLeft() = 0;  //Повернуть влево
  virtual void rotateRight() = 0; //Повернуть вправо
};
