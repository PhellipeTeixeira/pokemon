#include <iostream>
#include<windows.h>
#include <stdlib.h>
#include "pokedex.hh"

using namespace std;
using namespace jogo;

int main() {
    int resposta, acaoBot = 0;
    string player;
    Personagens personagens;
    Bulbasaur bulbasaur;
    Pikachu jogador;
    cout << "Bem vindo ao Ginasio Pokemon\nQual o seu nome treinador? ";
    cin >> player;
    cout << "Se prepare para o batalha\n";

    //cout << "Seu adversario sera o: " << bulbasaur.nome << '\n';
    jogador.set_life(jogador.life);
    bulbasaur.set_life(bulbasaur.life);
    do
    {
    system("cls");
    cout << "\n ------------------------------- \n";
    cout << "NOME: " << player << '\n'; 
    cout << "POKEMON: " << jogador.name << '\n';
    cout << "LIFE: " << jogador.get_life() << " HP" << '\n';
    cout << "ATTACK: " << jogador.attack << '\n';
    cout << "HEAL: " << jogador.heal;
    cout << "\n ------------------------------- \n";
    cout << "POKEMON: " << bulbasaur.name << '\n';    
    cout << "LIFE: " << bulbasaur.get_life() << " HP" << '\n';
    cout << "ATTACK: " << bulbasaur.attack << '\n';
    cout << "HEAL: " << bulbasaur.heal;
    cout << "\n ------------------------------- \n";
    cout << "Digite 1 para ATACAR e 0 para se curar: ";
    cin >> resposta;
    
    if(resposta == 1) {
        system("cls");
        cout << jogador.name << " ESTA ATACANDO \n";
        Sleep(1500);
        bulbasaur.life_damage(jogador.attack);
        if(bulbasaur.get_life() > 0) {
            cout << bulbasaur.name << " FICOU COM: " << bulbasaur.get_life() << " HP";
        } else {
            bulbasaur.set_life(0);
            cout << bulbasaur.name << " FICOU COM: " << bulbasaur.get_life() << " HP";
        }
        Sleep(1500);
    } else if(resposta == 0) {
        jogador.set_heal(jogador.heal);
    }

    if(bulbasaur.get_life() > 0) {
        if(acaoBot != 2) {
            system("cls");
            cout << bulbasaur.name << " ESTA ATACANDO \n";
            jogador.life_damage(bulbasaur.attack);
            acaoBot++;
            Sleep(1500);
            if(jogador.get_life() > 0){
            cout << jogador.name << " FICOU COM: " << jogador.get_life() << " HP";
            } else {
            jogador.set_life(0);
            cout << jogador.name << " FICOU COM: " << bulbasaur.get_life() << " HP";
            }
            Sleep(1500);
        } else {
            bulbasaur.set_heal(bulbasaur.heal);
            acaoBot = 0;
        }
    }

    } while (bulbasaur.get_life() > 0 && jogador.get_life() > 0);
    
    if(jogador.get_life() <= 0) {
        system("cls");
        cout << "\n ------------------------------- \n";
        cout << "NOME: " << player << '\n';
        cout << "POKEMON: " << jogador.name << '\n';    
        cout << "LIFE: " << jogador.get_life() << " HP" << '\n';
        cout << "\n ------------------------------- \n";
        cout << "POKEMON: " << bulbasaur.name << '\n';    
        cout << "LIFE: " << bulbasaur.get_life() << " HP" << '\n';
        cout << "\n ------------------------------- \n";
        cout << "VOCE MORREU";
    } else {
        system("cls");
        cout << "\n ------------------------------- \n";
        cout << "NOME: " << player << '\n';
        cout << "POKEMON: " << jogador.name << '\n';    
        cout << "LIFE: " << jogador.get_life() << " HP";
        cout << "\n ------------------------------- \n";
        cout << "POKEMON: " << bulbasaur.name << '\n';    
        cout << "LIFE: " << bulbasaur.get_life() << " HP";
        cout << "\n ------------------------------- \n";
        cout << "VOCE VENCEU";
    }

    return 0;
}