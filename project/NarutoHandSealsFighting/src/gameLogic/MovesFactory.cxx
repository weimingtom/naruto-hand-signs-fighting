/*
 * MovesFactory.cxx
 *
 *  Created on: Nov 19, 2010
 *      Author: michele
 */

#include <strings.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

#include "MovesFactory.h"
#include "MovesFactorySettings.h"

int usingTinyxml(MovesSet* mSet,  SealsMap* sm);

MovesFactoryAbstract *movesFactory = new MovesFactory();

void MovesFactory::buildMovesSet(MovesSet* mSet,  SealsMap* sm){
	cout<<"usingTinyxml call\n";
	cout<<"returning usingTinyxml :"<<usingTinyxml(mSet, sm)<<"\n";
}


int usingTinyxml(MovesSet* mSet,  SealsMap* sm){
	const char* name;
	MoveType t;
	MoveElements e;
	DifficultyRank d;

	TiXmlDocument doc(XML_FILE);
	if (!doc.LoadFile()) return -1;

	TiXmlHandle hDoc(&doc);
	TiXmlElement* pElem; //pointer user to go through the file
	TiXmlElement* moveIterator;
	TiXmlHandle moveHandler(0);

	// element: moveslist
	{
		pElem=hDoc.FirstChildElement().Element();
		// should always have a valid root but handle gracefully if it does
		if (!pElem) return -1;
		cout<<pElem->Value()<<"\n";
	}

	// element: move
	{
		pElem=pElem->FirstChildElement("move");
		// should always have a valid root but handle gracefully if it does
		if (!pElem) return -1;
		// save this for later
		moveHandler=TiXmlHandle(pElem);
		cout<<pElem->Value()<<"\n";
	}

	for(moveIterator = moveHandler.Element();
			moveIterator;
			moveIterator = moveIterator->NextSiblingElement()){

		Move *mTemp = new Move();
		moveHandler =TiXmlHandle(moveIterator);

		// element: name
		{
			pElem = moveHandler.FirstChildElement("name").Element();
			// should always have a valid root but handle gracefully if it does
			if (!pElem) return -1;
			//		name=pElem->Value();
			//We must clean the quotes "..." from the xml file
			string filter = string(pElem->FirstChild()->Value());
			mTemp->setMoveName(filter.substr(1, filter.length()-2).c_str());
//			cout<<pElem->Value()<<" "<<pElem->FirstChild()->Value()<<"\n";

		}

		// element: jutsutype
		{
			pElem = moveHandler.FirstChildElement("jutsutype").Element();
			// should always have a valid root but handle gracefully if it does
			if (!pElem) return -1;
			t.japName= string(pElem->FirstChild()->Value());
			mTemp->setType(t);

//			cout<<pElem->Value()<<" "<<pElem->FirstChild()->Value()<<"\n";
		}

		// element: move element
		{
			pElem = moveHandler.FirstChildElement("element").Element();
			// should always have a valid root but handle gracefully if it does
			if (!pElem) return -1;
			mTemp->setElementStr(string(pElem->FirstChild()->Value()));

//			cout<<pElem->Value()<<" "<<pElem->FirstChild()->Value()<<"\n";
		}

		// element: difficultyrank
		{
			pElem = moveHandler.FirstChildElement("difficultyrank").Element();
			// should always have a valid root but handle gracefully if it does
			if (!pElem) return -1;
			mTemp->setRankStr(string(pElem->FirstChild()->Value()));

//			cout<<pElem->Value()<<" "<<pElem->FirstChild()->Value()<<"\n";
		}

		// elements: seallist
		{
			pElem=moveHandler.FirstChildElement( "seallist" ).Element();
//			cout<<pElem->Value()<<"\n";
			for( pElem=pElem->FirstChildElement(); pElem; pElem=pElem->NextSiblingElement())
			{
				const char *pKey=pElem->Value();
				try{
				mTemp->addSeal( sm->getSeal(pKey) );
				}catch(std::exception e){
					cout<<e.what()<<"\n";
				}
//				cout<< pKey <<",";
			}
//			cout<<"\n";
		}
		mSet->addMove(mTemp);
	}

	return 0;
}
