#include "PasswordException.h"
/*********************************************/
/*********Constructeur et Destructeur*********/
/*********************************************/
PasswordException::PasswordException()
{
	#ifdef DEBUG
		cout<<"Constructeur par défault de PasswordException"<<endl;
	#endif

	setCode(0);
}
PasswordException::PasswordException(string m,int c):Exception(m)
{
	#ifdef DEBUG
		cout<<"Constructeur d'initialisation de PasswordException"<<endl;
	#endif

	setCode(c);
}
PasswordException::PasswordException(const PasswordException&source):Exception(source)
{
	#ifdef DEBUG
		cout<<"Constructeur de copie de PasswordException"<<endl;
	#endif

	setCode(source.getCode());
}
PasswordException::~PasswordException()
{
	#ifdef DEBUG
		cout<<"Destructeur de copie de PasswordException"<<endl;
	#endif
}
/*********************************************/
/***********Getters et Setters****************/
/*********************************************/
void PasswordException::setCode(int c)
{
	code=c;
}
int PasswordException::getCode()const
{
	return code;
}

const int PasswordException::INVALID_LENGTH=0;
const int PasswordException::ALPHA_MISSING=1;
const int PasswordException::DIGIT_MISSING=2;
const int PasswordException::NO_PASSWORD=3;