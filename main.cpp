#include <windows.h>
#include <stdio.h>

class Player
{
private:
    int* health;

public:
    Player();
    ~Player();

    int GetHealth();
    int Damage(int hp);
    int SetHealth(int hp);
};

//commit :D

Player::Player()
{
    printf("[!] Class constructor called.\n");
    printf("this ptr = 0x%llx\n", (unsigned long long int)this);
    printf("Health ptr = 0x%llx\n", (unsigned long long int)health);
    //printf("___________________________\n");

    health = new int;
    if (health)
        *health = 100;
}

Player::~Player()
{
    printf("[!] Class destructor called.\n");
    delete health;
}

int Player::GetHealth()
{
    printf("GetHealth called. ARG(null) = null\n");
    printf("this ptr = 0x%llx\n", (unsigned long long int)this);
    printf("___________________________\n");

    if (health)
        return *health;
    else
        return -1;
}

int Player::SetHealth(int hp)
{
    printf("SetHealth called. ARG(hp) = %d\n", hp);
    printf("this ptr = 0x%llx\n", (unsigned long long int)this);
    printf("___________________________\n");

    if (health)
    {
        *health = hp;
        return hp;
    }
    return -1;
}

int Player::Damage(int hp)
{
    printf("Damage called. ARG(hp) = %d\n", hp);
    printf("this ptr = 0x%llx\n", (unsigned long long int)this);
    printf("___________________________\n");

    if (health)
    {
        *health -= hp;
        return *health;
    }
    return -1;
}

int main()
{
    Player* pl = new Player;
    printf("Player pl created at 0x%llx\n", (long long unsigned int)pl);
    printf("Start value of player health: %d\n", pl->GetHealth());
    printf("___________________________\n");

    while (true)
    {
        if(pl->GetHealth() < 16)
        {
            pl->SetHealth(100);
            printf("Health < 0, set to 100.\n");
        }

        pl->Damage(15);
        printf("Damaged. New health value: %d\n", pl->GetHealth());

        char t = 0;
        gets(&t);
    }
    return 0;
}
