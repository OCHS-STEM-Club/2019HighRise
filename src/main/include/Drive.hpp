#pragma once

#include <iostream>
#include <frc/WPILib.h>
#include <frc/Joystick.h>
//#include <frc/MotorSafety.h>
//#include <frc/RobotDriveBase.h>
//#include <frc/DifferentialDrive.h>
#include <ctre/Phoenix.h>

class DriveManager {
    private:
    frc::Joystick *stick; 
    WPI_TalonSRX *driveMotorLeft; 
    WPI_TalonSRX *driveMotorRight; 

    WPI_TalonSRX *slaveMotorLeft1;
    WPI_TalonSRX *slaveMotorLeft2;

    WPI_TalonSRX *slaveMotorRight1;
    WPI_TalonSRX *slaveMotorRight2;

    frc::DifferentialDrive *tankDrive;

    double xStickValue;
    double yStickValue;

    public:
    DriveManager();
    void driveTrain(); 
};