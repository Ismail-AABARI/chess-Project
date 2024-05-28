//#include <iostream>
//#include "echiquier.h"
//using namespace std;
//
//afficherEchiquier(echiquier e)
//{
//	cout<<"Colonne :  | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7     "<<endl;
//	cout<<"_________________________________________________________________"<<endl;
//	for(int i=0;i<=7;i++)
//	{
//		cout<<"Ligne : "<<i<<" ";
//		for(int j=0;j<=7;j++)
//		{
//			//cout<<" | "<<e.getindice(i,j);
//			switch(e.getindice(i,j))
//			{
//				case 1: cout<<" | KB  ";
//					break;
//				case 2: cout<<" | QB  ";
//					break;
//				case 3: cout<<" | TB  ";
//					break;
//				case 4: cout<<" | FB  ";
//					break;
//				case 5: cout<<" | CB  ";
//					break;
//				case 6: cout<<" | PB  ";
//					break;
//				case -1: cout<<" | KN  ";
//					break;
//				case -2: cout<<" | QN  ";
//					break;
//				case -3: cout<<" | TN  ";
//					break;
//				case -4: cout<<" | FN  ";
//					break;
//				case -5: cout<<" | CN  ";
//					break;
//				case -6: cout<<" | PN  ";
//					break;
//				case 0 : cout<<" |     ";
//					break;
//			}
//		}
//		cout<<endl;
//		cout<<"_________________________________________________________________"<<endl;
//	}
//}
//
//saisirCoord(int &l,int &c)
//{
//	do
//	{
//		cout<<"Veuillez saisir une ligne : ";
//		cin>>l;
//	}while((l<0)||(l>7));
//	do
//	{
//		cout<<"Veuillez saisir une colonne : ";
//		cin>>c;
//	}while((c<0)||(c>7));
//	
//}
//
//deplacerPiece(echiquier &e,char joueur)
//{
//	int la,ld,ca,cd;
//	saisirCoord(ld,cd);
//	saisirCoord(la,ca);
//	e.mov(ld,cd,la,ca,joueur);
//}
//
//
//void partie(echiquier &e) 
//{
//    int tour = 0;
//    char joueur;
//    do {
//        if (tour % 2 == 0) 
//		{
//            cout << "\t\t\t\t JOUEUR : BLANC" << endl<<endl;
//            joueur = 'B'; // joueur blanc
//        }
//		else 
//		{
//            cout << "\t\t\t\t JOUEUR : NOIR " << endl<<endl;
//            joueur = 'N'; // joueur noir
//        }
//        afficherEchiquier(e);
//        deplacerPiece(e, joueur);
//        tour++;
//    } while (!e.finpartie());
//}
// 
//	
//main()
//{
//    echiquier e;
//    
//    char joueur='B';
//    do
//	{
//	  bool continuer = true;
//      while (continuer) 
//	  {
//    	system("color E");
//		partie(e);
//        afficherEchiquier(e);
//        deplacerPiece(e,joueur);
//        afficherEchiquier(e);
//        partie(e);
//        cout << "Voulez-vous continuer ? (O/N)" << endl;
//        char choix;
//        cin >> choix;
////        system("cls");
//        if (choix == 'N' || choix == 'n') 
//		{
//            continuer = false;
//        }
//        
//      }
//    return 0;
//	}while(e.finpartie());
//    
//}

//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include "echiquier.h"
//
//const int CASE_SIZE = 100;
//
//int caseToIndex(int coordinate)
//{
//    return coordinate / CASE_SIZE;
//}
//
//sf::Vector2i indexToCase(int index)
//{
//    return sf::Vector2i(index * CASE_SIZE, index * CASE_SIZE);
//}
//
//void afficherEchiquier(echiquier e, sf::RenderWindow& window, sf::Texture* whiteTextures, sf::Texture* blackTextures)
//{
//    sf::Sprite sprite;
//
//    for (int i = 0; i < 8; i++)
//    {
//        for (int j = 0; j < 8; j++)
//        {
//            // Dessiner les cases blanches et noires
//            sf::RectangleShape caseShape(sf::Vector2f(CASE_SIZE, CASE_SIZE));
//            if ((i + j) % 2 == 0) // Case blanche
//                caseShape.setFillColor(sf::Color(209, 198, 173));
//            else // Case noire
//                caseShape.setFillColor(sf::Color(132, 92, 64));
//            caseShape.setPosition(j * CASE_SIZE, i * CASE_SIZE);
//            window.draw(caseShape);
//
//            // Dessiner les pièces
//            int indicePiece = e.getindice(i, j);
//            if (indicePiece != 0)
//            {
//                if (indicePiece > 0)
//                    sprite.setTexture(whiteTextures[indicePiece]);
//                else
//                    sprite.setTexture(blackTextures[-indicePiece]);
//
//                sprite.setPosition(j * CASE_SIZE, i * CASE_SIZE);
//                window.draw(sprite);
//            }
//        }
//    }
//}
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(8 * CASE_SIZE, 8 * CASE_SIZE), "Jeu d'échecs");
//
//    sf::Texture whiteTextures[13];
//    if (!whiteTextures[1].loadFromFile("pieces/Whiteking.png") ||
//        !whiteTextures[2].loadFromFile("pieces/Whitequeen.png") ||
//        !whiteTextures[3].loadFromFile("pieces/Whiterook.png") ||
//        !whiteTextures[4].loadFromFile("pieces/Whitebishop.png") ||
//        !whiteTextures[5].loadFromFile("pieces/Whiteknight.png") ||
//        !whiteTextures[6].loadFromFile("pieces/Whitepawn.png") ||
//        !whiteTextures[7].loadFromFile("pieces/Whiteking.png") ||
//        !whiteTextures[8].loadFromFile("pieces/Whitequeen.png") ||
//        !whiteTextures[9].loadFromFile("pieces/Whiterook.png") ||
//        !whiteTextures[10].loadFromFile("pieces/Whitebishop.png") ||
//        !whiteTextures[11].loadFromFile("pieces/Whiteknight.png") ||
//        !whiteTextures[12].loadFromFile("pieces/Whitepawn.png"))
//    {
//        std::cout << "Erreur lors du chargement des textures des pièces blanches." << std::endl;
//        return 1;
//    }
//
//    sf::Texture blackTextures[13];
//    if (!blackTextures[1].loadFromFile("pieces/Blackking.png") ||
//        !blackTextures[2].loadFromFile("pieces/Blackqueen.png") ||
//        !blackTextures[3].loadFromFile("pieces/Blackrook.png") ||
//        !blackTextures[4].loadFromFile("pieces/Blackbishop.png") ||
//        !blackTextures[5].loadFromFile("pieces/Blackknight.png") ||
//        !blackTextures[6].loadFromFile("pieces/Blackpawn.png") ||
//        !blackTextures[7].loadFromFile("pieces/Blackking.png") ||
//        !blackTextures[8].loadFromFile("pieces/Blackqueen.png") ||
//        !blackTextures[9].loadFromFile("pieces/Blackrook.png") ||
//        !blackTextures[10].loadFromFile("pieces/Blackbishop.png") ||
//        !blackTextures[11].loadFromFile("pieces/Blackknight.png") ||
//        !blackTextures[12].loadFromFile("pieces/Blackpawn.png"))
//    {
//        std::cout << "Erreur lors du chargement des textures des pièces noires." << std::endl;
//        return 1;
//    }
//
//    echiquier e;
//    char joueur = 'B';
//
//    int selectedPieceRow = -1;
//    int selectedPieceCol = -1;
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::MouseButtonPressed)
//            {
//                if (event.mouseButton.button == sf::Mouse::Left)
//                {
//                    int mouseX = event.mouseButton.x;
//                    int mouseY = event.mouseButton.y;
//
//                    int row = caseToIndex(mouseY);
//                    int col = caseToIndex(mouseX);
//
//                    int pieceIndex = e.getindice(row, col);
//                    if ((joueur == 'B' && pieceIndex < 0) || (joueur == 'N' && pieceIndex > 0))
//                    {
//                        selectedPieceRow = row;
//                        selectedPieceCol = col;
//                    }
//                }
//            }
//
//            if (event.type == sf::Event::MouseButtonReleased)
//            {
//                if (event.mouseButton.button == sf::Mouse::Left)
//                {
//                    int mouseX = event.mouseButton.x;
//                    int mouseY = event.mouseButton.y;
//
//                    int targetRow = caseToIndex(mouseY);
//                    int targetCol = caseToIndex(mouseX);
//
//                    if (selectedPieceRow != -1 && selectedPieceCol != -1)
//                    {
//                        if (e.mov(selectedPieceRow, selectedPieceCol, targetRow, targetCol, joueur))
//                        {
//                            joueur = (joueur == 'B') ? 'N' : 'B'; // Changer de joueur après le mouvement
//                        }
//                    }
//
//                    selectedPieceRow = -1;
//                    selectedPieceCol = -1;
//                }
//            }
//
//            if (event.type == sf::Event::MouseMoved)
//            {
//                int mouseX = event.mouseMove.x;
//                int mouseY = event.mouseMove.y;
//
//                if (selectedPieceRow != -1 && selectedPieceCol != -1)
//                {
//                    int deltaX = mouseX - selectedPieceCol * CASE_SIZE;
//                    int deltaY = mouseY - selectedPieceRow * CASE_SIZE;
//
//                    sf::Sprite sprite;
//                    if (e.getindice(selectedPieceRow, selectedPieceCol) > 0)
//                        sprite.setTexture(whiteTextures[std::abs(e.getindice(selectedPieceRow, selectedPieceCol))]);
//                    else
//                        sprite.setTexture(blackTextures[std::abs(e.getindice(selectedPieceRow, selectedPieceCol))]);
//
//                    sprite.setPosition(selectedPieceCol * CASE_SIZE + deltaX, selectedPieceRow * CASE_SIZE + deltaY);
//                    window.draw(sprite);
//                }
//            }
//        }
//
//        window.clear(sf::Color::White);
//        afficherEchiquier(e, window, whiteTextures, blackTextures);
//        window.display();
//    }
//
//    return 0;
//}


//#include <SFML/Graphics.hpp>     //code travail bien !!!!!!!!!!
//#include <iostream>
//#include "echiquier.h"
//
//const int CASE_SIZE = 100;
//
//int caseToIndex(int coordinate)
//{
//    return coordinate / CASE_SIZE;
//}
//
//sf::Vector2i indexToCase(int index)
//{
//    return sf::Vector2i(index * CASE_SIZE, index * CASE_SIZE);
//}
//
//void afficherEchiquier(echiquier e, sf::RenderWindow& window, sf::Texture* textures)
//{
//    sf::Sprite sprite;
//
//    for (int i = 0; i < 8; i++)
//    {
//        for (int j = 0; j < 8; j++)
//        {
//            // Dessiner les cases blanches et noires
//            sf::RectangleShape caseShape(sf::Vector2f(CASE_SIZE, CASE_SIZE));
//            if ((i + j) % 2 == 0) // Case blanche
//                caseShape.setFillColor(sf::Color(209, 198, 173));
//            else // Case noire
//                caseShape.setFillColor(sf::Color(132, 92, 64));
//            caseShape.setPosition(j * CASE_SIZE, i * CASE_SIZE);
//            window.draw(caseShape);
//
//            // Dessiner les pièces
//            int indicePiece = e.getindice(i, j);
//            if (indicePiece != 0)
//            {
//                sprite.setTexture(textures[std::abs(indicePiece)]);
//                sprite.setPosition(j * CASE_SIZE, i * CASE_SIZE);
//                window.draw(sprite);
//            }
//        }
//    }
//}
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(8 * CASE_SIZE, 8 * CASE_SIZE), "Jeu d'échecs");
//
//    sf::Texture textures[13];
//    if (!textures[1].loadFromFile("pieces/Blackking.png") ||
//        !textures[2].loadFromFile("pieces/Blackqueen.png") ||
//        !textures[3].loadFromFile("pieces/Blackrook.png") ||
//        !textures[4].loadFromFile("pieces/Blackbishop.png") ||
//        !textures[5].loadFromFile("pieces/Blackknight.png") ||
//        !textures[6].loadFromFile("pieces/Blackpawn.png") ||
//        !textures[7].loadFromFile("pieces/Whiteking.png") ||
//        !textures[8].loadFromFile("pieces/Whitequeen.png") ||
//        !textures[9].loadFromFile("pieces/Whiterook.png") ||
//        !textures[10].loadFromFile("pieces/Whitebishop.png") ||
//        !textures[11].loadFromFile("pieces/Whiteknight.png") ||
//        !textures[12].loadFromFile("pieces/Whitepawn.png"))
//    {
//        std::cout << "Erreur lors du chargement des textures des pièces." << std::endl;
//        return 1;
//    }
//
//    echiquier e;
//    char joueur = 'B';
//
//    int selectedPieceRow = -1;
//    int selectedPieceCol = -1;
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::MouseButtonPressed)
//            {
//                if (event.mouseButton.button == sf::Mouse::Left)
//                {
//                    int mouseX = event.mouseButton.x;
//                    int mouseY = event.mouseButton.y;
//
//                    int row = caseToIndex(mouseY);
//                    int col = caseToIndex(mouseX);
//
//                    int pieceIndex = e.getindice(row, col);
//                    if ((joueur == 'B' && pieceIndex < 0) || (joueur == 'N' && pieceIndex > 0))
//                    {
//                        selectedPieceRow = row;
//                        selectedPieceCol = col;
//                    }
//                }
//            }
//
//            if (event.type == sf::Event::MouseButtonReleased)
//            {
//                if (event.mouseButton.button == sf::Mouse::Left)
//                {
//                    int mouseX = event.mouseButton.x;
//                    int mouseY = event.mouseButton.y;
//
//                    int targetRow = caseToIndex(mouseY);
//                    int targetCol = caseToIndex(mouseX);
//
//                    if (selectedPieceRow != -1 && selectedPieceCol != -1)
//                    {
//                        if (e.mov(selectedPieceRow, selectedPieceCol, targetRow, targetCol, joueur))
//                        {
//                            joueur = (joueur == 'B') ? 'N' : 'B'; // Changer de joueur après le mouvement
//                        }
//                    }
//
//                    selectedPieceRow = -1;
//                    selectedPieceCol = -1;
//                }
//            }
//
//            if (event.type == sf::Event::MouseMoved)
//            {
//                int mouseX = event.mouseMove.x;
//                int mouseY = event.mouseMove.y;
//
//                if (selectedPieceRow != -1 && selectedPieceCol != -1)
//                {
//                    int deltaX = mouseX - selectedPieceCol * CASE_SIZE;
//                    int deltaY = mouseY - selectedPieceRow * CASE_SIZE;
//
//                    sf::Sprite sprite(textures[std::abs(e.getindice(selectedPieceRow, selectedPieceCol))]);
//                    sprite.setPosition(selectedPieceCol * CASE_SIZE + deltaX, selectedPieceRow * CASE_SIZE + deltaY);
//                    window.draw(sprite);
//                }
//            }
//        }
//
//        window.clear(sf::Color::White);
//        afficherEchiquier(e, window, textures);
//        window.display();
//    }
//
//    return 0;
//}



#include <SFML/Graphics.hpp>
#include <iostream>
#include "echiquier.h"

const int CASE_SIZE = 100;

int caseToIndex(int coordinate)
{
    return coordinate / CASE_SIZE;
}

sf::Vector2i indexToCase(int index)
{
    return sf::Vector2i(index * CASE_SIZE, index * CASE_SIZE);
}

//void afficherEchiquier(echiquier e, sf::RenderWindow& window, sf::Texture* whiteTextures, sf::Texture* blackTextures, char joueur)
//{
//    sf::Sprite sprite;
//
//    for (int i = 0; i < 8; i++)
//    {
//        for (int j = 0; j < 8; j++)
//        {
//            // Dessiner les cases blanches et noires
//            sf::RectangleShape caseShape(sf::Vector2f(CASE_SIZE, CASE_SIZE));
//            if ((i + j) % 2 == 0) // Case blanche
//                caseShape.setFillColor(sf::Color(209, 198, 173));
//            else // Case noire
//                caseShape.setFillColor(sf::Color(132, 92, 64));
//            caseShape.setPosition(j * CASE_SIZE, i * CASE_SIZE);
//            window.draw(caseShape);
//
//            // Dessiner les pièces
//            int indicePiece = e.getindice(i, j);
//            if (indicePiece != 0)
//            {
//                if (indicePiece > 0)
//                    sprite.setTexture(whiteTextures[indicePiece]);
//                else
//                    sprite.setTexture(blackTextures[-indicePiece]);
//
//                sprite.setPosition(j * CASE_SIZE, i * CASE_SIZE);
//                window.draw(sprite);
//            }
//        }
//    }
//
//    // Afficher le joueur actuel (temps de jeu)
//    sf::Text joueurText;
//    sf::Font font;
//    if (font.loadFromFile("arial.ttf"))
//    {
//        joueurText.setFont(font);
//        joueurText.setCharacterSize(20);
//        joueurText.setFillColor(sf::Color::Black);
//
//        std::string joueurStr = "Temps de : ";
//        joueurStr += (joueur == 'B') ? "blanc" : "noir";
//
//        joueurText.setString(joueurStr);
//        joueurText.setPosition(10, 10);
//
//        window.draw(joueurText);
//    }
//}

void afficherEchiquier(echiquier e, sf::RenderWindow& window, sf::Texture* whiteTextures, sf::Texture* blackTextures, char joueur)
{
    sf::Sprite sprite;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // Dessiner les cases blanches et noires
            sf::RectangleShape caseShape(sf::Vector2f(CASE_SIZE, CASE_SIZE));
            if ((i + j) % 2 == 0) // Case blanche
                caseShape.setFillColor(sf::Color(209, 198, 173));
            else // Case noire
                caseShape.setFillColor(sf::Color(132, 92, 64));
            caseShape.setPosition(j * CASE_SIZE, i * CASE_SIZE);
            window.draw(caseShape);

            // Dessiner les pièces
            int indicePiece = e.getindice(i, j);
            if (indicePiece != 0)
            {
                if (indicePiece > 0)
                    sprite.setTexture(whiteTextures[indicePiece]);
                else
                    sprite.setTexture(blackTextures[-indicePiece]);

                sprite.setPosition(j * CASE_SIZE, i * CASE_SIZE);
                window.draw(sprite);
            }
        }
    }

    // Afficher le joueur actuel (temps de jeu)
    sf::Text joueurText;
    sf::Font font;
    if (font.loadFromFile("arial.ttf"))
    {
        joueurText.setFont(font);
        joueurText.setCharacterSize(50);
        joueurText.setFillColor(sf::Color::Black);

        std::string joueurStr = "Temps de : ";
        joueurStr += (joueur == 'B') ? "noir" : "blanc";

        joueurText.setString(joueurStr);
        joueurText.setPosition(20, 20); // Ajuster la position du texte

        window.draw(joueurText);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(8 * CASE_SIZE, 8 * CASE_SIZE), "Jeu d'échecs");

    sf::Texture whiteTextures[13];
    if (!whiteTextures[1].loadFromFile("pieces/Whiteking.png") ||
        !whiteTextures[2].loadFromFile("pieces/Whitequeen.png") ||
        !whiteTextures[3].loadFromFile("pieces/Whiterook.png") ||
        !whiteTextures[4].loadFromFile("pieces/Whitebishop.png") ||
        !whiteTextures[5].loadFromFile("pieces/Whiteknight.png") ||
        !whiteTextures[6].loadFromFile("pieces/Whitepawn.png") ||
        !whiteTextures[7].loadFromFile("pieces/Whiteking.png") ||
        !whiteTextures[8].loadFromFile("pieces/Whitequeen.png") ||
        !whiteTextures[9].loadFromFile("pieces/Whiterook.png") ||
        !whiteTextures[10].loadFromFile("pieces/Whitebishop.png") ||
        !whiteTextures[11].loadFromFile("pieces/Whiteknight.png") ||
        !whiteTextures[12].loadFromFile("pieces/Whitepawn.png"))
    {
        std::cout << "Erreur lors du chargement des textures des pièces blanches." << std::endl;
        return 1;
    }

    sf::Texture blackTextures[13];
    if (!blackTextures[1].loadFromFile("pieces/Blackking.png") ||
        !blackTextures[2].loadFromFile("pieces/Blackqueen.png") ||
        !blackTextures[3].loadFromFile("pieces/Blackrook.png") ||
        !blackTextures[4].loadFromFile("pieces/Blackbishop.png") ||
        !blackTextures[5].loadFromFile("pieces/Blackknight.png") ||
        !blackTextures[6].loadFromFile("pieces/Blackpawn.png") ||
        !blackTextures[7].loadFromFile("pieces/Blackking.png") ||
        !blackTextures[8].loadFromFile("pieces/Blackqueen.png") ||
        !blackTextures[9].loadFromFile("pieces/Blackrook.png") ||
        !blackTextures[10].loadFromFile("pieces/Blackbishop.png") ||
        !blackTextures[11].loadFromFile("pieces/Blackknight.png") ||
        !blackTextures[12].loadFromFile("pieces/Blackpawn.png"))
    {
        std::cout << "Erreur lors du chargement des textures des pièces noires." << std::endl;
        return 1;
    }

    echiquier e;
    char joueur = 'B';

    int selectedPieceRow = -1;
    int selectedPieceCol = -1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int mouseX = event.mouseButton.x;
                    int mouseY = event.mouseButton.y;

                    int row = caseToIndex(mouseY);
                    int col = caseToIndex(mouseX);

                    int pieceIndex = e.getindice(row, col);
                    if ((joueur == 'B' && pieceIndex < 0) || (joueur == 'N' && pieceIndex > 0))
                    {
                        selectedPieceRow = row;
                        selectedPieceCol = col;
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int mouseX = event.mouseButton.x;
                    int mouseY = event.mouseButton.y;

                    int targetRow = caseToIndex(mouseY);
                    int targetCol = caseToIndex(mouseX);

                    if (selectedPieceRow != -1 && selectedPieceCol != -1)
                    {
                        if (e.mov(selectedPieceRow, selectedPieceCol, targetRow, targetCol, joueur))
                        {
                            joueur = (joueur == 'B') ? 'N' : 'B'; // Changer de joueur après le mouvement
                        }
                    }

                    selectedPieceRow = -1;
                    selectedPieceCol = -1;
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                int mouseX = event.mouseMove.x;
                int mouseY = event.mouseMove.y;

                if (selectedPieceRow != -1 && selectedPieceCol != -1)
                {
                    int deltaX = mouseX - selectedPieceCol * CASE_SIZE;
                    int deltaY = mouseY - selectedPieceRow * CASE_SIZE;

                    sf::Sprite sprite;
                    if (e.getindice(selectedPieceRow, selectedPieceCol) > 0)
                        sprite.setTexture(whiteTextures[std::abs(e.getindice(selectedPieceRow, selectedPieceCol))]);
                    else
                        sprite.setTexture(blackTextures[std::abs(e.getindice(selectedPieceRow, selectedPieceCol))]);

                    sprite.setPosition(selectedPieceCol * CASE_SIZE + deltaX, selectedPieceRow * CASE_SIZE + deltaY);
                    window.draw(sprite);
                }
            }
        }

        window.clear(sf::Color::White);
        afficherEchiquier(e, window, whiteTextures, blackTextures, joueur);
        window.display();
    }

    return 0;
}




