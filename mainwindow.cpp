#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon("kasma_logo.png"));
    trayIcon->show();


}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateLabels(){
    //pytheas
    ui->label_pytheasFireIndex->setText("Fire Zone: " + QString::number((std::get<2>(parameters[0]))));
    switch(std::get<2>(parameters[1])){
    case 0:
        ui->label_pytheasFloodedIndex->setText("Flood Zone: No Flooding");
        break;
    case 1:
        ui->label_pytheasFloodedIndex->setText("Flood Zone: Director's Office");
        break;
    case 2:
        ui->label_pytheasFloodedIndex->setText("Flood Zone: Lobby Entrance");
        break;
    case 3:
        ui->label_pytheasFloodedIndex->setText("Flood Zone: Basement Atrium");
        break;
    }

    //ui->label_pytheasFloodedIndex->setText("Flood Zone: " + QString::number((std::get<2>(parameters[1]))));

    ui->label_pytheasRadIndex->setText("Rad Zone: " + QString::number((std::get<2>(parameters[2]))));
    if(std::get<2>(parameters[3]) == 0){
        ui->label_pytheasStairsLobby->setText("Lobby Stairs: No Damage");
    } else {
        ui->label_pytheasStairsLobby->setText("Lobby Stairs: Damaged");
    }
    if(std::get<2>(parameters[4]) == 0){
        ui->label_pytheasStairsDirector->setText("Director Stairs: No Damage");
    } else {
        ui->label_pytheasStairsDirector->setText("Director Stairs: Damaged");
    }
    //moonworks
    ui->label_moonworksFireIndex->setText("Fire Zone: " + QString::number((std::get<2>(parameters[5]))));
    // 1 = utility room/crater entrance
    ui->label_moonworksFloodedIndex->setText("Flood Zone: " + QString::number((std::get<2>(parameters[6]))));
    ui->label_moonworksRadIndex->setText("Rad Zone: " + QString::number((std::get<2>(parameters[7]))));
    //crew annex
    ui->label_crewFireIndex->setText("Fire Zone: " + QString::number((std::get<2>(parameters[8]))));
    ui->label_crewFloodedIndex->setText("Flood Zone: " + QString::number((std::get<2>(parameters[9]))));
    ui->label_crewRadIndex->setText("Rad Zone: " + QString::number((std::get<2>(parameters[10]))));

    ui->label_craterTunnel->setText("Tunnel: " + QString::number((std::get<2>(parameters[11]))));
    ui->label_craterDust->setText("Dust Storm: " + QString::number((std::get<2>(parameters[12]))));

    ui->label_worldHazardEnable->setText("Hazards Disabled: " + QString::number((std::get<2>(parameters[11]))));
    ui->label_craterHazard->setText("Crater Hazard: " + QString::number((std::get<2>(parameters[14]))));
    switch(std::get<2>(parameters[15])){
    case 0:
        ui->label_worldFireIndex->setText("Fire Level: No Fire");
        isFire = false;
        break;
    case 1:
        ui->label_worldFireIndex->setText("Fire Level: Control");
        isFire = true;
        break;
    case 2:
        ui->label_worldFireIndex->setText("Fire Level: Labs");
        isFire = true;
        break;
    case 3:
        ui->label_worldFireIndex->setText("Fire Level: Moonworks");
        isFire = true;
        break;
    case 4:
        ui->label_worldFireIndex->setText("Fire Level: Crew Annex");
        isFire = true;
        break;
    case 5:
        ui->label_worldFireIndex->setText("Fire Level: Scale");
        isFire = true;
        break;
    case 6:
        ui->label_worldFireIndex->setText("Fire Level: PowerControl");
        isFire = true;
        break;

    }
    switch(std::get<2>(parameters[16])){
    case 0:
        ui->label_worldFloodIndex->setText("Flooded Level: No Flood");
        isFlood = false;
        break;
    case 1:
        ui->label_worldFloodIndex->setText("Flooded Level: Control");
        isFlood = true;
        break;
    case 2:
        ui->label_worldFloodIndex->setText("Flooded Level: Labs");
        isFlood = true;
        break;
    case 3:
        ui->label_worldFloodIndex->setText("Flooded Level: Moonworks");
        isFlood = true;
        break;
    case 4:
        ui->label_worldFloodIndex->setText("Flooded Level: Crew Annex");
        isFlood = true;
        break;
    case 5:
        ui->label_worldFloodIndex->setText("Flooded Level: Scale");
        isFlood = true;
        break;
    case 6:
        ui->label_worldFloodIndex->setText("Flooded Level: PowerControl");
        isFlood = true;
        break;
    }
    switch(std::get<2>(parameters[17])){
    case 0:
        ui->label_worldRadIndex->setText("Rad Level: No Rad");
        isRad = false;
        break;
    case 1:
        ui->label_worldRadIndex->setText("Rad Level: Control");
        isRad = true;
        break;
    case 2:
        ui->label_worldRadIndex->setText("Rad Level: Labs");
        isRad = true;
        break;
    case 3:
        ui->label_worldRadIndex->setText("Rad Level: Moonworks");
        isRad = true;
        break;
    case 4:
        ui->label_worldRadIndex->setText("Rad Level: Crew Annex"); // pytheas once
        isRad = true;
        break;
    case 5:
        ui->label_worldRadIndex->setText("Rad Level: Scale");
        isRad = true;
        break;
    case 6:
        ui->label_worldRadIndex->setText("Rad Level: PowerControl");
        isRad = true;
        break;

    }
    ui->label_worldPodIndex->setText("Escape Pod: " + QString::number((std::get<2>(parameters[18]))));
    // 1 = crater?, 3 = crater?, 1 = pytheas? 3 = pytheas???, 2 = moonworks
    ui->label_worldTramBrokenIndex->setText("Tram Broken: " + QString::number((std::get<2>(parameters[19]))));
    // 3 = moonworks, 2 = pytheas
    ui->label_angelaLevelIndex->setText("Angela Level: " + QString::number((std::get<2>(parameters[20]))));
    ui->label_angelaLocationIndex->setText("Angela Location: " + QString::number((std::get<2>(parameters[21]))));
    //Angela Locations:
    /* Pytheas:
     *  Office Vent
     *  Psychometrics
     *  Morgue
     *  Escape Pod
     * Moonworks: 2
     *  Support Systems 3
     *  The Pit 2
     *  Refinery
     *  Central Mine Ledge
     */
    ui->label_vijayLevelIndex->setText("Vijay Level: " + QString::number((std::get<2>(parameters[31]))));
    ui->label_vijayLocationIndex->setText("Vijay Location: " + QString::number((std::get<2>(parameters[22]))));
    //Vijay Locations:
    /* Pytheas: 2
     *  Conference Room Vent
     *  Bathroom 1
     *  Behavior Analytics
     *  Typhon Containment
     * Moonworks: 3
     *  Window Break
     *  Central Mine Ledge 0
     *  Crater Access Ledge
     *  Escape Pod Bay
     * Crew Annex:
     *  Tram Pit
     *  Control Tower
     *  Locker Room
     *  Fab Room
     */

    if(std::get<2>(parameters[23]) == 0){
        ui->label_rileyUploadLevelIndex->setText("Riley Upload Level: Moonworks");
    } else {
        ui->label_rileyUploadLevelIndex->setText("Riley Upload Level: Crew Annex");
    }
    ui->label_rileyUploadLocationIndex->setText("Riley Upload Location: " + QString::number((std::get<2>(parameters[24]))));
    if(std::get<2>(parameters[25]) == 0){
        ui->label_claireListenerLevelIndex->setText("Claire Device Level: Crater");
    } else {
        ui->label_claireListenerLevelIndex->setText("Claire Device Level: Crew Annex");
    }
    ui->label_claireListener1Index->setText("Claire Device 1: " + QString::number((std::get<2>(parameters[26]))));
    ui->label_claireListener2Index->setText("Claire Device 2: " + QString::number((std::get<2>(parameters[27]))));
    ui->label_claireListener3Index->setText("Claire Device 3: " + QString::number((std::get<2>(parameters[28]))));

    ui->label_toyLevelIndex->setText("Toy Level: " + QString::number((std::get<2>(parameters[29]))));
    ui->label_toyLocationIndex->setText("Toy Location: " + QString::number((std::get<2>(parameters[30]))));
    // Toy Locations:
    /* Crew Annex:
     *  Control Tower
     *  Cafeteria
     *  Rec Center
     * Moonworks:
     *  Support Systems
     *  Crater Access Ledge
     *  Crater Access Cage
     */

}


void MainWindow::on_fileReadButton_clicked() {
    readLogFile();
    updateLabels();


}


void MainWindow::on_actionQuit_2_triggered()
{
    this->close();
}

