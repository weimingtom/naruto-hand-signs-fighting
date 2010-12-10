/*
 ******************************************************
 * NAME:
 * TrainingWindow.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 28, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "TrainingWindow.h"
#include "../DebugPrint.h"

static const string TIMER_STR = "00'.";
static const string TIMER_STR_DEC = "00'.0";
static const string TIMER_STR_SEC = "''";
static const char* TEMP_IMAGE_FILE = "tempImg.png";

using namespace std;

TrainingWindow::TrainingWindow(string targetMove) : MenuWindow() {
	title = "TRAINING SECTION";
	move = movesSetGlobal->getMove(targetMove);
	oldScreenWidth = screenWidth;
	oldScreenHeight = screenHeight;
	screenWidth = TRAINING_WINDOW_WIDTH;
	screenHeight = TRAINING_WINDOW_HEIGHT;
	screen = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_HWSURFACE);
	panel->setDimension(gcn::Rectangle(0,0, screenWidth, screenHeight));
	currentSealIndex = 0;
	seconds = 0;
	scores = 0;
	g_thresh = 100;
	g_gray = NULL;
	g_storage = NULL;
}

TrainingWindow::~TrainingWindow() {
	delete labelName;
	delete labelElement;
	delete labelRank;
	delete labelType;
	delete bigImageIcon;
	delete bigImage;
	delete bigImageLabel;
	delete secondsLabel;
	delete shotButton;
	delete bottomRow;
	delete cameraWindow;
	delete cameraIcon;
	delete cameraImage;
	delete secondsTitle;
	delete scoresBox;
	for(int i=0; i< icoVector.size(); i++)
		delete icoVector.at(i);
	icoVector.clear();
}

void TrainingWindow::restoreOldSizeWindow(){
	screen = SDL_SetVideoMode(oldScreenWidth, oldScreenHeight, 32, SDL_HWSURFACE);
	panel->setDimension(gcn::Rectangle(0,0, oldScreenWidth, oldScreenHeight));
}

void TrainingWindow::buildMoveDescription(int x, int y){
	string type;
	int distanceMoveDescription = 20;

	//Move Name:
	labelName = new gcn::Label("NAME: ");
	y = titleLabel->getY() + titleLabel->getHeight() + 10;
	labelName->setPosition(x, y);
	panel->add(labelName);
	moveName = new gcn::Label(move->getMoveName().c_str());
	moveName->setPosition(x + labelName->getWidth(), y);
	panel->add(moveName);


	//Move Element:
	labelElement = new gcn::Label("ELEMENT: ");
	y = labelName->getY() + distanceMoveDescription;
	labelElement->setPosition(x, y);
	panel->add(labelElement);
	moveElement = new gcn::Label(move->getElementStr().c_str());
	moveElement->setPosition(x+labelElement->getWidth(), y);
	panel->add(moveElement);

	//Move Rank:
	labelRank = new gcn::Label("RANK: ");
	y = labelElement->getY() + distanceMoveDescription;
	labelRank->setPosition(x, y);
	panel->add(labelRank);
	moveRank = new gcn::Label(move->getRankStr().c_str());
	moveRank->setPosition(x+labelRank->getWidth(), y);
	panel->add(moveRank);

	//Move type
	labelType = new gcn::Label("TYPE: ");
	y = labelRank->getY() + distanceMoveDescription;
	labelType->setPosition(x, y);
	panel->add(labelType);
	type = move->getType().japName + " - " +  move->getType().engName ;
	moveType = new gcn::Label(type.c_str());
	moveType->setPosition(x+labelType->getWidth(), y);
	panel->add(moveType);
}

void TrainingWindow::buildCameraWindow(){
	//Camera Window:
	cameraWindow = new gcn::Window("Camera");
//	cameraWindowWidth = screenWidth - (bigImageIcon->getWidth() + 30);
//	cameraWindowHeight = screenHeight - (titleLabel->getHeight() + bottomRowScroll->getHeight() + 30);
	cameraWindowWidth = 640;
	cameraWindowHeight = 480;
	cameraWindowX = screenWidth - cameraWindowWidth - 10;
	cameraWindowY = 10;
	cameraWindow->setSize(cameraWindowWidth, cameraWindowHeight);
	cameraWindow->setPosition(cameraWindowX, cameraWindowY);
	cameraWindow->setMovable(false);

	cameraIcon = NULL;
	//Remember: the size will be set to the closer approximation
	//of a well difined resolution: 320x240, 640x480 and 1280x960
	cam->setCaptureSize(cameraWindowWidth, cameraWindowHeight);
}

void TrainingWindow::buildBottomRow(int x, int y){
	gcn::Image* image;
	//Small Seals Thumbnails:
	gcn::Icon* ico;
	bottomRow = new gcn::Window("SEALS:");
	bottomRow->setPosition(10,screenHeight - 400);
	int bottomRowScrollWidth = screenWidth - 20;
	int bottomRowScrollHeight = 160;
	int brWidth = 0;
	//here the position is relative into the window
	x = 0;
	y = 0;
	for(int i=0; i<move->getMoveSeals().size(); i++){
		//		debugPrint("reaching the image: %s\n",
		//				move->getMoveSeals().at(i)->getThumbnailImagePath().c_str());
		image = gcn::Image::load(move->getMoveSeals().at(i)->getThumbnailImagePath().c_str());
		//		debugPrint("creating the ico\n");
		ico = new gcn::Icon(image);
		ico->setSize(130, 130);
		ico->setPosition(x,y);
		x += ico->getWidth() + 10;
		brWidth += ico->getWidth();
		icoVector.push_back(ico);
		//		debugPrint("adding to bottom row\n");
		bottomRow->add(ico);
	}
	if(brWidth < bottomRowScrollWidth)
		brWidth = bottomRowScrollWidth;
	bottomRow->setSize(brWidth + ico->getWidth(), 200);
	bottomRowScroll = new gcn::ScrollArea(bottomRow);
	bottomRowScroll->setHorizontalScrollPolicy( gcn::ScrollArea::SHOW_ALWAYS);
	bottomRowScroll->setVerticalScrollPolicy(gcn::ScrollArea::SHOW_NEVER);
	bottomRowScroll->setSize(bottomRowScrollWidth, bottomRowScrollHeight);
	bottomRowScroll->setPosition(10, screenHeight - bottomRowScroll->getHeight() - 10);
	panel->add(bottomRowScroll);
}

void TrainingWindow::translateTitleLabel(){
	titleLabel->setPosition( 40, 20);
}

void TrainingWindow::buildShotButton(){
	//we position the back button away
	shotButton = new gcn::Button("[S]HOT!");
	shotButton->setPosition(bigImageIcon->getX(),
			bigImageIcon->getY() + bigImageIcon->getHeight() + 25);
	shotButton->setSize(bigImageIcon->getWidth(), buttonHeight + 20);
	shotButton->setFrameSize(3);
	shotButton->setActionEventId("shot");
	shotButton->addActionListener(new EventToKeyPressConverter());
	panel->add(shotButton);
}

void TrainingWindow::buildWindow(){

	int numberOfSeals = move->getMoveSeals().size();


	buildBackButton();
	buildTitle();
	translateTitleLabel();

	int x=10, y=0;
	buildMoveDescription(x, y);

	//Current Seal
	string path = move->getMoveSeals().at(currentSealIndex)->getThumbnailImagePath();
	bigImage = gcn::Image::load(path);
	bigImageIcon = new gcn::Icon(bigImage);
	bigImageIcon->setPosition(10,labelType->getY() + 60);
	panel->add(bigImageIcon);
	bigImageLabel = new gcn::Label("CURRENT SEAL");
	bigImageLabel->setPosition(bigImageIcon->getX() + (bigImageIcon->getWidth()/2) -
			(bigImageLabel->getWidth()/2),
			bigImageIcon->getY() - 20);
	panel->add(bigImageLabel);

	buildBottomRow(x,y);
	buildCameraWindow();
	buildShotButton();

	backButton->setPosition(bigImageIcon->getX(),
			shotButton->getY() + shotButton->getHeight() + 15);

	//Seconds Label:
	//Warning: the string inserted into the Label constructor also defines the
	//total length of the label
	secondsLabel = new gcn::Label("00'.00''"); //<-
	secondsTitle = new gcn::Label("Timer");
//	secondsLabel->setPosition(cameraWindow->getX() + cameraWindow->getWidth()/2,
//			cameraWindow->getY() + cameraWindow->getHeight() + 5);
	secondsTitle->setPosition(cameraWindow->getX() - secondsTitle->getWidth() - 40,
			labelName->getY());
	secondsLabel->setPosition(secondsTitle->getX(),
			secondsTitle->getY() + secondsLabel->getHeight() + 10);
	panel->add(secondsLabel);
	panel->add(secondsTitle);

	buildScoresBox();
	createTemplateContours();

//	delete image;
}

void TrainingWindow::display(){
//	debugPrint("cameraCapturing\n");
	if(cam->capturing() < 0){
		cout<<"ERROR: capturing of the camera fails!\n";
	}
//	debugPrint("image conversion:...\n");
	cvDrawContours(
			cam->getFrame(),
			contours,
			cvScalarAll(255),
			cvScalarAll(255),
			100 );
	cameraImage = convertIplImageToGcnImage(cam->getFrame());
	if(cameraIcon == NULL){
		cameraIcon = new gcn::Icon(cameraImage);
		cameraIcon->setSize(cameraWindowWidth, cameraWindowHeight);
		cameraIcon->setPosition(cameraWindowX, cameraWindowY);
//		cameraWindow->add(cameraIcon);
		panel->add(cameraIcon);
	}
//	debugPrint("go to the display!!\n");
	cameraIcon->setImage(cameraImage);

	/////////////////////////
	//Updating the seconds//
	std::stringstream streamtemp;
	string temp;
	streamtemp << seconds;
	if(seconds > 9)
		temp = TIMER_STR + streamtemp.str();
	else
		temp = TIMER_STR_DEC + streamtemp.str();
	temp += TIMER_STR_SEC;
	secondsLabel->setCaption(temp.c_str());

	AbstractFactory::display();
}

gcn::Image* TrainingWindow::convertIplImageToGcnImage(IplImage* iplImage){
	SDL_Surface* surf = ipl_to_surface(iplImage);
	gcn::SDLImage* sdlImage = new gcn::SDLImage(surf,false);
	return (gcn::Image*) sdlImage;
}

SDL_Surface* TrainingWindow::ipl_to_surface (IplImage *opencvimg)
{
    int pitch = opencvimg->nChannels*opencvimg->width;
//    printf("Depth %d, nChannels %d, pitch %d\n", opencvimg->depth,
//                    opencvimg->nChannels, pitch);
    SDL_Surface *surface = SDL_CreateRGBSurfaceFrom((void*)opencvimg->imageData,
                    opencvimg->width,
                    opencvimg->height,
                    opencvimg->depth*opencvimg->nChannels,
                    opencvimg->widthStep,
                    0xff0000, 0x00ff00, 0x0000ff, 0
                    );
    return surface;

}


void ResizingListener::action(const gcn::ActionEvent & actionEvent){
	if(strcmp(actionEvent.getId().c_str(),"back") == 0){
		trainingWindow->restoreOldSizeWindow();
	}
	EventToKeyPressConverter::action(actionEvent);
}

void TrainingWindow::buildScoresBox(){
	scoresBox = new gcn::TextBox("scores:  \n");
//	scoresBox->setPosition( cameraWindow->getX() - scoresBox->getWidth() - 40 ,
//			secondsLabel->getY() + secondsLabel->getHeight() + 40);
	scoresBox->setSize(130, 150);
	scoresBox->setBackgroundColor(gcn::Color(10, 10, 255, 0));
	scoresBoxScroll = new gcn::ScrollArea(scoresBox);
	scoresBoxScroll->setSize(130, 150);
	scoresBoxScroll->setPosition( cameraWindow->getX() - scoresBox->getWidth() - 40 ,
				bigImageIcon->getY());
	panel->add(scoresBoxScroll);
}

void TrainingWindow::updateScore(double newScore){
	string sc = scoresBox->getText();
	std::stringstream streamtempSc;

	if(currentSealIndex < move->getMoveSeals().size()){
		scores =newScore;
		streamtempSc << scores;
		sc = sc + move->getMoveSeals().at(currentSealIndex)->getName() + " " +
				streamtempSc.str() + "\n";
	}
	scoresBox->setText(sc);
}

void TrainingWindow::incrementCurrentSealIndex(){
	currentSealIndex++;
	if(currentSealIndex < move->getMoveSeals().size()){
			debugPrint("currentSealIndex is: %d\n", currentSealIndex);
		string path = move->getMoveSeals().at(currentSealIndex)->getThumbnailImagePath();
			debugPrint("path to image is: %s", path.c_str());
		bigImage = gcn::Image::load(path);
		bigImageIcon->setImage(bigImage);
		createTemplateContours();
	}else{
		cout<<"You have just accomplished this move!\nPlease select a new one.\n";
		scoresBox->setText( scoresBox->getText() + "\ncompleted!\nselect a\nnew one\n" );
	}
}

void TrainingWindow::createTemplateContours(){
	IplImage* g_image = cvLoadImage(
			move->getMoveSeals().at(currentSealIndex)->getTemplateImagePath().c_str());
	if( g_storage != NULL ){
		cvClearMemStorage( g_storage );
		cvReleaseImage(&g_gray);
	}
	g_gray = cvCreateImage( cvGetSize( g_image ), 8, 1 );
	g_storage = cvCreateMemStorage(0);

	contours = 0;
	cvCvtColor( g_image, g_gray, CV_BGR2GRAY );
	cvThreshold( g_gray, g_gray, g_thresh, 255, CV_THRESH_BINARY );
	cvFindContours( g_gray, g_storage, &contours );
	cvZero( g_gray );
}
