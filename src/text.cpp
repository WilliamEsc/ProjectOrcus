// #include "text.h"

// text::text()
// {
//     texte = "";
//     color = {0, 0, 0};
//     font = TTF_OpenFont("fonts/Life_is_goofy.ttf", 50);
// }

// text::~text()
// {
//     delete t;
// }

// const char *text::getTexte()
// {
//     return texte;
// }

// SDL_Color text::getColor()
// {
//     return color;
// }

// TTF_Font *text::getFont()
// {
//     return font;
// }

// float text::getPosX()
// {
//     return posX;
// }

// float text::getPosY()
// {
//     return posY;
// }

// void text::setFont(TTF_Font *f)
// {
//     font = f;
// }

// void text::setColor(SDL_Color c)
// {
//     color = c;
// }

// void text::setPosText(float x, float y)
// {
//     posX = x;
//     posY = y;
// }

// void text::setTexte(const char *t1, SDL_Renderer *ren, float x, float y)
// {
//     texte = t1;
//     t->setTexture(t->loadTextureText(texte, font, color, ren));
//     t->renderTexture(ren);
// }