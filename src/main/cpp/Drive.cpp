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
  tankDrive1 = new frc::DifferentialDrive(*slaveMotorLeft1, *slaveMotorRight1);
  tankDrive2 = new frc::DifferentialDrive(*slaveMotorLeft2, *slaveMotorRight2);

    xStickValue = new double; 
    yStickValue = new double; 
}

//*slaveMotorLeft1->Set(ControlMode::Follower, 1);
//*slaveMotorLeft2->Set(ControlMode::Follower, 1);

//*slaveMotorRight1->Set(ControlMode::Follower, 4);
//*slaveMotorRight2->Set(ControlMode::Follower, 4);

//*slaveMotorLeft1->Set(ControlMode::Follower, 1);

void DriveManager::driveTrain() {
    *xStickValue = -stick->GetRawAxis(1);
    *yStickValue = stick->GetRawAxis(2);


    tankDrive->ArcadeDrive(*xStickValue, *yStickValue);
    tankDrive1->ArcadeDrive(*xStickValue, *yStickValue);
    tankDrive2->ArcadeDrive(*xStickValue, *yStickValue);
}