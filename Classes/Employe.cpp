#include "Employe.h"
#include "PasswordException.h"
/*********************************************/
/*********Constructeur et Destructeur*********/
/*********************************************/
Employe::Employe():Intervenant()
{
	#ifdef DEBUG
		cout<<"Constructeur par défault de Employe"<<endl;
	#endif

	setLogin("Pas de login");
	setFonction("Pas de fonction");
	mdp=NULL;
}
Employe::Employe(string nom,string prenom,int numero,string login,string fonction):Intervenant(nom,prenom,numero)
{
	#ifdef DEBUG
		cout<<"Constructeur d'initialisation de Employe"<<endl;
	#endif

	setLogin(login);
	setFonction(fonction);
	mdp=NULL;
}
Employe::Employe(const Employe &source):Intervenant(source)
{
	#ifdef DEBUG
		cout<<"Constructeur de copie de Employe"<<endl;
	#endif

	setLogin(source.getLogin());
	setFonction(source.getFonction());
	mdp=new string;
	*mdp=source.getMotDePasse();
}
Employe::~Employe()
{
	#ifdef DEBUG
		cout<<"Destructeur de Employe"<<endl;
	#endif

	delete mdp;
}
/*********************************************/
/***********Getters et Setters****************/
/*********************************************/
void Employe::setLogin(string l)
{
	login=l;
}
void Employe::setMotDePasse(string m)
{
	ResetMotDePasse();
	int digit=0,alpha=0;
	if(m.size()<6)
	{
		throw PasswordException("MDP inférieur à 6 caractères",PasswordException::INVALID_LENGTH);
	}
	for(int i=0;i<m.size();i++)
	{
		if(isalpha(m[i]))
		{
			alpha=1;
		}
		if(isdigit(m[i]))
		{
			digit=1;
		}
	}
	if(alpha==0)
	{
		throw PasswordException("MDP sans lettre",PasswordException::ALPHA_MISSING);
	}
	if(digit==0)
	{
		throw PasswordException("MDP sans chiffre",PasswordException::DIGIT_MISSING);
	}
	if(mdp==NULL)
	{
		mdp=new string(m);
	}
}
void Employe::setFonction(string f)
{
	fonction=f;
}
string Employe::getLogin()const
{
	return login;
}
string Employe::getMotDePasse()const
{
	string a;
	if(mdp==NULL)
	{
		throw PasswordException("Employe sans MDP",PasswordException::NO_PASSWORD);
	}
	return *mdp;
}
string Employe::getFonction()const
{
	return fonction;
}
/*********************************************/
/***********Methodes publiques****************/
/*********************************************/
void Employe::Affiche()const
{
	Intervenant::Affiche();
	cout<<"Login:"<<getLogin()<<endl;
	if(mdp!=NULL)
		cout<<"Mot de passe:"<<getMotDePasse()<<endl;
	cout<<"Fonction:"<<getFonction()<<endl;
}
void Employe::ResetMotDePasse()
{
	if(mdp!=NULL)
	{
		delete mdp;
		mdp=NULL;
	}
}

string Employe::ToString()const
{
	string tostring;
	if(fonction.compare("Administratif"))
	{
		tostring="[A"+to_string(getNumero())+"] "+getNom()+" "+getPrenom();
	}
	if(fonction.compare("Vendeur"))
	{
		tostring="[V"+to_string(getNumero())+"] "+getNom()+" "+getPrenom();
	}
	return tostring;
}

string Employe::Tuple() const
{
	string tuple;

	tuple=to_string(getNumero())+";"+getNom()+";"+getPrenom()+";"+getFonction();
	return tuple;
}
/*********************************************/
/***********Sucharge Opérateur****************/
/*********************************************/
Employe& Employe::operator=(const Employe& source)
{
	Intervenant::operator=(source);
	setLogin(source.getLogin());
	setFonction(source.getFonction());
	setMotDePasse(source.getMotDePasse());

	return(*this);
}

ostream& operator<<(ostream& s, const Employe& source)
{
	//source.Affiche();
	s<<"Nom:"<<source.getNom()<<endl<<"Prenom:"<<source.getPrenom()<<endl<<"Numero:"<<source.getNumero()<<endl<<"Login:"<<source.getLogin()<<endl;
	if(source.mdp!=NULL)
		s<<"Mot de passe:"<<source.getMotDePasse()<<endl;
	s<<"Fonction:"<<source.getFonction()<<endl;
	return s;
}

const string Employe::ADMINISTRATIF = "Administratif";
const string Employe::VENDEUR = "Vendeur";