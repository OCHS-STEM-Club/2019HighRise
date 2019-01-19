#include "Drive.hpp"

DriveManager::DriveManager () {
    stick = new frc::Joystick{ 0 };

    driveMotorLeft = new WPI_TalonSRX(1);
    driveMotorRight = new WPI_TalonSRX(4);

    slaveMotorLeft1 = new WPI_TalonSRX(2);
    slaveMotorLeft2 = new WPI_TalonSRX(3);

    slaveMotorRight1 = new WPI_TalonSRX(5);
    slaveMotorRight2 = new WPI_TalonSRX(6);

  tankDrive = new frc::DifferentialDrive(*driveMotorLeft, *driveMotorRight);

    xStickValue = new double; 
    yStickValue = new double; 

    slaveMotorLeft1->Follow(*driveMotorLeft);
    slaveMotorLeft2->Follow(*driveMotorLeft);

    slaveMotorRight1->Follow(*driveMotorRight);
    slaveMotorRight2->Follow(*driveMotorRight);
}

void DriveManager::driveTrain() {
    *xStickValue = -stick->GetRawAxis(1);
    *yStickValue = stick->GetRawAxis(2);


    tankDrive->ArcadeDrive(*xStickValue, *yStickValue);
}