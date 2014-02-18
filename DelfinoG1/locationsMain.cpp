/*
 * Filename: locationsMain.cpp
 *
 * Description: This program includes the initialization routines of openGL, as well as the main
 *              function that runs the campus map program.
 *
 */

#include "locations.h"
#include "vertices.h"
#include <vector>

// GLOBALS
float CUR_X = 50.0;                     // the x position of the navigation cursor
float CUR_Y = 50.0;                     // the y position of the navigation cursor
vector<Pavement> ROADS;                 // a Pavement vector that will store all of the Roads on the map
vector<Location> MISC_LABELED;          // a Location vector that will store miscallaneous objects that require labels
vector<Housing> DORMS;                  // a Housing vector that will store all of the housing objects
vector<CampusBuilding> CAMPUS_BUILDINGS;// a CampusBuilding vector that will store all of the campus building objects
CampusBuilding CHAPEL("Chapel",chapelX,chapelY,42.7,55.7);                      // CHAPEL GLOBAL used for highlighting
Academic MARS("Mars Center for Science and Technology",marsX,marsY,34.3,34.0);  // MARS GLOBAL used for highlighting
Academic LIB1("Wallace Library",lib1X,lib1Y,35.5,39.0);                         // LIB1 GLOBAL used for highlighting
Academic LIB2("Wallace Library",lib2X,lib2Y,35.5,39.0);                         // LIB2 GLOBAL used for highlighting
vector<CampusBuilding> FIELDHOUSE;      // a CampusBuilding vector that will store the three parts of Haas
bool dormsHighlight = false;            // a boolean indicating whether or not the dorms are highlighted
bool chapelHighlight = false;           // a boolean indicating whether or not the Chapel is highlighted
bool haasHighlight = false;             // a boolean indicating whether or not the fieldhouse (Haas) highlighted
bool libHighlight = false;              // a boolean indicating whether or not the Library highlighted
bool marsHighlight = false;             // a boolean indicating whether or not MARS is highlighted
bool labelsON = true;                   // a boolean indicating whether or not the labels are toggled on/off
bool roadsOn = true;                    // a boolean indicating whether or not the roads are toggled on/off
bool legendOn = true;                   // a boolean indicating whether or not the legend is toggled on/off

// draw function prototypes
void drawRoads();
void drawLots();
void drawFields();
void drawHousing();
void drawCampusBuildings();
void drawAcademic();
void drawDining();
void drawLabels();
void drawCursor();
int displayPosition(float,float);
void displayLegend();
void displayDirections();

// =================================== Drawing the Model =====================
void drawModel()
// The main display file of the openGL project. Everything that is drawn as output on the visualization window
// is drawn in this function.
// Pre: The program in running its main glut loop, calling its main drawing function
// Post: All of the locations will be successfully drawn in the map
{
   glClear(GL_COLOR_BUFFER_BIT);
   drawLots();
   if(roadsOn)
   {
      drawRoads();
   }
   drawFields();
   drawHousing();
   drawAcademic();
   drawDining();
   drawCampusBuildings();
   if(labelsON)
   {
      drawLabels();
   }
   if(legendOn)
   {
      displayLegend();
   }
   drawCursor();
   displayPosition(CUR_X,CUR_Y);
   glFlush(); 
}

void drawLots()
// draws all of the parking lots by initializing an object for each one. Also, the objects are 
 // added to the global vector so they can be used in other parts of the code.
 // Pre: The program is running for the first time and all of the lots are being drawn
 // Post: All of the parking lots will be displayed on the map
{
   // Draw parking lots
   Pavement pl1("Lot 1",pl1x,pl1y,20.0,82.5);
   Pavement pl3("Lot 3",pl3x,pl3y,90.0,15.0);
   Pavement pl1a("Lot 1A",pl1ax,pl1ay,7.5,88.2);
   Pavement pl2("Lot 2",pl2x,pl2y,65.0,81.0);
   Pavement pl10("Lot 10",pl10x,pl10y,11.5,62.5);
   Pavement pl4("Lot 4",pl4x,pl4y,67.0,42.5);
   Pavement pl8("Lot 8",pl8x,pl8y,33.0,15.0);
   Pavement pl9("Lot 9",pl9x,pl9y,31.5,24.0);
   Pavement pl3a("",pl3ax,pl3ay,0.0,0.0);
   Pavement pl3b("",pl3bx,pl3by,0.0,0.0);
   Pavement pl3c("",pl3cx,pl3cy,0.0,0.0);
   Pavement pl7("Lot 7",pl7x,pl7y,52.6,16.5);
   // add to global LOTS
   MISC_LABELED.push_back(pl1a),MISC_LABELED.push_back(pl1),MISC_LABELED.push_back(pl2),MISC_LABELED.push_back(pl3),
   MISC_LABELED.push_back(pl4),MISC_LABELED.push_back(pl7),MISC_LABELED.push_back(pl8),MISC_LABELED.push_back(pl9),
   MISC_LABELED.push_back(pl10),MISC_LABELED.push_back(pl3a),MISC_LABELED.push_back(pl3b),MISC_LABELED.push_back(pl3c);
}

void drawRoads()
// draws all of the roads by initializing an object for each one. Also, the objects are 
 // added to the global vector so they can be used in other parts of the code.
 // Pre: The program is running for the first time and all of the roads are being drawn, or the user
 //      chosen to toggle back on the roads
 // Post: All of the roads will be displayed on the map
{
   // Draw all main roads
   Pavement route140("Route 140",r140X,r140Y,1.0,80.0);
   Pavement route123("East Main St. (Route 123)",r123X,r123Y,45.0,73.2);
   Pavement taunton("Taunton St.",tauntx,taunty,2.5,40.5);
   Pavement Howard("Howard St.",howmidx,howmidy,18.6,50.0);
   Pavement Howardside("Howard St.",howsidex,howsidey,13,29.0);
   Pavement fork123("",fork123x,fork123y,0.0,0.0);
   Pavement Elm("Elm St.",elmx,elmy,75.0,90.0);
   Pavement Pine("Pine St.",pineX,pineY,80.0,60.0);
   Abstract filmore1("",15,26.5,27.4,filmore1X,filmore1Y,0.0,0.0,'p');
   Abstract filmore2("",11,40,16.8,filmore2X,filmore2Y,0.0,0.0,'p');
   Pavement filmore3("Filmore Dr.",filmore3X,filmore3Y,60,32.5);
   Pavement filmore4("Filmore Dr.",filmore4X,filmore4Y,60,32.5);
   Pavement filmore5("Filmore Dr.",filmore5X,filmore5Y,60,32.5);
   //add to global LABELED
   ROADS.push_back(route140),ROADS.push_back(route123),ROADS.push_back(taunton),
   ROADS.push_back(Howard),ROADS.push_back(Howardside),ROADS.push_back(Pine),
   ROADS.push_back(fork123),ROADS.push_back(Elm),
   ROADS.push_back(filmore3),ROADS.push_back(filmore4),ROADS.push_back(filmore5);

   // Draw side streets
   Pavement tennisStreet("",tstrX,tstrY,0.0,0.0);
   Pavement p1ext("",p1extx,p1exty,0.0,0.0);
   Pavement pl1acon("",pl1aconx,pl1acony,0.0,0.0);
   Pavement pl2con("",pl2conx,pl2cony,0.0,0.0);
   Pavement pl3con1("",pl3con1x,pl3con1y,0.0,0.0);
   Pavement pl3con2("",pl3con2x,pl3con2y,0.0,0.0);
   Pavement pl7con("",pl7conx,pl7cony,0.0,0.0);
   Pavement chasecon1("",chasecon1x,chasecon1y,0.0,0.0);
   Pavement chasecon2("",chasecon2x,chasecon2y,0.0,0.0);
   // add to global ROADS
   ROADS.push_back(tennisStreet),ROADS.push_back(pl2con),ROADS.push_back(pl7con),
   ROADS.push_back(p1ext),ROADS.push_back(pl3con1),ROADS.push_back(chasecon1),
   ROADS.push_back(pl1acon),ROADS.push_back(pl3con2),ROADS.push_back(chasecon2);
}

void drawFields()
// draws all of the fields by initializing an object for each one. Also, the objects are 
 // added to the global vector so they can be used in other parts of the code.
 // Pre: The program is running for the first time and all of the fields are being drawn
 // Post: All of the fields will be displayed on the map
{
   Grass dimple("The Dimple",dimpX,dimpY,34.8,55.0);
   Grass Siddell("Siddell Stadium",siddelX,siddelY,4.0,95.0);
   Grass Mirrione("Mirrione Stadium",mirrX,mirrY,70.0,18.0);
   Grass KeefeF("Keefe Field",keefefX,keefefY,80.0,35.0);
   Grass Diane("Diane Nordin Athletic Field",dianeX,dianeY,55.5,5.0);
   Grass tennis("Tennis Courts",tennisX,tennisY,27.0,88.2);
   Grass softball("Softball Field",softballX,softballY,32.0,95.0);
   Grass ClarkF("Clark Field",clarkfX,clarkfY,16.0,95.0);
   Abstract ChapelF1("Chapel Field",8,51,58,chapelF1X,chapelF1Y,48.9,58.3,'g');
   Abstract ChapelF2("Chapel Field",12,49.6,53,chapelF2X,chapelF2Y,48.9,58.3,'g');
   Abstract pondLower("Peacock Pond",20,57.9,54.0,pondLowerX,pondLowerY,54,52.5,'w');
   Abstract pondUpper("Peacock Pond",16,58,68.1,pondUpperX,pondUpperY,54,52.5,'w');
   //add to global MISC_LABELED
   MISC_LABELED.push_back(dimple),MISC_LABELED.push_back(KeefeF),MISC_LABELED.push_back(softball),
   MISC_LABELED.push_back(Siddell),MISC_LABELED.push_back(Diane),MISC_LABELED.push_back(ClarkF),
   MISC_LABELED.push_back(Mirrione),MISC_LABELED.push_back(tennis),MISC_LABELED.push_back(ChapelF1),
   MISC_LABELED.push_back(ChapelF2),MISC_LABELED.push_back(pondLower),MISC_LABELED.push_back(pondUpper);
}
 void drawHousing()
 // draws all of the student housing buildings by initializing an object for each one. Also, the objects are 
 // added to the global vector so they can be used in other parts of the code.
 // Pre: The program is running for the first time and all of the buildings are being drawn
 // Post: All of the student housing buildings will be displayed on the map
 {
   //draw student houses
   Housing Davis("Davis House",davisX,davisY,14.5,55.0);
   Housing h11("11 Howard",h11x,h11y,12.5,52.5);
   Housing outdoors("Outdoors House",outdoorsX,outdoorsY,84.0,42.6);
   Housing twap("TWAP",twapX,twapY,90.0,33.0);
   Housing bitter("Bittersweet",bitterX,bitterY,92.5,28.9);
   Housing pine57("5/7 Pine",pine57x,pine57y,73.6,65.5);
   Housing eco("Eco House",ecoX,ecoY,1.0,47.6);
   Housing t2628("26/28 Taunton",T2628x,T2628y,8.1,17.0);
   Housing h44("44 Howard",h44x,h44y,9.0,26.0);
   Housing bcHouse("Brooks Campbell",bcX,bcY,12.5,40.0);
   Housing oldfield("Oldfield House",oldfieldX,oldfieldY,65.5,76.6);
   Housing h22("22 Howard",h22X,h22Y,25.0,41.0);
   Housing wh("White House",whX,whY,16.0,46.0);
   Housing sem("The Sem",semX,semY,17.5,65.5);
   Housing guest("Guest House",guestX,guestY,12.6,80.5);
   //add to global DORMS
   DORMS.push_back(Davis),DORMS.push_back(pine57),DORMS.push_back(h22),
   DORMS.push_back(h11),DORMS.push_back(eco),DORMS.push_back(oldfield),
   DORMS.push_back(outdoors),DORMS.push_back(t2628),DORMS.push_back(wh),
   DORMS.push_back(twap),DORMS.push_back(h44),DORMS.push_back(sem),
   DORMS.push_back(bitter),DORMS.push_back(bcHouse),DORMS.push_back(guest);
   
   //draw student dorms
   Housing everett("Everett",everettX,everettY,25.0,43.9);
   Housing evheights("Ev. Heights",evheightsX,evheightsY,24.0,51.0);
   Housing stanton("Stanton",stantX,stantY,31.0,43.0);
   Housing cragin("Cragin",cragX,cragY,31.2,48.0);
   Housing larcom("Larcom",larcomX,larcomY,30.5,60.5);
   Housing chapin("Chapin",chapinX,chapinY,27.2,63.0);
   Housing metcalf("Metcalf",metcalfX,metcalfY,30.0,67.5);
   Housing kilham("Kilham",kilhamX,kilhamY,24.5,67.5);
   Housing emer("Emerson",emX,emY,25.0,57.0);
   Housing mac("MacIntire",macX,macY,66.5,62.5);
   Housing clark("Clark",clarkX,clarkY,62.6,67.5);
   Housing young("Young",youngX,youngY,70.0,67.5);
   Housing MconY("",MconYx,MconYy,0.0,0.0);
   Housing meadEast("Meadows East",meadEx,meadEy,69.5,46.5);
   Housing meadWest("Meadows West",meadWx,meadWy,60.5,46.5);
   Housing meadNorth("Meadows North",meadNx,meadNy,68.2,53.2);
   Housing meadCenter("Meadows Center",meadCx,meadCy,67.0,50.0);
   Housing beard("Beard",beardX,beardY,20.0,25.5);
   Housing keefe("Keefe",keefeX,keefeY,25.0,35.0);
   Housing gebbie("Gebbie",gebbieX,gebbieY,28.4,37.7);
   // add to global DORMS
   DORMS.push_back(gebbie),DORMS.push_back(keefe),DORMS.push_back(beard),DORMS.push_back(meadEast),
   DORMS.push_back(meadWest),DORMS.push_back(meadNorth),DORMS.push_back(meadCenter),DORMS.push_back(MconY),
   DORMS.push_back(young),DORMS.push_back(clark),DORMS.push_back(mac),DORMS.push_back(emer),
   DORMS.push_back(kilham),DORMS.push_back(chapin),DORMS.push_back(cragin),DORMS.push_back(stanton),
   DORMS.push_back(metcalf),DORMS.push_back(larcom),DORMS.push_back(everett),DORMS.push_back(evheights);
 }

 void drawDining()
 // draws all of the dining locations by initializing an object for each one. Also, the objects are 
 // added to the global vector so they can be used in other parts of the code.
 // Pre: The program is running for the first time and all of the buildings are being drawn
 // Post: All of the dining locations will be displayed on the map
 {
   Dining Den("Lyon's Den",lyonsdenX,lyonsdenY,8.1,20.7);
   Dining chase("Chase",chaseX,chaseY,61.0,60.0);
   Dining Emerson("Emerson",emersonDX,emersonDY,30.0,52.5);
   Dining daviscafe("Davis Spencer Cafe",daviscafeX,daviscafeY,40.0,31.5);
   Dining loft("The Loft",loftX,loftY,47.7,43.0);
   //add to global MISC_LABELED
   MISC_LABELED.push_back(Den),MISC_LABELED.push_back(daviscafe),
   MISC_LABELED.push_back(chase),MISC_LABELED.push_back(loft),
   MISC_LABELED.push_back(Emerson);
   Circle chaseCirc("Chase");
 }

 void drawAcademic()
 // draws all of the academic buildings by initializing an object for each one. Also, the objects are 
 // added to the global vector so they can be used in other parts of the code.
 // Pre: The program is running for the first time and all of the buildings are being drawn
 // Post: All of the academic buildings will be displayed on the map
 {
   MARS.reDraw();
   LIB1.reDraw();
   LIB2.reDraw();
   Academic oldsci1("Old Science Center",oldsci1X,oldsci1Y,35.5,25.0);
   Academic oldsci2("Old Science Center",oldsci2X,oldsci2Y,35.5,25.0);
   Academic knapton1("Knapton",knapton1X,knapton1Y,42.7,61.0);
   Academic knapton2("Knapton",knapton2X,knapton2Y,42.7,61.0);
   Academic meneely1("Meneely",meneely1X,meneely1Y,50.0,63.0);
   Academic meneely2("Meneely",meneely2X,meneely2Y,50.0,63.0);
   Academic watson1("Watson Fine Arts",watson1X,watson1Y,47.6,69.0);
   Academic watson2("Watson Fine Arts",watson2X,watson2Y,47.6,69.0);;
   Academic kollett("Kollett Hall",kollettX,kollettY,29.0,30.0);
   Academic marylyon1("Mary Lyon",marylyon1X,marylyon1Y,41.4,68.0);
   Academic marylyon2("Mary Lyon",marylyon2X,marylyon2Y,41.4,68.0);
   Academic observe("Old Observatory",observX,observY,47.0,91.9);
   //add to global MISC_LABELED
   MISC_LABELED.push_back(MARS),MISC_LABELED.push_back(knapton1),MISC_LABELED.push_back(watson1),
   MISC_LABELED.push_back(LIB1),MISC_LABELED.push_back(knapton2),MISC_LABELED.push_back(watson2),
   MISC_LABELED.push_back(LIB2),MISC_LABELED.push_back(meneely1),MISC_LABELED.push_back(marylyon1),
   MISC_LABELED.push_back(oldsci1),MISC_LABELED.push_back(meneely2),MISC_LABELED.push_back(marylyon2),
   MISC_LABELED.push_back(oldsci2),MISC_LABELED.push_back(kollett),MISC_LABELED.push_back(observe);

 }

 void drawCampusBuildings()
 // draws all of the campus buildings by initializing an object for each one. Also, the objects are 
 // added to the global vector so they can be used in other parts of the code.
 // Pre: The program is running for the first time and all of the buildings are being drawn
 // Post: All of the campus buildings will be displayed on the map
 {
   CampusBuilding marshall("Marshall Center",marshallX,marshallY,14.5,69.0);
   CampusBuilding balfour("Balfour-Hood",balfourX,balfourY,42.8,45.0);
   CampusBuilding libsq("10 Library Sq.",libsqX,libsqY,9.9,77.0);
   CampusBuilding facop("Facilities",facopX,facopY,55,45);
   CampusBuilding hebe("Hebe Hall",hebeX,hebeY,26.1,72.0);
   CampusBuilding pubsaf("Public Safety",pubsafX,pubsafY,8.1,12.5);
   CampusBuilding globaled("Global Ed.",globaledX,globaledY,16.3,62.5);
   CampusBuilding doll("Doll's House",dollX,dollY,40.0,42.5);
   CampusBuilding admis1("Admission",admis1X,admis1Y,42.7,51.0);
   CampusBuilding admis2("Admission",admis2X,admis2Y,42.7,51.0);
   CampusBuilding park("Park Hall",parkX,parkY,33.3,65.5);
   CampusBuilding pres("President's House",presX,presY,38.0,76.6);
   CampusBuilding bookstore("Bookstore",bookstoreX,bookstoreY,8.1,47.6);
   CampusBuilding nortonmed("Norton Medical Center",nortonmedX,nortonmedY,5.6,35.0);
   CampusBuilding clarkrec("Clark Athletic Center",clarkrecX,clarkrecY,13.6,88.2);
   CampusBuilding nursery("Nursery School",nurseryX,nurseryY,16.6,76.0);
   CampusBuilding counsel("Counseling",counselX,counselY,13.0,24.5);
   CampusBuilding haas1("Haas Athletic Center",haas1X,haas1Y,42.7,13.0);
   CampusBuilding haas2("Haas Athletic Center",haas2X,haas2Y,42.7,13.0);
   CampusBuilding haas3("Haas Athletic Center",haas3X,haas3Y,42.7,13.0);
   CHAPEL.reDraw();
   FIELDHOUSE.push_back(haas1),FIELDHOUSE.push_back(haas2),FIELDHOUSE.push_back(haas3);
   //add to global CAMPUS_BUILDING
   CAMPUS_BUILDINGS.push_back(CHAPEL),CAMPUS_BUILDINGS.push_back(pubsaf),CAMPUS_BUILDINGS.push_back(park),CAMPUS_BUILDINGS.push_back(bookstore),
   CAMPUS_BUILDINGS.push_back(marshall),CAMPUS_BUILDINGS.push_back(globaled),CAMPUS_BUILDINGS.push_back(pres),CAMPUS_BUILDINGS.push_back(nortonmed),
   CAMPUS_BUILDINGS.push_back(balfour),CAMPUS_BUILDINGS.push_back(doll),CAMPUS_BUILDINGS.push_back(haas1),CAMPUS_BUILDINGS.push_back(clarkrec),
   CAMPUS_BUILDINGS.push_back(libsq),CAMPUS_BUILDINGS.push_back(admis1),CAMPUS_BUILDINGS.push_back(haas2),CAMPUS_BUILDINGS.push_back(nursery),
   CAMPUS_BUILDINGS.push_back(facop),CAMPUS_BUILDINGS.push_back(admis2),CAMPUS_BUILDINGS.push_back(haas3),CAMPUS_BUILDINGS.push_back(counsel),
   CAMPUS_BUILDINGS.push_back(hebe);
 }

void drawLabels()
// draws the labels for all of the significant locations around campus
// Pre: Either the program has just started and the labels are being rendered for the first time,
//      or the user has toggled back on the labels and they are being rerendered.
// Post: The labels will be displayed near their corresponding icon on the map
{
   if(roadsOn)
   {   
      for(vector<Pavement>::iterator it = ROADS.begin(); it != ROADS.end(); ++it)
      {
         (*it).label();
      }
   }
   for(vector<Location>::iterator it = MISC_LABELED.begin(); it != MISC_LABELED.end(); ++it)
   {
      (*it).label();
   }
   for(vector<Housing>::iterator it = DORMS.begin(); it != DORMS.end(); ++it)
   {
      (*it).label();
   }
   for(vector<CampusBuilding>::iterator it = CAMPUS_BUILDINGS.begin(); it != CAMPUS_BUILDINGS.end(); ++it)
   {
      (*it).label();
   }
}

void drawCursor()
// draws the cursor/marker that is used for super interactive mode. This cursor can be controlled by the user
// using the '7', '8', '9', and '0' keys if the labels are toggled off.
// Pre: The label option is turned off
// Post: The cursor will move around the visualization window depending on the user input keys
{
   GLUquadricObj *cur;
   cur = gluNewQuadric();
   glColor3f(0.0,0.0,0.523);
   glTranslatef(CUR_X,CUR_Y,0.0);
   gluDisk(cur,0.0,0.5,10,1);
   glTranslatef(-CUR_X,-CUR_Y,0.0);
}

void displayLegend()
// Displays the legend explaing the color coordination of the map. This option can be toggled of using the
// 'k' keyboard key.
// Pre: Either the program is running for the first time, or the legend is being rerendered after the
//      user chose to hide it
// Post: The map key will be displayed in the top right corner of the visualization window
{
  string title = "Map Legend";
  string dorms = "Dorms";
  string pave = "Roads/Parking Lots";
  string Aca = "Academic Buildings";
  string dining = "Dining";
  string camp = "Campus Buildings";
  string fields = "Fields";
  glColor3f(0,0,.502);
  glBegin(GL_LINE_STRIP);
    glVertex3f(81.0,84,0.0);
    glVertex3f(81.0,99.5,0.0);
    glVertex3f(98.0,99.5,0.0);
    glVertex3f(98.0,84,0.0);
    glVertex3f(81.0,84,0.0);
  glEnd();

  glRasterPos2f(85.4,98);
  for(int i=0;i<title.size();i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,title[i]);
  }

  glColor3f(.533,.533,.533);
  glRectf(84,95.5,85,96.5);
  glRasterPos2f(86.2,95.5);
  for(int i=0;i<pave.size();i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,pave[i]);
  }

  glColor3f(.6,.4,1);
  glRectf(84,93.5,85,94.5);
  glRasterPos2f(86.2,93.5);
  for(int i=0;i<dorms.size();i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,dorms[i]);
  }

  glColor3f(.322,0.435,0.208);
  glRectf(84,91.5,85,92.5);
  glRasterPos2f(86.2,91.5);
  for(int i=0;i<fields.size();i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,fields[i]);
  }

  glColor3f(0.714,0.584,0.129);
  glRectf(84,89.5,85,90.5);
  glRasterPos2f(86.2,89.5);
  for(int i=0;i<dining.size();i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,dining[i]);
  }

  glColor3f(0.498,0.09,0.412);
  glRectf(84,87.5,85,88.5);
  glRasterPos2f(86.2,87.5);
  for(int i=0;i<Aca.size();i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,Aca[i]);
  }

  glColor3f(0.867,0.118,0.184);
  glRectf(84,85.5,85,86.5);
  glRasterPos2f(86.2,85.5);
  for(int i=0;i<camp.size();i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,camp[i]);
  }
}

void displayDirections()
{
  cout << "*************************************************************************" << endl;
  cout << "*                  Wheaton College (MA) Campus Map                      *" << endl;
  cout << "*************************************************************************" << endl;
  cout << "\n                            Controls                                     \n" << endl;
  cout << "   KEY                  EVENT                                            \n" << endl;
  cout << "   'c'                  Highlights the Chapel" << endl;
  cout << "   'd'                  Highlights the Student Housing" << endl;
  cout << "   'f'                  Highlights Haas Athletic Center (fieldhouse)" << endl;
  cout << "   'l'                  Highlights the Wallace Library" << endl;
  cout << "   's'                  Highlights the Mars Science Center" << endl;
  cout << "   'k'                  Toggle the map key on / off" << endl;
  cout << "   'L'                  Toggle the labels on / off" << endl;
  cout << "   'R'                  Toggle the Roads on / off" << endl;
  cout << "   'q'                  Exit the program" << endl;
  cout << "\nSUPER INTERACTIVE MODE" << endl;
  cout << "Navigate around the campus map, and the cursor will tell you where you are located!\n" << endl;
  cout << "Note: Labels must be turned off for this functionality.\n" << endl;
  cout << "   '7'                  Move cursor left" << endl;
  cout << "   '8'                  Move cursor down" << endl;
  cout << "   '9'                  Move cursor up" << endl;
  cout << "   '0'                  move cursor right" << endl;
  cout << "\n***********************************************************************\n" << endl;
}

int displayPosition(float x, float y)
// displays the current location of the circular cursor during super interactive mode. If the cursor is
// not on a specific location, "Wheaton College" will be displayed.
// Parameters: x - a float representing the x coordinate of the cursor
//             y - a float representing the y coordinate of the cursor
// Pre: Super interactive mode is enabled, meaning that the user has chosen to turn off labels
// Post: The current position of the marker will be displayed at the top of the visualization window
//       as the user moves the marker around
{
  for(vector<Housing>::iterator it = DORMS.begin(); it != DORMS.end(); ++it)
  {
      if((*it).findPosition(x,y))
      {
        glColor3f(0.0,0,0);
        glRasterPos2f(44,95);
        for(int i=0;i<(*it).getName().size();i++)
        {
          glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(*it).getName()[i]);
        }
        cout << "Current Position: " << (*it).getName() << endl;
        return 0;
      }
  }
  for(vector<Location>::iterator it = MISC_LABELED.begin(); it != MISC_LABELED.end(); ++it)
  {
      if((*it).findPosition(x,y))
      {
        glColor3f(0.0,0,0);
        glRasterPos2f(44,95);
        for(int i=0;i<(*it).getName().size();i++)
        {
          glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(*it).getName()[i]);
        }
        cout << "Current Position: " << (*it).getName() << endl;
        return 0;
      }
  }
  for(vector<CampusBuilding>::iterator it = CAMPUS_BUILDINGS.begin(); it != CAMPUS_BUILDINGS.end(); ++it)
  {
      if((*it).findPosition(x,y))
      {
        glColor3f(0.0,0,0);
        glRasterPos2f(44,95);
        for(int i=0;i<(*it).getName().size();i++)
        {
          glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(*it).getName()[i]);
        }
        cout << "Current Position: " << (*it).getName() << endl;
        return 0;
      }
  }
  string def = "Wheaton College";
  glColor3f(0.0,0,0);
  glRasterPos2f(44,95);
        for(int i=0;i<def.size();i++)
        {
          glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,def[i]);
        }
  return 0;
}

void keyboardInput(unsigned char key, int x, int y)
// Handles all of the various cases of user input via keyboard buttons
// Parameters: key - an unsigned char representing the key that has back clicked by the user
//             x   - an integer representing the x coordinate at the mouse cursor's position at the time of a keyboard click
//             y   - an integer representing the y coordinate at the mouse cursor's position at the time of a keyboard click
// Pre: The user is entering input to the program through the keyboard
// Post: According to the specfic key that is clicked, a corresponding event will occur
{
   switch(key)
   {
      case 'c': if(chapelHighlight)
                {
                  CHAPEL.reDraw();
                  chapelHighlight = false;
                }
                else
                {
                  CHAPEL.highlight();
                  chapelHighlight = true;
                }
                if(labelsON){CHAPEL.label();}
                glFlush();
                break;
      case 'd': if(dormsHighlight)
                {
                  for(vector<Housing>::iterator it = DORMS.begin(); it != DORMS.end(); ++it)
                  {
                     (*it).reDraw();
                     if(labelsON)
                     {
                        (*it).label();
                     }
                  }
                  dormsHighlight = false;
                }
                else
                {
                  for(vector<Housing>::iterator it = DORMS.begin(); it != DORMS.end(); ++it)
                  {
                     (*it).highlight();
                     if(labelsON)
                     {
                        (*it).label();
                     }
                  }
                  dormsHighlight = true;
                }
                glFlush();
                break;
      case 'f': if(haasHighlight)
                {
                  for(vector<CampusBuilding>::iterator it = FIELDHOUSE.begin(); it != FIELDHOUSE.end(); ++it)
                  {
                     (*it).reDraw();
                     if(labelsON)
                     {
                        (*it).label();
                     }
                  }
                  haasHighlight = false;
                }
                else
                {
                  for(vector<CampusBuilding>::iterator it = FIELDHOUSE.begin(); it != FIELDHOUSE.end(); ++it)
                  {
                     (*it).highlight();
                     if(labelsON)
                     {
                        (*it).label();
                     }
                  }
                  haasHighlight = true;
                }
                glFlush();
                break;
      case 'k': if(legendOn)
                {
                  legendOn = false;
                  glutPostRedisplay();
                }
                else
                {
                  legendOn = true;
                  glutPostRedisplay();
                }
                break;
      case 'l': if(libHighlight)
                {
                  LIB1.reDraw();
                  LIB2.reDraw();
                  libHighlight = false;
                }
                else
                {
                  LIB1.highlight();
                  LIB2.highlight();
                  libHighlight = true;
                }
                if(labelsON)
                {
                  LIB1.label();
                  LIB2.label();
                }
                glFlush();
                break;
      case 'L': if(labelsON)
                {
                  labelsON = false;
                  glutPostRedisplay();
                }
                else
                {
                  labelsON = true;
                  glutPostRedisplay();
                }
                glutPostRedisplay();
                break;
      case 'R': if(roadsOn)
                {
                  roadsOn = false;
                  glutPostRedisplay();
                }
                else
                {
                  roadsOn = true;
                  glutPostRedisplay();
                }
                glutPostRedisplay();
                break;
      case 's': if(marsHighlight)
                {
                  MARS.reDraw();
                  marsHighlight = false;
                }
                else
                {
                  MARS.highlight();
                  marsHighlight = true;
                }
                if(labelsON){MARS.label();}
                glFlush();
                break;
      case '7': if(!labelsON)
                {
                  CUR_X=CUR_X-0.5;
                  glutPostRedisplay();
                }
                break;
      case '8': if(!labelsON)
                {
                  CUR_Y=CUR_Y-0.5;
                  glutPostRedisplay();
                }
                break;
      case '9': if(!labelsON)
                {
                  CUR_Y=CUR_Y+0.5;
                  glutPostRedisplay();
                }
                break;
      case '0': if(!labelsON)
                {
                  CUR_X=CUR_X+0.5;
                  glutPostRedisplay();
                }
                break;
      case 'q': exit(1);
   }
}
// Initialization routine.
void init() 
// Initializes the program by setting the background color of the visualization window
// Pre: The function is called from the main function
// Post: The background (clear color) color is set.
{
   glClearColor(0.8, 0.8, 0.8, 0.0);
   displayDirections();
}

void resizeWindow(int w, int h)
// Handles cases where the window is reshaped while the program is running
// Parameters: w - an integer representing width of the window
//             h - an integer representing height of the window
// Pre: The program is currently running and the user has altered the size of the display window
// Post: The model drawn will scale according to the window adjustments made by the user
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char **argv)
// main function
{  
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   glutInitWindowSize(870, 900);
   glutInitWindowPosition(100, 100); 
   glutCreateWindow("Wheaton College (MA)");
   init(); 
   glutKeyboardFunc(keyboardInput);   // the default keyboard function of the openGL program
   glutDisplayFunc(drawModel);        // the default display function of the openGL program
   glutReshapeFunc(resizeWindow);     // the default reshape function of the openGL program
   glutMainLoop(); 
   return 0;  
}
