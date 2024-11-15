#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
	char *nom;
	char *cin;
	int age;
}Etudiant;

typedef struct
{
	Etudiant TEtudiant;
	char *NumGroupe;
}Groupe;

typedef struct
{
	Groupe TGroupe;
	int NumClasse;
}Classe;

typedef struct
{
	char *NomModule;
	int coefficient;
}Module;

typedef struct
{
	Classe TClasse;
	Module TModule;
	char *NomAnnee;
}Annee;
typedef struct
{
	Annee TAnnee;
	char *NomFiliere;
	char *Type;
}Filiere;

typedef struct
{
	Filiere fil;
}Etablissement;

void menuPrincip(int &choix)
{
	system("cls");
	system("color 70");
	printf("||**||*******---------------------|| CHAOUI && TAGMOUTI ||---------------------*******||**||");
	printf("								            --------------------\n\n\n");
	printf("*----------|MENU PRINCIPALE|--------------*\n");
	printf("            I-Gestion Filieres\n           II-Gestion Classes\n          III-Gestion Modules\n           IV-Gestion Etudiants\n            V-Gestion Etablissement\n           VI-Quitter\n ");
	printf("veuillez saisir votre choix : ");
	scanf("%d",&choix);
}

void menuF(int &choixF)
{
	system("cls");
	system("color 80");
	printf("||**||*******---------------------|| CHAOUI && TAGMOUTI ||---------------------*******||**||");
	printf("								            --------------------\n\n\n");
	printf("*-----------|MENU FILIERE|--------------*\n");
	printf("             1-Ajouter Filiere\n             2-Modifier Filiere\n             3-Supprimer Filiere\n             4-Lister Filiere\n             5-Rechercher Filiere\n             6-Quitter Gestion Filiere\n");
	printf("veuillez saisir votre choix : ");
	scanf("%d",&choixF);
}
void menuC(int &choixC)
{
	system("cls");
	system("color 60");
	printf("||**||*******---------------------|| CHAOUI && TAGMOUTI ||---------------------*******||**||");
	printf("								            --------------------\n\n\n");
	printf("*-----------|MENU CLASSE|--------------*\n");
	printf("             1-Ajouter Classe\n             2-Modifier Classe\n             3-Supprimer Classe\n             4-Lister Classe\n             5-Rechercher Classe\n             6-Quitter\n");
	printf("veuillez saisir votre choix : ");
	scanf("%d",&choixC);
}

void menuM(int &choixM)
{
	system("cls");
	system("color 30");
	printf("||**||*******---------------------|| CHAOUI && TAGMOUTI ||---------------------*******||**||");
	printf("								            --------------------\n\n\n");
	printf("*-----------|MENU MODULE|--------------*\n");
	printf("             1-Ajouter Module\n             2-Modifier Module\n             3-Supprimer Module\n             4-Lister Module\n             5-Rechercher Module\n             6-Quitter\n");
	printf("veuillez saisir votre choix : ");
	scanf("%d",&choixM);
}

void menuE(int &choixE)
{
	system("cls");
	system("color 20");
	printf("||**||*******---------------------|| CHAOUI && TAGMOUTI ||---------------------*******||**||");
	printf("								            --------------------\n\n\n");
	printf("*-----------|MENU ETUDIANT|--------------*\n");
	printf("             1-Ajouter Etudiant\n             2-Modifier Etudiant\n             3-Supprimer Etudiant\n             4-Lister Etudiant\n             5-Rechercher Etudiant\n             6-Quitter\n");
	printf("veuillez saisir votre choix : ");
	scanf("%d",&choixE);
}


void menuEtab(int &choixEt)
{
	system("cls");
	system("color 90");
	printf("||**||*******---------------------|| CHAOUI && TAGMOUTI ||---------------------*******||**||");
	printf("								            --------------------\n\n\n");
	printf("*-----------|MENU ETABLISSEMENT|--------------*\n");
	printf("             1-Ajouter\n             2-Modifier\n             3-Supprimer\n             4-Lister\n             5-Rechercher\n             6-Quitter\n");
	printf("veuillez saisir votre choix : ");
	scanf("%d",&choixEt);
}

///////////////////////////////////////////////////////////////////
void AjouterE(Etudiant *&E , int &e , char *cinE)
{
	if(E==NULL)
	{
		E=(Etudiant*)malloc(sizeof(Etudiant)*100);
		realloc(E,sizeof(Etudiant));
	}
	else
	{
		realloc(E,sizeof(Etudiant)*(e+1));
	}
	
	printf("veuillez saisir le nom d'Etudiant : ");
	E[e].nom=(char*)malloc(sizeof(char));
	scanf("%s",E[e].nom);
	
	printf("veuillez saisir le cin d'Etudiant : ");
	E[e].cin=(char*)malloc(sizeof(char));
	scanf("%s",E[e].cin);
	
	do{
		printf("veuillez saisir l'age d'Etudiant : ");
		scanf("%d",&E[e].age);
	}while((E[e].age<16) || (E[e].age>28));
	
	e++;
}

int findE(Etudiant *E , int e , char *cinE)
{
	for(int i=0;i<e;i++)
	{
		if(strcmp(E[i].cin,cinE)==0)
		{
			return i;
		}
	}
	return -1;
}

void ModifierE(Etudiant *E , int e , char *cinE)
{
	int pos;
	pos=findE(E,e,cinE);
	
	if(pos==-1)
	{
		printf("Etudiant INTROUVABLE !");
	}
	else
	{
		printf("veuillez saisir le nom d'Etudiant : ");
		E[pos].nom=(char*)malloc(sizeof(char));
		scanf("%s",E[pos].nom);
		
		do{
			printf("veuillez saisir l'age d'Etudiant : ");
			scanf("%d",&E[pos].age);
		}while((E[pos].age<16) || (E[pos].age>28));
	}
}

void SupprimerE(Etudiant *&E , int &e , char *cinE)
{
	int pos=findE(E,e,cinE);
	if(pos==-1)
	{
		printf("FILIERE INTROUVABLE !");
	}
	else
	{
		for(int i=pos;i<e-1;i++)
		{
			E[i]=E[i+1];
		}
		e--;
		realloc(E,sizeof(Etudiant)*(e));
	}
}


void ListerE(Etudiant *E , int e)
{
	int i;
	if(E==NULL)
	{
		printf("TABLEAU VIDE !");
	}	
	else
	{
		for(i=0;i<e;i++)
		{
			printf("NOM : %s || CIN : %s || AGE : %d\n",E[i].nom,E[i].cin,E[i].age);
		}
	}
}

void RechercherE(Etudiant *E , int e , char *cinE)
{
	int pos=findE(E,e,cinE);
	if(pos==-1)
	{
		printf("TABLEAU INTROUVABLE");
	}
	else
	{
		if(strcmp(E[pos].cin,cinE)==0)
		{
			printf("NOM : %s || CIN : %s || AGE : %d\n",E[pos].nom,E[pos].cin,E[pos].age);
		}
	}
}
/////////////////////////////////////////////////////////////////////////
void AjouterM(Module *&M , int &m)
{
	if(M==NULL)
	{
		M=(Module*)malloc(sizeof(Module)*100);
		realloc(M,sizeof(Module));
	}
	else
	{
		realloc(M,sizeof(Module)*(m+1));
	}
	
	printf("veuillez saisir le nom du module : ");
	M[m].NomModule=(char*)malloc(sizeof(char));
	scanf("%s",M[m].NomModule);
	
	printf("veuillez saisir la coefficient : ");
	scanf("%d",&M[m].coefficient);
	m++;
}

int findM(Module *M , int m , char *nomM)
{
	for(int i=0;i<m;i++)
	{
		if(strcmp(M[i].NomModule,nomM)==0)
		{
			return i;
		}
	}
	return -1;
}

void ModifierM(Module *M , int m , char *nomM)
{
	int pos=findM(M,m,nomM);
	
	if(pos==-1)
	{
		printf("MODULE INTROUVABLE !");
	}
	else
	{
		printf("veuillez saisir la coefficient : ");
		scanf("%d",&M[pos].coefficient);
	}
}

void SupprimerM(Module *&M , int &m , char *nomM)
{
	int pos=findM(M,m,nomM);
	if(pos==-1)
	{
		printf("FILIERE INTROUVABLE !");
	}
	else
	{
		for(int i=pos;i<m-1;i++)
		{
			M[i]=M[i+1];
		}
		m--;
		realloc(M,sizeof(Module)*(m));
	}
}

void ListerM(Module *M , int m)
{
	int i;
	if(M==NULL)
	{
		printf("TABLEAU VIDE !");
	}	
	else
	{
		for(i=0;i<m;i++)
		{
			printf("MODULE : %s || COEFFICIENT : %d\n",M[i].NomModule,M[i].coefficient);
		}
	}
}

void RechercherM(Module *M , int m , char *nomM)
{
	int pos=findM(M,m,nomM);
	if(pos==-1)
	{
		printf("TABLEAU INTROUVABLE");
	}
	else
	{
		if(strcmp(M[pos].NomModule,nomM)==0)
		{
			printf("MODULE : %s || COEFFICIENT : %d\n",M[pos].NomModule,M[pos].coefficient);
		}
	}
}
/////////////////////////////////////////////////////////////////////////
void AjouterC(Classe *&C , int &c)
{
	if(C==NULL)
	{
		C=(Classe*)malloc(sizeof(Classe)*100);
		realloc(C,sizeof(Classe));
	}
	else
	{
		realloc(C,sizeof(Classe)*(c+1));
	}
	
	do{
		printf("veuillez saisir le numero de classe | 1 ou 2| : ");
		scanf("%d",&C[c].NumClasse);
	}while((C[c].NumClasse!=1) && (C[c].NumClasse!=2));	
	
	do{
		printf("veuillez saisir le groupe | A ou B| : ");
		C[c].TGroupe.NumGroupe=(char*)malloc(sizeof(char));
		scanf("%s",C[c].TGroupe.NumGroupe);
	}while(((strcmp(C[c].TGroupe.NumGroupe,"A")!=0) && (strcmp(C[c].TGroupe.NumGroupe,"a")!=0)) && ((strcmp(C[c].TGroupe.NumGroupe,"B")!=0) && (strcmp(C[c].TGroupe.NumGroupe,"b")!=0)));
	c++;
}

int findC(Classe *C , int c , int cl)
{
	for(int i=0;i<c;i++)
	{
		if(C[i].NumClasse==cl)
		{
			return i;
		}
	}
	return -1;
}


void ModifierC(Classe *C , int c , int cl)
{
	int pos=findC(C,c,cl);
	if(pos==-1)
	{
		printf("Classe INTROUVABLE");
	}
	else
	{
		do{
			printf("veuillez saisir le groupe | A ou B| : ");
			C[pos].TGroupe.NumGroupe=(char*)malloc(sizeof(char));
			scanf("%s",C[pos].TGroupe.NumGroupe);
		}while(((strcmp(C[pos].TGroupe.NumGroupe,"A")!=0) && (strcmp(C[pos].TGroupe.NumGroupe,"a")!=0)) && ((strcmp(C[pos].TGroupe.NumGroupe,"B")!=0) && (strcmp(C[pos].TGroupe.NumGroupe,"b")!=0)));
	}
}

void SupprimerC(Classe *&C , int &c , int cl)
{
	int pos=findC(C,c,cl);
	if(pos==-1)
	{
		printf("FILIERE INTROUVABLE !");
	}
	else
	{
		for(int i=pos;i<c-1;i++)
		{
			C[i]=C[i+1];
		}
		c--;
		realloc(C,sizeof(Classe)*(c));
	}
}
void ListerC(Classe *C , int c)
{
	if(C==NULL)
	{
		printf("TABLEAU VIDE");
	}
	else
	{
		for(int i=0;i<c;i++)
		{
			printf("Classe : %d || Groupe : %s\n",C[i].NumClasse,C[i].TGroupe.NumGroupe);
		}
	}
}

void RechercherC(Classe *C , int c , int cl)
{
	int pos=findC(C,c,cl);
	if(pos==-1)
	{
		printf("TABLEAU INTROUVABLE");
	}
	else
	{
		if(C[pos].NumClasse==cl)
		{
			printf("Classe : %d || Groupe : %s\n",C[pos].NumClasse,C[pos].TGroupe.NumGroupe);
		}
	}
}
///////////////////////////////////////////////////////////////////////////
void AjouterF(Filiere *&F , int &n)
{
	Module *M;
	int m;
	if(F==NULL)
	{
		F=(Filiere*)malloc(sizeof(Filiere)*100);
		realloc(F,sizeof(Filiere));
	}
	else
	{
		realloc(F,sizeof(Filiere)*(n+1));
	}
	
	printf("veuillez saisir le nom du filiere : ");
	F[n].NomFiliere=(char*)malloc(sizeof(char));
	scanf("%s",F[n].NomFiliere);
	
	int choixL,choixMO;
	do{
		printf("veuillez saisir le type du Filiere ('L' ou 'l'=LICENCE || 'M' ou 'm'=MASTER) : ");
		F[n].Type=(char*)malloc(sizeof(char));
		scanf("%s",F[n].Type);
		if((strcmp(F[n].Type,"L")==0) || (strcmp(F[n].Type,"l")==0))
		{
			printf("vous avez choisi LICENCE |3 ANS|");
		}
		else if((strcmp(F[n].Type,"M")==0) || (strcmp(F[n].Type,"m")==0))
		{
			printf("vous avez choisi MASTER |2 ANS|");
		}
		else
		{
			printf("ERREUR\n");
		}
		
	}while(((strcmp(F[n].Type,"L")!=0) && (strcmp(F[n].Type,"l")!=0)) && ((strcmp(F[n].Type,"M")!=0) && (strcmp(F[n].Type,"m")!=0)));
	n++;
}

int findF(Filiere *F , int n , char *nomf)
{
	for(int i=0;i<n;i++)
	{
		if(strcmp(F[i].NomFiliere,nomf)==0)
		{
			return i;
		}
	}
	return -1;
}

void ModifierF(Filiere *F , int n , char *nomf)
{
	Module *M;
	int m;
	int choixL,choixMO;
	int pos=findF(F,n,nomf);
	if(pos==-1)
	{
		printf("Filiere INTROUVABLE !");
	}
	else
	{
		do{
			printf("veuillez saisir le type du Filiere ('L' ou 'l'=LICENCE || 'M' ou 'm'=MASTER) : ");
			F[pos].Type=(char*)malloc(sizeof(char));
			scanf("%s",F[pos].Type);
			if((strcmp(F[pos].Type,"L")==0) || (strcmp(F[pos].Type,"l")==0))
			{
				printf("vous avez choisi LICENCE |3 ANS|");
			}
			else if((strcmp(F[pos].Type,"M")==0) || (strcmp(F[pos].Type,"m")==0))
			{
				printf("vous avez choisi MASTER |2 ANS|");
			}
			else
			{
				printf("ERREUR\n");
			}
		}while(((strcmp(F[pos].Type,"L")!=0) && (strcmp(F[pos].Type,"l")!=0)) && ((strcmp(F[pos].Type,"M")!=0) && (strcmp(F[pos].Type,"m")!=0)));
	}
}

void ListerF(Filiere *F , int n)
{
	Module *M;
	int m;
	int i;
	int choixL=0;
	if(F==NULL)
	{
		printf("TABLEAU VIDE!");
	}
	else
	{
		for(i=0;i<n;i++)
		{
			printf("NOM FILIERE : %s ||",F[i].NomFiliere);
			
			if((strcmp(F[i].Type,"L")==0) || (strcmp(F[i].Type,"l")==0))
			{
				printf("TYPE : LICENCE\n");
			}
			else if((strcmp(F[i].Type,"M")==0) || (strcmp(F[i].Type,"m")==0))
			{
				printf("TYPE : MASTER\n");
			}
		}
	}
}

void SupprimerF(Filiere *&F , int &n , char *nomf)
{
	int pos=findF(F,n,nomf);
	if(pos==-1)
	{
		printf("FILIERE INTROUVABLE !");
	}
	else
	{
		for(int i=pos;i<n-1;i++)
		{
			F[i]=F[i+1];
		}
		n--;
		realloc(F,sizeof(Filiere)*(n));
	}
}

void RechercherF(Filiere *F , int n , char *nomf)
{
	int pos=findF(F,n,nomf);
	if(pos==-1)
	{
		printf("TABLEAU INTROUVABLE");
	}
	else
	{
		if(strcmp(F[pos].NomFiliere,nomf)==0)
		{
			printf("NOM FILIERE : %s ||",F[pos].NomFiliere);
			
			if((strcmp(F[pos].Type,"L")==0) || (strcmp(F[pos].Type,"l")==0))
			{
				printf("TYPE : LICENCE\n");
			}
			else if((strcmp(F[pos].Type,"M")==0) || (strcmp(F[pos].Type,"m")==0))
			{
				printf("TYPE : MASTER\n");
			}
		}
	}
}
///////////////////////////////////////////////////////////////////

void AjouterEtab(Etablissement *&T , int &taille)
{
	if(T==NULL)
	{
		T=(Etablissement*)malloc(sizeof(Etablissement)*100);
		realloc(T,sizeof(Etablissement));
	}
	else
	{
		realloc(T,sizeof(Etablissement)*(taille+1));
	}
	
	printf("veuillez saisir le nom de filiere : ");
	T[taille].fil.NomFiliere=(char*)malloc(sizeof(char));
	scanf("%s",T[taille].fil.NomFiliere);
	
	do{
		printf("veuillez saisir le type du Filiere ('L' ou 'l'=LICENCE || 'M' ou 'm'=MASTER) : ");
		T[taille].fil.Type=(char*)malloc(sizeof(char));
		scanf("%s",T[taille].fil.Type);
		if((strcmp(T[taille].fil.Type,"L")==0) || (strcmp(T[taille].fil.Type,"l")==0))
		{
			printf("vous avez choisi LICENCE |3 ANS|\n");
			
			do{
				printf("veuillez saisir || 1ER ANNEE LICENCE -> PL && 2EME ANNEE LICENCE -> DL  && 3EME ANNEE LICENCE -> TL|| : ");
				T[taille].fil.TAnnee.NomAnnee=(char*)malloc(sizeof(char));
				scanf("%s",T[taille].fil.TAnnee.NomAnnee);
				if(strcmp(T[taille].fil.TAnnee.NomAnnee,"PL")==0)
				{
					printf("veuillez saisir le nom du module : ");
					T[taille].fil.TAnnee.TModule.NomModule=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TModule.NomModule);	
					printf("veuillez saisir la coefficient du module : ");
					scanf("%d",&T[taille].fil.TAnnee.TModule.coefficient);
					do{
						printf("veuillez saisir le numero de classe | 1 ou 2| : ");
							scanf("%d",&T[taille].fil.TAnnee.TClasse.NumClasse);	
					}while((T[taille].fil.TAnnee.TClasse.NumClasse!=1) && (T[taille].fil.TAnnee.TClasse.NumClasse!=2));	

					do{
						printf("veuillez saisir le groupe | A ou B| : ");
						T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe=(char*)malloc(sizeof(char));
						scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe);
					}while(((strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"A")!=0) && (strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"a")!=0)) && ((strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"B")!=0) && (strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"b")!=0)));
					printf("veuillez saisir le nom d'Etudiant : ");
					T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom);
					printf("veuillez saisir le cin d'Etudiant : ");
					T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin);
					printf("veuillez saisir l'age d'Etudiant : ");
					scanf("%d",&T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.age);
				}
				else if(strcmp(T[taille].fil.TAnnee.NomAnnee,"DL")==0)
				{
					printf("veuillez saisir le nom du module : ");
					T[taille].fil.TAnnee.TModule.NomModule=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TModule.NomModule);	
					printf("veuillez saisir la coefficient du module : ");
					scanf("%d",&T[taille].fil.TAnnee.TModule.coefficient);
					do{
						printf("veuillez saisir le numero de classe | 1 ou 2| : ");
							scanf("%d",&T[taille].fil.TAnnee.TClasse.NumClasse);	
					}while((T[taille].fil.TAnnee.TClasse.NumClasse!=1) && (T[taille].fil.TAnnee.TClasse.NumClasse!=2));	

					do{
						printf("veuillez saisir le groupe | A ou B| : ");
						T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe=(char*)malloc(sizeof(char));
						scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe);
					}while(((strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"A")!=0) && (strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"a")!=0)) && ((strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"B")!=0) && (strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"b")!=0)));
					printf("veuillez saisir le nom d'Etudiant : ");
					T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom);
					printf("veuillez saisir le cin d'Etudiant : ");
					T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin);
					printf("veuillez saisir l'age d'Etudiant : ");
					scanf("%d",&T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.age);
				}
				else if(strcmp(T[taille].fil.TAnnee.NomAnnee,"TL")==0)
				{
					printf("veuillez saisir le nom du module : ");
					T[taille].fil.TAnnee.TModule.NomModule=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TModule.NomModule);	
					printf("veuillez saisir la coefficient du module : ");
					scanf("%d",&T[taille].fil.TAnnee.TModule.coefficient);
					do{
						printf("veuillez saisir le numero de classe | 1 ou 2| : ");
							scanf("%d",&T[taille].fil.TAnnee.TClasse.NumClasse);	
					}while((T[taille].fil.TAnnee.TClasse.NumClasse!=1) && (T[taille].fil.TAnnee.TClasse.NumClasse!=2));	

					do{
						printf("veuillez saisir le groupe | A ou B| : ");
						T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe=(char*)malloc(sizeof(char));
						scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe);
					}while(((strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"A")!=0) && (strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"a")!=0)) && ((strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"B")!=0) && (strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"b")!=0)));
					printf("veuillez saisir le nom d'Etudiant : ");
					T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom);
					printf("veuillez saisir le cin d'Etudiant : ");
					T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin);
					printf("veuillez saisir l'age d'Etudiant : ");
					scanf("%d",&T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.age);
				}
				else
				{
					printf("ERREUR\n");
				}
			}while((strcmp(T[taille].fil.TAnnee.NomAnnee,"PL")!=0) && ((strcmp(T[taille].fil.TAnnee.NomAnnee,"DL")!=0) )&& ((strcmp(T[taille].fil.TAnnee.NomAnnee,"TL")!=0)));			
		}
		else if((strcmp(T[taille].fil.Type,"M")==0) || (strcmp(T[taille].fil.Type,"m")==0))
		{
			do{
				printf("veuillez saisir  || 1ER ANNEE MASTER -> PM && 2EME ANNEE MASTER -> DM|| : ");
				T[taille].fil.TAnnee.NomAnnee=(char*)malloc(sizeof(char));
				scanf("%s",T[taille].fil.TAnnee.NomAnnee);
				
				if(strcmp(T[taille].fil.TAnnee.NomAnnee,"PM")==0)
				{
					printf("veuillez saisir le nom du module : ");
					T[taille].fil.TAnnee.TModule.NomModule=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TModule.NomModule);	
					printf("veuillez saisir la coefficient du module : ");
					scanf("%d",&T[taille].fil.TAnnee.TModule.coefficient);
					do{
						printf("veuillez saisir le numero de classe | 1 ou 2| : ");
							scanf("%d",&T[taille].fil.TAnnee.TClasse.NumClasse);	
					}while((T[taille].fil.TAnnee.TClasse.NumClasse!=1) && (T[taille].fil.TAnnee.TClasse.NumClasse!=2));	

					do{
						printf("veuillez saisir le groupe | A ou B| : ");
						T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe=(char*)malloc(sizeof(char));
						scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe);
					}while(((strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"A")!=0) && (strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"a")!=0)) && ((strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"B")!=0) && (strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"b")!=0)));
					printf("veuillez saisir le nom d'Etudiant : ");
					T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom);
					printf("veuillez saisir le cin d'Etudiant : ");
					T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin);
					printf("veuillez saisir l'age d'Etudiant : ");
					scanf("%d",&T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.age);
				}
				else if(strcmp(T[taille].fil.TAnnee.NomAnnee,"DM")==0)
				{
					printf("veuillez saisir le nom du module : ");
					T[taille].fil.TAnnee.TModule.NomModule=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TModule.NomModule);	
					printf("veuillez saisir la coefficient du module : ");
					scanf("%d",&T[taille].fil.TAnnee.TModule.coefficient);
					do{
						printf("veuillez saisir le numero de classe | 1 ou 2| : ");
							scanf("%d",&T[taille].fil.TAnnee.TClasse.NumClasse);	
					}while((T[taille].fil.TAnnee.TClasse.NumClasse!=1) && (T[taille].fil.TAnnee.TClasse.NumClasse!=2));	

					do{
						printf("veuillez saisir le groupe | A ou B| : ");
						T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe=(char*)malloc(sizeof(char));
						scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe);
					}while(((strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"A")!=0) && (strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"a")!=0)) && ((strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"B")!=0) && (strcmp(T[taille].fil.TAnnee.TClasse.TGroupe.NumGroupe,"b")!=0)));
					printf("veuillez saisir le nom d'Etudiant : ");
					T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom);
					printf("veuillez saisir le cin d'Etudiant : ");
					T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin=(char*)malloc(sizeof(char));
					scanf("%s",T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin);
					printf("veuillez saisir l'age d'Etudiant : ");
					scanf("%d",&T[taille].fil.TAnnee.TClasse.TGroupe.TEtudiant.age);
				}
				else
				{
					printf("ERREUR\n");
				}
			}while((strcmp(T[taille].fil.TAnnee.NomAnnee,"PM")!=0) && ((strcmp(T[taille].fil.TAnnee.NomAnnee,"DM")!=0) ));
		}
		else
		{
			printf("ERREUR\n");
		}	
	}while(((strcmp(T[taille].fil.Type,"L")!=0) && (strcmp(T[taille].fil.Type,"l")!=0)) && ((strcmp(T[taille].fil.Type,"M")!=0) && (strcmp(T[taille].fil.Type,"m")!=0)));
	
	taille++;
}

int findEtab(Etablissement *T , int taille , char *cin)
{
	int i;
	for(i=0;i<taille;i++)
	{
		if(strcmp(T[i].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin,cin)==0)
		{
			return i;
		}
	}
	return -1;
}

void ModifierEtab(Etablissement *T , int taille , char *cin)
{
	int pos=findEtab(T,taille,cin);
	if(pos==-1)
	{
		printf("INTROUVABLE!");
	}
	else
	{
		printf("veuillez saisir le nom de filiere : ");
		T[pos].fil.NomFiliere=(char*)malloc(sizeof(char));
		scanf("%s",T[pos].fil.NomFiliere);
	
		do{
			printf("veuillez saisir le type du Filiere ('L' ou 'l'=LICENCE || 'M' ou 'm'=MASTER) : ");
			T[pos].fil.Type=(char*)malloc(sizeof(char));
			scanf("%s",T[pos].fil.Type);
			if((strcmp(T[pos].fil.Type,"L")==0) || (strcmp(T[pos].fil.Type,"l")==0))
			{
				printf("vous avez choisi LICENCE |3 ANS|\n");
				
				do{
					printf("veuillez saisir || 1ER ANNEE LICENCE -> PL && 2EME ANNEE LICENCE -> DL  && 3EME ANNEE LICENCE -> TL|| : ");
					T[pos].fil.TAnnee.NomAnnee=(char*)malloc(sizeof(char));
					scanf("%s",T[pos].fil.TAnnee.NomAnnee);
					if(strcmp(T[pos].fil.TAnnee.NomAnnee,"PL")==0)
					{
						printf("veuillez saisir le nom du module : ");
						T[pos].fil.TAnnee.TModule.NomModule=(char*)malloc(sizeof(char));
						scanf("%s",T[pos].fil.TAnnee.TModule.NomModule);	
						printf("veuillez saisir la coefficient du module : ");
						scanf("%d",&T[pos].fil.TAnnee.TModule.coefficient);
						do{
							printf("veuillez saisir le numero de classe | 1 ou 2| : ");
							scanf("%d",&T[pos].fil.TAnnee.TClasse.NumClasse);	
						}while((T[pos].fil.TAnnee.TClasse.NumClasse!=1) && (T[pos].fil.TAnnee.TClasse.NumClasse!=2));	

						do{
							printf("veuillez saisir le groupe | A ou B| : ");
							T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe=(char*)malloc(sizeof(char));
							scanf("%s",T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe);
						}while(((strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"A")!=0) && (strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"a")!=0)) && ((strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"B")!=0) && (strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"b")!=0)));
						printf("veuillez saisir le nom d'Etudiant : ");
						T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom=(char*)malloc(sizeof(char));
						scanf("%s",T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom);
						
						printf("veuillez saisir l'age d'Etudiant : ");
						scanf("%d",&T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.age);
					}
					else if(strcmp(T[pos].fil.TAnnee.NomAnnee,"DL")==0)
					{
						printf("veuillez saisir le nom du module : ");
						T[pos].fil.TAnnee.TModule.NomModule=(char*)malloc(sizeof(char));
						scanf("%s",T[pos].fil.TAnnee.TModule.NomModule);	
						printf("veuillez saisir la coefficient du module : ");
						scanf("%d",&T[pos].fil.TAnnee.TModule.coefficient);
						do{
							printf("veuillez saisir le numero de classe | 1 ou 2| : ");
							scanf("%d",&T[pos].fil.TAnnee.TClasse.NumClasse);	
						}while((T[pos].fil.TAnnee.TClasse.NumClasse!=1) && (T[pos].fil.TAnnee.TClasse.NumClasse!=2));	

						do{
							printf("veuillez saisir le groupe | A ou B| : ");
							T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe=(char*)malloc(sizeof(char));
							scanf("%s",T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe);
						}while(((strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"A")!=0) && (strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"a")!=0)) && ((strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"B")!=0) && (strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"b")!=0)));
						printf("veuillez saisir le nom d'Etudiant : ");
						T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom=(char*)malloc(sizeof(char));
						scanf("%s",T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom);

						printf("veuillez saisir l'age d'Etudiant : ");
						scanf("%d",&T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.age);
					}
					else if(strcmp(T[pos].fil.TAnnee.NomAnnee,"TL")==0)
					{
						printf("veuillez saisir le nom du module : ");
						T[pos].fil.TAnnee.TModule.NomModule=(char*)malloc(sizeof(char));
						scanf("%s",T[pos].fil.TAnnee.TModule.NomModule);	
						printf("veuillez saisir la coefficient du module : ");
						scanf("%d",&T[pos].fil.TAnnee.TModule.coefficient);
						do{
							printf("veuillez saisir le numero de classe | 1 ou 2| : ");
							scanf("%d",&T[pos].fil.TAnnee.TClasse.NumClasse);	
						}while((T[pos].fil.TAnnee.TClasse.NumClasse!=1) && (T[pos].fil.TAnnee.TClasse.NumClasse!=2));	

						do{
							printf("veuillez saisir le groupe | A ou B| : ");
							T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe=(char*)malloc(sizeof(char));
							scanf("%s",T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe);
						}while(((strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"A")!=0) && (strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"a")!=0)) && ((strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"B")!=0) && (strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"b")!=0)));
						printf("veuillez saisir le nom d'Etudiant : ");
						T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom=(char*)malloc(sizeof(char));
						scanf("%s",T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom);

						printf("veuillez saisir l'age d'Etudiant : ");
						scanf("%d",&T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.age);
					}
					else
					{
						printf("ERREUR\n");
					}
				}while((strcmp(T[pos].fil.TAnnee.NomAnnee,"PL")!=0) && ((strcmp(T[pos].fil.TAnnee.NomAnnee,"DL")!=0) )&& ((strcmp(T[pos].fil.TAnnee.NomAnnee,"TL")!=0)));			
			}
			else if((strcmp(T[pos].fil.Type,"M")==0) || (strcmp(T[pos].fil.Type,"m")==0))
			{
				do{
					printf("veuillez saisir  || 1ER ANNEE MASTER -> PM && 2EME ANNEE MASTER -> DM|| : ");
					T[pos].fil.TAnnee.NomAnnee=(char*)malloc(sizeof(char));
					scanf("%s",T[pos].fil.TAnnee.NomAnnee);
					
					if(strcmp(T[pos].fil.TAnnee.NomAnnee,"PM")==0)
					{
						printf("veuillez saisir le nom du module : ");
						T[pos].fil.TAnnee.TModule.NomModule=(char*)malloc(sizeof(char));
						scanf("%s",T[pos].fil.TAnnee.TModule.NomModule);	
						printf("veuillez saisir la coefficient du module : ");
						scanf("%d",&T[pos].fil.TAnnee.TModule.coefficient);
						do{
							printf("veuillez saisir le numero de classe | 1 ou 2| : ");
							scanf("%d",&T[pos].fil.TAnnee.TClasse.NumClasse);	
						}while((T[pos].fil.TAnnee.TClasse.NumClasse!=1) && (T[pos].fil.TAnnee.TClasse.NumClasse!=2));	

						do{
							printf("veuillez saisir le groupe | A ou B| : ");
							T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe=(char*)malloc(sizeof(char));
							scanf("%s",T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe);
						}while(((strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"A")!=0) && (strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"a")!=0)) && ((strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"B")!=0) && (strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"b")!=0)));
						printf("veuillez saisir le nom d'Etudiant : ");
						T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom=(char*)malloc(sizeof(char));
						scanf("%s",T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom);
						
						printf("veuillez saisir l'age d'Etudiant : ");
						scanf("%d",&T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.age);
					}
					else if(strcmp(T[pos].fil.TAnnee.NomAnnee,"DM")==0)
					{
						printf("veuillez saisir le nom du module : ");
						T[pos].fil.TAnnee.TModule.NomModule=(char*)malloc(sizeof(char));
						scanf("%s",T[pos].fil.TAnnee.TModule.NomModule);	
						printf("veuillez saisir la coefficient du module : ");
						scanf("%d",&T[pos].fil.TAnnee.TModule.coefficient);
						do{
							printf("veuillez saisir le numero de classe | 1 ou 2| : ");
							scanf("%d",&T[pos].fil.TAnnee.TClasse.NumClasse);	
						}while((T[pos].fil.TAnnee.TClasse.NumClasse!=1) && (T[pos].fil.TAnnee.TClasse.NumClasse!=2));	

						do{
							printf("veuillez saisir le groupe | A ou B| : ");
							T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe=(char*)malloc(sizeof(char));
							scanf("%s",T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe);
						}while(((strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"A")!=0) && (strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"a")!=0)) && ((strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"B")!=0) && (strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe,"b")!=0)));
						printf("veuillez saisir le nom d'Etudiant : ");
						T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom=(char*)malloc(sizeof(char));
						scanf("%s",T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom);
						
						printf("veuillez saisir l'age d'Etudiant : ");
						scanf("%d",&T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.age);
					}
					else
					{
						printf("ERREUR\n");
					}
				}while((strcmp(T[pos].fil.TAnnee.NomAnnee,"PM")!=0) && ((strcmp(T[pos].fil.TAnnee.NomAnnee,"DM")!=0) ));
			}
			else
			{
				printf("ERREUR\n");
			}	
		}while(((strcmp(T[pos].fil.Type,"L")!=0) && (strcmp(T[pos].fil.Type,"l")!=0)) && ((strcmp(T[pos].fil.Type,"M")!=0) && (strcmp(T[pos].fil.Type,"m")!=0)));
	}
}

void SupprimerEtab(Etablissement *&T , int &taille , char *cin)
{
	int pos=findEtab(T,taille,cin);
	if(pos==-1)
	{
		printf("INTROUVABLE!");
	}
	else
	{
		for(int i=pos;i<taille-1;i++)
		{
			T[i]=T[i+1];
		}
		taille--;
		realloc(T,sizeof(Etablissement)*(taille));
	}
}

void ListerEtab(Etablissement *T , int taille)
{
	if(T==NULL)
	{
		printf("TABLEAU VIDE!");
	}
	else
	{
		int i;
		for(i=0;i<taille;i++)
		{
			printf("NOM FILIERE : %s\n",T[i].fil.NomFiliere);
			if((strcmp(T[i].fil.Type,"L")==0) || (strcmp(T[i].fil.Type,"l")==0))
			{
				printf("TYPE : LICENCE\n");
			}
			else if((strcmp(T[i].fil.Type,"M")==0) || (strcmp(T[i].fil.Type,"m")==0))
			{
				printf("TYPE : MASTER\n");
			} 	
			printf("ANNEE : %s\n",T[i].fil.TAnnee.NomAnnee);
			printf("MODULE : %s\n",T[i].fil.TAnnee.TModule.NomModule);
			printf("COEFFICIENT : %d\n",T[i].fil.TAnnee.TModule.coefficient);
			printf("NUMERO CLASSE : %d\n",T[i].fil.TAnnee.TClasse.NumClasse);
			printf("NUMERO GROUPE : %s\n",T[i].fil.TAnnee.TClasse.TGroupe.NumGroupe);
			printf("NOM ETUDIANT : %s\n",T[i].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom);
			printf("CIN ETUDIANT : %s\n",T[i].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin);
			printf("AGE ETUDIANT : %d\n",T[i].fil.TAnnee.TClasse.TGroupe.TEtudiant.age);
			printf("********************************************\n");
		}
	}
}


void RechercherEtab(Etablissement *T , int taille , char *cin)
{
	int i;
	int pos=findEtab(T,taille,cin);
	if(pos==-1)
	{
		printf("INTROUVABLE!");
	}
	else
	{
		if(strcmp(T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin,cin)==0)
		{
			printf("NOM FILIERE : %s\n",T[pos].fil.NomFiliere);
			if((strcmp(T[pos].fil.Type,"L")==0) || (strcmp(T[pos].fil.Type,"l")==0))
			{
				printf("TYPE : LICENCE\n");
			}
			else if((strcmp(T[pos].fil.Type,"M")==0) || (strcmp(T[pos].fil.Type,"m")==0))
			{
				printf("TYPE : MASTER\n");
			} 	
			printf("ANNEE : %s\n",T[pos].fil.TAnnee.NomAnnee);
			printf("MODULE : %s\n",T[pos].fil.TAnnee.TModule.NomModule);
			printf("COEFFICIENT : %d\n",T[pos].fil.TAnnee.TModule.coefficient);
			printf("NUMERO CLASSE : %d\n",T[pos].fil.TAnnee.TClasse.NumClasse);
			printf("NUMERO GROUPE : %s\n",T[pos].fil.TAnnee.TClasse.TGroupe.NumGroupe);
			printf("NOM ETUDIANT : %s\n",T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.nom);
			printf("CIN ETUDIANT : %s\n",T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.cin);
			printf("AGE ETUDIANT : %d\n",T[pos].fil.TAnnee.TClasse.TGroupe.TEtudiant.age);
		}
	}
}


//////////////////////////////////////////////////////////////////

main()
{
	Filiere *F=NULL;
	Classe *C=NULL;
	Module *M=NULL;
	Etudiant *E=NULL;
	Etablissement *T=NULL;
	int n,c,m,e,t,taille;
	n=0;
	c=0;
	m=0;
	e=0;
	t=0;
	taille=0;
	int cl;
	char *nomf;
	char *nomM;
	char *cinE;
	char *cin;
	int choix,choixF,choixC,choixM,choixE,choixEt;
	do{
		menuPrincip(choix);
		switch(choix)
		{
			case 1:
				do{
					menuF(choixF);
					switch(choixF)
					{
						case 1:
							system("color FC");
							AjouterF(F,n);
						break;
						
						case 2:
							system("color 75");
							printf("veuillez saisir le nom Filiere a modifier : ");
							nomf=(char*)malloc(sizeof(char));
							scanf("%s",nomf);
							ModifierF(F,n,nomf);
						break;
						
						case 3:
							system("color F2");
							printf("veuillez saisir le nom Filiere a supprimer : ");
							nomf=(char*)malloc(sizeof(char));
							scanf("%s",nomf);
							SupprimerF(F,n,nomf);
						break;
						
						case 4:
							system("color ED");
							ListerF(F,n);
						break;
						
						case 5:
							system("color B0");
							printf("veuillez saisir le nom Filiere a rechercher : ");
							nomf=(char*)malloc(sizeof(char));
							scanf("%s",nomf);
							RechercherF(F,n,nomf);
						break;
						
						case 6:
							printf("FIN PROGRAMME !");
						break;
					}
					getch();
				}while(choixF!=6);
			break;
			
			case 2:
				do{
					
					menuC(choixC);
					switch(choixC)
					{
						case 1:
							system("color FC");
							AjouterC(C,c);
						break;
						
						case 2:
							system("color 75");
							printf("veuillez saisir numero de classe a modifier : ");
							scanf("%d",&cl);
							ModifierC(C,c,cl);
						break;
						
						case 3:
							system("color F2");
							printf("veuillez saisir numero de classe a supprimer : ");
							scanf("%d",&cl);
							SupprimerC(C,c,cl);
						break;
						
						case 4:
							system("color ED");
							ListerC(C,c);
						break;
						
						case 5:
							system("color B0");
							printf("veuillez saisir numero de classe a rechercher : ");
							scanf("%d",&cl);
							RechercherC(C,c,cl);
						break;
						
						case 6:
							printf("FIN PROGRAMME !");
						break;
					}
					getch();
				}while(choixC!=6);
			break;
			
			case 3:
				do{
					menuM(choixM);
					switch(choixM)
					{	
						case 1:
							system("color FC");
							AjouterM(M,m);
						break;
						
						case 2:
							system("color 75");
							printf("veuillez saisir le nom Module a modifier : ");
							nomM=(char*)malloc(sizeof(char));
							scanf("%s",nomM);
							ModifierM(M,m,nomM);
						break;
						
						case 3:
							system("color F2");
							printf("veuillez saisir le nom Module a supprimer : ");
							nomM=(char*)malloc(sizeof(char));
							scanf("%s",nomM);
							SupprimerM(M,m,nomM);
						break;
						
						case 4:
							system("color ED");
							ListerM(M,m);
						break;
						
						case 5:
							system("color B0");
							printf("veuillez saisir le nom Module a rechercher : ");
							nomM=(char*)malloc(sizeof(char));
							scanf("%s",nomM);
							RechercherM(M,m,nomM);
						break;
						
						case 6:
							printf("FIN GESTION MODULE!");
						break;
					}
					getch();
				}while(choixM!=6);
			break;
			
			case 4:
				do{
					menuE(choixE);
					switch(choixE)
					{
						case 1:
							system("color FC");
							AjouterE(E,e,cinE);
						break;
						
						case 2:
							system("color 75");
							printf("veuillez saisir le cin a modifier : ");
							cinE=(char*)malloc(sizeof(char));
							scanf("%s",cinE);
							ModifierE(E,e,cinE);
						break;
						
						case 3:
							system("color F2");
							printf("veuillez saisir le cin a supprimer : ");
							cinE=(char*)malloc(sizeof(char));
							scanf("%s",cinE);
							SupprimerE(E,e,cinE);
						break;
						
						case 4:
							system("color ED");
							ListerE(E,e);
						break;
						
						case 5:
							system("color B0");
							printf("veuillez saisir le cin a rechercher : ");
							cinE=(char*)malloc(sizeof(char));
							scanf("%s",cinE);
							RechercherE(E,e,cinE);
						break;
						
						case 6:
							printf("FIN GESTION ETUDIANT !");
						break;
					}
					getch();
				}while(choixE!=6);
			break;
			
			case 5:
				do{
					menuEtab(choixEt);
					switch(choixEt)
					{
						case 1:
							system("color FC");
							AjouterEtab(T,taille);
						break;
						
						case 2:
							system("color 75");
							printf("veuillez saisir le cin a modifier : ");
							cin=(char*)malloc(sizeof(char));
							scanf("%s",cin);
							ModifierEtab(T,taille,cin);
						break;
						
						case 3:
							system("color F2");
							printf("veuillez saisir le cin a supprimer : ");
							cin=(char*)malloc(sizeof(char));
							scanf("%s",cin);
							SupprimerEtab(T,taille,cin);
						break;
						
						case 4:
							system("color ED");
							ListerEtab(T,taille);
						break;
						
						case 5:
							system("color B0");
							printf("veuillez saisir le cin a rechercher : ");
							cin=(char*)malloc(sizeof(char));
							scanf("%s",cin);
							RechercherEtab(T,taille,cin);
						break;
						
						case 6:
							printf("FIN PRPGRAMME ETABLISSEMENT!");
						break;
					}
					getch();
				}while(choixEt!=6);
			break;
			
			case 6:
				printf("FIN PROGRAMME || BY MARWA && GHITA|| !");
			break;
		}
		getch();
	}while(choix!=6);
	free(C);
	free(M);
	free(F);
	free(E);
	free(T);
}
