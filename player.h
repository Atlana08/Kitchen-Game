#ifndef PLAYER_H
#define PLAYER_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include "food.h"
#include <vector>

class Player:public QWidget{
public:
    /*! This is the Player class initializer*/
    Player(QWidget *parent= nullptr);
    /*! This is the Player class initializer with parameters
     * @param x position, y position, person value
    */
    Player(int,int,int player = 0);
    /*! Sets the specific location of a character*/
    void set_position(int,int);
    /*! Places the actual figure of the character on the board and the food widgets on the tray*/
    void paintEvent(QPaintEvent* e);
    /*! This hides the image of the player, removing them from the board*/
    void remove_event();
    /*! This adds the image of the player to the board*/
    void create_event();
    /*! This gets the position of the player
     * @return position x
    */
    int get_pos_x() const;
    /*! This gets the position of the player
     * @return position y
    */
    int get_pos_y() const;
    /*! This adds a food pointer to the sandwich vector*/
    void add_food(Food*);
    /*! This gets the title of the sandwich
     * @return sandwich title
    */
    QString* get_sandwich_name() const;
    /*! Gets the size of the sandwich
     * @return the sandwich.size()
    */
    size_t get_vector_size();
    /*! creates a random sandwich of the basic variety for the customers*/
    void set_basic_sandwich();
    /*! creates a random sandwich of the medium variety for the customers*/
    void set_intermediate_sandwich();
    /*! creates a random sandwich of the hard variety for the customers*/
    void set_expert_sandwich();
    /*! This is an operation overloading to see if players are equal by seeing if their sandwich vectors are equal*/
    Player& operator = (Player*);
    /*! checks vector to see if two sandwhiches match
     * @return bool for if order is true
    */
    bool check_order(Player*);
    /*! checks to see if the player's image in so the board with if character draw = true
     * * @return bool for if character draw = true
    */
    bool check_presence();
    /*! clears the sandwich vector, called if player tries to give customer the wrong sandwich
      or if you throw sandwich in trash can*/
    void delete_sandwich();
    /*! moves the position x to the right one*/
    void move_right();
    /*! moves the position x to the left one*/
    void move_left();
    /*! moves the position y to the up one*/
    void move_up();
    /*! moves the position y to the down one*/
    void move_down();
    /*! Sets the random value of the character so it is randomly generated*/
    void set_character();
    /*! Sets the player's character to face right*/
    void turnRight();
     /*! Sets the player's character to face left*/
    void turnLeft();

private:
    std::vector<Food*> sandwich;
    int rand_num = 0;
    int pos_x;
    int pos_y;
    int chara;
    bool draw_character = true;
    bool change_character = true;
    bool flip = false;
    QString type_of_sandwich;
};

#endif // PLAYER_H
