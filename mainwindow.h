#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include<QString>
#include <QSystemTrayIcon>
#include <QHotkey>
#include "windows.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void parametersEmplaceBack(std::tuple<std::string,std::string,int>);
public slots:
    void readLogFile();
    void updateLabels();
private:
    std::vector<std::tuple<std::string,std::string,int>> parameters {
        //To look for: power and closet states!!!!!!
        //Pytheas
        std::make_tuple("WL_LevelState_TranstarLabs_FireIndex","pytheasFireIndex",-1),
        std::make_tuple("WL_LevelState_TranstarLabs_FloodedIndex","pytheasFloodedIndex",-1),
        std::make_tuple("WL_LevelState_TranstarLabs_RadiationIndex","pytheasRadIndex",-1),
        std::make_tuple("WL_LevelState_TranstarLabs_BrokenStairs_Lobby","pytheasStairsLobby",-1),
        std::make_tuple("WL_LevelState_TranstarLabs_BrokenStairs_Director","pytheasStairsDirector",-1),
        //Moonworks
        std::make_tuple("WL_LevelState_Moonworks_FireIndex","moonworksFireIndex",-1),
        std::make_tuple("WL_LevelState_Moonworks_FloodedIndex","moonworksFloodedIndex",-1),
        std::make_tuple("WL_LevelState_Moonworks_RadiationIndex","moonworksRadIndex",-1),
        //Crew Annex
        std::make_tuple("WL_LevelState_CrewAnnex_FireIndex","crewFireIndex",-1),
        std::make_tuple("WL_LevelState_CrewAnnex_FloodedIndex","crewFloodedIndex",-1),
        std::make_tuple(" WL_LevelState_CrewAnnex_RadiationIndex","crewRadIndex",-1),
        //Crater Hazards
        std::make_tuple("WL_LevelState_Crater_TunnelClearChance","craterTunnel",-1),
        std::make_tuple("WL_LevelState_Crater_DustStormchance","craterDust",-1),
        //Broad Level States
        std::make_tuple("WL_HazardImmuneLevel","worldHazardImmune",-1),
        std::make_tuple("WL_LevelState_Crater_Hazard","craterHazard",-1),
        std::make_tuple("WL_LevelState_Crater_FireIndex","worldFireIndex",-1),
        std::make_tuple("WL_LevelState_Crater_FloodedIndex","worldFloodedIndex",-1),
        std::make_tuple("WL_LevelState_Crater_RadiationIndex","worldRadIndex",-1),
        std::make_tuple("WL_Escape_WhichEscapePodIsAvailable","worldPodIndex",-1),
        std::make_tuple("WL_WorldState_WhichTramStationIsInoperable","worldBrokenTramIndex",-1),
        //Angela and Vijay
        std::make_tuple("WL_PilotLevelIndex","angelaLevelIndex",-1),
        std::make_tuple("WL_PilotLocationIndex","angelaLocationIndex",-1),
        std::make_tuple("WL_PlayableSecurityGuardLocationIndex","vijayLocationIndex",-1),
        //Riley
        std::make_tuple("WL_Escape_UploadScan_Level","rileyUploadLevelIndex",-1),
        std::make_tuple("WL_Escape_UploadScan_CorpseLocation","rileyUploadLocationIndex",-1),
        //Claire
        std::make_tuple("WL_SideQuest_KasmaListener_Level","claireListenerLevelIndex",-1),
        std::make_tuple("WL_SideQuest_KasmaListener_Device1Location","claireListener1Index",-1),
        std::make_tuple("WL_SideQuest_KasmaListener_Device2Location","claireListener2Index",-1),
        std::make_tuple("WL_SideQuest_KasmaListener_Device3Location","claireListener3Index",-1),
        //Toy
        std::make_tuple("WL_SideQuest_VolunteerToyLevel","toyLevelIndex",-1),
        std::make_tuple("WL_SideQuest_VolunteerToyPosition","toyLocationIndex",-1),
        //vijay again
        std::make_tuple("WL_PlayableSecurityGuardLevelIndex","vijayLevelIndex",-1)
    };
    bool isFire;
    bool isFlood;
    bool isRad;
    bool isHazard;

private slots:
    void on_fileReadButton_clicked();
    void on_actionQuit_2_triggered();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
};
#endif // MAINWINDOW_H
