#pragma once

class reflectable { // Фигуры, пригодные к зеркальному отражению

public:
	virtual void flipHorisontally() = 0; // Отразить горизонтально
	virtual void flipVertically() = 0;   // Отразить вертикально
};
