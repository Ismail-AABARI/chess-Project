//#include "Piece.h"
#include "echiquier.h"

#include<iostream>

using namespace std;


echiquier::echiquier()
{
	init();
}
echiquier::~echiquier()
{
	
}
echiquier::init()
{
	for(int i=2;i<=5;i++)
	{
		for(int j=0;j<=7;j++)
		{
			t[i][j]=0;
		}
	}
	for(int i=0;i<=7;i++)
	{
		t[1][i]=-6;
		t[6][i]=6;		
	}
	
	t[0][0]=-3; //tour noir
	t[0][1]=-5; //cavalier noir 
	t[0][2]=-4; //fou noir 
	t[0][3]=-2; //dame noir 
	t[0][4]=-1;	//king noir
	t[0][5]=-4;	//fou noir 
	t[0][6]=-5;	//cavalier noir
	t[0][7]=-3;	//tour noir
				
	t[7][0]=3; //tour blanc
	t[7][1]=5; //cavalier blanc
	t[7][2]=4; //fou blanc
	t[7][3]=2; //dame blanc
	t[7][4]=1;	//king blanc
	t[7][5]=4;	//fou blanc
	t[7][6]=5;	//cavalier blanc
	t[7][7]=3;	//tour blanc	
}

int echiquier::getindice(int i,int j)
{
	return t[i][j];
}

int echiquier::cav(int ld,int cd,int la,int ca)
{
	if((ld+1==la)&&(cd+2==ca)||(ld+2==la)&&(cd-1==ca)||(ld-2==la)&&(cd-1==ca)||(ld-1==la)&&(cd-2==ca)||(ld+1==la)&&(cd-2==ca)||(ld-2==la)&&(cd+1==ca)||(ld-1==la)&&(cd+2==ca)||(ld+2==la)&&(cd+1==ca)) 
	{
		return 1;
	}
	else 
	{
	    return 0;
	}
}


//pour echec et mat en scan tout les cases de notres jeux de tout les joueurs adversaires 
//par exeple il va me dire que tu dois faire un movement si une piece d'un adversaire vous attaques , 
//echec a mat me dit que vous n avez aucun solution de j'ai pas une possibilite de hreb de l ennemi donc je vais scan tout mes pssibilites des cases 

int echiquier::cheminlibreDroiteBLANC(int ld, int la,int cd,int ca) //a droite meme ligne colonne different
{
	int cp=0;
	if(ld==la)
	{
		if(cd<ca)
		{
			for(int i=cd+1;i<ca;i++)
			{
				if(t[ld][i]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
			if(cp==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int echiquier::cheminlibreGaucheBLANC(int ld, int la,int cd,int ca) //a gauche meme ligne colonne different
{
	int cp=0;
	if(ld==la)
	{
		if(cd>ca)
		{
			for(int i=cd-1;i>ca;i--)
			{
				if(t[ld][i]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
			if(cp==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
}

int echiquier::cheminlibreAvantBLANC(int ld, int la,int cd,int ca)
{
	int cp=0;
	if(cd==ca)
	{
		if(ld>la)
		{
			for(int i=ld-1;i>la;i--)
			{
				if(t[i][ca]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
				if(cp==0)
				{
					return 1;
				}
			    else
			    {
			    	return 0;
				}	
		}
	}
	else
	{
		return 0;
	}
}

int echiquier::cheminlibreArriereBLANC(int ld, int la,int cd,int ca)
{
	int cp=0;
	if(cd==ca)
	{
		if(ld<la)
		{
			for(int i=ld+1;i<la;i++)
			{
				if(t[i][ca]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
			if(cp==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
}

int echiquier::cheminlibreDigonaleDroiteAvantBLANC(int ld, int la, int cd, int ca)
{
    int cp=0;
    if (ld>la) 
	{
        if (cd<ca) 
		{
            for (int i=ld-1,j=cd+1;i>la&&j<ca;i--,j++) 
			  {
                if (t[i][j] != 0) 
				{
                    cp=1;
                }
                else
                {
                	cp=0;
				}
			  }
			  if(cp==0)
			  {
				return 1;
			  }
				else
			  {
				return 0;
			  }
        }
        else
        {
        	return 0;
		}
    } 
	else
	 {
      return 0;		
     }
   
}

int echiquier::cheminlibreDigonaleDroiteArriereBLANC(int ld, int la, int cd, int ca)
{
	int cp=0;
	if(ld<la)
	{
		if(cd<ca)
		{
			for(int i=ld+1,j=cd+1;i<la&&j<ca;i++,j++)
			{
				if(t[i][j]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
			if(cp==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int echiquier::cheminlibreDigonaleGaucheAvantBLANC(int ld, int la, int cd, int ca)
{
	int cp=0;
	if(ld>la)
	{
		if(cd>ca)
		{
			for(int i=ld-1,j=cd-1;i>la,j>ca;i--,j--)
			{
				if(t[i][j]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
			if(cp==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int echiquier::cheminlibreDigonaleGaucheArriereBLANC(int ld, int la, int cd, int ca)
{
	int cp=0;
	if(ld<la)
	{
		if(cd>ca)
		{
			for(int i=ld-1,j=cd-1;i>la,j>ca;i--,j--)
			{
				if(t[i][j]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
			if(cp==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}


int echiquier::cheminlibreDroiteNOIR(int ld, int la,int cd,int ca) //a droite meme ligne colonne different
{
	int cp=0;
	if(ld==la)
	{
		if(cd<ca)
		{
			for(int i=cd+1;i<ca;i++)
			{
				if(t[ld][i]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
			if(cp==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}


int echiquier::cheminlibreGaucheNOIR(int ld, int la,int cd,int ca) //a gauche meme ligne colonne different
{
	int cp=0;
	if(ld==la)
	{
		if(cd>ca)
		{
			for(int i=cd-1;i>ca;i--)
			{
				if(t[ld][i]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
			if(cp==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}


int echiquier::cheminlibreAvantNOIR(int ld, int la,int cd,int ca)
{
	int cp=0;
	if(cd==ca)
	{
		if(ld<la)
		{
			for(int i=ld+1;i<la;i++)
			{
				if(t[i][ca]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
				if(cp==0)
				{
					return 1;
				}
			    else
			    {
			    	return 0;
				}	
		}
	}
	else
	{
		return 0;
	}
}

int echiquier::cheminlibreArriereNOIR(int ld, int la,int cd,int ca)
{
	int cp=0;
	if(cd==ca)
	{
		if(ld>la)
		{
			for(int i=ld-1;i>la;i--)
			{
				if(t[i][ca]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
			if(cp==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
}

int echiquier::cheminlibreDigonaleDroiteAvantNOIR(int ld, int la, int cd, int ca)
{
    int cp=0;
    if (ld<la) 
	{
        if (cd>ca) 
		{
            for (int i=ld+1,j=cd-1;i<la&&j>ca;i++,j--) 
			  {
                if (t[i][j] != 0) 
				{
                    cp=1;
                }
                else
                {
                	cp=0;
				}
			  }
			  if(cp==0)
			  {
				return 1;
			  }
				else
			  {
				return 0;
			  }
        }
        else
        {
        	return 0;
		}
    } 
	else
	 {
      return 0;		
     }
   
}

int echiquier::cheminlibreDigonaleDroiteArriereNOIR(int ld, int la, int cd, int ca)
{
	int cp=0;
	if(ld>la)
	{
		if(cd>ca)
		{
			for(int i=ld-1,j=cd-1;i>la&&j>ca;i--,j--)
			{
				if(t[i][j]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
			if(cp==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int echiquier::cheminlibreDigonaleGaucheAvantNOIR(int ld, int la, int cd, int ca)
{
	int cp=0;
	if(ld<la)
	{
		if(cd<ca)
		{
			for(int i=ld+1,j=cd+1;i<la,j<ca;i++,j++)
			{
				if(t[i][j]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
			if(cp==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int echiquier::cheminlibreDigonaleGaucheArriereNOIR(int ld, int la, int cd, int ca)
{
	int cp=0;
	if(ld>la)
	{
		if(cd<ca)
		{
			for(int i=ld-1,j=cd+1;i>la,j<ca;i--,j++)
			{
				if(t[i][j]!=0)
				{
					cp=1;
				}
				else
				{
					cp=0;
				}
			}
			if(cp==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}





//int echiquier::cheminlibredamedroite(int ld, int la, int cd, int ca)
//{
//    int cp = 0;
//    if (ld==la) 
//    {
//        if (cd<ca) 
//        {
//            for (int j=cd+1;j<ca;j++)
//            {
//                if (t[ld][j] != 0)
//                {
//                    cp = 1;
//                    break;
//                }
//            }
//            if (cp == 0) 
//            {
//                return 1;
//            }
//        }
//    }
//    return 0;
//}
//
//int echiquier::cheminlibredamegauche(int ld, int la, int cd, int ca)
//{
//    int cp = 0;
//    if (ld==la) 
//    {
//        if (cd>ca) 
//        {
//            for (int j=cd-1;j>=ca;j--) 
//            {
//                if (t[ld][j] != 0) 
//                {
//                    cp = 1;
//                    break;
//                }
//            }
//            if (cp == 0) 
//            {
//                return 1;
//            }
//        }    
//    }
//    return 0;
//}
//
//
//int echiquier::cheminlibrediagonaleavantd(int ld, int la, int cd, int ca)
//{
//    int i=ld+1,j=cd+1;
//    while (i <= la && j <= ca)
//    {
//        if (t[i][j] != 0)
//        {
//            return 0;
//        }
//        i++;
//        j++;
//    }
//    return 1;
//}
//
//int echiquier::cheminlibrediagonaleavantg(int ld, int la, int cd, int ca)
//{
//    int i = ld + 1, j = cd - 1;
//    while (i <= la && j >= ca)
//    {
//        if (t[i][j] != 0)
//        {
//            return 0;
//        }
//        i++;
//        j--;
//    }
//    return 1;
//}
//
//int echiquier::cheminlibrediagonalearriered(int ld, int la, int cd, int ca)
//{
//    int i = ld - 1, j = cd + 1;
//    while (i >= la && j <= ca)
//    {
//        if (t[i][j] != 0)
//        {
//            return 0;
//        }
//        i--;
//        j++;
//    }
//    return 1;
//}



int echiquier::cheminlibredamedroite(int ld, int la, int cd, int ca)
{
    int cp=0;
    if (ld==la) 
    {
        if (cd<ca) 
        {
            for (int j=cd+1;j<ca;j++)
            {
                if (t[ld][j] != 0)
                {
                    cp = 1;
                    break;
                }
            }
            if (cp==0 || t[la][ca] * t[ld][cd] < 0) 
            {
                return 1;
            }
        }
    }
    return 0;
}

int echiquier::cheminlibredamegauche(int ld, int la, int cd, int ca)
{
    int cp=0;
    if (ld==la) 
    {
        if (cd>ca) 
        {
            for (int j=cd-1;j>=ca;j--) 
            {
                if (t[ld][j]!=0) 
                {
                    cp = 1;
                    break;
                }
            }
            if (cp==0 || t[la][ca] * t[ld][cd] < 0) 
            {
                return 1;
            }
        }    
    }
    return 0;
}

int echiquier::cheminlibrediagonaleavantd(int ld, int la, int cd, int ca)
{
    int i=ld+1, j=cd+1;
    while (i<=la && j<=ca)
    {
        if (t[i][j]!=0)
        {
            break;
        }
        i++;
        j++;
    }
    if ((i==la+1 && j==ca+1) || t[la][ca]*t[ld][cd]<0) 
    {
        return 1;
    }
    return 0;
}


int echiquier::cheminlibrediagonaleavantg(int ld, int la, int cd, int ca)
{
    int i = ld - 1, j = cd - 1;
    while (i >= la && j >= ca)
    {
        if (t[i][j] != 0)
        {
            break;
        }
        i--;
        j--;
    }
    if ((i == la - 1 && j == ca - 1) || t[la][ca] * t[ld][cd] < 0) 
    {
        return 1;
    }
    return 0;
}

int echiquier::cheminlibrediagonalearriered(int ld, int la, int cd, int ca)
{
    int i = ld - 1, j = cd + 1;
    while (i >= la && j <= ca)
    {
        if (t[i][j] != 0)
        {
            break;
        }
        i--;
        j++;
    }
    if ((i==la-1 && j==ca+1) || t[la][ca] * t[ld][cd] < 0) 
    {
        return 1;
    }
    return 0;
}

int echiquier::cheminlibrediagonalearriereg(int ld, int la, int cd, int ca)
{
    int i=ld+1, j=cd-1;
    while (i <= la && j >= ca)
    {
        if (t[i][j] != 0)
        {
            return 0;
        }
        i++;
        j--;
    }
    if(i==la+1 && j==ca-1 || t[la][ca] * t[ld][cd] < 0)
    {
    	return 1;
	}
	return 0;
    
}

int echiquier::cheminlibreavant(int ld, int la, int cd, int ca) 
{
    if (cd!=ca)
    {
        return 0;
    }
    int i=ld+1;
    while(i<=la)
    {
        if (t[i][cd]!=0)
        {
            if (t[i][cd]*t[ld][cd] < 0)
            {
                return 1; 
            }
            else
            {
                return 0; 
            }
        }
        i++;
    }
    if((i==la+1 && cd==ca) || t[la][ca] * t[ld][cd] < 0)
    {
        return 1;
    }
    return 0;
}



int echiquier::cheminlibrearriere(int ld, int la, int cd, int ca) 
{
    if (cd != ca)
    {
        return 0;
    }
    int i=ld-1;
    while (i >= la)
    {
        if (t[i][cd] != 0)
        {
            if (t[i][cd] * t[ld][cd] < 0)
            {
                return 1; // piece adverse detectee, le chemin est libre pour la prise
            }
            else
            {
                return 0; // piece alliée detectee, le chemin n'est pas libre
            }
        }
        i--;
    }
    if((i==la-1 && cd==ca) || t[la][ca] * t[ld][cd] < 0)
    {
        return 1;
    }
    return 0;
}

int echiquier::cheminlibre(int ld, int la, int cd, int ca)
{
    // Vérification du chemin libre diagonale avant droite
    if (ld < la && cd < ca)
    {
        return cheminlibrediagonaleavantd(ld, la, cd, ca);
    }
    // Vérification du chemin libre diagonale avant gauche
    else if (ld < la && cd > ca)
    {
        return cheminlibrediagonaleavantg(ld, la, cd, ca);
    }
    // Vérification du chemin libre diagonale arrière droite
    else if (ld > la && cd < ca)
    {
        return cheminlibrediagonalearriered(ld, la, cd, ca);
    }
    // Vérification du chemin libre diagonale arrière gauche
    else if (ld > la && cd > ca)
    {
        return cheminlibrediagonalearriereg(ld, la, cd, ca);
    }
    // Vérification du chemin libre avant
    else if (ld < la && cd == ca)
    {
        return cheminlibreavant(ld, la, cd, ca);
    }
    // Vérification du chemin libre arrière
    else if (ld > la && cd == ca)
    {
        return cheminlibrearriere(ld, la, cd, ca);
    }
    // Si aucun des cas précédents n'est vrai, le mouvement n'est pas valide
    else
    {
        return 0;
    }
}


int echiquier::avantgauche(int ld, int la, int cd, int ca)
{
    int i = ld + 1, j = cd - 1;  //equivalent a for(i=ld+1,j=cd-1;i<la,j>ca;i++,j--)
    while (i <= la && j >= ca)
    {
        if (t[i][j] != 0)
        {
            break;
        }
        i++;
        j--;
    }
    if ((i == la + 1 && j == ca - 1) || t[la][ca] * t[ld][cd] < 0) 
    {
        return 1;
    }
    return 0;
}

int echiquier::arrieregauche(int ld, int la, int cd, int ca)
{
    int i = ld - 1, j = cd - 1;
    while (i >= la && j >= ca)
    {
        if (t[i][j] != 0)
        {
            return 0;
        }
        i--;
        j--;
    }
    if(i==la-1 && j==ca-1 || t[la][ca] * t[ld][cd] < 0)
    {
    	return 1;
	}
	return 0;
    
}

int echiquier::dame(int ld ,int cd,int la,int ca)
{
	if(t[ld][cd]==2)
	{
		for(int i=0;i<8;i++)
		{
			if((la==ld) && (ca==cd+i)) // droite marche tres bien 
			{
				if(t[la][ca]==0 || t[la][ca]<0)
				{
					if(cheminlibredamedroite(ld,la,cd,ca)==1)
					{
						return 1;
					}

				}
				
			}
			else
			{
				if((la==ld) && (ca==cd-i))
				{
					if(cheminlibredamegauche(ld,la,cd,ca)==1) //gauche   marche tre bien
					{
						return 1;
					}
				}
				else
				{
					if((la==ld-i)&&(ca==cd)) //haut  marche tres bien
					{
							if(cheminlibre(ld,la,cd,ca)==1)
							{
							   return 1;
							}
					}
					else
					{
						if((la==ld+i)&&(ca==cd))//bas marche tres bien
						{
							if(cheminlibre(ld,la,cd,ca)==1)
							{
								return 1;
							}
						}
						else
						{
							if((la==ld-i)&&(ca==cd+i)) //droite en avant 
							{
								if(cheminlibre(ld,la,cd,ca)==1)
								{
								  return 1;
								}
							}
							else
							{
								if((la==ld+i)&&(ca==cd+i))//droite en arriere
								{
									if(cheminlibre(ld,la,cd,ca)==1)
									{
								  		return 1;
									}
								}
								else
								{
									if((la==ld-i)&&(ca==cd-i)) // gauche en avant
									{
										if(cheminlibrediagonaleavantg(ld,la,cd,ca)==1)
										{
								  		  return 1;
										}
									}
									else
									{
										if((la==ld+i)&&(ca==cd-i))  //gauche en arriere
										{
											if(cheminlibrediagonalearriereg(ld,la,cd,ca)==1)
											{
								  		  	  return 1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		
		}
		
	}
	else
	{
		if(t[ld][cd]==-2)
		{
			for(int i=0;i<8;i++)
			{
				if((la==ld)&&(ca==cd+i)) //droite
				{
				 if(t[la][ca]==0 || t[la][ca]>0)
				 {
					if(cheminlibredamedroite(ld,la,cd,ca)==1)
					{
						return 1;
					}
				 }
				}
				else
				{
					if((la==ld)&&(ca==cd-i))
					{
						if(cheminlibredamegauche(ld,la,cd,ca)==1) //gauche
						{
							return 1;
						}
					}
					else
					{
						if((la==ld-i)&&(ca==cd)) //haut
						{
							if(cheminlibre(ld,la,cd,ca)==1) 
							{
								return 1;
							}
						}
						else
						{
							if((la==ld+i)&&(ca==cd)) //bas
							{
								if(cheminlibre(ld,la,cd,ca)==1) 
								{
								return 1;
								}
							}
							else
							{
								if((la==ld+i)&&(ca==cd+i)) //droite en avant
								{
									if(cheminlibre(ld,la,cd,ca)==1) 
									{
									return 1;
									}	
								}
								else
								{
									if((la==ld-i)&&(ca==cd+i)) //droite en bas
									{
										if(cheminlibre(ld,la,cd,ca)==1) 
										{
											return 1;
										}	
									}
									else
									{
										if((la==ld+i)&&(ca==cd-i)) //gauche en avant
										{
											if(avantgauche(ld,la,cd,ca)==1) 
											{
											return 1;
											}	
										}
										else
										{
											if((la==ld-i)&&(ca==cd-i)) //gauche en arriere
											{
												if(arrieregauche(ld,la,cd,ca)==1) 
												{
												return 1;
												}	
												
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
}

int echiquier::king(int ld, int cd, int la, int ca)
{
	if(t[ld][cd]==1)
	{
			if((la==ld) && (ca==cd+1)) //droite
			{
				if((t[la][ca] == 0 || t[la][ca] < 0))
				{
					if(cheminlibreDroiteBLANC(ld,la,cd,ca)==1) // droite colonne
					{
						return 1;
					}
				}
				return 0;
		    }
			else
			{
				if((la==ld) && (ca=cd-1)) // gauche
				{
					if((t[la][ca] == 0 || t[la][ca] < 0)) // case vide ou contient une pièce adverse
					{
					  if(cheminlibreGaucheBLANC(ld,la,cd,ca)==1)
					  {
						return 1;
					  }
					  return 0;	
					}
					return 0;
				}
				else
				{
					if((la==ld-1) && (ca==cd)) //avant
					{
						if((t[la][ca] == 0 || t[la][ca] < 0))
						{
							if(cheminlibreAvantBLANC(ld,la,cd,ca)==1)
							{
								return 1;
							}
						}
					}
					else
					{
						if((la==ld+1) && (ca==cd)) //bas
						{
							if(t[la][ca]==0 || t[la][ca]<0)
							{
								if(cheminlibreArriereBLANC(ld,la,cd,ca)==1)
							    {
							      return 1;	
							    }
							}
						}
						else
						{
							if((la==ld-1) && (ca==cd+1)) //droite en avant
							{
								if(t[la][ca]==0 || t[la][ca]<0)
								{
									if(cheminlibreDigonaleDroiteAvantBLANC(ld,la,cd,ca)==1)
									{
										return 1;
									}
								}
							}
							else
							{
								if((la==ld+1) && (ca==cd+1)) //droite en arriere
								{
									if(cheminlibreDigonaleDroiteArriereBLANC(ld,la,cd,ca)==1)
									{
										if(t[la][ca]==0 || t[la][ca]<0)
										{
											return 1;
										}
									}
								}
								else
								{
									if((la==ld-1) && (ca==cd-1)) //gauche en avant
									{
										if(cheminlibreDigonaleGaucheAvantBLANC(ld,la,cd,ca)==1)
										{
											if(t[la][ca]==0 || t[la][ca]<0)
											{
												return 1;
											}
										}
									}
									else
									{
										if((la==ld+1) && (ca==cd-1)) //gauche en arriere
										{
										    if(cheminlibreDigonaleGaucheArriereBLANC(ld,la,cd,ca)==1)
											{
												if(t[la][ca]==0 || t[la][ca]<0)
												{
													return 1;
												}
											}
											return 0;
										}
										return 0;
										}
									}
									
								}
								
							}
						
						}
						
					}
					
				}
				
			
			
		}
	else
	{
		if(t[ld][cd]==-1)
		{
		for(int i=0;i<8;i++)
		 {
			if((la==ld) && (ca==cd+1)) //droite
			{
				if((t[la][ca] == 0 || t[la][ca] > 0))
				{
					if(cheminlibreDroiteNOIR(ld,la,cd,ca)==1) // droite colonne
					{
						return 1;
					}
				}
			}
			else
			{
				if((la==ld) && (ca=cd-1)) // gauche
				{
					if((t[la][ca] == 0 || t[la][ca] > 0)) // case vide ou contient une pièce adverse
					{
					  if(cheminlibreGaucheNOIR(ld,la,cd,ca)==1)
					  {
						return 1;
					  }
					  return 0;	
					}
					return 0;
				}
				else
				{
					if((la==ld+1) && (ca==cd)) //avant
					{
						if((t[la][ca] == 0 || t[la][ca] > 0))
						{
							if(cheminlibreAvantNOIR(ld,la,cd,ca)==1)
							{
								return 1;
							}
						}
					}
					else
					{
						if((la==ld-1) && (ca==cd)) //bas
						{
							if(t[la][ca]==0 || t[la][ca]>0)
							{
								if(cheminlibreArriereNOIR(ld,la,cd,ca)==1)
							    {
							      return 1;	
							    }
							}
						}
						else
						{
							if((la==ld+1) && (ca==cd+1)) //droite en avant
							{
								if(t[la][ca]==0 || t[la][ca]>0)
								{
									if(cheminlibreDigonaleDroiteAvantNOIR(ld,la,cd,ca)==1)
									{
										return 1;
									}
								}
							}
							else
							{
								if((la==ld-1) && (ca==cd+1)) //droite en arriere
								{
									if(cheminlibreDigonaleDroiteArriereNOIR(ld,la,cd,ca)==1)
									{
										if(t[la][ca]==0 || t[la][ca]>0)
										{
											return 1;
										}
									}
								}
								else
								{
									if((la==ld+1) && (ca==cd-1)) //gauche en avant
									{
										if(cheminlibreDigonaleGaucheAvantNOIR(ld,la,cd,ca)==1)
										{
											if(t[la][ca]==0 || t[la][ca]>0)
											{
												return 1;
											}
										}
									}
									else
									{
										if((la==ld-1) && (ca==cd-1)) //gauche en arriere
										{
											if(cheminlibreDigonaleGaucheArriereNOIR(ld,la,cd,ca)==1)
											{
												if(t[la][ca]==0 || t[la][ca]>0)
												{
													return 1;
												}
											}
										}
									}
									
								}
								
							}
						
						}
						
					}
					
				}
				
			}
			
		}
		return 0;
	}
		return 0;
	}
}

int echiquier::fou(int ld, int cd, int la, int ca)
{
    if(t[ld][cd]==4) // fou blanc
    {
        for(int i=0; i<8; i++)
        {
            if((la==ld-i) && (ca==cd+i)) // droite avant
            {
                if(t[la][ca]==0 || t[la][ca]<0)
                {
                    if(cheminlibre(ld,la,cd,ca)==1)
                    {
                        return 1;
                    }
                }
            }
            else if((la==ld-i) && (ca==cd-i)) // gauche avant
            {
                if(t[la][ca]==0 || t[la][ca]<0)
                {
                    if(cheminlibrediagonaleavantg(ld,la,cd,ca)==1)
                    {
                        return 1;
                    }
                }
            }
            else if((la==ld+i) && (ca==cd+i)) // droite arriere
            {
                if(t[la][ca]==0 || t[la][ca]<0)
                {
                    if(cheminlibre(ld,la,cd,ca)==1)
                    {
                        return 1;
                    }
                }
            }
            else if((la==ld+i) && (ca==cd-i)) // gauche arriere
            {
                if(t[la][ca]==0 || t[la][ca]<0)
                {
                    if(cheminlibrediagonalearriereg(ld,la,cd,ca)==1)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    else if(t[ld][cd]==-4) // fou noir
    {
        for(int i=0;i<8;i++)
        {
            if((la==ld+i) && (ca==cd+i)) // droite avant
            {
                if(t[la][ca]==0 || t[la][ca]<0)
                {
                    if(cheminlibre(ld,la,cd,ca)==1)
                    {
                        return 1;
                    }
                }
            }
            else if((la==ld+i) && (ca==cd-i)) // gauche avant
            {
                if(t[la][ca]==0 || t[la][ca]<0)
                {
                    if(avantgauche(ld,la,cd,ca)==1)
                    {
                        return 1;
                    }
                }
            }
            else if((la==ld-i) && (ca==cd+i)) // droite arriere
            {
                if(t[la][ca]==0 || t[la][ca]<0)
                {
                    if(cheminlibre(ld,la,cd,ca)==1)
                    {
                        return 1;
                    }
                }
            }
            else if((la==ld-i) && (ca==cd-i)) // gauche arriere
            {
                if(t[la][ca]==0 || t[la][ca]<0)
                {
                    if(arrieregauche(ld,la,cd,ca)==1)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int echiquier::tour(int ld, int cd, int la, int ca)
{
    if (t[ld][cd]==3) 
	{
        for (int i=0;i<8;i++) 
		{
            if ((la==ld) && (ca==cd+i)) 
			{
               if((t[la][ca] == 0 || t[la][ca] < 0))
				{
					if(cheminlibredamedroite(ld,la,cd,ca)==1)
					{
						return 1;
					}
				}
				return 0;
            }
            else
            {
            	if((la==ld) && (ca==cd-i))
            	{
            		if((t[la][ca] == 0 || t[la][ca] < 0)) // case vide ou contient une piece adverse
					{
					  if(cheminlibredamegauche(ld,la,cd,ca)==1)
						{
						  return 1;
						}
					  return 0;	
					}
					return 0;
				}
				else
				{
					if((la==ld-i) && (ca==cd))
					{
						 if((t[la][ca] == 0 || t[la][ca] < 0))
						 {
							if(cheminlibre(ld,la,cd,ca)==1)
                    		{
                        		return 1;
                    		}
						 }  
					}
					else
					{
						if((la==ld+i)&&(ca==cd))
						{
						
							if(t[la][ca]==0 || t[la][ca]<0)
							{
								if(cheminlibre(ld,la,cd,ca)==1)
                    			{
                        		  return 1;
                    			}
							}		
						}
					}
				}
			}
        }
        return 0; // Ajout d une instruction de retour si la boucle for se termine sans retourner 1
    } 
	else 
      {
    	if (t[ld][cd]==-3) 
	         {
        			for (int i=0;i<8;i++) 
		   			{
            			if ((ld==la) && (cd+i==ca) || (ld==la) && (cd-i==ca) || (ld+i==la) && (cd==ca) || (ld-i==la) && (cd==ca)) 
						{
                			if((ld==la)&&(cd+i==ca))
                			{
                				if(cheminlibredamedroite(ld,la,cd,ca)==1)
								{
									return 1;
								}
							}
							else
							{
								if((ld==la)&&(cd-i==ca))
								{
									if(cheminlibredamegauche(ld,la,cd,ca)==1)
									{
										return 1;
									}
								}
								else
								{
									if((ld+i==la)&&(cd==ca))
									{
										if(cheminlibre(ld,la,cd,ca)==1)
										{
											return 1;
										}
									}
									else
									{
										if((ld-i==la)&&(cd==ca))
										{
											if(cheminlibre(ld,la,cd,ca)==1)
											{
												return 1;
											}
										}
									}
								}
							}
            			}
           			}
        	return 0; // Ajout d une instruction de retour si la boucle for se termine sans retourner 1
    		} 
			else 
			{
        		return 0; // Ajout d une instruction de retour si t[ld][cd] ne vaut ni 3 ni -3
    		}
	  }	          
}

int echiquier::pion(int ld, int cd, int la, int ca)
{
    if (t[ld][cd]==6) 
    {
        if (((la==ld-1) || (la==ld-2)) && (ca==cd)) // Mouvement vertical
        {
            if (t[la][ca]==0) 
            {
                if (cheminlibre(ld,la,cd,ca) == 1)
                {
                    if (la==0) 
                    {
                        int choix;
                        cout << "Promotion du pion: choisissez une piece (2=reine, 4=fou, 3=tour, 5=cavalier): ";
                        cin >> choix;
                        switch (choix) 
                        {
                            case 1:
                                t[la][ca] = 2; // Reine blanche
                                break;
                            case 2:
                                t[la][ca] = 4; // Fou blanc
                                break;
                            case 3:
                                t[la][ca] = 3; // Tour blanche
                                break;
                            case 4:
                                t[la][ca] = 5; // Cavalier blanc
                                break;
                            default:
                                cout << "Choix invalide, promotion du pion annulee." << endl;
                                return 0; 
                        }
                        t[ld][cd] = 0; 
                        t[ld][cd]=choix;
                        return 1; 
                    }
                    else 
                    {
                        return 1;
                    }
                }
            }
            else 
            {
                return 0; // Interdire le deplacement vertical si la case d'arrivee est occupee
            }
        }
        else if (((la==ld-1) && (ca==cd-1 || ca==cd+1))) // Mouvement diagonal
        {
            if (t[la][ca] < 0) 
            {
                if (la==0) 
                {
                    int choix;
                    cout << "Promotion du pion: choisissez une piece (2=reine , 4=fou , 3=tour, 5=cavalier): "<<endl<<"choix : ";
                    cin >> choix;
                    switch (choix)
						{
							case 1:
								t[la][ca] = 2; // La reine est représentée par le chiffre 2
							break;
							case 2:
								t[la][ca] = 4; // Le fou est représenté par le chiffre 4
							break;
							case 3:
								t[la][ca] = 3; // La tour est représentée par le chiffre 3
							break;
							case 4:
								t[la][ca] = 5; // Le cavalier est représenté par le chiffre 5
							break;
							default:
									cout << "Choix invalide. La reine a ete choisie par defaut." << endl;
									t[la][ca] = 2; 
							break;
						}
						t[ld][cd] = 0; 
						t[ld][cd]=choix;
						cout << "Le pion a ete promu !" << endl;
				}
				else 
				{
					cout << "Le pion a avance !" << endl;
				}
			  return 1;
			}
			else 
			{
				cout << "Mouvement impossible. Case occupee ." << endl;
				return 0;
			}
		}
	}
	else
	{
		if(t[ld][cd]==-6)
		{
			if (((la == ld + 1) || (la == ld + 2)) && (ca == cd)) // Mouvement vertical
        {
            if (t[la][ca] == 0) 
            {
                if (cheminlibre(ld, la, cd, ca) == 1)
                {
                    if (la == 8) 
                    {
                        int choix;
                        cout << "Promotion du pion: choisissez une piece (-2=reine, -4=fou, -3=tour, -5=cavalier): ";
                        cin >> choix;
                        switch (choix) 
                        {
                            case 1:
                                t[la][ca] = -2; // Reine blanche
                                break;
                            case 2:
                                t[la][ca] = -4; // Fou blanc
                                break;
                            case 3:
                                t[la][ca] = -3; // Tour blanche
                                break;
                            case 4:
                                t[la][ca] = -5; // Cavalier blanc
                                break;
                            default:
                                cout << "Choix invalide, promotion du pion annulee." << endl;
                                return 0; // Sortir de la fonction sans déplacer le pion
                        }
                        t[ld][cd] = 0; 
                        t[ld][cd]=choix;
                        return 1; 
                    }
                    else 
                    {
                        return 1;
                    }
                }
            }
            else 
            {
                return 0; 
            }
        }
        else if (((la == ld + 1) && (ca == cd + 1 || ca == cd + 1))) // Mouvement diagonal
        {
            if (t[la][ca] < 0) 
            {
                if (la == 8) 
                {
                    int choix;
                    cout << "Promotion du pion: choisissez une piece (-2=reine, -4=fou, -3=tour, -5= cavalier): ";
                    cin >> choix;
                    switch (choix)
						{
							case 1:
								t[la][ca] = -2; // La reine est représentée par le chiffre -2
							break;
							case 2:
								t[la][ca] = -4; // Le fou est représenté par le chiffre -4
							break;
							case 3:
								t[la][ca] = -3; // La tour est représentée par le chiffre -3
							break;
							case 4:
								t[la][ca] = -5; // Le cavalier est représenté par le chiffre -5
							break;
							default:
									cout << "Choix invalide. La reine a ete choisie par defaut." << endl;
									t[la][ca] = -2; 
							break;
						}
						t[ld][cd] = 0; 
						t[ld][cd]=choix;
						cout << "Le pion a ete promu !" << endl;
				}
				else 
				{
					cout << "Le pion a avance !" << endl;
				}
			  return 1;
			}
			else 
			{
				cout << "Mouvement impossible. Case occupee." << endl;
				return 0;
			}
		}
		}
	}
}
int echiquier::roque(int ld, int la, int cd, int ca)
{
    if(t[ld][cd]==1 || t[ld][cd]==-1 || t[ld][cd]==3 || t[ld][cd]==-3)
    {
        if(ld==la)
        {
            // Roque court 
            if(ca==cd+2)
            {
                if(t[ld][cd+1]==0 && t[ld][cd+2]==0 && t[ld][cd+3]==3)
                {
                    t[ld][cd+2]=t[ld][cd];
                    t[ld][cd]=0;
                    t[ld][cd+1]=t[ld][ca+3];
                    t[ld][ca+3]=0;
                    return 1; 
                }
            }
            // Roque long : le roi se déplace de deux cases à gauche et la tour se place à sa droite
            else if(ca==cd-2)
            {
                if(t[ld][cd-1]==0 && t[ld][cd-2]==0 && t[ld][cd-3]==0 && t[ld][cd-4]==3)
                {
                    t[ld][cd-2]=t[ld][cd];
                    t[ld][cd]=0;
                    t[ld][cd-1]=t[ld][ca-4];
                    t[ld][ca-4]=0;
                    return 1; 
                }
            }
        }
    }
    return 0; // Roque impossible
}





echiquier::mov(int ld,int cd,int la,int ca,char joueur)
{
	if((t[ld][cd]==-5)||(t[ld][cd]==5)) // movement d'un cavalier
	{
		if(cav(ld,cd,la,ca)==1)
		{
			t[la][ca]=t[ld][cd];
			t[ld][cd]=0;
		}
		else
		{
			//"Mouvement Cavalier Impossible ";
		}
	}
	
	if((t[ld][cd]==-6)||(t[ld][cd]==6)) // movement d'un pion 
	{
		if(pion(ld,cd,la,ca)==1)
		{
			t[la][ca]=t[ld][cd];
			t[ld][cd]=0;
		}
		else
		{
			//"Mouvement pion Impossible ";
		}
	}
	
	if((t[ld][cd]==-4)||(t[ld][cd]==4)) // movement d'un fou
	{
		if(fou(ld,cd,la,ca)==1)
		{
			t[la][ca]=t[ld][cd];
			t[ld][cd]=0;
		}
		else
		{
			//"Mouvement fou Impossible ";
		}
	}
	
	if((t[ld][cd]==-3)||(t[ld][cd]==3)) // movement d'un tour
	{
		if(tour(ld,cd,la,ca)==1)
		{
			t[la][ca]=t[ld][cd];
			t[ld][cd]=0;
		}
		else
		{
			//"Mouvement tour Impossible ";
		}
	}
	
	if((t[ld][cd]==2)||(t[ld][cd]==-2)) // movement d'une dame
	{
		if(dame(ld,cd,la,ca)==1)
		{
               if (t[la][ca] != 0 && t[la][ca] > 0) 
			   {
        		// pièce adverse détectée à la case d'arrivée
        		// supprimez la pièce adverse de l'échiquier
        		t[la][ca] = 0;
    		   }
    			// déplace la dame à la case d'arrivée
    			t[la][ca] = t[ld][cd];
    			t[ld][cd] = 0;
    			return 1;
		}
		else
		{
			//"Mouvement dame Impossible ";
		}
	}
	
	if((t[ld][cd]==1)||(t[ld][cd]==-1)) // movement de king
	{
		if(king(ld,cd,la,ca)==1)
		{
			t[la][ca]=t[ld][cd];
			t[ld][cd]=0;
		}
		else
		{
			//"Mouvement king Impossible ";
		}
	}

}

//int echiquier::echecMat(int ld,int cd,int la,int ca)
//{
//	if(t[ld][cd]==1)
//	{
//		for(int i=0;i<8;i++)
//		{
//			if(cd==ca)
//			{
//				for(int j=ld-i;j>la;j--) //tester si il a un echecmat en avant
//				{
//					return 0;
//					cout<<"echec en avant";
//				}
//				
//				for(int j=ld+i;j<la;j++)
//				{
//					return 0;
//					cout<<"echec en arriere";
//				}
//			}
//			else
//			{
//				if(ld==la)
//				{
//					for(int j=cd+i;j<la;j++)
//					{
//						return 0;
//						cout<<"echec a droite";
//					}
//					
//					for(int j=cd-i;j>la;j--)
//					{
//						return 0;
//						cout<<"echec a gauche";
//					}
//					
//				}
//				else
//				{
//					int i,j;
//					if((la==ld-i)&&(ca==cd+i))//diagonale avant droite
//					{
//						for(i=ld,j=cd;i>la,j<ca;i--,j++)
//						{
//							return 0;
//							cout<<"echec a avant droite";
//						}
//					}
//					if((la==ld-i)&&(ca==cd-i))//diagonale avant gauche
//					{
//						for(i=ld,j=cd;i>la,j>ca;i--,j--)
//						{
//							return 0;
//							cout<<"echec a avant gauche";
//						}
//					}
//					if((la==ld+i)&&(ca==cd+i))//diagonale arriere droite
//					{
//						for(i=ld,j=cd;i<la,j<ca;i++,j++)
//						{
//							return 0;
//							cout<<"echec a arriere droite";
//						}
//					}
//					if((la==ld+i)&&(ca==cd-i))//diagonale arriere gauche
//					{
//						for(i=ld,j=cd;i<la,j>ca;i++,j--)
//						{
//							return 0;
//							cout<<"echec a arriere gauche";
//						}
//					}
//				}
//			}
//		}
//	}
//}



int echiquier::echecMat(int ld, int cd, int la, int ca) 
{
    if(t[ld][cd]==1) 
	{
        for(int i=0; i<8; i++) 
		{
            if(cd==ca) 
			{
                for(int j=ld-1; j>la; j--) 
				{ // Tester sil y a un échec mat en avant
                    if(t[j][cd] != 0) 
					{
                        return 0;
                    }
                }
                
                for(int j=ld+1; j<la; j++) 
				{ // Tester sil y a un échec mat en arrière
                    if(t[j][cd] != 0) 
					{
                        return 0;
                    }
                }
            } 
			else if(ld==la) 
			{
                for(int j=cd+1; j<ca; j++) 
				{ // Tester sil y a un échec mat à droite
                    if(t[ld][j] != 0) 
					{
                        return 0;
                    }
                }
                
                for(int j=cd-1; j>ca; j--) 
				{ // Tester sil y a un échec mat à gauche
                    if(t[ld][j] != 0) 
					{
                        return 0;
                    }
                }
            } 
			else if((la==ld-i) && (ca==cd+i)) 
			{ // Diagonale avant droite
                for(int j=ld-1, k=cd+1; j>la && k<ca; j--, k++) 
				{
                    if(t[j][k] != 0) 
					{
                        return 0;
                    }
                }
            } 
			else if((la==ld-i) && (ca==cd-i)) 
			{ // Diagonale avant gauche
                for(int j=ld-1, k=cd-1; j>la && k>ca; j--, k--) 
				{
                    if(t[j][k] != 0) 
					{
                        return 0;
                    }
                }
            } 
			else if((la==ld+i) && (ca==cd+i)) 
			{ // Diagonale arriere droite
                for(int j=ld+1, k=cd+1; j<la && k<ca; j++, k++) 
				{
                    if(t[j][k] != 0) 
					{
                        return 0;
                    }
                }
            } 
			else if((la==ld+i) && (ca==cd-i)) 
			{ // Diagonale arriere gauche
                for(int j=ld+1, k=cd-1; j<la && k>ca; j++, k--) 
				{
                    if(t[j][k] != 0) 
					{
                        return 0;
                    }
                }
            }
        }
        return 1; // Il n y a pas d'échec mat
    } 
	else 
	{
         return 0; // La piece n est pas valide
    }
}


int echiquier::finpartie()
{
    int tour=0; 
    char joueur='B'; 
    int ld,cd,la,ca; 
    
    for (int i=tour+1;i<50;i++)
    {
        if (joueur=='B' && tour==50)
        {
            cout << "fin partie blanc" << endl; 
            return 0;
        }
        else if (joueur=='N' && tour==50) 
        {
            cout << "fin partie noir" << endl; 
            return 0;
        }
        
        if(echecMat(ld,cd,la,ca) && joueur=='B')
        {
            cout << "joueur blanc qui gagne" << endl;
            return 1; 
        }
        else if(echecMat(ld,cd,la,ca) && joueur=='N')
        {
            cout << "joueur noir qui gagne" << endl;
            return 1; 
        }
        
        joueur=(joueur=='B') ? 'N' : 'B'; 
    }
    
    cout << "ni blanc ni noir" << endl;
    
    return 1; 
}





//TRAVAIL DE ISMAIL AABARI ET NADA EL OUARDI
