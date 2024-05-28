#ifndef ECHIQUIER_H
#define ECHIQUIER_H



class echiquier
{
	public:
		echiquier();
		~echiquier();
		init();
		int getindice(int i,int j);
		mov(int ld,int cd,int la,int ca,char joueur);
		cav(int ld,int cd,int la,int ca);
		pion(int ld,int cd,int la,int ca);	
		fou(int ld,int cd,int la,int ca);	
		tour(int ld, int cd, int la, int ca);
		dame(int ld, int cd, int la, int ca);
		king(int ld, int cd, int la, int ca);
		int cheminlibreDroiteBLANC(int ld, int la,int cd,int ca); //king blanc
		int cheminlibreAvantBLANC(int ld, int la,int cd,int ca);
		int cheminlibreArriereBLANC(int ld, int la,int cd,int ca);
		int cheminlibreGaucheBLANC(int ld, int la,int cd,int ca);
		int cheminlibreDigonaleDroiteAvantBLANC(int ld, int la,int cd,int ca);
		int cheminlibreDigonaleDroiteArriereBLANC(int ld, int la,int cd,int ca);
		int cheminlibreDigonaleGaucheAvantBLANC(int ld, int la,int cd,int ca);
		int cheminlibreDigonaleGaucheArriereBLANC(int ld, int la, int cd, int ca);
		
		int cheminlibreDroiteNOIR(int ld, int la,int cd,int ca); //king noir 
		int cheminlibreAvantNOIR(int ld, int la,int cd,int ca);
		int cheminlibreArriereNOIR(int ld, int la,int cd,int ca);
		int cheminlibreGaucheNOIR(int ld, int la,int cd,int ca);
		int cheminlibreDigonaleDroiteAvantNOIR(int ld, int la,int cd,int ca);
		int cheminlibreDigonaleDroiteArriereNOIR(int ld, int la,int cd,int ca);
		int cheminlibreDigonaleGaucheAvantNOIR(int ld, int la,int cd,int ca);
		int cheminlibreDigonaleGaucheArriereNOIR(int ld, int la, int cd, int ca);
		
		int cheminlibredamedroite(int ld ,int la,int cd,int ca); // dame ou tour noir et blanc
		int cheminlibredamegauche(int ld ,int la,int cd,int ca); // dame ou tour 
		int cheminlibre(int ld, int la, int cd, int ca);
		int cheminlibrearriere(int ld, int la, int cd, int ca);
		int	cheminlibreavant(int ld, int la, int cd, int ca);
		int	cheminlibrediagonalearriereg(int ld, int la, int cd, int ca); //dame,fou
		int cheminlibrediagonalearriered(int ld, int la, int cd, int ca); //dame,fou
		int cheminlibrediagonaleavantg(int ld, int la, int cd, int ca);   //dame,fou
		int cheminlibrediagonaleavantd(int ld, int la, int cd, int ca);   //dame,fou
		
		int avantgauche(int ld, int la, int cd, int ca);   // dame,fou noir
		int arrieregauche(int ld, int la, int cd, int ca); // dame,fou noir 


		int roque(int ld, int la, int cd, int ca);
		int cheminlibrePION(int ld,int cd,int la,int ca);
		int echecMat(int ld,int cd,int la,int ca);
//		partie();
		finpartie();
	private:
		int t[8][8];
};

#endif
