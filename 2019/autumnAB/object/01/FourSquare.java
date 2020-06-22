public class FourSquare {
  public static void main(String[] args) {
    SimpleRobot robot = new SimpleRobot();
    for (int i = 0; i < 4; i++) {
      robot.moveForward(100);
      robot.turnLeft(45);
      robot.moveForward(100);
      robot.turnRight(90);
      robot.moveForward(100);
      robot.turnRight(90);
      robot.moveForward(100);
      robot.turnRight(90);
      robot.moveForward(100);
      robot.turnLeft(45);
      robot.moveForward(100);
      robot.turnRight(90);
    }
  }
}