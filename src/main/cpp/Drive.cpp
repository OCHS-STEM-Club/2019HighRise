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


    slaveMotorLeft1->Follow(*driveMotorLeft);
    slaveMotorLeft2->Follow(*driveMotorLeft);

    slaveMotorRight1->Follow(*driveMotorRight);
    slaveMotorRight2->Follow(*driveMotorRight);
}

int Sign(double input) {
    if (input > 0) {
        return 1;
    }
    else if (input < 0) {
        return -1;
    }
    else if (input == 0) {
        return 0;
    }
}

double deadband(double joystickValue, double deadbandValue) {
    if(abs(joystickValue) < 0.2){
        return 0;
    }
    else{
        return (1 / (1 - deadbandValue)) * (joystickValue + (-Sign(joystickValue) * deadbandValue));
    } 
}

void DriveManager::driveTrain() {
    xStickValue = deadband(-stick->GetRawAxis(1), 0.1);
    yStickValue = deadband(stick->GetRawAxis(2), 0.1);

    tankDrive->ArcadeDrive(xStickValue, yStickValue);

    frc::SmartDashboard::PutNumber("current left 1", driveMotorLeft->GetOutputCurrent());
    frc::SmartDashboard::PutNumber("current left 2", slaveMotorLeft1->GetOutputCurrent());
    frc::SmartDashboard::PutNumber("current left 3", slaveMotorLeft2->GetOutputCurrent());

    frc::SmartDashboard::PutNumber("current right 1", driveMotorRight->GetOutputCurrent());
    frc::SmartDashboard::PutNumber("current right 2", slaveMotorRight1->GetOutputCurrent());
    frc::SmartDashboard::PutNumber("current right 3", slaveMotorRight2->GetOutputCurrent());

}