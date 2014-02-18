/*
 *Filename: vertices.h
 *
 *Description: This .h file contains all of the coordinate points for 
 *             the vertices of many of the locations on campus. These
 *			   points will be used to draw all of the objects on the map.
 *
 */
 
using namespace std;

// Coordinates for Main Roads
float r140X [4] = {0.0,0.0,2.6,2.6};
float r140Y [4] = {68.0,100.0,100.0,68.0};
float r123X [4] = {0,0,100,100};
float r123Y [4] = {72.4,75,75,72.4};
float tauntx[4] = {5,5,7.6,7.6};
float taunty[4] = {0,70,70,0};
float howmidx[4] = {21.5,21.5,24.1,24.1};
float howmidy[4] = {30,78.2,78.2,30};
float howsidex[4] = {7.6,7.6,26.5,26.5};
float howsidey[4] = {27.4,30,30,27.4};
float elmx[4] = {76.5,76.5,79.1,79.1};
float elmy[4] = {69,100,100,69};
float pineX[4] = {100,76.5,79.1,100};
float pineY[4] = {22,69,69,26.3};
float fork123x[4] = {2.6,2.6,10,21.1};
float fork123y[4] = {68,70.6,72.4,72.4};
float filmore1X[15] = {26.5,26,28,29,30,31,32.5,34,34,31.8,31,30,29,27.5,26.5};
float filmore1Y[15] = {27.4,27,26,24,22.2,20.1,18.6,16.6,20,22.2,24.7,27.3,29,29.8,30};
float filmore2X[12] = {34,37,42,45.2,48,50.4,48.5,45.2,38,34,34};
float filmore2Y[12] = {20,18,18.8,20.6,24.5,24.5,22,18.5,16.6,16.5,20};
float filmore3X[4] = {48,50.2,72,72.5};
float filmore3Y[4] = {24.5,24.5,37,34.5};
float filmore4X[4] = {72.5,72.5,82,83};
float filmore4Y[4] = {34.5,36.5,44.5,44};
float filmore5X[4] = {83,82.3,87.3,88.3};
float filmore5Y[4] = {44,44.9,47.2,46.7};
// Coordinates for Parking Lots
float pl3x [4] = {91.5,85,93.5,100.0};
float pl3y [4] = {6.8,17.6,22.0,11.2};
float pl1ax [4] = {3.1,3.1,14,14};
float pl1ay [4] = {87,90,90,87};
float pl1x[4] = {18.9,18.9,26.7,26.7};
float pl1y[4] = {78.2,85,85,78.2};
float pl2x[4] = {56,56,76.5,76.5};
float pl2y[4] = {78.2,83.2,83.2,78.2};
float pl10x[4] = {10,10,17,17};
float pl10y[4] = {57,67,67,57};
float pl4x[4] = {65,65,72.5,72.5};
float pl4y[4] = {34.5,45,45,34.5};
float pl8x[4] = {29.2,29.2,41.6,41.6};
float pl8y[4] = {7.5,16.6,16.6,7.5};
float pl9x[4] = {31.8,31.8,35,35};
float pl9y[4] = {22,25,25,22};
float pl3ax[4] = {77.7,78.3,88.3,88};
float pl3ay[4] = {30.2,31.6,27.5,25.8};
float pl3bx[4] = {85.0,86.7,90,88.3};
float pl3by[4] = {28.8,33,31.6,27.4};
float pl3cx[4] = {86.7,88.8,90.4,88.3};
float pl3cy[4] = {33,38.1,37.4,32.3};
float pl7x[4] = {52.3,52.3,55,55};
float pl7y[4] = {14.3,18.5,18.5,14.3};

// Coordinates for Side Roads
float pl7conx[4] = {49,49.8,55,53.6};
float pl7cony[4] = {22.5,23.5,18.5,18.5};
float chasecon1x[4] = {65.2,65.2,74.2,73.6};
float chasecon1y[4] = {57.6,59,59,57.6};
float chasecon2x[4] = {73.6,74.2,83,81.9};
float chasecon2y[4] = {57.6,59,44,43.2};
float pl3con1x[4] = {86.7,88.3,93,91.4};
float pl3con1y[4] = {26.6,27.4,21.5,20.7};
float pl3con2x[4] = {93,100,100,94.2};
float pl3con2y[4] = {21,24,22,19.6};
float pl2conx[4] = {56,56,58.6,58.6};
float pl2cony[4] = {78.2,75,75,78.2};
float pl1aconx[4] = {10,10,11.5,11.5};
float pl1acony[4] = {67,87,87,67};
float p1extx[4] = {11.5,11.5,18.9,18.9};
float p1exty[4] = {83,85,85,83};
float tstrX [4] = {2.6,2.6,40,40};
float tstrY [4] = {85,86.5,86.5,85};

// Coordinates for Fields
float dimpX [4]= {34.9,34.9,41,41};
float dimpY [4]= {43.2,62.0,62.0,43.2};
float siddelX [4] = {3.1,3.1,14,14};
float siddelY [4] = {90,99.7,99.7,90};
float mirrX[4] = {75.1,67.3,74.3,82.1};
float mirrY[4] = {10,19,24.6,15.6};
float keefefX[4] = {85.0,78.3,82.1,88.8};
float keefefY[4] = {28.8,31.6,40.9,38.1};
float dianeX[4] = {56,58.9,67.7,66};
float dianeY[4] = {0,9,7,0};
float tennisX[4] = {23.9,23.9,40.5,40.5};
float tennisY[4] = {87,90.5,90.5,87};
float softballX[4] = {30.7,30.7,40.2,40.2};
float softballY[4] = {92.6,99.2,99.2,92.6};
float clarkfX[4] = {15,15,29.5,29.5};
float clarkfY[4] = {92.6,99.2,99.2,92.6};
float chapelF1X[8] = {49,49,54.2,54.1,52.5,51.1,50,49};
float chapelF1Y[8] = {55,60,60,57.3,57,55,55,55};
float chapelF2X[12] = {49,49,49,50,51.1,50.9,50.7,51.1,51.5,51.8,50,49};
float chapelF2Y[12] = {49.4,53,55,55,55,54,52.5,51.3,50.6,49.4,49.4,49.4};

// Coordinates for Student Houses
float davisX[4] = {17.3,17.3,21.2,21.2};
float davisY[4] = {53.4,57,57,53.4};
float h11x[4] = {12.5,12.5,16.9,16.9};
float h11y[4] = {53.9,51.3,51.3,53.9};
float outdoorsX[4] = {85.9,84.5,87.5,88.9};
float outdoorsY[4] = {40.5,43.4,44.9,42};
float twapX[4] = {91.7,90.1,93.1,94.7};
float twapY[4] = {29.7,33,34.4,31.1};
float bitterX[4] = {94.1,92.5,95.2,96.7};
float bitterY[4] = {25.8,28.9,30.1,27};
float pine57x[4] = {73.8,73.8,76.2,76.2};
float pine57y[4] = {64,67,67,64};
float ecoX[4] = {1.8,1.8,4.7,4.7};
float ecoY[4] = {46.8,50,50,46.8};
float T2628x[4] = {7.9,7.9,11.3,11.3};
float T2628y[4] = {15.7,18.9,18.9,15.7};
float h44x[4] = {11.1,11.1,14.2,14.2};
float h44y[4] = {25.7,27.1,27.1,25.7};
float bcX[4] = {17.3,17.3,21.2,21.2};
float bcY[4] = {38,41.8,41.8,38};
float oldfieldX[4] = {66,66,69,69};
float oldfieldY[4] = {75.3,78.2,78.2,75.3};
float h22X[4] = {24.4,24.4,27.5,27.5};
float h22Y[4] = {39.1,42.2,42.2,39.1};
float whX[4] = {17.3,17.3,21.2,21.2};
float whY[4] = {44,47.5,47.5,44};
float semX[4] = {17.3,17.3,21.2,21.2};
float semY[4] = {64.5,67.5,67.5,64.5};
float guestX[4] = {13.8,13.8,17.3,17.3};
float guestY[4] = {79,82,82,79};

// Coordinates for Student Dorms
float everettX[4] = {24.3,24.3,29.9,29.9};
float everettY[4] = {43.7,45.2,45.2,43.7};
float evheightsX[4] = {24.3,24.3,27.2,27.2};
float evheightsY[4] = {45.2,54.1,54.1,45.2};
float stantX[4] = {30.9,30.9,33,33};
float stantY[4] = {41.8,45.2,45.2,41.8};
float cragX[4] = {31.3,31.3,33.4,33.4};
float cragY[4] = {47.3,50,50,47.3};
float larcomX[4] = {30.6,30.6,33.3,33.3};
float larcomY[4] = {59,61.5,61.5,59};
float chapinX[4] = {27.1,27.1,30.6,30.6};
float chapinY[4] = {62,64,64,62};
float metcalfX[4] = {30.5,30.5,32.6,32.6};
float metcalfY[4] = {66.3,72.1,72.1,66.3};
float kilhamX[4] = {24.3,24.3,27.1,27.1};
float kilhamY[4] = {66.3,72.1,72.1,66.3};
float emX[4] = {24.3,24.3,30.1,30.1};
float emY[4] = {54.1,59,59,54.1};
float macX[4] = {66.3,66.3,69,69};
float macY[4] = {59.7,65,65,59.7};
float clarkX[4] = {62.4,62.4,65.1,65.1};
float clarkY[4] = {64.4,70,70,64.4};
float youngX[4] = {69.8,69.8,72,72};
float youngY[4] = {64.4,70,70,64.4};
float MconYx[4] = {65.1,65.1,69.8,69.8};
float MconYy[4] = {65,65.6,65.6,65};
float meadEx[4] = {69.5,69.5,73.7,73.7};
float meadEy[4] = {45.2,48,48,45.2};
float meadWx[4] = {65,65,69.5,69.5};
float meadWy[4] = {45.2,48,48,45.2};
float meadNx[4] = {67.5,67.5,73.7,73.7};
float meadNy[4] = {52.5,54.7,54.7,52.5};
float meadCx[4] = {67.5,67.5,70.2,70.2};
float meadCy[4] = {48,52.5,52.5,48};
float beardX[4] = {19.2,19.2,27,27};
float beardY[4] = {23.7,27.1,27.1,23.7};
float keefeX[4] = {24.3,24.3,27.7,27.7};
float keefeY[4] = {32.4,36.1,36.1,32.4};
float gebbieX[4] = {27.7,27.7,31.9,31.9};
float gebbieY[4] = {36.1,39,39,36.1};

// Coordinates for Campus Buildings
float marshallX[4] = {17.3,17.3,21.2,21.2};
float marshallY[4] = {68,70.7,70.7,68};
float balfourX[4] = {42.6,42.6,51,52.5};
float balfourY[4] = {44.1,47.1,47.1,44.1};
float libsqX[4] = {11.8,11.8,14.8,14.8};
float libsqY[4] = {75.3,77.7,77.7,75.3};
float facopX[4] = {54.4,54.4,57.6,57.6};
float facopY[4] = {44.6,46.6,46.6,44.6};
float hebeX[4] = {27.1,27.1,30.5,30.5};
float hebeY[4] = {69.8,72.1,72.1,69.8};
float pubsafX[4] = {7.9,7.9,11.5,11.5};
float pubsafY[4] = {11,14.4,14.4,11};
float chapelX[4] = {42.5,42.5,46.9,46.9};
float chapelY[4] = {54.5,57.1,57.1,54.5};
float globaledX[4] = {17.3,17.3,21.2,21.2};
float globaledY[4] = {61,64,64,61};
float dollX[4] = {41.8,41.8,44,44};
float dollY[4] = {41.6,43.6,43.6,41.6};
float admis1X[4] = {42.5,42.5,47.5,47.5};
float admis1Y[4] = {50,52.6,52.6,50};
float parkX[4] = {33.8,33.8,36.2,36.2};
float parkY[4] = {64,67.3,67.3,64};
float presX[4] = {38,38,44.6,44.6};
float presY[4] = {75.3,77.7,77.7,75.3};
float bookstoreX[4] = {7.9,7.9,13,13};
float bookstoreY[4] = {46.5,49.3,49.3,46.5};
float nortonmedX[4] = {7.9,7.9,13,13};
float nortonmedY[4] = {33.8,38.8,38.8,33.8};
float haas1X[4] = {42.5,42.5,47,47};
float haas1Y[4] = {12,15,15,12};
float haas2X[4] = {47,47,52.3,52.3};
float haas2Y[4] = {9.4,18,18,9.4};
float clarkrecX[4] = {14.3,14.3,23.6,23.6};
float clarkrecY[4] = {87,92,92,87};
float nurseryX[4] = {18.9,18.9,21.5,21.5};
float nurseryY[4] = {75.3,78.2,78.2,75.3};
float counselX[4] = {15.6,15.6,17.4,17.4};
float counselY[4] = {25.7,27.1,27.1,25.7};
float haas3X[4] = {52.3,52.3,56,56};
float haas3Y[4] = {9.4,14.3,14.3,9.4};
float admis2X[4] = {42.5,42.5,45,45};
float admis2Y[4] = {49,50,50,49};

// Coordinates for Dining
float lyonsdenX[4] = {7.9,7.9,12.2,12.2};
float lyonsdenY[4] = {19,22.5,22.5,19};
float chaseX[4] = {59.8,59.8,65.2,65.2};
float chaseY[4] = {57.5,62.1,62.1,57.5};
float emersonDX[4] = {30.1,30.1,33.3,33.3};
float emersonDY[4] = {51,58,58,51};
float daviscafeX[4] = {39.1,39.1,49,49};
float daviscafeY[4] = {30.2,33,33,33};
float loftX[4] = {49.1,46.8,52.5,52.5};
float loftY[4] = {42,44.1,44.1,44.1};

// Coordinates for Academic Buildings
float marsX[4] = {36,36,52,52};
float marsY[4] = {33,35.7,35.7,33};
float oldsci1X[4] = {35,35,36.5,36.5};
float oldsci1Y[4] = {22,30.2,30.2,22};
float oldsci2X[4] = {36.5,36.5,39.1,39.1};
float oldsci2Y[4] = {19.8,30.2,30.2,19.8};
float knapton1X[4] = {42.5,42.5,45,45};
float knapton1Y[4] = {59,63.5,63.5,59};
float knapton2X[4] = {45,45,46.9,46.9};
float knapton2Y[4] = {57.7,62.5,62.5,57.7};
float meneely1X[4] = {48.8,48.8,54.1,54.1};
float meneely1Y[4] = {61.8,63.9,63.9,61.8};
float meneely2X[4] = {48,48,51.1,51.1};
float meneely2Y[4] = {60.8,63,63,60.8};
float watson1X[4] = {47.7,47.7,51.7,51.7};
float watson1Y[4] = {67.1,71,71,67.1};
float watson2X[4] = {51.7,51.7,53.8,53.8};
float watson2Y[4] = {67.5,70,70,67.5};
float kollettX[4] = {31.8,31.8,35,35};
float kollettY[4] = {25,33.7,33.7,25};
float marylyon1X[4] = {43.5,43.5,46,46};
float marylyon1Y[4] = {65.4,70,70,65.4};
float marylyon2X[4] = {42,42,46.8,46.8};
float marylyon2Y[4] = {67,69,69,67};
float lib1X[4] = {35,35,42.1,42.1};
float lib1Y[4] = {37.1,40.2,40.2,37.1};
float lib2X[4] = {36.5,36.5,40.6,40.6};
float lib2Y[4] = {40.2,42,42,40.2};
float observX[4] = {48.5,48.5,51.5,51.5};
float observY[4] = {90.2,92.7,92.7,90.2};

// Peacock Pond
float pondLowerX[20] = {55,52.5,52.6,54.1,56,56.2,56.1,56.1,57.7,57.8,58,59.2,61.8,64.6,65.9,65.2,63.4,61,59,55};
float pondLowerY[20] = {49,50.9,53.3,55.1,56,59,61,63.9,63.9,61.2,58.5,55.7,55.7,55.1,54.1,52.2,50.4,50,48.9,49};
float pondUpperX[16] = {56.1,55.8,54.9,54.9,55.4,56,57.4,57.5,59,60.4,61,60.8,59.9,58.3,57.7,56.1};
float pondUpperY[16] = {64.9,65.7,66,67.5,67.5,68.2,69.1,70.2,71.1,70.1,68.8,67,66.8,66.3,64.9,64.9};

